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
const int N=1e6+1;
vii counting(N,0);
int32_t main()
{
    FAST;
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x;cin>>x;
        counting[x]=1;
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(counting[i]==0)ans=i;
        counting[i]=0;
    }
    return 0;
}