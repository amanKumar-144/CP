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
const int N=1005;
vector<int>graph[N];
vector<bool>check(N,false);
void dfs(int v)
{
    check[v]=true;
    for(int i=0;i<graph[v].size();i++)
    {
        int child=graph[v][i];
        if(check[child]==false)
            dfs(child);
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vector<pair<pii,int>>coordinates;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        coordinates.pb(mp(mp(x,y),i));
    }
    for(int i=0;i<n;i++)
    {
        pair<pii,int>a=coordinates[i];
        for(int j=i+1;j<n;j++)
        {
            pair<pii,int>b=coordinates[j];
            if(a.fi.fi==b.fi.fi || a.fi.se==b.fi.se)
            {
                graph[a.se].pb(b.se);
                graph[b.se].pb(a.se);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans-1<<endl;
    return 0;
}