// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


const int MOD=1e9+7;
const int N=1e5+1;
int dp[N];
vector<bool>check(N,false);

int calc(int n)
{
    check[n]=true;
    
    
    if(n-1>=0 && check[n-1]==false)dp[n-1]=calc(n-1);
    if(n-1>=0){
        dp[n]+=dp[n-1];dp[n]%=MOD;
    }
    
    if(n-2>=0 && check[n-2]==false)dp[n-2]=calc(n-2);
    if(n-2>=0){
        dp[n]+=dp[n-2];dp[n]%=MOD;
    }
    
    if(n-3>=0 && check[n-3]==false)dp[n-3]=calc(n-3);
    if(n-3>=0){
        dp[n]+=dp[n-3];dp[n]%=MOD;
    }
    
    dp[n]%=MOD;
    return dp[n];
}

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        for(int i=0;i<=n;i++){
            dp[i]=0;
            check[i]=false;
        }
        
        dp[0]=1;
        check[0]=true;
        
        if(check[n]==false)dp[n]=calc(n);
        
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends