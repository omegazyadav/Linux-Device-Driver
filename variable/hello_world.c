/*
 *
 * Variable assignment in hello_world kernel module. 
 *
 */


#include <linux/module.h>
#include <linux/kernel.h>


static int var __initdata = 10;


static int __init hello_init(void){

	printk(KERN_INFO "Hello world %d Times. \n",var );
	return 0;
}

static void __exit hello_exit(void){

	printk(KERN_INFO "Goodbye!\n");
}



module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");

