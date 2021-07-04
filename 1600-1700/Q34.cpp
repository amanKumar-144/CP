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
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());

    vii cumSum(n,0);
    vii indexPos(n,0);
    cumSum[0]=0;
    indexPos[0]=1;

    for(int i=1;i<n;i++)
    {
        cumSum[i]=cumSum[i-1]+(a[i]-a[i-1])*i;
    }
   
    for(int i=1;i<n;i++)
    {
        int start=0;int end=i;
        int ans=i;
        while(start<=end)
        {
            int middle=start+(end-start)/2;//Index
            int diff=cumSum[i]-cumSum[middle]-(a[i]-a[middle])*(middle);
            if(diff<=k)
            {
                end=middle-1;
                ans=middle;
            }
            else start=middle+1;
        }
        indexPos[i]=i-ans+1;
    }
    int answer=indexPos[0];
    int store=0;
    for(int i=0;i<n;i++)
    {
        if(indexPos[i]>answer){
            answer=indexPos[i];
            store=i;
        }
    }
    cout<<answer<<" "<<a[store]<<endl;
    return 0;
}