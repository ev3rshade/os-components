

#include "algorithms.h"
#include "pcb.h"


void fcfs(PCB *processes, int count) {

  int time = 0;
  for (int i = 0; i < count; i++) {

    // if time is less than curr process, increment time up to arrival
    if (time < processes[i].arrival_time) {
      time = processes[i].arrival_time;
    }

    // run curr_process
    processes[i].state = RUNNING;
    processes[i].waiting_time = time - processes[i].arrival_time;

    time += processes[i].cpu_time;

    // time it take to switch to next proc
    processes[i].turnaround_time = time - processes[i].arrival_time;
    processes[i].state = DONE;

  }
}
