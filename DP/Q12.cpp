// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int N=1001;
long long int dp[N][N];
#define vii vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        //code here.
        vii a;
        a.pb(0);
        for(int i=0;i<m;i++)a.pb(S[i]);
        sort(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            for(int j=0;j<=n;j++){
                if(j==0)dp[i][j]=1;
                else dp[i][j]=0;
            }
        }

        for(int i=1;i<a.size();i++){
            for(int j=1;j<=n;j++)
            {
                if(j<a[i])dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-a[i]];
                }
            }
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends