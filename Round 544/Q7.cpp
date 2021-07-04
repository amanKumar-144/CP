#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")
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
vector<bool>used(N,false);
vector<int>comp1;
vector<vii>compVertices;
int n,m,k;
set<pii>edgeList;
vector<pii>answers;

void bfs(int s)
{
    queue<int>q;
    vector<bool>used(N,false);
    q.push(s);
    used[s]=true;
    while(!q.empty()) 
    {
        int v=q.front();
        q.pop();
        for(int u:graph[v]) 
        {
            if(!used[u]) 
            {
                used[u] = true;
                q.push(u);
                answers.pb(mp(u,v));
            }
        }
    }
}
void dfs(int v) 
{
    used[v]=true;
    comp1.push_back(v);
    for(int i=0;i<graph[v].size();i++)
    {
        int to=graph[v][i];
        if(!used[to])
        {
            dfs(to);
        }
    }
}
void find_comps() 
{
    for(int i=2;i<=n;i++)
    {
        if(!used[i]) 
        {
            comp1.clear();
            dfs(i);
            compVertices.pb(comp1);
        }
    }
}
int valid=1;
int32_t main()
{
    FAST;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x!=1 && y!=1)
        {
            graph[x].pb(y);
            graph[y].pb(x);
        }
        else {
            edgeList.ins(mp(x,y));
            edgeList.ins(mp(y,x));
        }
    }
    int vertex1Size=edgeList.size()/2;
    find_comps();
    if(vertex1Size<k)valid=0;
    if(compVertices.size()>k)valid=0;

    for(int i=0;i<compVertices.size();i++)
    {
        vii a=compVertices[i];
        int c=0;
        for(int j=0;j<a.size();j++)
        {
            auto it1=edgeList.find(mp(1,a[j]));
            auto it2=edgeList.find(mp(a[j],1));
            if(it1!=edgeList.end() && it2!=edgeList.end())
            {
                c=1;
                graph[1].pb(a[j]);
                graph[a[j]].pb(1);
                edgeList.erase(it1);
                edgeList.erase(it2);
                break;
            }
        }
        if(c==0)valid=0;
    }
    int leftSize=k-compVertices.size();
    for(auto itr=edgeList.begin();itr!=edgeList.end();itr++)
    {
        if(leftSize==0)break;
        graph[itr->fi].pb(itr->se);
        graph[itr->se].pb(itr->fi);
        leftSize--;
    }
    if(leftSize!=0)valid=0;
    if(valid==0)cout<<"NO"<<endl;
    else
    {
        bfs(1);
        cout<<"YES"<<endl;
        for(int i=0;i<answers.size();i++)
        {
            cout<<answers[i].fi<<" "<<answers[i].se<<endl;
        }
    }
    return 0;
}