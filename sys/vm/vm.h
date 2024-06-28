#ifndef FUKURO_SYS_VM_VM_H
# define FUKURO_SYS_VM_VM_H 1

/* our virtual memory manager is mosly based on Rashid's paper 
 * https://research.cs.wisc.edu/areas/os/Qual/papers/mach-memory.pdf
 */

/**
 * Allocate and fill with zeros new virtual memory either anywhre
 * or at a specified address.
 */
vm_allocate();

/**
 * Virtually copy a range of memory from one address to another.
 */
vm_copy();

/**
 * Deallocate a range of addresses, i.e make them no longer valid.
 */
vm_deallocate();

/**
 * Set the inheritance attribute of an address range.
 */
vm_inherit();

/**
 * Set the protection attribute of an address range.
 */
vm_protect();

/**
 * Read the contents of a region of a task's address space.
 */
vm_read();

/**
 * Return description of specified region of task's address space.
 */
vm_regions();

/**
 * Return statistics about the use of memory by a targe_task.
 */
vm_statistics();

/**
 * Write the contents of a region of a task's address space.
 */
vm_write();

#endif /* !FUKURO_SYS_VM_VM_H */
