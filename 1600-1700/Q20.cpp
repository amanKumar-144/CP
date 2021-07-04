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
vector<pair<pii,int>>coordinates;
void print(vii &a) {
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
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
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        coordinates.pb(mp(mp(x,y),i));
        make_set(i);
    }
    for(int i=0;i<coordinates.size();i++)
    {
        for(int j=0;j<coordinates.size();j++)
        {
            if(coordinates[i].fi.fi==coordinates[j].fi.fi || coordinates[i].fi.se==coordinates[j].fi.se)
            {
                union_sets(coordinates[i].se,coordinates[j].se);
            }
        }
    }
    for(int i=0;i<coordinates.size();i++)
    {
        for(int j=0;j<coordinates.size();j++)
        {
            if(coordinates[i].fi.fi==coordinates[j].fi.fi || coordinates[i].fi.se==coordinates[j].fi.se)
            {
                union_sets(coordinates[i].se,coordinates[j].se);
            }
        }
    }
    set<int>a;
    for(int i=1;i<=n;i++)
    {
        a.ins(parent[i]);
    }
    cout<<a.size()-1<<endl;
    return 0;
}