//Name : Abu Jamil Faisal Shuvo
//ID : 21224103176
//Section: 1
// Intake -48
#include<bits/stdc++.h>
using namespace std;
void inputProcess( vector<pair<string,pair<int,int>>>&process,int n)
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
//for sorting the vector of pairs of pairs ..
bool strev(const pair<string,pair<int,int>>&a,const pair<string,pair<int,int>>&b)
{
    return a.second.first<b.second.first;
}
int main()
{
    int n;
    cout<<"Enter the number of process : ";
    cin>>n;
    vector<pair<string,pair<int,int>>> process;
    vector<pair<string,pair<int,int>>>final_process;

    inputProcess(process,n);

    sort(process.begin(),process.end(),strev);

    int x = 0;
    //finding compilation time..
    vector<int>compilation_time;
     x = x + process[0].second.second;
    compilation_time.push_back(x);
    for(int i = 1;i<n;i++)
    {

         if(compilation_time[i-1]<process[i].second.first)
        {
             x = process[i].second.first + process[i].second.second;
             compilation_time.push_back(x);
        }
         else
      {
         
         int r = x + process[i].second.second;
        compilation_time.push_back(r);
          x+=process[i].second.second;
      }

    }

    for(int i = 0;i<n;i++)
    {
         cout<<"Compilation Time  "<<i+1<<" : "<<compilation_time[i]<<endl;
    }

    float sum1_waiting_time = 0,sum2_turnAroundTime = 0;
     for(int i = 0;i<n;i++)
     {
        //finding turnAround time..
        int tat = compilation_time[i] -  process[i].second.first;
        //finding Waiting Time...
        sum2_turnAroundTime+=tat;
        int wt = tat-process[i].second.second;
        sum1_waiting_time+=wt;
        final_process.push_back({process[i].first,{tat,wt}});
     }
    //sorting again according to process name..
    sort(final_process.begin(),final_process.end());
    printVec(final_process,n);

    cout<<fixed<<setprecision(2)<<"Average Waiting Time = "<<(float)(sum1_waiting_time/(n *1.00))<<endl;
    cout<<fixed<<setprecision(2)<<"Average Turn Around Time = "<<(float)(sum2_turnAroundTime/(n*1.00))<<endl;
    // printVec(process,n);

}
