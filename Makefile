CROSS_COMPILE=
AR=$(CROSS_COMPILE)ar
ARCH=x86_64
LD=$(CROSS_COMPILE)ld
CC=$(CROSS_COMPILE)gcc


obj-m := my_timer.o


KDIR := /lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -rf $(srcdir)*.o $(srcdir)*.mod.o $(srcdir)*.ko $(srcdir)*.mod.c *.o *.mod.o *.ko *.mod.c *.symvers *.order .*.cmd
