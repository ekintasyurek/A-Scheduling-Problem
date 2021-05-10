# A Scheduling Problem
You are expected to solve the scheduling problem of an experimental operating system using MultiQueue. In this experimental operating system, a process includes sub tasks which are the individual sub programs that should not be interrupted. Because of this property, when a process has the access to the CPU, it executes one sub task before leaving the CPU free.

To finish its execution, a process has to execute all the sub tasks it has with an order. When given CPU time, process executes the top sub task of the Stack and leaves the CPU free. To complete the execution, a process needs to be granted CPU time as much as number of the sub tasks.
