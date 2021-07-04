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
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }

    int maxSum=a[0];
    int sum=a[0];
    
    for(int i=1;i<n;i++)
    {
        if(sum<0)sum=0;
        sum+=a[i];
        maxSum=max(sum,maxSum);
        if(sum<0)sum=0;
    }
    cout<<maxSum<<endl;
    return 0;
}