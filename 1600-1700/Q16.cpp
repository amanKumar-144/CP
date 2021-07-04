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
    int s,n;cin>>s>>n;
    vector<pair<pii,int>>a;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        a.pb(mp(mp(x,y),1));
    }
    int ans=1;
    int selectIndex,maxBoost;
    for(int i=0;i<a.size();i++)
    {
        selectIndex=-1;
        maxBoost=-1;
        for(int j=0;j<a.size();j++)
        {
            if(s>a[j].fi.fi && a[j].se==1)
            {
                if(maxBoost<a[j].fi.se)
                {
                    maxBoost=a[j].fi.se;
                    selectIndex=j;
                }
            }
        }
        if(selectIndex==-1)
        {
            ans=0;break;
        }
        else
        {
            a[selectIndex].se=0;
            s+=maxBoost;
        }
    }
    if(ans==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}