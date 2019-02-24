#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_custom_call(void) {
	printk("Hello, Syscall!");
	return 0;
}
