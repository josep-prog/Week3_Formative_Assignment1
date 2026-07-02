# 

| Name | Link  |
| :---- | :---- |
| **Project 1:** Investigating a Suspicious Binary | [data\_sync.c](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project1/data_sync.c)  |
|  | [forensic\_report.md](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project1/forensic_report.md)  |
|  | [README.md](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project1/README.md)  |
| **Project 2:** System Call Monitoring Tool | [backup\_tool.c](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project2/backup_tool.c)  |
|  | [README.md](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project2/README.md)  |
| **Project 3:** Building a Python Performance Extension | [fastsum.c](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project3/fastsum.c)  |
|  | [benchmark.py](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project3/benchmark.py)  |
|  | [setup.py](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project3/setup.py)  |
|  | [README.md](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project3/README.md)  |
| **Project 4:** Signal-Based Server Controller | [monitor\_service.c](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project4/monitor_service.c)  |
|  | [README.md](https://github.com/josep-prog/Week3_Formative_Assignment1/blob/main/project4/README.md)  |

# 

# **Linux Systems Programming & Security Projects**

Four system programming and security-related projects done in Linux using C, Python, and system tools. The goal of these projects is to understand how programs interact with the operating system, how binaries can be analyzed safely, how system calls work, and how performance can be improved using low-level programming.

Each project focuses on a different concept: binary analysis, system call monitoring, signal handling, and Python performance optimization using C extensions.

## **Project 1: Investigating a Suspicious Binary**

In this project, I created a simple C program that simulates a file synchronization tool. The program copies data from one file into another, which helps represent the behavior of a real backup or sync utility.

Instead of trusting or running an unknown executable, I learned how to inspect a compiled binary using tools like objdump and nm. These tools helped me understand the structure of the program without executing it.

From the analysis, I identified the entry point of the program, the imported library functions such as fopen, fgetc, and fputc, and the internal ELF sections like .text, .data, and .rodata. Based on this information, I concluded that the binary behaves like a simple file-copying program with no suspicious behavior such as networking or process execution.

## **Project 2: System Call Monitoring Tool**

In this project, I built a file backup program in C that creates a log file, reads data from a source file, and writes it into a backup file. The goal was to understand how a program communicates with the Linux operating system at runtime.

To observe this interaction, I used strace, which shows all system calls made by a program. By analyzing the trace output, I was able to see how the program creates files using openat, reads data using read, writes data using write, and closes files using close.

From this, I learned how user programs rely on system calls to interact with files and how the operating system manages these operations at a low level. The final output confirmed that the backup file correctly matches the source file, and the log file records the backup process.

## **Project 3: Building a Python Performance Extension**

In this project, I explored performance optimization by comparing pure Python with a C extension module. I first wrote a Python program that calculates the sum of a large list of random numbers. Then I implemented a C extension using the CPython API to perform the same task more efficiently.

The C extension works by directly processing Python objects in compiled C code, which reduces overhead and improves speed. After running benchmarks, I compared execution times between the Python version and the C extension version.

The results showed that the C extension was significantly faster than the pure Python implementation. This demonstrated how performance-critical parts of a Python program can be improved using C extensions.

## **Project 4: Signal-Based Server Controller**

In this project, I created a simple monitoring service in C that runs continuously like a background server. The program prints a status message every 5 seconds to show that the system is running normally.

To make the program interactive at the system level, I implemented signal handling using signal(). The program responds to different signals such as SIGINT, SIGUSR1, and SIGTERM.

Each signal triggers a different behavior. SIGUSR1 displays a status message, SIGINT shuts down the program safely, and SIGTERM performs an emergency shutdown. I used the kill command to send signals to the running process and observe the responses.

This project helped me understand how processes communicate with the operating system and how programs can react dynamically to external events.