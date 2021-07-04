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
bool comp(pii &a,pii &b)
{
    if(a.fi>b.fi)return true;
    else if(a.fi<b.fi)return false;
    else
    {
        if(a.se<b.se)return true;
        else return false;
    }
}
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    vector<pii>store;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        store.pb(mp(x,y));
    }
    sort(store.begin(),store.end(),comp);
    map<pii,int>m;
    for(int i=0;i<store.size();i++)
    {
        pii a=store[i];
        auto itr=m.find(a);
        if(itr==m.end())m.ins(mp(a,1));
        else itr->se++;
    }
    k--;
    pii a=store[k];
    auto it=m.find(a);
    cout<<it->se<<endl;
    return 0;
}