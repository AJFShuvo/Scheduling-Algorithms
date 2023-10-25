#include<bits/stdc++.h>
#define endl '\n'
// Creating a global list
using namespace std;
list<int>g[26];
 //Creating a tracker of boolean types
 bool hasCycle = false;  
//Creating a array of tacker all of the value is initially 0;
int visited[26];
  //DFS Function which take the current node visited
 void dfs(int node)
 {
    //Initially and checking of there is any associate visited node or not
    visited[node];
    // traversing and checking of there is any associate visited node or not
    for(auto v:g[node])
    {
        if(!visited[v])
        {
            dfs(v);
        }
        else 
        {
            //If we found any cycle it means we founded a deadlock which we will return from the function 
            // and before doing this we will make our trcker time.
            if(!visited[v])
            {
                hasCycle = true;
                return ;
            }
            }
    }
    visited[node] = 2;
 }
 //After traversing each node we are colouring the the node by initializing the visited nodes value = 2;

int main()
{
    //input section
    cout<<"Number of Node = ";
    int node;
    cin>>node;
    cout<<"Number of edges = ";
    int edges;
    cin>>edges;
    for(int i = 0;i<edges;i++)
    {
        char u,v;
        cin>>u>>v;
        //Creating Different and pusing the edges on each nodes
        g[u-'A'].push_back(v-'A');
    }
    for(int i = 0;i<26;i++)
    {
        if(!visited[i])
        dfs(i);
    }
    //Checking if our there is my cycle or not
    cout<<"Deadlock = "<<(hasCycle)?"Yes\n":"No\n";
}
