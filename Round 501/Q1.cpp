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
vector<pii>coordinates;
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
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        coordinates.pb(mp(x,y));
    }
    vector<int>positions(m+1,0);
    for(int i=0;i<coordinates.size();i++)
    {
        int l=coordinates[i].fi;
        int r=coordinates[i].se;
        for(int j=l;j<=r;j++)
        {
            positions[j]=1;
        }
    }
    vii ans;
    for(int i=1;i<=m;i++)
    {
        if(positions[i]==0)ans.pb(i);
    }
    cout<<ans.size()<<endl;
    print(ans);
    return 0;
}