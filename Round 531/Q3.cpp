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
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n,x,y;cin>>n>>x>>y;
    vii a;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        a.pb(val);
    }
    sort(a.begin(),a.end());
    if(x>y)cout<<n<<endl;
    else if(x<=y)
    {
        int element=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=x)element++;
            else break;
        }
        int ans=element/2;
        if(element%2==1)ans++;
        cout<<ans<<endl;
    }
    return 0;
}