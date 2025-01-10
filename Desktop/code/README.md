### Project and Documentation Overview

Project Name: Debloating and randomizing kernel implementations

File Description: 

/linux-5.4.273/build_kernel.sh: Compile the kernel script file for the first time

/linux-5.4.273/mm/memory.c: Core files for randomization and debloating

/linux-5.4.273/mm/mmap.c: Prevent modification of files between new vma and old vma

/linux-5.4.273/kernel/exit.c: Because global variables are created in the memory.c file, the file needs to be released when the target process exits

/linux-5.4.273/include/linux/select_memory.h: The structures that need to be used are uniformly declared in this header file

### Build kernel

Notice:

- When compiling to the kernel configuration file, you need to save it manually

- Modify the .config file: Modify CONFIG_SYSTEM_TRUSTED_KEYS and assign it an empty value.(Different environments will be different)

```
sudo bash build_kernel.sh
```

### Test File Overview

decode_example: Target Program

filenames.txt: This file stores the target program's file name, so you can run the program without recompiling the kernel

fixup.rewritten: Stores the fixup information that needs to be corrected

dep.offset: The start and end offsets of each function

dep.cls_num: The cluster number of each function and its dependencies

libFLAC.so.12: Target shared library

### Run the program

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libFLAC.so.12
./decode_example music.flac music.wav 
```

### environment

This project is based on Ubuntu 18.04 system, the kernel source version is 5.4.273
