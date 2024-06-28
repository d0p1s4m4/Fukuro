#include <stdint.h>
#include <stddef.h>
#include <sys/multiboot.h>
#include <fukuro/kinfo.h>

static struct kernel_info kinfo;

static void
unpaged_add_mmap_entry(uint64_t addr, uint64_t len)
{
	if (addr > 0xFFFFF000) return;

	if (addr + len > 0xFFFFF000) len -= (addr + len) - 0xFFFFF000;
}

struct kernel_info *
unpaged_init(uint32_t magic, struct multiboot *mb)
{
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		return (NULL); /* :'( */
	}

	if (mb->flags & MULTIBOOT_INFO_MMAP)
	{
		unpaged_add_mmap_entry(0, 0);

	}
	else if (mb->flags & MULTIBOOT_INFO_MEM)
	{
		/* TODO */
	}
	else
	{
		return (NULL); /* :'( */
	}

	return (&kinfo);
}
