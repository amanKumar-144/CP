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
void solve()
{
    int a,b,k;cin>>a>>b>>k;
    int gap=a-b;
    int ans=(k/2)*gap;
    if(k%2==1)ans+=a;
    cout<<ans<<endl;
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