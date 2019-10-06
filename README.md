#Linux Device Driver -GKH

When you are writing a krenel module then never forget to append next line character in KERN_INFO otherwise 
insmod and rmmod may show unusual behaviour.<br>


Different Data Types in Linux Kernel:
Depending upon the different architecture different data types are available in linux kernel. 

Data Types:						Description:

1. u8 							/* unsigned byte (8 bits) */
2. u16 							/* unsigned word (16 bits) */
3. u32 							/* unsigned 32-bit value */
4. u64							/* unsigned 64-bit value */


