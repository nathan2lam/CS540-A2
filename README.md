# CS540-A2
Lottery Scheduler
This C++ program simulates a lottery scheduler, a scheduling algorithm that assigns a number of tickets to each process. The likelihood of a process being selected for execution is proportional to the number of tickets it holds.

Program Functionality
There are 2 classes and a main section:
Process: Represents a process with a unique process ID (pid) and a specified number of tickets.
Scheduler: Manages the scheduling logic, including adding processes, allocating tickets, and selecting a winner based on a lottery mechanism.
Main Program (main()): Demonstrates the functionality of the lottery scheduler by adding processes, allocating tickets, and selecting a winner.

How it Works
Processes are added to the scheduler using the addProcess method.
Tickets are allocated to processes proportionally using the allocateTickets method.
The selectWinner method uses a random number generator to select a winning process based on the allocated tickets.
Sample code is already provided to show off the program so all you need to do is run the code.

