#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h> /* Character driver header file*/

int scull_open( struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Hello world");
	return 0;
}

//int scull_read(){
//	printk(KERN_ALERT "Hello world");
//	return 0;
//}
//
//int scull_write(){
//	printk(KERN_ALERT "Hello world");
//	return length;
//}
//
int scull_close(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "goodbye world");
	return 0;
}
struct file_operations major_minor_operation={
.owner    =THIS_MODULE,
.open	  =scull_open,
//.read     =scull_read,
//.write    =scull_write,
.release  =scull_close,
//
};



int scull_simple_module_init(void){
	printk(KERN_ALERT"Hello world");
	
	/* For registering the character device driver */

	register_chrdev(120				/*Major Number */,
			 "scull driver"			/* Name of the driver */,
			&major_minor_operation		/* File operations */ 
			 
			 );
	return  0;
			
}

void scull_simple_module_exit(void){
	printk(KERN_ALERT "Goodbye world");

	unregister_chrdev(120,"scull driver");
}


module_init(scull_simple_module_init);
module_exit(scull_simple_module_exit);
