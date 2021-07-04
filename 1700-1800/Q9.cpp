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
#define endl "\n"
using namespace std;
const int N=2001;
vector<int>graph[N];
vector<int>level(N,0);
vector<bool>check(N,false);

void dfs(int v)
{
    check[v]=true;
    for(auto child:graph[v])
    {
        if(check[child]==false)
        {
            level[child]=level[v]+1;
            dfs(child);
        }
    }
}

int32_t main()
{
    FAST;
    int n;cin>>n;
    vii treeIndex;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x!=-1)
        {
            graph[i].pb(x);
            graph[x].pb(i);
        }
        else treeIndex.pb(i);
    }
    for(int i=0;i<treeIndex.size();i++)
    {
        level[treeIndex[i]]=1;
        dfs(treeIndex[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,level[i]);
    }
    cout<<ans<<endl;
    return 0;
}