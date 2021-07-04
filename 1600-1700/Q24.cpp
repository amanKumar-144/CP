#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2001;
vector<int>graph[N];
vector<int>d(N,0),p(N,0);
vector<bool>used(N);

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    d[s]=1;
    while(!q.empty()) 
    {
        int v = q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++) 
        {
            int u=graph[v][i];
            if(!used[u]) 
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii parentArray;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x!=-1)
        {
            graph[i].pb(x);
            graph[x].pb(i);
        }
        else parentArray.pb(i);
    }
    for(int i=0;i<parentArray.size();i++)
    {
        int root=parentArray[i];
        bfs(root);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,d[i]);
    cout<<ans<<endl;
    return 0;
}