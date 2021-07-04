// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

const int N=11;
int dp[N][N];
bool check[N][N];

int calc(int x,int y,int m,int n)
{
    if(x-1>=0 && x-1<m)
    {
        if(check[x-1][y]==false)dp[x-1][y]=calc(x-1,y,m,n);
        dp[x][y]+=dp[x-1][y];
    }
    if(y-1>=0 && y-1<n)
    {
        if(check[x][y-1]==false)dp[x][y-1]=calc(x,y-1,m,n);
        dp[x][y]+=dp[x][y-1];
    }
    check[x][y]=true;
    return dp[x][y];
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            check[i][j]=false;
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;check[0][0]=true;
    dp[m-1][n-1]=calc(m-1,n-1,m,n);
    return dp[m-1][n-1];
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends