#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
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
    }cout<<endl;
}
vector<vii>songList;
int comp(vii &a,vii &b)
{
    if(a[0]>b[0])return 1;
    else if(a[0]<b[0])return 0;
    else
    {
        if(a[1]>b[1])return 1;
        else if(a[1]<b[1])return 0;
        else if(a[1]==b[1])
        {
            if(a[2]>b[2])return 1;
            else return 0;
        }
    }
}
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    int totSum=0;
    int noCompressSum=0;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        vii a={x-y,x,y};
        songList.pb(a);
        totSum+=y;
        noCompressSum+=x;
    }
    sort(songList.begin(),songList.end(),comp);
    if(totSum>m)cout<<-1<<endl;
    else 
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(noCompressSum<=m)break;
            else
            {
                ans++;
                noCompressSum-=songList[i][0];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}