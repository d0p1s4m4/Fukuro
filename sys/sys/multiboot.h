#ifndef FUKURO_SYS_SYS_MULTIBOOT_H
# define FUKURO_SYS_SYS_MULTIBOOT_H 1

# define MULTIBOOT_HEADER_MAGIC     0x1BADB002
# define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

# define MULTIBOOT_PAGE_ALIGN  (1 << 0)
# define MULTIBOOT_MEMORY_INFO (1 << 1)
# define MULTIBOOT_VIDEO       (1 << 2)

# define MULTIBOOT_INFO_MEM             (1 << 0)
# define MULTIBOOT_INFO_BOOT_DEVICE     (1 << 1)
# define MULTIBOOT_INFO_CMDLINE         (1 << 2)
# define MULTIBOOT_INFO_MODS            (1 << 3)
# define MULTIBOOT_INFO_AOUT_SYMS       (1 << 4)
# define MULTIBOOT_INFO_AOUT_SHDR       (1 << 5)
# define MULTIBOOT_INFO_MMAP            (1 << 6)
# define MULTIBOOT_INFO_DRIVES          (1 << 7)
# define MULTIBOOT_INFO_CONFIG_TABLE    (1 << 8)
# define MULTIBOOT_INFO_BOOTLOADER_NAME (1 << 9)
# define MULTIBOOT_INFO_APM_TABLE       (1 << 10)
# define MULTIBOOT_INFO_VBE             (1 << 11)
# define MULTIBOOT_INFO_FRAMEBUFFER     (1 << 12)

# ifndef __ASSEMBLER__

#  include <stdint.h>

struct multiboot_aout_symbole_table
{
	uint32_t tabsize;
	uint32_t strsize;
	uint32_t addr;
	uint32_t reserved;
};

struct multiboot_elf_section_header_table
{
	uint32_t num;
	uint32_t size;
	uint32_t addr;
	uint32_t shndx;
};

struct multiboot
{
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t boot_device;
	uint32_t cmdline;
	uint32_t mods_count;
	uint32_t mods_addr;
	union
	{
		struct multiboot_aout_symbole_table aout_sym;
		struct multiboot_elf_section_header_table elf_sec;
	} u;

	uint32_t mmap_length;
	uint32_t mmap_addr;
	uint32_t drives_length;
	uint32_t drives_addr;
	uint32_t config_table;
	uint32_t bootloader_name;
	uint32_t apm_table;

	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint16_t vbe_mode;
	uint16_t vbe_interface_seg;
	uint16_t vbe_interface_off;
	uint16_t vbe_interface_len;

	uint64_t framebuffer_addr;
	uint32_t framebuffer_pitch;
	uint32_t framebuffer_width;
	uint32_t framebuffer_height;
	uint8_t framebuffer_bpp;
	uint8_t framebuffer_type;
};

struct multiboot_mmap_entry
{
	uint32_t size;
	uint64_t addr;
	uint64_t len;
	uint32_t type;
} __attribute__((packed));

#  define MULTIBOOT_MEMORY_AVAILABLE 1
#  define MULTIBOOT_MEMORY_RESERVED  2
#  define MULTIBOOT_MEMORY_ACPI      3
#  define MULTIBOOT_MEMORY_NVS       4
#  define MULTIBOOT_MEMORY_BADRAM    5

# endif /* !__ASSEMBLER__ */

#endif /* !FUKURO_SYS_SYS_MULTIBOOT_H */
