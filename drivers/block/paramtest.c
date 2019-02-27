#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

static char *message = "default";

static int __init param_module_init(void) 
{
	pr_crit("Param module says %s\n", message);
	return 0;
}

static void __exit param_module_exit(void)
{
	pr_crit("Farewell from param module!\n");
}

module_init(param_module_init);
module_exit(param_module_exit);

module_param(message, charp, S_IRUGO);

MODULE_PARM_DESC(message, "This message will be printed when the module is loaded");
MODULE_AUTHOR("Liam Ryan <liamryandev@gmail.com>");
MODULE_LICENSE("GPL");
