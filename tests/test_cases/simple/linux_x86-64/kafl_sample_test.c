/*
 * Copyright 2019 Sergej Schumilo, Cornelius Aschermann
 *
 * SPDX-License-Identifier: MIT OR GPL-2.0
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <asm/uaccess.h>
#include <linux/version.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Juhyun Song");
MODULE_DESCRIPTION("kAFL Test Module");

#define MAX_LEN		128
#define NAME	    "kafl_vuln"

ssize_t write_info(struct file *filp, const char __user *buff, size_t len, loff_t *data);

struct proc_dir_entry *proc_file_entry;

static const struct file_operations proc_file_fops = {
	 .owner = THIS_MODULE,
	 .write = write_info,
	};

int init_mod( void )
{
	proc_file_entry = proc_create(NAME, 0666, NULL, &proc_file_fops);
	if(proc_file_entry == NULL)
		return -ENOMEM;
	return 0;
}

void cleanup_mod( void )
{
	remove_proc_entry(NAME, NULL);
	printk(KERN_INFO "/proc/%s removed.\n", NAME);
}

module_init(init_mod);
module_exit(cleanup_mod);

ssize_t write_info(struct file *filp, const char __user *buff, size_t len, loff_t *data) {
	char input[256];
	int *array = (int *)kmalloc(1332, GFP_KERNEL);
	
	if (len >= 256){
		return -EFAULT;
	}
	
	if (copy_from_user(input, buff, len)) {
		return -EFAULT;
	}

	/* Length wall seems to exist
	 *
	 * BOB9 (4 bytes) -> succeed
	 * KERNELAFL (9 bytes) -> failed
	 */
	if (input[0] == 'K')
		if (input[1] == 'E')
			if (input[2] == 'R')
				if(input[3] == 'N')
					if (input[4] == 'E')
						if (input[5] == 'L')
							if (input[6] == 'A')
								if (input[7] == 'F')
									if (input[8] == 'L')
										panic(KERN_INFO "EXPLODE!\n");

	kfree(array);
	return len;
}