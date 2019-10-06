#Linux Device Driver -GKH

- Hacking into the linux kernel. <br>
- This repository contains the device driver modules which can be loaded into the linux kernel
 space with the help of kernel utilities like insmod, rmmod, modprobe, etc. <br>

- The program available here are for educatioal purposes only. 
The device driver stack in linux kernel is divided into three categories, they are: <br>
1. Character Device Drivers <br>
2. Block Deivce Drivers <br>
3. Network Device Drivers <br>



Different Data Types in Linux Kernel:
Depending upon the different architecture different data types are available in linux kernel. 

Data Types:						Description:

1. u8 							/* unsigned byte (8 bits) */
2. u16 							/* unsigned word (16 bits) */
3. u32 							/* unsigned 32-bit value */
4. u64							/* unsigned 64-bit value */

REMARKS:- When you are writing a krenel module then never forget to append next line character in KERN_INFO otherwise 
insmod and rmmod may show unusual behaviour.<br>


