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
    int t;cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(2*a<=b)
        {
            cout<<n*a<<endl;
        }
        else
        {
            int ans=(n/2)*b+(n%2)*a;
            cout<<ans<<endl;
        }
    }
    return 0;
}