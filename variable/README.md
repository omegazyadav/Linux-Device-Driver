This file accepts the command line arguemnts while loading the module into the kernel. 

Instruction for passing the command line arguments in kernel module. 

$ make

$ insmod module_name.ko kernel_variable=value

e.g: In this example the kernel module name is command_line_args.c and it accepts command line arguments of my_int, arr and my_long. 

We can pass the command line arguments for above parameters simply by:

$ insmod command_line_args.ko my_int=5 arr="omegazyadav" my_long=1000

$ dmesg | tail
