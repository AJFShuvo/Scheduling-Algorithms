#include<bits/stdc++.h>
using namespace std;
//for taking inputs 

void inputVec(vector<pair<string,pair<int,int>>>&process,vector<int>&bt,int n)
 {
    for(int i = 0;i<n;i++)
    {
        cout<<"Process "<<i+1<<" Data : "<<endl;
        cout<<"Name : ";
        string str;
        cin>>str;
        cout<<"Burst time : ";
        int k;
        cin>>k;
        bt.push_back(k);
        cout<<"Priority : ";
        int r;
        cin>>r;
        process.push_back({str,{k,r}});

    }
 }
 // Making Compare funtion .. according to the priority
bool comparison(const pair<string,pair<int,int>>&a,const pair<string,pair<int,int>>&b)
{
    return a.second.second < b.second.second;
}
// printing the result in tabular form
void printVec(vector<pair<string,pair<int,int>>>&process,int n)
{
    cout<<"Process Name\t\t\t\t"<<"Turn Around Time \t\t\t"<<"Waiting Time"<<endl;
    for(int i = 0;i<n;i++)
    {
       cout<<process[i].first<<"\t\t\t\t\t"<<process[i].second.first<<"\t\t\t\t\t\t"<<process[i].second.second<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of process = ";
    cin>>n;
    vector<pair<string,pair<int,int>>>process;
    vector<pair<string,pair<int,int>>>final_process;
    vector<int>bt;
    vector<int>completion_time;
    inputVec(process,bt,n);
    //sorting the data in ascending order agains priority
    sort(process.begin(),process.end(),comparison);
    int x = 0;
    for(int i = 0;i<n;i++)
    {
        x += process[i].second.first;
        completion_time.push_back(x);
    }
    // taking two vairable to store the all value of turnAround time and Waiting Time .
    int sum1 = 0,sum2 = 0;

    for(int i = 0;i<n;i++)
    {
        int wt = completion_time[i] - bt[i];
        final_process.push_back({process[i].first,{completion_time[i],wt}});
          sum1+=completion_time[i];
          sum2+=wt;
    }
    //Printing the result 
    printVec(final_process,n);
    cout<<fixed<<setprecision(2)<<"Average TurnOver Time = "<<(float)sum1/(1.00*n)<<endl;
    cout<<fixed<<setprecision(2)<<"Average Waiting Time = "<<(float)sum2/(1.00*n)<<endl;
    return 0;
}
