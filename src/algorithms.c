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

void round_robin(PCB *processes, int count, int quantum) {

  int time = 0;
  int completed = 0;

  // basic queue ds
  int queue[MAX_PROCESSES];
  int left = 0; int right = 0;

  while (completed < count) {

    // check for new arrivals
    for (int i = 0; i < count; i++) {
      if (processes[i].arrival_time == time && processes[i].state == READY) {
        queue[right] = i;
        right = (right + 1 < MAX_PROCESSES) ? right + 1 : 0;
      }
    }

    // dequeue
    int curr = queue[left];
    left = (left + 1 < MAX_PROCESSES) ? left + 1: 0;
    processes[curr].state = RUNNING;

    int run_time = (processes[curr].remaining_time < quantum)
                 ? processes[curr].remaining_time
                 : quantum;

    time += run_time;
    processes[curr].remaining_time -= run_time;

    // check for new arrivals
    for (int j = 0; j < count; j++) {
      if (processes[j].arrival_time > time - run_time &&
          processes[j].arrival_time <= time &&
          processes[j].state == READY) {

          queue[right] = j;
          right = (right + 1 < MAX_PROCESSES) ? right + 1 : 0;
      }
    }

    if (processes[curr].remaining_time == 0) {
      processes[curr].state = DONE;
      processes[curr].turnaround_time = time - processes[curr].arrival_time;
      processes[curr].waiting_time = processes[curr].turnaround_time -
                                        processes[curr].cpu_time;
      completed++;
    }
    else {

      // not done push back to queue
      processes[curr].state = READY;
      queue[right] = curr;
      right = (right + 1 < MAX_PROCESSES) ? right + 1 : 0;
    }

    if (left == right) {
      time++;
    }
  }
}
