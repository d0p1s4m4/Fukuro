#ifndef FUKURO_SYS_VM_PMAP_H
# define FUKURO_SYS_VM_PMAP_H 1

# include <stdint.h>

typedef struct pmap *pmap_t;

/**
 * Initialize using specified range of physical address
 */
void pmap_init(uintptr_t start, uintptr_t end);

/**
 * Create a new physical map
 */
pmap_t pmap_create(void);

/**
 * Add a reference to a physical map
 */
void pmap_reference(pmap_t pmap);

/**
 * Deference physical map, destroy if no references remain
 */
void pmap_destroy(pmap_t pmap);

/**
 * Remove the specified range of virtual address from map.
 * (Used in memory deallocation)
 */
void pmap_remove(pmap_t pmap, uintptr_t start, uintptr_t end);

/**
 * Remove physical page from all maps.
 * (pageout)
 */
void pmap_remove_all(uintptr_t phys);

/**
 * Remove write access for page from all maps
 * (virtual copy of shared page)
 */
void pmap_copy_on_write(uintptr_t phys);

/**
 * Enter mapping.
 * (page fault)
 */
void pmap_enter(pmap_t pmap, v, p, prot, wired);

/**
 * Set the protection on the specified range of address.
 */
void pmap_protect(pmap_t map, start, end, prot);

/**
 * Convert virtual to physical.
 */
uintptr_t pmap_extract(pmap_t pmap, uintptr_t va);

/**
 * Report if virtual address is mapped
 */
bool pmap_access(pmap_t pmap, uintptr_t va);

/**
 * Sync pmap system
 */
void pmap_update(void);

/**
 * Setup map thread to run on cpu
 */
void pmap_activate(pmap_t pmap, thread, cpu);

/**
 * Map thread are done on cpu
 */
void pmpa_deactivate(pmap_t pmap, thread, cpu);

/**
 * Zero fill physical page.
 */
void pmap_zero_page(uintptr_t phys);

/**
 * Copy physical page.
 * (modify/reference bit maintenance)
 */
void pmap_copy_page(uintptr_t src, uintptr_t dest);



#endif /* !FUKURO_SYS_VM_PMAP_H */
