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
    int n,k;cin>>n>>k;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    int leftPtr=0;int rightPtr=n-1;
    int ans=0;
    while(leftPtr<=rightPtr)
    {
        if(leftPtr==rightPtr && a[leftPtr]<=k){ans++;break;}
        if(a[leftPtr]<=k){ans++;leftPtr++;}
        if(a[rightPtr]<=k){ans++;rightPtr--;}
        if(a[leftPtr]>k && a[rightPtr]>k)break;
    }
    cout<<ans<<endl;
    return 0;
}