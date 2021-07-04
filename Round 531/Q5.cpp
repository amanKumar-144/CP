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
map<int,pii>storeIndex;
const int MOD=998244353;
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        auto itr=storeIndex.find(x);
        if(itr==storeIndex.end())
            storeIndex.ins(mp(x,mp(i,i)));
        else itr->se.se=i;
    }
    int seqLength=0;
    int startElement=a[0];
    auto itr=storeIndex.find(startElement);
    int l=itr->se.fi;
    int r=itr->se.se;
    while(r<n)
    {
        for(int i=l;i<=r;i++)
        {
            int element=a[i];
            auto it=storeIndex.find(element);
            r=max(r,it->se.se);
        }
        r++;
        if(r<n)
        {
            int element=a[r];
            l=r;
            auto it=storeIndex.find(element);
            r=it->se.se;
        }
        seqLength+=1;
    }
    //cout<<"The sequence length is "<<seqLength<<endl;
    seqLength--;
    int ans=1;
    for(int i=1;i<=seqLength;i++)
    {
        ans=ans*2;
        ans=ans%MOD;
    }
    cout<<ans<<endl;
    return 0;
}