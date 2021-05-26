obj-m := net_driver.o
SRC = /lib/modules/$(shell uname -r)/build
 
ko:
	make -C $(SRC) M=$(PWD) modules
	
clean:
	make -C $(SRC) M=$(PWD) clean

