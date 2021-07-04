#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2001;
const int MOD=1e9+7;
int dp[N][N]; //Number,Length
int n,k;
int solve(int number,int length)
{
    if(length==1)
    {
        return 1;
    }
    else if(length==0)return 0;
    else
    {
        for(int i=number;i<=n;i=i+number)
        {
            if(length-1>=0 && dp[i][length-1]==0)
            {
                dp[i][length-1]=solve(i,length-1);
            }
            dp[number][length]+=dp[i][length-1];
            dp[number][length]%=MOD;
        }
        return dp[number][length];
    }
}
int32_t main()
{
    FAST;
    cin>>n>>k;
    for(int i=1;i<=n;i++)dp[i][1]=1;
    int ans=0;
   
    for(int i=1;i<=n;i++)
    {
        if(dp[i][k]==0)dp[i][k]=solve(i,k);
        ans=ans+dp[i][k];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}