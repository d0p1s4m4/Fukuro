#ifndef FUKURO_SYS_RISCV_PMAP_H
# define FUKURO_SYS_RISCV_PMAP_H 1

typedef struct {
} PhyAddrMap;

pmap_init();
PhysAddrMap pmap_create();
pmap_reference();
pmap_destroy();
pmap_remove();
pmap_remove_all();
pmap_copy_on_write();
pmap_enter();
pmap_protect();
pmap_extract();
pmap_access();
pmap_update();
pmap_activate();
pmap_deactivate();
pmap_zero_page();
pmap_copy_page();

#endif /* !FUKURO_SYS_RISCV_PMAP_H */
