/* 
 * Followed
 *    http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/
 * by
 *    Derek Molloy
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wo3kie");

char const * const deviceName = "toUpperChar";
char const * const className = "toUpper";

static int majorNumber;
static char message[256] = { 0 };
static short sizeOfMessage;
static struct class* toUpperCharClass = 0;
static struct device* toUpperCharDevice = 0;

static int devOpen(struct inode * , struct file *);
static int devRelease(struct inode * , struct file *);
static ssize_t devRead(struct file * , char *, size_t, loff_t *);
static ssize_t devWrite(struct file * , char const *, size_t, loff_t *);

static struct file_operations fops =
{
    .open = devOpen,
    .read = devRead,
    .write = devWrite,
    .release = devRelease,
};

static int __init toUpperCharInit(void) {
    // major number
    majorNumber = register_chrdev(0, deviceName, &fops);

    if(majorNumber<0) {
    	printk(KERN_ALERT "EBBChar failed to register a major number\n");
       	return majorNumber;
    }

    printk(KERN_INFO "EBBChar: registered correctly with major number %d\n", majorNumber);

    // device class
    toUpperCharClass = class_create(THIS_MODULE, className);

    if(IS_ERR(toUpperCharClass)) {
       	unregister_chrdev(majorNumber, deviceName);
       	printk(KERN_ALERT "EBBChar: Failed to register device class\n");
       	return PTR_ERR(toUpperCharClass);
    }

    printk(KERN_INFO "EBBChar: device class registered correctly\n");

    // device 
    toUpperCharDevice = device_create(
		toUpperCharClass,
		NULL,
		MKDEV(majorNumber, 0),
		NULL,
		deviceName
	);

    if(IS_ERR(toUpperCharDevice)) {
       	class_destroy(toUpperCharClass);
       	unregister_chrdev(majorNumber, deviceName);
       	printk(KERN_ALERT "EBBChar: Failed to create the device\n");
       	return PTR_ERR(toUpperCharDevice);
    }

    printk(KERN_INFO "EBBChar: device class created correctly\n");
    
	return 0;
}

static void __exit toUpperCharExit(void) {
    device_destroy(toUpperCharClass, MKDEV(majorNumber, 0));
    class_unregister(toUpperCharClass);
    class_destroy(toUpperCharClass);
    unregister_chrdev(majorNumber, deviceName);
    printk(KERN_INFO "EBBChar: toUpperCharExit\n");
}

static int devOpen(
	struct inode * inodep,
	struct file *filep
) {
    printk(KERN_INFO "EBBChar: devOpen\n");
    return 0;
}

static int devRelease(
	struct inode * inodep,
	struct file * filep
) {
    printk(KERN_INFO "EBBChar: devRelease\n");
    return 0;
}

static ssize_t devWrite(
	struct file * filep,
	char const * buffer,
	size_t len,
	loff_t * offset
) {
    sprintf(message, "%s(%zu letters)", buffer, len);
    sizeOfMessage = strlen(message);
    printk(KERN_INFO "EBBChar: Received %zu characters from the user\n", len);
    return len;
}

static ssize_t devRead(
	struct file * filep,
	char * buffer, 
	size_t len, 
	loff_t * offset
) {
    int const error_count = copy_to_user(buffer, message, sizeOfMessage);

    if(error_count == 0) {
       printk(KERN_INFO "EBBChar: Sent %d characters to the user\n", sizeOfMessage);
       sizeOfMessage = 0;
	   return sizeOfMessage;
    }
    else {
       printk(KERN_INFO "EBBChar: Failed to send %d characters to the user\n", error_count);
       return -EFAULT;
    }
}

module_init(toUpperCharInit);
module_exit(toUpperCharExit);

