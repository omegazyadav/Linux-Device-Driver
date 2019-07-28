This is the simple hello world linux kernel module. 

The hello.c file consist of two module, one for insertion of module inside kernel, 
whereas another for deletion of module from the linux kernel. 

For insertion of module inside kernel, we need to compile the hello.c code with make command,
which refers to the Makefile and hello.ko kernel object is generated. Later we then insert .ko file 
into the kernel with insmod command. 
i.e. $insmod hello.ko

To observe the changes in the kernel log file you can simply type:
$dmesg | tail -1

Similarly for removing the kernel module we remove the kernel object i.e. hello.ko type:
$rmmod hello.ko

To observe the changes made after removing the kernel module type:
$dmesg | tail -1
