# **Project 2: System Call Monitoring Tool**

In this project, I created a backup_tool.c  that simulates a file backup tool. The program creates a log file, reads data from a source file, and writes the data into a backup file. To understand how the program interacts with the operating system, I monitored it using strace. This helped me observe the system calls made while the program was running.

## **Reason for using strace** 

## I used strace because it shows the system calls a program makes while it is running. It helped me see how the program creates files, opens files, reads data, writes data, closes files, and exits. This made it easier to understand how the operating system handles the program's requests.

## **Implemented Solution steps**

I wrote a backup_tool.c that creates a log file named backup.log, reads the contents of source.txt, copies them into backup.txt, and records the backup process in the log file.

After compiling the program, I ran it with strace to capture every system call it made. I then examined the trace output to identify the file-related and process-related system calls and summarized their purposes.

## **Run the Project**

First, compile the program:

*gcc backup_tool.c -o backup_tool*

Create a source file to back up:

*echo "Linux System Call Project" \> source.txt*

Run the program with strace:

*strace -o trace.txt ./backup_tool*

This creates a file named trace.txt containing all the system calls made by the program.

You can also check the generated files:

*cat backup.txt*  
*cat backup.log*

## **What to Expect**

After running the program:

* backup.txt should contain the same content as source.txt.  
* backup.log should contain messages showing when the backup started and completed.  
* trace.txt should contain the system calls made during execution, including file operations such as openat, read, write, and close, as well as process-related calls such as execve and exit_group.

## **System Call Summary Table**

| Syscall | Category | Purpose |
| :---- | :---- | :---- |
| execve | Process | Loads and starts the backup_tool program |
| openat | File | Opens backup.log, source.txt, and backup.txt |
| read | File | Reads the contents of source.txt into memory |
| write | File | Writes data into backup.txt and status messages into backup.log |
| close | File | Closes each file descriptor after it is done being used |
| fstat | File | Retrieves size/metadata for an open file before reading or writing it |
| access | File | Checks whether /etc/ld.so.preload exists before loading shared libraries |
| brk / mmap / mprotect | Process (memory) | Allocates and protects memory needed by the program and dynamic linker |
| arch_prctl / set_tid_address / set_robust_list / rseq | Process (init) | Low-level thread/process setup performed automatically by glibc at startup |
| prlimit64 | Process | Checks the process's stack size limit |
| getrandom | Process | Generates a random value used internally by glibc (e.g. stack protector) |
| munmap | Process | Releases memory that was mapped while loading shared libraries |
| exit_group | Process | Terminates the process once the backup is complete |

The file-related calls (openat, read, write, close, fstat) show the program's actual backup logic: opening the three files, reading source.txt, writing to backup.txt and backup.log, then closing everything. The process-related calls are mostly automatic overhead from program startup and shutdown (loading libc, memory setup, and exiting), not something the program's own code requests directly.