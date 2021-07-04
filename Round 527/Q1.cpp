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
    int n,k;cin>>n>>k;
    int count=n/k;
    string ans="";
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<count;j++)
            ans+=('a'+i);

    }
    int leftOver=n-ans.size();
    for(int i=0;i<leftOver;i++)
    {
        ans+=('a'+i);
    }
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