/*
 *This is the static way of assigning the major and minor number 
 * in character device driver. 
 */

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
 
static dev_t dev=1 ;
 
static int __init hello_world_init(void)
{
        /*Allocating Major number*/

	static int maj;

	/*	
	 *
	 *The frist parameter of register_chardev_region is the minor number
	 * since the compiler automatically assign the major number to 0.
	 */
	
	maj=register_chrdev_region(dev,1,"omega_dev");
        if(maj <0){
                printk(KERN_INFO "Cannot allocate major number for device 1\n");
                return -1;
        }
        printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
        printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
 return 0;
}
 
void __exit hello_world_exit(void)
{
 	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yadav Lamichhane omegazyadav1@gmail.com");
