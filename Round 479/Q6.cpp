#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void print(vii &a)
{
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    vii b;
    vii c;
    map<int,int>index;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
        b.pb(1);
        c.pb(-1);
    }
    for(int i=n-1;i>=0;i--)
    {
        auto it=index.find(a[i]);
        if(it==index.end())
            index.ins(mp(a[i],i));
        else it->se=i;
        auto itr=index.find(a[i]+1);
        if(itr!=index.end())
        {
            b[i]+=b[itr->se];
            c[i]=itr->se;
        }
    }
    int count=-1;
    int start=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]>count)
        {
            count=b[i];
            start=i;
        }
    }
    vii ans;
    while(start!=-1)
    {
        ans.pb(start+1);
        start=c[start];
    }
    cout<<ans.size()<<endl;
    print(ans);
    return 0;
}