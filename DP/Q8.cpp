// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


const int N=1001;
int dp[N][N];
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        vector<pii>store;
        for(int i=0;i<n;i++)
        {
            store.push_back(make_pair(wt[i],val[i]));
        }
        sort(store.begin(),store.end());
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=W;j++){
                dp[i][j]=0;
            }
        }
        for(int j=1;j<=W;j++)
        {
            if(j>=store[0].fi)dp[0][j]=max(dp[0][j],store[0].se);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(store[i].fi>j)dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=max(dp[i-1][j],store[i].se+dp[i-1][j-store[i].fi]);
                }
            }
        }
        return dp[n-1][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends