# **Joseph Nishimwe**

# **Forensic Report: Investigating the data_sync Binary**

The purpose of this investigation was to understand what the data_sync executable is likely to do without running it. To keep the analysis safe, I only inspected the binary using objdump and nm. These tools allowed me to examine the structure of the executable and identify the functions it uses.

## **Binary Information**

The objdump output shows that data_sync is a 64-bit ELF executable for Linux. It is dynamically linked, meaning it uses shared libraries provided by the operating system instead of containing all of its code inside the executable.

## **Entry Point**

Using objdump, I found the program's entry point. This is the address where the operating system begins executing the program.

The entry point is:

0x1090

This points to the program startup code, which prepares the program before calling the main() function.

## **Imported Library Functions**

The nm command showed several library functions imported by the program. The most important ones are:

| Function | Purpose |
| ----- | ----- |
| fopen | Opens a file |
| fgetc | Reads data from a file one character at a time |
| fputc | Writes data to another file |
| fclose | Closes an opened file |
| puts | Prints messages to the terminal |

These functions suggest that the program mainly works with files and displays simple messages.

## **ELF Sections**

The ELF binary contains several sections that organize the program.

| Section | Purpose |
| ----- | ----- |
| .text | Contains the executable program code |
| .data | Stores initialized global variables |
| .bss | Stores uninitialized global variables |
| .rodata | Stores read-only data such as text messages |
| .plt | Helps the program call shared library functions |

Each section has a specific role, making it easier for the operating system to load and execute the program.

## **Analysis**

From the imported functions and the ELF sections, the binary appears to be a simple file synchronization program.

The presence of fopen, fgetc, fputc, and fclose shows that the program reads data from one file and writes it to another. The puts function indicates that it also prints messages to inform the user about its progress.

During my inspection, I did not find functions related to networking, process creation, or command execution. Based on the ELF information alone, there is no evidence that the program performs suspicious activities such as connecting to remote systems or launching other programs.

## **Conclusion**

Based only on the ELF inspection, I conclude that data_sync is most likely a simple file synchronization utility. It appears to open a source file, copy its contents into another file, display status messages, and then exit.

This conclusion is based entirely on the binary analysis performed with objdump and nm, without executing the program. The imported library functions, entry point, and ELF sections all support this interpretation.