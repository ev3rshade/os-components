#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "pcb.h"

void fcfs(PCB *processes, int count);
void round_robin(PCB *processes, int count, int quantum);

#endif // ALGORITHMS_H
