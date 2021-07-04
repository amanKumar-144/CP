// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

const int N=31;
vector<int>graph[N];
vector<bool>check(N,false);
vector<int>dist(N,0);
map<int,int>ladder;
map<int,int>snakes;
        
void bfs(int start)
{
    dist[start]=0;
    deque<int>dq;
    dq.pb(start);
    check[start]=true;
    while(dq.size()>0)
    {
        int v=dq.front();
        if(v==30)break;
        dq.pop_front();
        for(int i=0;i<graph[v].size();i++)
        {
            int u=graph[v][i];
            auto it1=ladder.find(v);
            if(it1!=ladder.end() && it1->se==u)
            {
                if(check[u]==false)
                {
                    check[u]=true;dq.pb(u);
                    dist[u]=dist[v];
                }
            }
            else if(check[u]==false)
            {
                check[u]=true;dq.pb(u);dist[u]=dist[v]+1;
            }
            else if(check[u]==true)
            {
                if(dist[v]+1<dist[u]){
                    dist[u]=dist[v]+1;
                    dq.pb(u);
                }
            }
        }
    }
}

class Solution{
public:
    int minThrow(int n, int arr[])
    {
        
        for(int i=0;i<2*n;i=i+2)
        {
            if(arr[i+1]>arr[i])
            ladder.ins(mp(arr[i],arr[i+1]));
            
            else if(arr[i]>arr[i+1])
            snakes.ins(mp(arr[i],arr[i+1]));
        }
       

        for(int i=1;i<N;i++)
        {
            auto it1=ladder.find(i);
            auto it2=snakes.find(i);
            if(it1!=ladder.end())graph[i].pb(it1->se);
            else if(it2!=snakes.end())continue;

            else if(it1==ladder.end() && it2==snakes.end())
            {
                for(int j=1;j<=6;j++)
                {
                    int oldCoord=i;int newCoord=i+j;
                    if(newCoord<=30)graph[oldCoord].pb(newCoord);
                }
            }
        }
       
        bfs(1);
        int ans=dist[30];
       
        for(int i=1;i<N;i++){
            check[i]=false;
            graph[i].clear();
            dist[i]=0;
        }
        ladder.clear();
        snakes.clear();
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends