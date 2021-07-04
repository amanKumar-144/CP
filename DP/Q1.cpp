// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

const int N=1e6+1;
int dp[N];
vector<bool>check(N,false);

int calc(int n)
{
    if(n%2==0){

        if(check[n/2]==false)dp[n/2]=calc(n/2);
        if(check[n-1]==false)dp[n-1]=calc(n-1);

        dp[n]=min(1+dp[n/2],1+dp[n-1]);
        check[n]=true;
    }
    else{

        if(check[n-1]==false)dp[n-1]=calc(n-1);
        dp[n]=1+dp[n-1];
        check[n]=true;
    }
    return dp[n];
}
class Solution
{
  public:
    int minOperation(int n)
    {
        dp[0]=0;dp[1]=1;dp[2]=1;
        check[0]=true;check[1]=true;check[2]=true;

        dp[n]=calc(n);
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends