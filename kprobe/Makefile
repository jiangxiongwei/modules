PWD = $(shell pwd)
VERSION = $(shell uname -r)
KPATH = /lib/modules/$(VERSION)/build
obj-m := kprobe-test.o

default:
	make -C  $(KPATH) SUBDIRS=$(PWD) modules        

clean:
	make -C  $(KPATH) SUBDIRS=$(PWD) clean
