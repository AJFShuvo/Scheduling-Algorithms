#include<bits/stdc++.h>
using namespace std;

//Creating 2 variable to store the sum of all turnaround time and waiting time 
int sum1 = 0,sum2 = 0;
// Creating a Process which has process id , arrival Time , completion time , turnaround time, waiting time

struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnaroundTime;
  int waitingTime;
};

// Calculating Tmies for each process against quantum time
void calculateTimes(Process processes[], int n, int quantum)
 {
  //Declaring a container for storing the burst time..
  int remainingTime[n];

  for (int i = 0; i < n; i++) {
    remainingTime[i] = processes[i].burstTime;
  }
//Creating a tracker for tracking the completion time

  int currentTime = 0;
//Creating a boolean variable for tracking if all the process is done ..

  bool allDone = false;
  // makig a while loop .. it will run till all the process is done ...
  while (!allDone) 
  {
    //atfirst we will make the tracker true.
    allDone = true;

    for (int i = 0; i < n; i++)
     {
      //Here we will check if the remaining time is greater than 0 or not.. If we get 0 then we make the tracker = false.

      if (remainingTime[i] > 0)
       {
        allDone = false;
        //then we will check if the quantum time is less than the current remaining burst time or not... if condition fullfill then we will update this 
        //the quantum time into currentTime and the we will minus quantum time from remaining burst time

        if (remainingTime[i] > quantum) {
          currentTime = currentTime + quantum;
          remainingTime[i] = remainingTime[i] - quantum;
        }
        //If above condition is not happening then we will initialize currentTime + remainingTime and we will also initialize the completetion time
        //Then we will make the remaining burst time = 0.

         else {
          currentTime = currentTime + remainingTime[i];
          processes[i].completionTime = currentTime;
          remainingTime[i] = 0;
        }
      }
    }
  }
}
//Here this funciton if for calculating turnAround Time 
//Parameter is process and the number of process 
//in each process there contains (id, Arrivaltime)
void calculateTurnaroundTime(Process processes[], int n) 
{
  for (int i = 0; i < n; i++)
  {
     processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    //This is for taking up all the sum of turnaround time 
    sum1+=processes[i].turnaroundTime;
  }
}
// Here this function is for calculating Waiting Time 
// Parameter is process and the number of process
//In each process there contains (id,arrival time, burst time, completionTime,TurnAround Time , waiting Time)
void claculateWaitingTime(Process processes[], int n)
 {
  for (int i = 0; i < n; i++)
  {
      processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
      //For sum of all waiting time ..
      sum2+=processes[i].waitingTime;
  } 
 }
// Printing the result in tabuler form
void printTable(Process processes[], int n) {
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  cout << "| Process | Arrival Time | Burst Time | Completion Time | "
          "Turnaround Time | Waiting Time |\n";
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  for (int i = 0; i < n; i++) {
    cout << "|    " << processes[i].id << "    |      "
         << processes[i].arrivalTime << "      |     " << processes[i].burstTime
         << "     |        " << processes[i].completionTime
         << "        |        " << processes[i].turnaroundTime
         << "         |      " << processes[i].waitingTime << "      |\n";
  }
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
}
int main() {
  int n, quantum;
  cout << "Enter The Number of Process";
  cin >> n;
  cout << "Enter The Time Quantum";
  cin >> quantum;

  Process processes[n];
  cout << "Enter process details:\n";
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << ":\n";
    processes[i].id = i + 1;
    cout << "   Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "   Burst Time: ";
    cin >> processes[i].burstTime;
  }

  calculateTimes(processes, n, quantum);
  calculateTurnaroundTime(processes, n);
  claculateWaitingTime(processes, n);

  cout << "\nRound Robin Scheduling Results:\n";
  printTable(processes, n);
  cout<<fixed<<setprecision(2)<<"Average Turn Around time = "<<(float)sum1/(1.00 * n)<<endl;
  cout<<fixed<<setprecision(2)<<"Average Waiting TIme = "<<(float)sum2/(1.00 * n)<<endl;
  return 0;
}