#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    sort(a.begin(),a.end());
    k--;
    if(k==-1)
    {
        int ans=a[0];
        ans--;
        if(ans>=1)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        int ans=a[k];
        if(k+1<n && a[k+1]==ans)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}