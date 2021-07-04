// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


const int N=201;
int dp[N][N];

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++)dp[1][i]=i;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++)
            {
                if(i>j)dp[i][j]=dp[i-1][j];
                
                int val=INT_MAX;
                for(int p=1;p<=j;p++)
                {
                    val=min(val,1+max(dp[i-1][p-1],dp[i][j-p]));
                }
                dp[i][j]=val;
            }
        }
        
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends