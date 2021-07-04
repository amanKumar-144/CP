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
    }
    cout<<endl;
}
const int N=200000;
map<int,int>storeFreq;
const int maxValue=1e18;
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())storeFreq.ins(mp(x,1));
        else itr->se++;
    }
    vii linearSearch;
    for(auto it=storeFreq.begin();it!=storeFreq.end();it++)
    {
        linearSearch.pb(it->se);
    }
    sort(linearSearch.begin(),linearSearch.end());
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        int currElement=i;
        auto it=lower_bound(linearSearch.begin(),linearSearch.end(),currElement);
        if(it!=linearSearch.end())
        {
            int index=it-linearSearch.begin();
            int nxtElement=currElement*2;
            int temp=currElement;
            while(lower_bound(linearSearch.begin()+index+1,linearSearch.end(),nxtElement)!=linearSearch.end())
            {
                temp+=nxtElement;
                index=lower_bound(linearSearch.begin()+index+1,linearSearch.end(),nxtElement)-linearSearch.begin();
                nxtElement*=2;
            }
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}