#include <linux/module.h>


static int __init myfs_init(void)
{
    return 0;

}

static void __exit myfs_exit(void)
{
    return;

}

module_init(myfs_init);
module_exit(myfs_exit);
MODULE_LICENSE("GPL");
