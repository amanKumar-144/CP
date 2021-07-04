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
        cout<<a[i]+1<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    vii a;
    map<int,int>storeCount;
    vector<int>graph[5001];

    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        auto itr=storeCount.find(x);
        if(itr==storeCount.end())storeCount.ins(mp(x,1));
        else itr->se++;

        graph[x].pb(i);
    }
    int validity=1;
    int presentColour=0;
    vii colours(n,0);
    for(auto itr=storeCount.begin();itr!=storeCount.end();itr++)
    {
        if(itr->se > k)validity=0;
        else
        {
            for(int j=0;j<graph[itr->fi].size();j++)
            {
                colours[graph[itr->fi][j]]=presentColour;
                presentColour=(presentColour+1)%k;
            }
        }
    }
    if(validity==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        print(colours);
    }
    return 0;
}