// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define ll long long 
const int MOD=1e9+7;
const int N=1e5+1;
int dp[N];
vector<bool>check(N,false);

int calc(int n)
{
    if(check[n-1]==false)dp[n-1]=calc(n-1);
    if(check[n-2]==false)dp[n-2]=calc(n-2);

    dp[n]=(dp[n-1]+dp[n-2])%MOD;
    check[n]=true;
    return dp[n];
}
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        dp[0]=0;check[0]=true;
        dp[1]=1;dp[2]=2;
        check[1]=true;check[2]=true;
        if(check[n]==false)dp[n]=calc(n);
        return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends