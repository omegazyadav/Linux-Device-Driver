#This is a makefile for the loadable kernel module. 


obj-m := dynamic_major_minor.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
