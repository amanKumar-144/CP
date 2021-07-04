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
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    int moves=0;
    int presentHouse=1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=presentHouse)moves+=(a[i]-presentHouse);
        else
        {
            moves+=(n-presentHouse);
            moves+=a[i];
        }
        presentHouse=a[i];
    }
    cout<<moves<<endl;
    return 0;
}