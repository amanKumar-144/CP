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
    int ans=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        if(a+b+c>=2)ans++;
    }
    cout<<ans<<endl;
    return 0;
}