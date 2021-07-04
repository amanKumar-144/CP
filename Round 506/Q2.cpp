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
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    vii ans(n+1,1);
    for(int i=n-2;i>=0;i--)
    {
        if(2*a[i]>=a[i+1])
        {
            ans[i]=ans[i+1]+1;
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,ans[i]);
    }
    cout<<maxi<<endl;
    return 0;
}