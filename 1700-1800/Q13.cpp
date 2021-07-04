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

vector<int>graph[N];
map<pii,int>storeEdgeType;
vector<bool>check1(N,false);
vector<bool>check2(N,false);
vector<int>parent(N,-1);
vector<int>toxic(N,0);
vector<int>leafNodes;

void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}

void dfs(int v)
{
    check1[v]=true;
    for(auto child:graph[v])
    {
        if(check1[child]==false)
        {
            parent[child]=v;
            dfs(child);
            toxic[v]+=toxic[child];
        }
    }
    auto it=storeEdgeType.find(mp(v,parent[v]));
    if(it->se==2)
    {
        toxic[v]++;
        toxic[parent[v]]++;
    }
    if(graph[v].size()==1)
    {
        leafNodes.pb(v);
    }
}

int32_t main()
{
    FAST;
    int n;cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        storeEdgeType.ins(mp(mp(x,y),t));
        storeEdgeType.ins(mp(mp(y,x),t));
        graph[x].pb(y);
        graph[y].pb(x);
    }

    parent[1]=1;
    dfs(1);

    vector<pii>storeVertexToxicity;
    for(int i=0;i<leafNodes.size();i++)
    {
        storeVertexToxicity.pb(mp(toxic[leafNodes[i]],leafNodes[i]));
    }
    sort(storeVertexToxicity.begin(),storeVertexToxicity.end(),greater<pii>());

    vii ans;
    for(int i=1;i<=n;i++)
    {
        if(toxic[i]==1)ans.pb(i);
    }
    
    cout<<ans.size()<<endl;
    print(ans);
    return 0;
}