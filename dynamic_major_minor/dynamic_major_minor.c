/*
 *
 * This program demonstrate the dynamic allocation of the major and minor number 
 * for the character device drivers
 *
 */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/fs.h>
/*This is already u32 type defined so no need to delcare as unsigned value*/

static dev_t dev=10;


static int __init hello_world_init(void){

	static int maj;
	maj=alloc_chrdev_region(&dev,10,15,"omega_device");

	if (maj<0){
		printk(KERN_INFO "Major and Minor number cannot be assigned!\n");
		return -1;

	}

	printk(KERN_INFO "The value of major and minor number is :%d %d \n",MAJOR(dev),MINOR(dev));
	printk(KERN_INFO "The kernel module is loaded succesfully ! \n");
	return 0;

}


void __exit hello_world_exit(void){
	unregister_chrdev_region(dev,10);
	printk(KERN_INFO "The kernel module is removed successfully !\n");
	
}

module_init(hello_world_init);
module_exit(hello_world_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yadav Lamichhane <omegazyadav1@gmail.com>");
