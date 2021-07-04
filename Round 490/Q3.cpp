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
    string s;cin>>s;
    map<char,int>storeFreq;
    map<char,int>finalFreq;
    for(int i=0;i<s.size();i++)
    {
        auto itr=storeFreq.find(s[i]);
        if(itr==storeFreq.end())storeFreq.ins(mp(s[i],1));
        else itr->se++;
    }
    finalFreq=storeFreq;
    for(auto itr=finalFreq.begin();itr!=finalFreq.end();itr++)
    {
        if(k==0)break;
        if(itr->se >= k){itr->se=itr->se-k;k=0;}
        else if(itr->se < k){k=k-itr->se;itr->se=0;}
    }
    vii a(n,0);
    for(int i=0;i<n;i++)
    {
        auto afterOper=finalFreq.find(s[i]);
        auto beforeOper=storeFreq.find(s[i]);
        if(beforeOper->se > afterOper->se)
        {
            //Means deleted
            a[i]=-1;beforeOper->se--;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1)cout<<s[i];
    }cout<<endl;
    return 0;
}