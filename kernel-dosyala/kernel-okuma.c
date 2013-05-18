#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/module.h>  
#include <linux/kernel.h>  
  

int init_module(void)
{
struct file* filp = NULL;
mm_segment_t oldfs;
int err = 0;
char buf[128];
int ret;
filp = filp_open("/etc/dosyam/oku", O_RDONLY, 0);
   if(IS_ERR(filp)) 
	{
        err = PTR_ERR(filp);
        return NULL;
	}
    else{
        oldfs = get_fs();
        set_fs(get_ds());
	ret = vfs_read(filp, buf, 128, &filp->f_pos);
	set_fs(oldfs);
        printk(KERN_INFO "buf:%s\n",buf);
}        
     filp_close(filp,NULL);
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Modül yüklenemedi\n");
}   

    
  

  

