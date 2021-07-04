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
const int N=100001;
const int MOD=1e9+7;
int n,m;
vector<int>g[N];//Graph 
vector<int>gr[N];//Reverse Graph
vector<bool>used;
vector<int>order,component;
vector<int>costNode(N,0);//Cost for each node
vector<vii>storeComponents;

void print(vii &a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
void dfs1 (int v) 
{
    used[v] = true;
    for(size_t i=0;i<g[v].size();++i)
        if(!used[ g[v][i] ])
            dfs1 (g[v][i]);

    order.push_back (v);
}
void dfs2 (int v) 
{
    used[v] = true;
    component.push_back (v);
    for(size_t i=0;i<gr[v].size();++i)
        if(!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
int32_t main() 
{
    FAST;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        costNode[i]=x;
    }

    cin>>m;
    for(int i=1;i<=m;i++) 
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        gr[b].pb(a);
    }

    used.assign(n+1,false);
    for(int i=1;i<=n;++i)
    {
        if(!used[i])
            dfs1(i);
    }

    used.assign(n+1,false);
    for(int i=1;i<=n;++i) 
    {
        int v=order[n-i];
        if(!used[v]) 
        {
            dfs2(v);
            storeComponents.pb(component);
            component.clear();
        }
    }
    int ans=1;
    int finalPrice=0;
    for(int i=0;i<storeComponents.size();i++)
    {
        int cost=LLONG_MAX;
        int freq=0;
        vii a=storeComponents[i];
       
        for(int j=0;j<a.size();j++)
        {
            int node=a[j];
            int money=costNode[node];
            if(money<cost)
            {
                cost=money;
                freq=1;
            }
            else if(money==cost)freq++;
            else continue;
        }
        ans=ans*freq;
        ans%=MOD;
        finalPrice+=cost;
    }
    cout<<finalPrice<<" "<<ans<<endl;
    return 0;
}