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
    int n;cin>>n;
    map<int,int>freq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto itr=freq.find(x);
        if(itr==freq.end())freq.ins(mp(x,1));
        else itr->se++;
    }
    int ans=0;
    for(auto itr=freq.begin();itr!=freq.end();itr++)
    {
        ans=max(ans,itr->se);
    }cout<<ans<<endl;
    return 0;
}