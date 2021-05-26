PWD = $(shell pwd)
VERSION = $(shell uname -r)
KPATH = /lib/modules/$(VERSION)/build
obj-m := myfs.o

default:
	make -C  $(KPATH) SUBDIRS=$(PWD) modules        

clean:
	make -C  $(KPATH) SUBDIRS=$(PWD) clean
