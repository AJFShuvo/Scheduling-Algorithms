#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here
 
  int n, m, i, j, k;
    
    
   // Number of processes
   cout<<"Enter the number of Process : ";
   cin>>n;

   // Number of resources
    cout<<"Enter the Number of Resources : ";
    cin>>m;
    // Available Resources 

  int avail[m];
  int g[m];
  cout<<"Enter the Available Resource : "<<endl;
  for(int i = 0;i<m;i++)
  {
    avail[i] = 0;
    cin>>g[i];
  }


  int alloc[n][m];

  //Allocation Resources
  cout<<"ALLOCATION RESOURCES"<<endl;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>alloc[i][j];
        }
    }
    //Max resource allocation
  int max[n][m];
  cout<<"MAX RESOURCE ALLOCATION : "<<endl;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>max[i][j];
        }
    }
  
 
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<m;j++)
    {
        avail[j] += alloc[i][j];
    }
  }


  
  for(int i = 0;i<m;i++)
  {
    avail[i] = g[i] - avail[i];
  }

  

  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
    

  int y = 0;
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {
 
        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > avail[j]){
            flag = 1;
            break;
          }
        }
 
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }
   
  int flag = 1;
   
  // To check if sequence is safe or not
  for(int i = 0;i<n;i++)
  {
        if(f[i]==0)
      {
        flag = 0;
        cout << "The given sequence is not safe";
        break;
      }
  }
 
  if(flag==1)
  {
    cout << "Following is the SAFE Sequence" << endl;
      for (i = 0; i < n - 1; i++)
        cout << " P" << ans[i] + 1 << " ->";
      cout << " P" << ans[n - 1] + 1 <<endl;
  }
 
    return 0;
}

/*
Number or process & resources = 5 3
    A B C
    10 5 7

              allocation 
                 0 1 0
                 2 0 0
                 3 0 2
                 2 1 1
                 0 0 2


    Max Need 
   7 5 3
   3 2 2
   9 0 2
   4 2 2
   5 3 3

    safe sequence = P2 -> P4 -> P5 -> P1 -> P3.
*/