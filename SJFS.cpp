//Name : Abu Jamil Faisal Shuvo
//ID : 21224103176
//Section: 1
// Intake -48
#include<bits/stdc++.h>
using namespace std;
void inputVec(vector<pair<string,pair<int,int>>>&process,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<"PROCESS - "<<i+1<<" : "<<endl;
        cout<<"1.name = ";
        string str;
        cin>>str;
        cout<<"2.arrival time = ";
        int r;
        cin>>r;
        cout<<"3.burst/CPU time = ";
        int k ;
        cin>>k;
        process.push_back({str,{r,k}});
    }
}
void printVec( vector<pair<string,pair<int,int>>>&process,int n)
{
      cout<<"Process Name \t\t\t Waiting Time\t\tTurnOver Time\t\t\t"<<endl;
    for(int i = 0;i<n;i++)
    {

        cout<<process[i].first<<" \t\t\t\t\t\ "<<process[i].second.second<<" \t\t\t"<<process[i].second.first<<endl;
    }
}
bool strev2(const pair<string,pair<int,int>>&a,const pair<string,pair<int,int>>&b)
{
    return a.second.first < b.second.first;
}
int main()
{
    int n;
    cout<<"Enter the number of process = ";
    cin>>n;
    vector<pair<string,pair<int,int>>>process;
    vector<pair<string,pair<int,int>>>Final_process;
    inputVec(process,n);
    // sorting the process by arrival time and mapping them.
    sort(process.begin(),process.end(),strev2);
   //for using track of the burst time from the ready queue.
    int currentTime = 0;
    //for sum of all turAround time
    int sum_TAT = 0;
    // for sum of all waiting time 
    int sum_WT = 0;
    cout<<endl<<endl;
    for(int i =  0;i<n;i++)
    {
        if(currentTime<process[i].second.first)
        {
            currentTime = process[i].second.first;
        }
        int CompletionTime = currentTime + process[i].second.second;
        cout<<"CompletionTime["<<i+1<<"] = "<<CompletionTime<<endl;
        int tat = CompletionTime - process[i].second.first;
        sum_TAT+=tat;
        int wt = tat - process[i].second.second;
        sum_WT+=wt;
        Final_process.push_back({process[i].first,{tat,wt}});
        currentTime = CompletionTime;

    }
    cout<<endl;
    //sorted by process name..
    sort(Final_process.begin(),Final_process.end());
    //printing the process ..
    printVec(Final_process,n);
    cout<<endl<<fixed<<setprecision(2)<<"The Average TurnAround time = "<<(float)sum_TAT/(1.00*n);
    cout<<endl<<fixed<<setprecision(2)<<"The Average Waiting time = "<<(float)sum_WT/(1.00*n);
}
