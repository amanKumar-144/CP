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
    sort(a.begin(),a.end());
    int diff=0;
    for(int i=0;i<n;i=i+2)
    {
        diff+=a[i+1]-a[i];
    }
    cout<<diff<<endl;
    return 0;
}