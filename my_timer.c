#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/kthread.h>

struct timer_list my_timer1;	// 定义定时器

static void my_timer_func(unsigned long data)	// 定义定时器回调函数
{
//	int i = my_timer1.data;
//	printk("%s:%d\n", __FUNCTION__, i);
//	my_timer1.data = i + 1;
	printk("aaa\n");
	my_timer1.expires = jiffies + HZ;
	add_timer(&my_timer1);
}

static int ICC_init(void)
{
	printk("%s\n", __FUNCTION__);
//	init_timer(&my_timer1);	// 初始化定时器，实际上，这个初始化函数仅仅将结构中的 list 成员初始化为空。

//	my_timer1.function = my_timer_func;	// 设置回调函数
//	my_timer1.data = 0;					// 设置data参数，一般传入0即可

	timer_setup(&my_timer1, (void (*)(struct timer_list *))my_timer_func, 0);
	my_timer1.expires = jiffies + HZ;	// 设置超时时间，1秒

	add_timer(&my_timer1);				// 把定时器添加到系统中，激活定时器

	return 0;
}

static void ICC_exit(void)
{
	printk("Uninstall SC device OK\n");
	del_timer(&my_timer1);				// 删除定时器
	return;
}

module_init(ICC_init);
module_exit(ICC_exit);

MODULE_DESCRIPTION("Contact Card Driver");
MODULE_AUTHOR("Felix Mo");
MODULE_LICENSE("GPL");
