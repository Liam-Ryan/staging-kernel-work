/* Using wait queues */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/workqueue.h>

static DECLARE_WAIT_QUEUE_HEAD(my_waitq);
static int wake_condition = 0;

static struct work_struct wrk;

static void work_handler(struct work_struct *work)
{
	printk("Waitqueue module handler %s\n", __FUNCTION__);
	msleep(5000);
	printk("Wake up the sleeping module \n");
	wake_condition = 1;
	wake_up_interruptible(&my_waitq);
}

static int __init initfunction(void)
{
	printk("Using wait queues\n");

	INIT_WORK(&wrk, work_handler);
	schedule_work(&wrk);

	printk("Sleeping %s\n", __FUNCTION__);
	wait_event_interruptible(my_waitq, wake_condition !=0);

	printk("woken up by the work job\n");
	return 0;
}

static void __exit exitfunction(void)
{
	printk("Wait queue module unloading\n");
}

module_init(initfunction);
module_exit(exitfunction);
MODULE_AUTHOR("Liam Ryan <liamryandev@gmail.com>");
MODULE_LICENSE("GPL");
