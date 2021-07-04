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
vii ans;
void solve()
{
    int d,v,l,r;
    cin>>d>>v>>l>>r;
    int totalLamps=d/v;
    int lamps1=r/v;
    int lamps2=l/v;
    int blocked=lamps1-lamps2;
    if(l%v==0)blocked++;
    int seen=totalLamps-blocked;
    cout<<seen<<endl;
}
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
int32_t main()
{
    FAST;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}