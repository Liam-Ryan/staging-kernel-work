#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hellomodule_init(void) {
	pr_crit("Hello module init function\n");
	return 0;
}

static void __exit hellomodule_exit(void) {
	pr_crit("Hello module exit function\n");
}

module_init(hellomodule_init);
module_exit(hellomodule_exit);

MODULE_AUTHOR("Liam Ryan <liamryandev@gmail.com>");
MODULE_LICENSE("GPL");
