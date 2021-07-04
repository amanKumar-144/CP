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
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    for(int i=0;i<n;i++){
        a.pb(a[i]);
    }
    int ans=0;
    int streak=0;
    int temp=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==1 && streak==0)
        {
            streak=1;
            temp=1;
        }
        else if(a[i]==1 && streak==1)
        {
            temp++;
        }
        else if(a[i]==0)
        {
            streak=0;
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}