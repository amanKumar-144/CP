#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=200001;
vector<int>graph[N];
vector<bool>check(N,false);
void dfs(int v,vii &a)
{
    a.pb(v);
    check[v]=true;
    for(int i=0;i<graph[v].size();i++)
    {
        int child=graph[v][i];
        if(check[child]==false)
        {
            dfs(child,a);
        }
    }
}
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            vii a;
            dfs(i,a);
            int valid=1;
            for(int j=0;j<a.size();j++)
            {
                if(graph[a[j]].size()!=2)valid=0;
            }
            if(valid==1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}