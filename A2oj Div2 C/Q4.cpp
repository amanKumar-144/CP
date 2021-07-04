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
#define endl "\n"
using namespace std;

int32_t main()
{
    FAST;
    int n;cin>>n;
    vector<pii>a;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        a.pb(mp(x,y));
    }
    sort(a.begin(),a.end());
    int ans=a[0].se;
    for(int i=1;i<a.size();i++)
    {
        if(ans<=a[i].se)
        {
            ans=a[i].se;
        }
        else ans=a[i].fi;
    }
    cout<<ans<<endl;
    return 0;
}