/*
 * This is a implementation of file_operations on character device driver mainly for SCULL driver.
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/cdev.h>


dev_t dev=0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
static int etx_open(struct inode *inode,struct file *file);
static int etx_release(struct inode *inode,struct file *file);
static ssize_t etx_read(struct file *filp,char __user *buf,size_t len,loff_t *off);
static ssize_t etx_write(struct file *filp,const char *buf,size_t len,loff_t *off);

static struct file_operations fops=
{
	.owner		= THIS_MODULE,
	.read		= etx_read,
	.write		= etx_write,
	.open		= etx_open,
	.release	= etx_release,

};


