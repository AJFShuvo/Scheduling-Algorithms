#include<bits/stdc++.h>
/* 
    Name : Abu Jamil Faisal Shuvo 
    ID   :21224103176
    Intake: 48-1
*/

using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

void roundRobinScheduling(Process processes[], int n, int quantum) {
    queue<Process> readyQueue;
    
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }
    
    int currentTime = 0;
    int completedProcesses = 0;
    
    int waitingTime[n] = {0};
    int turnaroundTime[n];
    
    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] <= quantum) {
                    currentTime += remainingTime[i];
                    processes[i].burstTime = 0;
                    remainingTime[i] = 0;
                } else {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                }
                
                cout << "Process " << processes[i].id << " executed for " << currentTime << " units of time." << endl;
                
                if (remainingTime[i] == 0) {
                    completedProcesses++;
                    turnaroundTime[i] = currentTime - processes[i].arrivalTime;
                    waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;
                } else {
                    readyQueue.push(processes[i]);
                }
            }
        }
        
        if (!readyQueue.empty()) {
            Process nextProcess = readyQueue.front();
            readyQueue.pop();
            readyQueue.push(nextProcess);
        }
    }
    
    // Print waiting time and turnaround time for each process
    cout << "Process\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    int sum1 = 0,sum2 = 0;
    for(int i = 0;i<n;i++)
    {
        sum1+=turnaroundTime[i];
        sum2+=waitingTime[i];
    }
    cout<<"Average TurnAround Time = "<<(float) sum1/(1.00*n)<<endl;
    cout<<"Average Waiting Time = "<<(float) sum2/(1.00*n)<<endl;
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    cout << "Enter the time quantum: ";
    cin >> quantum;
    
    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for Process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
    }
    
    roundRobinScheduling(processes, n, quantum);
    
    return 0;
}
