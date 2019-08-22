obj-m += example_module_01.o
obj-m += example_module_init_02.o
obj-m += example_module_exit_03.o


#obj-m := ex0102_simple_module.o
#ex0102_simple_module-objs := example_module_init_02.o example_module_exit_03.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

