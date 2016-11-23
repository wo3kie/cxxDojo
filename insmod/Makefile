obj-m+=toUpperChar.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	$(CC) testToUpperChar.c -o testToUpperChar

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm testToUpperChar

insmod:
	@echo
	@sudo insmod toUpperChar.ko

lsmod:
	@sudo lsmod | head -n 1
	@sudo lsmod | grep toUpperChar || true
	@echo

rmmod:
	@sudo rmmod toUpperChar

