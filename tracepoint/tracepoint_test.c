#include <linux/module.h>
#include <trace/events/block.h>

static void blk_add_trace_rq_insert1(void *ignore,struct request_queue *q,struct request *rq)
{
        printk("request size: %d %pf \n",rq->__data_len, q);
}
static int __init trace_init(void)
{
        WARN_ON(register_trace_block_rq_insert(blk_add_trace_rq_insert1,NULL));
        return 0;
}
static void __exit trace_exit(void)
{
        unregister_trace_block_rq_insert(blk_add_trace_rq_insert1,NULL);
}

module_init(trace_init)
module_exit(trace_exit)
MODULE_AUTHOR("miles");
MODULE_DESCRIPTION("A tracepoint example module");
MODULE_LICENSE("GPL");
