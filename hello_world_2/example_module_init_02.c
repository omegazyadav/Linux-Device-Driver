#include <linux/module.h>    
#include <linux/kernel.h>    
#include <linux/init.h>      

MODULE_LICENSE("GPL");
MODULE_AUTHOR("omegazyadav");


int __init hello_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

module_init(hello_init);
