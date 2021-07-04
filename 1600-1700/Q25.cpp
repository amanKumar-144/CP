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
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    vii b;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        b.pb(i+1);
    }
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=abs(a[i]-b[i]);
    cout<<ans<<endl;
    return 0;
}