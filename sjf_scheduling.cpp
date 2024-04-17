// SJF Scheduling

#include <iostream>

struct Process {
  int process_id;
  int burst_time;
  int arrival_time;
  int waiting_time = 0;
  int turnaround_time = 0;
  int completion_time = 0;
};

struct SJFResult {
  float avg_wt;
  float avg_tat;
};

SJFResult SJF_scheduling(Process *processes, int n) {
  SJFResult result;

  int time = processes[0].arrival_time;
  int total_wt = 0;
  int total_tat = 0;
  int *remaining_jobs = static_cast<int *>(malloc(n * sizeof(int)));
  int num_remaining = n;
  // initialize remaining
  for (int i = 0; i < n; i++) {
    remaining_jobs[i] = i;
  }

  for (int i = 0; i < n; i++) {
    // find shortest job that has arrived
    int shortest = 0;
    for (int j = 1; j < num_remaining; j++) {
      if (processes[remaining_jobs[j]].arrival_time >= time &&
          processes[remaining_jobs[j]].burst_time <
              processes[remaining_jobs[shortest]].burst_time) {
        shortest = j;
      }
    }

    std::cout<<shortest<<std::endl;

    // remove selected job from remaining list
    for(int j=shortest;j<num_remaining;j++){
      remaining_jobs[j]=remaining_jobs[j+1];
    }

    for(int a =0 ;a<num_remaining;a++){
      std::cout<<remaining_jobs[a]<<" ";
    }

    std::cout<<std::endl;

    num_remaining -= 1;
    shortest=remaining_jobs[shortest];
    processes[shortest].completion_time = time + processes[shortest].burst_time;
    processes[shortest].turnaround_time =
        processes[shortest].completion_time - processes[shortest].arrival_time;
    processes[shortest].waiting_time =
        processes[shortest].turnaround_time - processes[shortest].burst_time;
    time = processes[shortest].completion_time;
    total_wt += processes[shortest].waiting_time;
    total_tat += processes[shortest].turnaround_time;
  }

  return {static_cast<float>(total_wt) / static_cast<float>(n),
          static_cast<float>(total_tat) / static_cast<float>(n)};
}

int main() {

  Process processes[5] = {
      {1, 5, 1}, {2, 7, 2}, {3, 6, 3}, {4, 6, 7}, {5, 5, 7}};

  SJFResult result = SJF_scheduling(processes, 5);

  for (int i = 0; i < 5; i++) {
    std::cout << "\nProcess ID: " << processes[i].process_id;
    std::cout << " Arrival Time: " << processes[i].arrival_time;
    std::cout << " Burst TIme: " << processes[i].burst_time;
    std::cout << " Waiting Time: " << processes[i].waiting_time;
    std::cout << " Turn Around Time: " << processes[i].turnaround_time;
    std::cout << " Completion Time: " << processes[i].completion_time
              << std::endl;
  }

  std::cout << "\n Average Waiting Time: " << result.avg_wt << std::endl;
  std::cout << "Average Turn Around Time: " << result.avg_tat << std::endl;

  return 0;
}
