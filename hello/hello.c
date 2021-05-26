#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/proc_fs.h>
#include <linux/file.h>

unsigned long (*__kallsyms_lookup_name)(const char *name);

int kallsymcall(void *data , const char *namebuff, struct module *mu, unsigned long address)
{

   if (strcmp(namebuff, "kallsyms_lookup_name") == 0) {// 0  indicates that both strings are equal.
        __kallsyms_lookup_name = (void *)address;
        printk("name=%s address=%p\n",namebuff,(void*)address);
        return address;
    }

    return 0; 
}


struct proc_dir_entry *diag_proc_mkdir(const char *name, struct proc_dir_entry *parent)
{
    
    struct proc_dir_entry *ret = NULL;
    struct file *file;
    char full_name[255];

    snprintf(full_name, 255, "/proc/%s", name);
    file = filp_open(full_name, O_RDONLY, 0);
    if(IS_ERR(file)) {
        ret = proc_mkdir(name, parent);
    } else {
        fput(file);
    }

    return ret;


}


static int __init  hello_init(void)
{
    struct proc_dir_entry *pe;
    pe = diag_proc_mkdir("ali-linux", NULL);
    pe = diag_proc_mkdir("ali-linux/diagnose", NULL);
    
    (void)kallsyms_on_each_symbol(kallsymcall,NULL);
    

    
    return 0;
}


static void __exit hello_exit(void)
{
    return;
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");


