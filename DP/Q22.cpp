// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

const int N=1e3+1;
long long int dp[N][N];
bool check[N][N];

int calc(int arr[],int start,int end)
{
    check[start][end]=true;

    if(start==end){
        dp[start][end]=arr[start];
        return dp[start][end];
    }
    else if(start+1==end){
        dp[start][end]=max(arr[start],arr[end]);
        return dp[start][end];
    }
    if(check[start+2][end]==false)dp[start+2][end]=calc(arr,start+2,end);
    if(check[start+1][end-1]==false)dp[start+1][end-1]=calc(arr,start+1,end-1);
    if(check[start][end-2]==false)dp[start][end-2]=calc(arr,start,end-2);

    int val1=arr[start]+min(dp[start+2][end],dp[start+1][end-1]);
    int val2=arr[end]+min(dp[start+1][end-1],dp[start][end-2]);
    dp[start][end]=max(val1,val2);
    return dp[start][end];
}


//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
            check[i][j]=false;
        }
    }

    dp[0][n-1]=calc(arr,0,n-1);
    return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends