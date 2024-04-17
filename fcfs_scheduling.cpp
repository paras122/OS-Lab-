// FCFS Scheduling

#include <iostream>

struct Process {
  int process_id;
  int burst_time;
  int arrival_time;
  int waiting_time = 0;
  int turnaround_time = 0;
  int completion_time = 0;
};

struct FCFSResult {
  float avg_wt;
  float avg_tat;
};

FCFSResult FCFS_scheduling(Process *processes, int n) {
  int time = processes[0].arrival_time;

  int total_wt = 0;
  int total_tat = 0;

  for (int i = 0; i < n; i++) {
    processes[i].completion_time = time + processes[i].burst_time;
    processes[i].turnaround_time =
        processes[i].completion_time - processes[i].arrival_time;
    processes[i].waiting_time =
        processes[i].turnaround_time - processes[i].burst_time;
    time = processes[i].completion_time;
    total_tat += processes[i].turnaround_time;
    total_wt += processes[i].waiting_time;
  }

  return {static_cast<float>(total_tat) / static_cast<float>(n),
          static_cast<float>(total_wt) / static_cast<float>(n)};
}

int main() {

  Process processes[5] = {
      {1, 4, 1}, {2, 7, 2}, {3, 2, 3}, {4, 10, 6}, {5, 7, 7}};

  FCFSResult result = FCFS_scheduling(processes, 5);

  for (int i = 0; i < 5; i++) {
    std::cout << "\nProcess ID: " << processes[i].process_id;
    std::cout << " Arrival Time: " << processes[i].arrival_time;
    std::cout << " Burst TIme: " << processes[i].burst_time;
    std::cout << " Waiting Time: " << processes[i].waiting_time;
    std::cout << " Turn Around Time: " << processes[i].turnaround_time;
    std::cout << " Completion Time: " << processes[i].completion_time
              << std::endl;
  }

  std::cout << "\nAverage Waiting Time: " << result.avg_wt << std::endl;
  std::cout << "Average Turn Around Time: " << result.avg_tat << std::endl;

  return 0;
}
