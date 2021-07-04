// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


const int N=1e6+1;
int dp[N];
int prevDp[N];

class Solution{

	public:
	int minDifference(int arr[], int n) 
	{ 
	    // Your code goes here
        int sum=0;
        int totalSum=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            totalSum+=arr[i];
        }sum--;
        
        
        for(int i=1;i<=sum;i++){
            dp[i]=0;
            prevDp[i]=0;
        }
        dp[0]=1;
        prevDp[0]=1;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(prevDp[j]==1)dp[j]=1;
                else if(j-arr[i]>=0 && prevDp[j-arr[i]]==1)dp[j]=1;
            }
            for(int j=1;j<=sum;j++)prevDp[j]=dp[j];
        }
        
        int answer=INT_MAX;
        
        for(int i=0;i<=sum;i++){
            if(dp[i]==1)
            {
                //cout<<"THE SUM IS "<<i<<endl;
                int sum1=i;int sum2=totalSum-i;
                answer=min(answer,abs(sum1-sum2));
            }
        }
        return answer;
	} 
};




// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends