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
    map<int,int>storeFreq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())
        {
            storeFreq.ins(mp(x,i+1));
        }
    }
    if(k>storeFreq.size())
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(auto itr=storeFreq.begin();itr!=storeFreq.end();itr++)
        {
            if(k==0)break;
            k--;
            cout<<itr->se<<" ";
        }cout<<endl;
    }
    return 0;
}