obj-m += cxx_dojo_module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

info:
	modinfo cxx_dojo_module.ko

insmod:
	sudo insmod ./cxx_dojo_module.ko param_int=1 param_string=\"configuration string\"

rmmod:
	sudo rmmod cxx_dojo_module

lsmod:
	@lsmod | head -n 1
	@lsmod | grep cxx_dojo_module

log:
	@echo ""
	@dmesg | tail
	@echo ""
	@cat /var/log/kern.log | tail

allsyms:
	cat /proc/kallsyms

