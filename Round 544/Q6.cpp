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
int parent[N];
int size[N];
vector<pii>answers;
void make_set(int v) 
{
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) 
{
    int v1=a;int v2=b;
    a = find_set(a);
    b = find_set(b);
    if (a != b) 
    {
        answers.pb(mp(v1,v2));
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
set<pii>edgeList;
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        make_set(i);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
        pii a=mp(x,y);
        edgeList.ins(a);
    }
    int maxDegreeVertex=0;
    int size=-1;
    for(int i=1;i<=n;i++)
    {
        int s=graph[i].size();
        if(s>size)
        {
            size=s;
            maxDegreeVertex=i;
        }
    }
    for(int i=0;i<graph[maxDegreeVertex].size();i++)
    {
        pii a=mp(maxDegreeVertex,graph[maxDegreeVertex][i]);
        auto it=edgeList.find(a);
        if(it==edgeList.end())
            union_sets(a.se,a.fi);
        else 
            union_sets(a.fi,a.se);
    }
    for(auto itr=edgeList.begin();itr!=edgeList.end();itr++)
    {
        union_sets(itr->fi,itr->se);
    }
    for(int i=0;i<answers.size();i++)
    {
        cout<<answers[i].fi<<" "<<answers[i].se<<endl;
    }
    return 0;
}