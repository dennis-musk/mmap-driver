# mmap-driver
The kernel alloc memory, user space use this area with mmap, no copy.

1. Edit Makefile, set $(KERNEL_SOURCE) to actual kernel directory which used to build this module.
2. make build
3. make load
4. open two windows, do this:  ./client a   ./client b
