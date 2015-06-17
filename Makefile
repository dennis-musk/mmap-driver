.PHONY: all clean build load unload
obj-m := embshmem.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement
KERNEL_SOURCE = /lib/modules/`uname -r`/build

all: unload build load

load: 
	sudo ./installit.sh
	cd testmod && sudo insmod test_embshmem.ko

unload:
	- sudo rmmod test_embshmem.ko
	- sudo rmmod embshmem.ko
	
build:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) modules
	cd testmod && $(MAKE)
	$(MAKE) -f Makefile.testprog

clean:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) clean
	$(MAKE) -f Makefile.testprog clean
	$(MAKE) -C testmod clean



