# Round_Robin_in_OS
_Actually the Question For this Problem is ?_

Design a scheduling program to implements a Queue with two levels:

Level 1: Fixed priority pre-emptive Scheduling

Level 2: Round Robin Scheduling

For a Fixed priority pre-emptive Scheduling (Queue 1), the Priority 0 is highest priority. If one process P1 is scheduled and running, another process P2 with higher priority comes. The New process (high priority) process P2 pre-empts currently running process P1 and process P1 will go to second level queue. Time for which process will strictly execute must be considered in the multiples of 2.
All the processes in second level queue will complete their execution according to round robin scheduling.

Consider:

1. Queue 2 will be processed after Queue 1 becomes empty.
2.	Priority of Queue 2 has lower priority than in Queue 1.

Before rushing to the Answer you need to be aware of Concepts Like :

1.[Priority Preemptive Scheduling](https://en.wikipedia.org/wiki/Fixed-priority_pre-emptive_scheduling)

2.[Round Robin Scheduling](https://en.wikipedia.org/wiki/Round-robin_scheduling})

### Input Format

First of all, It Require Value `N` (No.of Processes Required)

After that Input Sample like as Below:

if `N = 2` taken

|Process Id |Arrival Time |Burst Time |Priority |
|:-------:|:------:|:------:|:------:|
|  1     |34|2|3|
|2|34|5|5|

### Output Format

|Process Id| Response Time |Completion Time| Waiting Time |
|:-------:|:------:|:------:|:------:|
|1|0|36|0|
|2|2|41|2|
