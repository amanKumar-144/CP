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

const int N=101;
int parent[N];
int sizes[N];
vector<int>graph[N];
set<int>revGraph[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}


int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    int extra=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        make_set(i);
        if(x==0)
        {
            extra++;
            parent[i]=-1;
        }
        
        for(int j=1;j<=x;j++)
        {
            int y;cin>>y;
            graph[i].pb(y);
            revGraph[y].ins(i);
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //Employee i and j
            for(int lang=1;lang<=m;lang++)
            {
                auto it1=revGraph[lang].find(i);
                auto it2=revGraph[lang].find(j);
                if(it1!=revGraph[lang].end() && it2!=revGraph[lang].end())
                {
                    union_sets(i,j);
                }
            }
        }   
    }
    
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]!=-1)
        s.ins(parent[i]);
    }
    int val=s.size();val--;
    cout<<max(0LL,val)+extra<<endl;
    return 0;
}