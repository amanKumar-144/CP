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
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    vii a;
    a.pb(x1);a.pb(x2);
    a.pb(x3);a.pb(x4);
    sort(a.begin(),a.end());
    for(int i=0;i<=2;i++){
        cout<<a[3]-a[i]<<" ";
    }cout<<endl;
    return 0;
}