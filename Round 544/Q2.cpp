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
    map<int,int>storeRemFreq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        x=x%k;
        auto itr=storeRemFreq.find(x);
        if(itr==storeRemFreq.end())storeRemFreq.ins(mp(x,1));
        else itr->se++;
    }
    int ans=0;
    for(auto itr=storeRemFreq.begin();itr!=storeRemFreq.end();itr++)
    {
        int rem1=itr->fi;
        int required=(k-rem1)%k;
        auto it=storeRemFreq.find(required);
        if(it!=storeRemFreq.end() && rem1!=required)
        {
            int value=min(itr->se,it->se);
            itr->se-=value;
            it->se-=value;
            ans+=value;
        }
        else if(it!=storeRemFreq.end() && rem1==required)
        {
            int value=itr->se/2;
            ans+=value;
        }
    }
    cout<<ans*2<<endl;
    return 0;
}