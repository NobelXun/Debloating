// memory.h
#ifndef MEMORY_H
#define MEMORY_H

// 结构体声明
typedef struct function_context {
    unsigned char *buf;
    int bytes_len;
} function_context;

typedef struct offset_range {
    unsigned long start_offset;
    unsigned long end_offset;
    struct function_context func_bin;
} offset_range;

typedef struct function_offsets {
    const char *func_name;
    struct offset_range *offsets;
    int offset_count;
} function_offsets;

typedef struct func_info {
    const char *func_name;
    int cluster_ids[20];
    int num_clusters;
} func_info;

struct vm_info {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    unsigned long vm_flags;
    unsigned long size;
};

typedef struct section_infos {
    Elf64_Addr sh_addr;
    uint64_t size;
	bool flags;
    uint64_t **section_pgoff;
} section_infos;

typedef struct modify_section_infos {
    section_infos dynsym_section;
    section_infos reladyn_section;
    section_infos relaplt_section;
    section_infos gotplt_section;
    section_infos rodata_section;
    section_infos finiarray_section;
    section_infos initarray_section;
    section_infos dynamic_section;
    section_infos got_section;
    section_infos datarelro_section;
    section_infos main_section;
    section_infos text_section;
} modify_section_infos;
//dep.offset
typedef struct {
    const char *function_name;
    struct offset_range *offsets;
    int offset_count;
} select_info;

typedef struct fixup_struct {
    uint64_t base;
    uint64_t va;
    uint64_t target;
    uint64_t value;
    uint64_t new_value;
    uint64_t size;
    uint64_t is_relative;
} fixup_struct;

typedef struct {
    unsigned int start_offset;
    unsigned int end_offset;
} OffsetRange;

typedef struct myran_vma_struct {
    long old_start;
    long new_start;
    long old_end;
    long new_end;
    long old_size;
    long new_size;
    long old_flags;
    long new_flags;
    long old_pgoff;
    long new_pgoff;
} myran_vma_struct;

typedef struct my_random_struct {
    Elf64_Addr base_addr;
    Elf64_Addr text_base_addr;
    Elf64_Addr random_start_addr;
    Elf64_Addr random_end_addr;
    int fixup_num;
    fixup_struct* fixup_array;
    long vma_num;
    int* random_array;
    myran_vma_struct* myran_vma_array;
    long cluster_num;
    long first_cluster_index;
} my_random_struct;

typedef struct {
    const char *test_res;
    const char *so_res;
    struct file *vm_file;
    struct file *so_vm_file;
    int so_vma_count;
    select_info *select_cluster;
    my_random_struct *my_ran;
    OffsetRange ranges[200];
    struct vm_info *vma_infos;
    int **page_array;
    int sum_page;
    int function_count;
    modify_section_infos sect_infos;
    int pid;
    int same_index;
} process_select_info;

// 全局变量声明
extern process_select_info **select_data;
extern int select_infos_num;


#endif // MEMORY_H

