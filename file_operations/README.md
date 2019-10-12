file_operations.c file contains the details of various file operation on scull driver. <br>
SCULL driver refers to simple character utility loading localities which is character specific driver. <br>
Various function involved in this file are: <br>

	- static int __init etx_driver_init(void);
	- static void __exit etx_driver_exit(void);
	- static int etx_open(struct inode *inode, struct file *file);
	- static int etx_release(struct inode *inode, struct file *file);
	- static ssize_t etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off); 
	- static ssize_t etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
 
