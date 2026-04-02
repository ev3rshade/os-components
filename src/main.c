#include <stdio.h>

#include "pcb.h"
#include "algorithms.h"

int main(void) {

  PCB processes[] = {
    {1, 0, 5, 5, 0, 0, READY},
    {2, 0, 3, 3, 0, 0, READY},
    {3, 0, 8, 8, 0, 0, READY},
  };

  int count = 3;

  // fcfs(processes, count);
  round_robin(processes, count, 4);

  for (int i = 0; i < count; i++) {
    printf("PID %d | wait: %d | turnaround: %d\n",
        processes[i].pid,
        processes[i].waiting_time,
        processes[i].turnaround_time
    );
  }

  return 0;
}
