obj-m := test_embshmem.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement -I$(PWD)/..
KBUILD_EXTRA_SYMBOLS := $(PWD)/../Module.symvers

KERNEL_SOURCE = /lib/modules/`uname -r`/build

all:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) clean
	
