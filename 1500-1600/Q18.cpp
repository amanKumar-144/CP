#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    int ans=LLONG_MAX;
    for(int i=0;i<m;i++)
    {
        int nextPtr=i+n-1;
        if(nextPtr>=m)break;
        else
        {
            ans=min(ans,a[nextPtr]-a[i]);
        }
    }cout<<ans<<endl;
    return 0;
}