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
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    vii cumSum;
    cumSum.pb(a[0]);
    for(int i=1;i<n;i++){
        cumSum.pb(a[i]+cumSum[i-1]);
    }
    double finalAns=0.0;
    for(int i=0;i<n;i++)
    {
        int minIndexReq=i+k-1;
        if(minIndexReq<n)
        {
            double ans=cumSum[minIndexReq]-cumSum[i]+a[i];
            ans=ans/(minIndexReq-i+1);
            finalAns=max(finalAns,ans);
            for(int j=minIndexReq+1;j<n;j++)
            {
                ans=cumSum[j]-cumSum[i]+a[i];
                ans=ans/(j-i+1);
                finalAns=max(finalAns,ans);
            }
        }
    }
    cout<<setprecision(12)<<finalAns<<endl;
    return 0;
}