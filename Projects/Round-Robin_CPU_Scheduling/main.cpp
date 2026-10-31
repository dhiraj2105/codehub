/**
 * Round Robin CPU Scheduling Algorithm
 *
 *  * INPUT
 * --------
 * 1. Number of processes.
 * 2. Time quantum.
 * 3. Arrival time and burst time for each process.
 *
 *  * OUTPUT
 * --------
 * 1. A simple Gantt chart showing the CPU execution order.
 * 2. Completion time (CT) for every process.
 * 3. Turnaround time (TAT) for every process.
 * 4. Waiting time (WT) for every process.
 * 5. Response time for every process.
 * 6. Average TAT, WT, and response time.
 *
 *  * FORMULAS
 * --------
 * Turnaround Time = Completion Time - Arrival Time
 * Waiting Time    = Turnaround Time - Burst Time
 * Response Time   = First CPU Start Time - Arrival Time
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Data structure to represent a process in the scheduling simulation.
 */
struct Process
{
    string id; // Human-readable process identifier, e.g. "P1".

    int arrivalTime; // Time at which this process becomes ready.
    int burstTime;   // Total CPU time this process needs.

    int remainingTime; // CPU time still needed; starts equal to burstTime.

    int completionTime = -1; // Time process finishes; -1 means "not finished".
    int firstStartTime = -1; // First CPU start; -1 means "not started yet".

    int turnaroundTime = 0; // Total time from arrival until completion.
    int waitingTime = 0;    // Total time spent waiting in the ready queue.
    int responseTime = 0;   // Time from arrival until first CPU execution.
};

/**
 * Data Structure to represent Execution Interval
 *
 * One ExecutionInterval records one continuous period on the CPU timeline.
 *
 * Example:
 *     {"P1", 0, 2}
 *
 * Means:
 *     Process P1 occupied the CPU from time 0 up to (but not including) time 2.
 *
 * We store intervals so that we can print a Gantt chart after scheduling.
 *
 * The special process ID "IDLE" means that no process was ready and the CPU
 * had nothing to execute during that interval.
 */
struct ExecutionInterval
{
    std::string processId; // Process that ran, or "IDLE" for CPU idle time.
    int startTime;         // Inclusive start time of this interval.
    int endTime;           // End time of this interval.
};

/**
 * Function : addArrivedProcess
 *
 * PURPOSE
 * -------
 * Add every process that has arrived by currentTime to the ready queue.
 *
 * PARAMETERS
 * ----------
 * processes:
 *     The complete process list. It must already be sorted by arrival time.
 *
 * nextProcess:
 *     Index of the next process that has NOT yet been added to the ready queue.
 *     It is passed by reference because this function advances the index.
 *
 * currentTime:
 *     Current simulated CPU time.
 *
 * readyQueue:
 *     FIFO queue containing indices of processes that are ready to execute.
 *     It is passed by reference because this function inserts into it.
 */
void addArrivedProcesses(
    const vector<Process> processes, // Read only list of all process
    int nextProcess,                 // Next process waiting to be admitted
    int currentTime,                 // Current Simulated time
    queue<int> readyQueue            // FIFO queue of ready process indices
)
{
    // keep admitting processes while there are unprocessed arrivals.
    while (nextProcess < processes.size() &&
           processes[nextProcess].arrivalTime <= currentTime)
    {
        // Add the next arrived process's vector Index to back of the queue
        readyQueue.push(nextProcess);
        // Move to next process so this process cannot be enqueued again
        ++nextProcess;
    }
}