// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */


const int N=21;
int dp[N][N];
bool check[N][N];

int calc(int n,int k)
{
    if(n==1) return dp[1][k];
    
    if(check[n-1][k]==false)dp[n-1][k]=calc(n-1,k);
    
    
    dp[n][k]=(dp[n-1][k]+(k-1))%n + 1;
    check[n][k]=true;
    return dp[n][k];
}

class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       for(int i=0;i<=n;i++){
           check[i][k]=false;
           dp[i][k]=0;
       }
       
       
       dp[1][k]=1;
       check[1][k]=true;
       
       dp[n][k]=calc(n,k);
       return dp[n][k];
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends