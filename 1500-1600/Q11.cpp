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
    vii a;a.pb(0);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vii diff;
    for(int i=1;i<a.size();i++)
    {
        diff.pb(a[i-1]-a[i]);
    }

    int negSum=0;
    int tot=0;

    for(int i=0;i<diff.size();i++){
        tot+=diff[i];
        negSum=min(negSum,tot);
    }
    cout<<-1*negSum<<endl;
    return 0;
}