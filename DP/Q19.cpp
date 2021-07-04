// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int N=1e6+1;
long long int dp[N];
long long int prevDp[N];




class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
        //M coins and V is the value
        for(int i=0;i<=V;i++){
            dp[i]=INT_MAX;
            prevDp[i]=INT_MAX;
        }
        sort(coins,coins+M);
        dp[0]=0;
        prevDp[0]=0;

        for(int i=0;i<M;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(j<coins[i])dp[j]=prevDp[j];
                else{
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);
                }
            }
            for(int j=1;j<=V;j++)prevDp[j]=dp[j];
            
        }
        if(dp[V]==INT_MAX)return -1;
        else return dp[V];
	} 
	  
};



// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends