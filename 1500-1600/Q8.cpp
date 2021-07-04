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
    for(int i=0;i<m;i++){
        int x;cin>>x;
        if(i==0)a.pb(x);
        else{
            if(a[a.size()-1]!=x)a.pb(x);
        }
    }
    int ans=a[0]-1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])ans+=(a[i]-a[i-1]);
        else{
            ans+=(n-a[i-1]);
            ans+=1;
            ans+=(a[i]-1);
        }
    }cout<<ans<<endl;
    return 0;
}