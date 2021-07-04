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
int t1[4*N];
int t2[4*N]; 
void build1(vii &a, int v, int tl, int tr) 
{
    if (tl == tr) {
        t1[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build1(a, v*2, tl, tm);
        build1(a, v*2+1, tm+1, tr);
        t1[v] = t1[v*2] + t1[v*2+1];
    }
}
void build2(vii &a, int v, int tl, int tr) 
{
    if (tl == tr) {
        t2[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build2(a, v*2, tl, tm);
        build2(a, v*2+1, tm+1, tr);
        t2[v] = t2[v*2] + t2[v*2+1];
    }
}

int sum1(int v, int tl, int tr, int l, int r) 
{
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return sum1(v*2, tl, tm, l, min(r, tm))+sum1(v*2+1, tm+1, tr, max(l, tm+1), r);
}
int sum2(int v, int tl, int tr, int l, int r) 
{
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return sum2(v*2, tl, tm, l, min(r, tm))+sum2(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void print(vii &a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    vii b;
    vii dp1(n,0);
    vii dp2(n,0);

    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
        b.pb(x);
    }
    sort(b.begin(),b.end());

    dp1[0]=a[0];
    dp2[0]=b[0];

    for(int i=1;i<n;i++){
        dp1[i]=dp1[i-1]+a[i];
        dp2[i]=dp2[i-1]+b[i];
    }
   
    build1(a,1,0,n-1);
    build2(b,1,0,n-1);

    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int t,x,y;cin>>t>>x>>y;
        x--;y--;
        if(t==1)
        {
            //int val=sum1(1,0,n-1,x,y);
            int val=dp1[y]-dp1[x]+a[x];
            cout<<val<<"\n";
        }
        else if(t==2)
        {
            //int val=sum2(1,0,n-1,x,y);
            int val=dp2[y]-dp2[x]+b[x];
            cout<<val<<"\n";
        }
    }
    return 0;
}