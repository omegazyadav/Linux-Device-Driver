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

static int etx_open(struct inode *inode, struct file *file){
	
	printk(KERN_INFO " Driver open function called...\n");
	return 0;
}
 
static int etx_release(struct inode *inode,struct file *file){

	printk(KERN_INFO "Driver release function called...\n");
	return 0;
}

static ssize_t etx_read(struct file *filp,char __user *buf, size_t len, loff_t *off){

	printk(KERN_INFO "Driver read function called ...\n");
	return 0;

}

static ssize_t etx_write(struct file *filp,const char *buf,size_t len,loff_t *off){

	printk(KERN_INFO "Driver write function called ...\n");
	return len;
}


static int __init etx_driver_init(void)
{
	/*Allocating a major number for the SCULL driver*/
	
	if((alloc_chrdev_region(&dev,0,1,"etx_Dev"))<0)	{

		printk(KERN_INFO "Cannot allocate major number\n");
		return -1;
	}
	printk(KERN_INFO "The Major number is :%d Minor number is :%d\n",MAJOR(dev),MINOR(dev));

	/* Creating cdev structure */
	cdev_init(&etx_cdev,&fops);

	/* Adding character device to the system */
	
	if((cdev_add(&etx_cdev,dev,1))<0){

		printk(KERN_INFO "Cannot add the device to the system. \n");
		goto r_class;

	}

	/* Creating struct class */

	if((dev_class=class_create(THIS_MODULE,"etx_calss"))==NULL){

		printk(KERN_INFO "cannot create teh struct class \n");
		goto r_class;
	}
	
	/* Creating devie */

	if((device_create(dev_class,NULL,dev,NULL,"etx_device"))==NULL)	{

		printk(KERN_INFO " Cannot create the device  \n");
		goto r_device;

	}
	printk(KERN_INFO "Device Driver Insert ... Done!!!\n ");
	return 0;

r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit etx_driver_exit(void)
{
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Device Driver Remove .... Done!!!\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yadav Lamichhane <omegazyadav1@gmail.com");
MODULE_DESCRIPTION("Experimenting with SCULL driver");
