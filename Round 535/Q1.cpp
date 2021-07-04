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
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1!=l2)cout<<l1<<" "<<l2<<endl;
    else if(l1!=r2)cout<<l1<<" "<<r2<<endl;
    else if(r1!=l2)cout<<r1<<" "<<l2<<endl;
    else if(r1!=r2)cout<<r1<<" "<<r2<<endl;
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