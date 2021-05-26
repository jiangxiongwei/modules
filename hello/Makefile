PWD = $(shell pwd)
VERSION = $(shell uname -r)
KPATH = /lib/modules/$(VERSION)/build
obj-m := hello.o

default:
	make -C  $(KPATH) SUBDIRS=$(PWD) modules        

clean:
	make -C  $(KPATH) SUBDIRS=$(PWD) clean
