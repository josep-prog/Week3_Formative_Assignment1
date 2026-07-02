# **Project 4: Signal-Based Server Controller**

In this project, I created a simple background service in C that behaves like a small server monitoring system. The program runs continuously and reacts to signals sent from the operating system or another process. The goal was to understand how processes can communicate using Unix signals.

## **Reason for chosen**

I used signals because they are this way for the operating system to communicate with a running process. Instead of stopping the program, signals allow it to react in real time.

I used SIGINT, SIGUSR1, and SIGTERM because each one represents a different kind of control:

* SIGINT is usually used to stop a program normally (like Ctrl+C)  
* SIGUSR1 is a user-defined signal for custom actions  
* SIGTERM is used for controlled termination from the system or administrator

## **Implemented Solution**

I wrote a C program called monitor\_service.c that runs in an infinite loop. Every 5 seconds, it prints a message saying the system is running normally.

Then I registered signal handlers using signal() so the program can respond when a signal is received.

Each handler performs a specific action:

* SIGINT → prints a safe shutdown message and exits  
* SIGUSR1 → prints a status request message  
* SIGTERM → prints an emergency shutdown message and exits

The program also prints its PID so it can be controlled using the kill command.

## **Run the Project**

First, compile the program:

*gcc monitor\_service.c \-o monitor\_service*

Run the program:

*./monitor\_service*

It will display its process ID (PID). Example:

*PID: 12345*

## **How to Send Signals**

In another terminal, use the PID to send signals:

*kill \-SIGUSR1 12345*  
*kill \-SIGTERM 12345*

You can also press:

*Ctrl \+ C*

*for SIGINT.*

## 

## **What to Expect**

While the program is running, it will print:

\[Monitor Service\] System running normally...

every 5 seconds.

When signals are sent:

* SIGUSR1 → prints:  
  System status requested by administrator.  
* SIGTERM → prints:  
  Emergency shutdown signal received.  
* SIGINT → prints:  
  Monitor Service shutting down safely. and the program stops.

## **Terminal Demonstration**

Output from actually running the program and sending it signals:

```
$ ./monitor_service &
PID: 68586
[Monitor Service] System running normally...

$ kill -SIGUSR1 68586
System status requested by administrator.
[Monitor Service] System running normally...        <- program kept going, as expected

$ kill -SIGTERM 68586
Emergency shutdown signal received.
```

SIGUSR1 did not stop the program, while SIGTERM ended it cleanly, exactly as required.

