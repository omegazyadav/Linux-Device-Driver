/*
 *
 * This kernel module accepts the command line arguments.
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("YADAV LAMICHHANE");



static int my_int = 10;
static char *arr = "omega";
static long int my_long = 1999;



module_param(my_int, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(arr,charp,0000);
module_param(my_long, long, S_IRUSR);





static int __init hello_module(void){

	printk(KERN_INFO "Hello, World\n");
	printk(KERN_INFO "Value of Integer:%d\n",my_int );
	printk(KERN_INFO "Value of character array: %s\n",arr);
	printk(KERN_INFO "Value of long integer:%ld\n",my_long);
	
	return 0;

}


static void __exit exit_module(void){

	printk(KERN_INFO "Goodbye! \n");
}


module_init(hello_module);
module_exit(exit_module);



