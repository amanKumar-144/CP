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
const int N=200001;
vector<int>graph[N];
vector<int>ans;
vector<int>subTreeSize(N,0);
vector<bool>check(N,false);
int dfs(int start)
{
    ans.pb(start);
    check[start]=true;
    int totSize=1;
    for(int i=0;i<graph[start].size();i++)
    {
        int child=graph[start][i];
        if(check[child]==false)
        {
            totSize+=dfs(child);
        }
    }
    subTreeSize[start]=totSize;
    return totSize;
}
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        graph[i].pb(x);
        graph[x].pb(i);
    }
    for(int i=2;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(1);
   
    map<int,int>storeIndex;
    for(int i=0;i<ans.size();i++)
    {
        storeIndex.ins(mp(ans[i],i));
    }
    for(int i=1;i<=k;i++)
    {
        int v,pos;cin>>v>>pos;
        pos--;
        auto itr=storeIndex.find(v);
        int startPos=itr->se;
        int newPos=startPos+pos;

        if(pos<subTreeSize[v])cout<<ans[newPos]<<" ";
        else cout<<-1<<" ";
    }cout<<endl;
    return 0;
}