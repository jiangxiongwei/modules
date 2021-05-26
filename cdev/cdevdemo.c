#include<linux/module.h>

#define CDEVDEMO_MAJOR 255

static int cdevdemo_major = CDEVDEMO_MAJOR;

struct cdevdemo_dev
{
    struct cdev cdev;
};

struct cdevdemo_dev *cdevdemo_devp;

/*open function*/
int cdevdemo_open(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE "=====cdevdemo_open");
}


/*close function*/
int cdevdemo_release(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE "=====cdevdemo_release");


}


/*read function*/
static ssize_t cdevdemo_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_NOTICE "======== cdevdemo_read ");
}

static const struct file_operations cdevdemo_fops = 
{
    .owner = THIS_MODULE,
    .open = cdevdemo_open,
    .release = cdevdemo_release,
    .read = cdevdemo_read,
};

/* */
static void cdevdemo_setup_cdev(struct cdevdemo_dev *dev, int index)
{
    printk(KERN_NOTICE "====cdevdemo");
