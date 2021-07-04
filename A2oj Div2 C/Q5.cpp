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
#define endl "\n"
using namespace std;
map<int,int>storeFreq;
const int N=500001;
int dp[N];
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    for(int i=0;i<n;i++)
    {
        int element=a[i];
        auto itr=storeFreq.find(element);
        if(itr==storeFreq.end())storeFreq.ins(mp(element,1));
        else itr->se++;
    }
    vector<pii> newArray;//element,freq
    for(auto itr=storeFreq.begin();itr!=storeFreq.end();itr++)
    {
        newArray.pb(mp(itr->fi,itr->se));
    }
    int size=newArray.size();
    for(int i=size-1;i>=0;i--)
    {
        int element=newArray[i].fi;
        int freq=newArray[i].se;
        if(i==size-1)
        {
            dp[i]=element*freq;
        }
        else
        {
            int nextElement=newArray[i+1].fi;

            if(element+1==nextElement)dp[i]=max(element*freq+dp[i+2],dp[i+1]);
            else dp[i]=element*freq+dp[i+1];
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}