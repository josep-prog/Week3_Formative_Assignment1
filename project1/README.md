# **Project 1: Investigating a Suspicious Binary**

In this project, I created  data_sync.c  that acts like a file synchronization tool. Instead of running the executable to understand what it does, I investigated the ELF binary using analysis tools. This helped me learn how to examine a program safely and understand its purpose from its binary information.

## **Why I Chose These Tools**

I used objdump because it shows the internal structure of the ELF binary. It helped me identify the program's entry point and view the different sections inside the executable.

I used nm because it lists the symbols stored in the binary. It also helped me identify the library functions the program imports, giving clues about what the program is likely to do.

## **Solution implemention**

I wrote a data_sync.c that copies the contents of source.txt into backup.txt to simulate file synchronization.

After compiling the program, I did not run the executable for the investigation. Instead, I used objdump and nm to inspect the binary. By connecting the information from both tools, I was able to understand the program's likely functionality without executing it.

## 

## **Run the Project**

First, compile the program:

*gcc data_sync.c -o data_sync*

To inspect the ELF binary, run:

*objdump -x data_sync*

This displays information such as the entry point, ELF sections, and other details about the executable.

then, run:

*nm data_sync*

This lists the symbols and imported library functions used by the program.

If you want to test the program itself, create a file named source.txt with some text, then run:

*./data_sync*

If the program runs successfully, it creates a file named backup.txt containing the same contents as source.txt. It also prints messages indicating that synchronization has started and completed.

