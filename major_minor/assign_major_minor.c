#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
 
static dev_t dev = 1;
 
static int __init hello_world_init(void)
{
        /*Allocating Major number*/

	static int maj;
	maj=alloc_chrdev_region(&dev,1,6,"omega_dev");
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
 	unregister_chrdev_region(dev, 6);
	printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yadav Lamichhane omegazyadav1@gmail.com");
