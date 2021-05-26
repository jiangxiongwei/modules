#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xeba4f07b, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x27969118, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x3a9b6fb9, __VMLINUX_SYMBOL_STR(blk_unregister_region) },
	{ 0x636d35c9, __VMLINUX_SYMBOL_STR(del_gendisk) },
	{ 0xb5a459dc, __VMLINUX_SYMBOL_STR(unregister_blkdev) },
	{ 0x521445b, __VMLINUX_SYMBOL_STR(list_del) },
	{ 0xb82f52fa, __VMLINUX_SYMBOL_STR(blk_register_region) },
	{ 0x71a50dbc, __VMLINUX_SYMBOL_STR(register_blkdev) },
	{ 0x3d9ee9f0, __VMLINUX_SYMBOL_STR(clear_page) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x5453c428, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0xda476858, __VMLINUX_SYMBOL_STR(page_endio) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x622598b1, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x7f02188f, __VMLINUX_SYMBOL_STR(__msecs_to_jiffies) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x65124ccf, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x55d31df9, __VMLINUX_SYMBOL_STR(get_disk) },
	{ 0x343a1a8, __VMLINUX_SYMBOL_STR(__list_add) },
	{ 0x68309801, __VMLINUX_SYMBOL_STR(device_add_disk) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x86ffda49, __VMLINUX_SYMBOL_STR(alloc_disk) },
	{ 0x50ac1106, __VMLINUX_SYMBOL_STR(blk_queue_max_discard_sectors) },
	{ 0x91e69922, __VMLINUX_SYMBOL_STR(blk_queue_physical_block_size) },
	{ 0xc279777b, __VMLINUX_SYMBOL_STR(blk_queue_bounce_limit) },
	{ 0xf1d7c70b, __VMLINUX_SYMBOL_STR(blk_queue_max_hw_sectors) },
	{ 0x4b241cbd, __VMLINUX_SYMBOL_STR(blk_queue_make_request) },
	{ 0x35cfc5f8, __VMLINUX_SYMBOL_STR(blk_alloc_queue) },
	{ 0xc886cc37, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x82638ce5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x3e2286cd, __VMLINUX_SYMBOL_STR(__radix_tree_insert) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x9754ec10, __VMLINUX_SYMBOL_STR(radix_tree_preload) },
	{ 0xa188a67, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x19c85478, __VMLINUX_SYMBOL_STR(radix_tree_lookup) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe76e55b7, __VMLINUX_SYMBOL_STR(blk_cleanup_queue) },
	{ 0xa1cb1058, __VMLINUX_SYMBOL_STR(put_disk) },
	{ 0xc908d38, __VMLINUX_SYMBOL_STR(kill_bdev) },
	{ 0x8ebabaa8, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x71e4c06d, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xfba2796c, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0xedd0cd89, __VMLINUX_SYMBOL_STR(radix_tree_delete) },
	{ 0x3725893a, __VMLINUX_SYMBOL_STR(radix_tree_gang_lookup) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "6B7E7BECEA623A4F89B0F2E");
