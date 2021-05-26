#include <linux/module.h>
#include <linux/errno.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/in.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/string.h>
#include <linux/init.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/ip.h> 

//#include <asm/system.h>
#include <asm/io.h>
#include <asm/irq.h>


static struct net_device    *virt_net;


static void virt_rs_packet(struct sk_buff *skb, struct net_device *dev)
{
       unsigned char *type;
       struct iphdr *ih;
       __be32 *saddr, *daddr, tmp;
       unsigned char tmp_dev_addr[ETH_ALEN];
       struct ethhdr *ethhdr;
       struct sk_buff *rx_skb;

       /* swap source/destination address*/
       ethhdr = (struct ethhdr *)skb->data;
       memcpy(tmp_dev_addr, ethhdr->h_dest, ETH_ALEN);
       memcpy(ethhdr->h_dest, ethhdr->h_source, ETH_ALEN);
       memcpy(ethhdr->h_source, tmp_dev_addr, ETH_ALEN);

     /*2)¶Ե÷hdr½ṹÌ"Դ/ĿµÄ IPµØ·*/
       ih = (struct iphdr *)(skb->data + sizeof(struct ethhdr));
       saddr = &ih->saddr;
       daddr = &ih->daddr;
       tmp = *saddr;
       *saddr = *daddr;
       *daddr = tmp;

   

    /*3)ʹÓip_fast_csum()4ÖÐ»ñphdr½ṹÌµÄ£ÑÂ*/
        ih->check = 0;               
        ih->check = ip_fast_csum((unsigned char *)ih,ih->ihl);


    /*4)ÉÖÊ¾Ýà*/
       type = skb->data + sizeof(struct ethhdr) + sizeof(struct iphdr);
       *type = 0;      //֮ǰÊ·¢Ëping°üÐҪ¸Äª0x00,±í½ÓÕing°ü  /*5)ʹÓdev_alloc_skb()4¹¹Ôһ¸öÄk_buff   */
       rx_skb = dev_alloc_skb(skb->len + 2);
   
    /*6)ʹÓskb_reserve()4Ì³ö½Ú·²¿¿ռä*/
       skb_reserve(rx_skb, 2);

   
    /*7)ʹÓmemcpy()½«֮ǰÐ¸ĺõÄk_buff->data¸´Öµ½ÐµÄk_buffÀ*/
    memcpy(skb_put(rx_skb, skb->len), skb->data, skb->len); // skb_put():4¶¯̬)´óbuff½ṹÌÀÖµÄý¬±Üâ³ö   /*8)ÉÖÐµÄk_buff ÆË³É±*/
    rx_skb->dev = dev;
    rx_skb->ip_summed = CHECKSUM_UNNECESSARY; /* don't check it */


    
    rx_skb->protocol = eth_type_trans(rx_skb, dev);

       dev->stats.rx_packets++;
       dev->stats.rx_bytes += skb->len;
    //   dev->last_rx= jiffies;
       netif_rx(rx_skb);

}

static int virt_send_packet(struct sk_buff *skb, struct net_device *dev)
{
       
       netif_stop_queue(dev);
 
    virt_rs_packet(skb,dev);
 
       dev_kfree_skb(skb);
       
       dev->stats.tx_packets++;         
       dev->stats.tx_bytes+=skb->len;
       dev->trans_start = jiffies;
       netif_wake_queue(dev); 

    return 0;
}

 
static int virt_net_init(void)
{
    /*1)ʹÓalloc_netdev()4·Öä¸ö_device½ṹÌ*/
    virt_net= alloc_netdev(sizeof(struct net_device), "virt_eth0", NET_NAME_UNKNOWN, ether_setup);

    /*2)ÉÖnet_device½ṹÌµĳÉ± */
    virt_net->hard_start_xmit = virt_send_packet;

    virt_net->dev_addr[0] = 0x08;
    virt_net->dev_addr[1] = 0x89;
    virt_net->dev_addr[2] = 0x89;
    virt_net->dev_addr[3] = 0x89;
    virt_net->dev_addr[4] = 0x89;
    virt_net->dev_addr[5] = 0x89;

    virt_net->flags |= IFF_NOARP;
    virt_net->features |= NETIF_F_NO_CSUM;


   /*3)ʹÓregister_netdev()4ע²át_device½ṹÌ */
    register_netdev(virt_net);
    return 0;
}

static void virt_net_exit(void)
{
    unregister_netdev(virt_net);
    free_netdev(virt_net);   
}

module_init(virt_net_init);
module_exit(virt_net_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("by:zhang");
