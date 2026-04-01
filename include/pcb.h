#ifndef PCB_H
#define PCB_H

#define MAX_PROCESSES 64

typedef enum {
  READY,
  RUNNING,
  DONE
} ProcessState;


typedef struct {
  int pid;
  int arrival_time;
  int cpu_time;         // total CPU time needed
  int remaining_time;   // counts down as process runs
  int waiting_time;     // calculated at end
  int turnaround_time;  // calculated at end
  ProcessState state;            // READY, RUNNING, DONE
} PCB;


#endif // PCB_H
