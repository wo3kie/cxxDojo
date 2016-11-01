/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      make
 *
 * Usage:
 *      $ make insmod
 *
 *      $ make lsmod
 *
 *      $ make rmmod
 *
 *      $ make log
 */

/*
 * http://www.tldp.org/LDP/lkmpg/2.6/html/lkmpg.html
 * https://perf.wiki.kernel.org/index.php/Tutorial
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

//int init_module(void)
static int __init my_init(void)
{
	// printk is not a user space function like printf
	printk("Hello cxx_dojo_module!\n");

	// return 0 to show loading was OK
	return 0;
}

// void cleanup_module(void)
static void __exit my_exit(void)
{
	printk("Bye cxx_dojo_module!\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("wo3kie");
MODULE_DESCRIPTION("cxx_dojo_module description");

