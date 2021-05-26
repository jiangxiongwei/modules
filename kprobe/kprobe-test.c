#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <linux/sched.h>
#include <linux/time.h>
static struct kprobe kp;
static struct timeval start, end;
static int hit_counter = 0;
int handler_pre(struct kprobe *p, struct pt_regs *regs)
{

	printk("current task on CPU#%d: %s \n", smp_processor_id(), current->comm);
	hit_counter++;
	return 0;
}


int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
	printk("A fault happened during probing.\n");
	return 0;
}

static __init int kprobe_test_init(void)
{
	int ret;

	kp.pre_handler = handler_pre;
//	kp.post_handler = handler_post;
	kp.fault_handler = handler_fault;
	kp.addr = (kprobe_opcode_t*) kallsyms_lookup_name("tcp_grow_window.isra.28");

	if (!kp.addr) {
		printk("Couldn't get the address of schedule.\n");
		return -1;
	}
	if ((ret = register_kprobe(&kp) < 0)) {
		printk("register_kprobe failed, returned %d\n", ret);
		return -1;
	}

	do_gettimeofday(&start);

	printk("kprobe registered\n");
	return 0;
}

static __exit void kprobe_test_exit(void)
{
	unregister_kprobe(&kp);
	do_gettimeofday(&end);
	printk("hit count is %d during of %ld milliseconds.\n", hit_counter, ((end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec))/1000);
	printk("kprobe unregistered\n");
}

module_init(kprobe_test_init);
module_exit(kprobe_test_exit);

MODULE_LICENSE("GPL");
