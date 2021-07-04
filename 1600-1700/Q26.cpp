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
const int N=100001;
vector<int>a(N,0);
vector<int>b[N]; //Start,End,Difference
vector<int>c(N,0);
vector<int>temp(N,0);
int32_t main()
{
    FAST;
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,d;cin>>x>>y>>d;
        b[i].pb(x);
        b[i].pb(y);
        b[i].pb(d);
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;cin>>x>>y;
        c[x]+=1;
        c[y+1]-=1;
    }
    for(int i=2;i<=m;i++)c[i]+=c[i-1];
    for(int i=1;i<=m;i++)
    {
        int start=b[i][0];int end=b[i][1];int diff=b[i][2];
        temp[start]+=c[i]*diff;
        temp[end+1]-=c[i]*diff;
    }
    for(int i=2;i<=n;i++)temp[i]+=temp[i-1];
    for(int i=1;i<=n;i++)a[i]+=temp[i];

    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}