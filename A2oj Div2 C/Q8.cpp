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
#define endl "\n"
using namespace std;
const int N=101;
const int MOD=1e9+7;
int n,k,d;
int dp[N][2];//(sum,2)
//0->(more than or =d) not present
//1->(more than or =d) present

int calculate(int sum)
{
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                if(j<d)
                {
                    dp[i][0]+=dp[i-j][0];
                    dp[i][1]+=dp[i-j][1];

                    dp[i][0]%=MOD;
                    dp[i][1]%=MOD;
                }
                else if(j>=d)
                {
                    dp[i][1]+=dp[i-j][1];
                    dp[i][1]%=MOD;
                    dp[i][1]+=dp[i-j][0];
                    dp[i][1]%=MOD;
                    
                }
            }
        }
    }
}
int32_t main()
{
    FAST;
    cin>>n>>k>>d;
    memset(dp,0,sizeof(dp));
    

    calculate(n);
    cout<<dp[n][1]<<endl;
    return 0;
}