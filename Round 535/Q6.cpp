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
const int N=400001;
const int INF=1e9;
vector<pii>query;
vector<int>t(N);
vector<int>lazy(N);

void print(vii &a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void build(vii &a, int v, int tl, int tr) 
{
    if(tl==tr) 
    {
        t[v] = a[tl];
    }
    else 
    {
        int tm = (tl + tr) / 2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

void push(int v) 
{
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) 
{
    if(l > r) 
        return;
    if(l == tl && tr == r) 
    {
        t[v] += addend;
        lazy[v] += addend;
    } else 
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int queryTreeMin(int v, int tl, int tr, int l, int r) 
{
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return t[v];

    push(v);

    int tm = (tl + tr) / 2;
    return min(queryTreeMin(v*2, tl, tm, l, min(r, tm)), 
               queryTreeMin(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int32_t main()
{
    FAST;
    int n,m;
    cin>>n>>m;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    build(a,1,0,n-1);

    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        query.pb(mp(l,r));
    }

    int ans=0;
    vii storeIndex(m,0);
    int size=0;
    vector<pair<pii,int>>validQuery(m,mp(mp(0,0),0));
    for(int i=0;i<n;i++)
    {
        int maxElement=a[i];
        int index=i+1;
        int validSize=0;
        for(int j=0;j<query.size();j++)
        {
            int l=query[j].fi;
            int r=query[j].se;
            if(!(l<=index && index<=r)){
                validQuery[validSize]=mp(query[j],j+1);
                update(1,0,n-1,l-1,r-1,-1);
                validSize++;
            }
        }
        int minElement=queryTreeMin(1,0,n-1,0,n-1);
        int diff=maxElement-minElement;
        if(diff>ans)
        {
            ans=diff;
            for(int j=0;j<validSize;j++){
                storeIndex[j]=validQuery[j].se;
            }
            size=validSize;
        }
        for(int j=0;j<validSize;j++)
        {
            int l=validQuery[j].fi.fi;
            int r=validQuery[j].fi.se;
            update(1,0,n-1,l-1,r-1,1);
        }
    }
    cout<<ans<<endl;
    cout<<size<<endl;
    print(storeIndex,size);
    return 0;
}