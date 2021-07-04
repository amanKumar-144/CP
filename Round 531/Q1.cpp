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
    if(n%2==0)
    {
        int ans=1;
        if(n%4==0)ans=0;
        cout<<ans<<endl;
    }
    else if(n%2==1)
    {
        int ans=1;
        int gap=n-3;
        if(gap%4==0)ans=0;
        cout<<ans<<endl;
    }
    return 0;
}