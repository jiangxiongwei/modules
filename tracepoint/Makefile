PWD = $(shell pwd)
VERSION = $(shell uname -r)
KPATH = /lib/modules/$(VERSION)/build
obj-m := tracepoint_test.o

default:
	make -C  $(KPATH) SUBDIRS=$(PWD) modules        

clean:
	make -C  $(KPATH) SUBDIRS=$(PWD) clean
