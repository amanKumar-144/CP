// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int a[], int n) {
	    int start=0;int end=n-1;
	    int ans=a[n-1];
	    if(n==1)return ans;
	    
	    while(start<=end)
	    {
	        int middle=start+(end-start)/2;
	        if(middle==0)
	        {
	           if(a[middle]>a[middle+1]){
	               ans=a[middle];
	               break;
	           }
	           else{
	               start=middle+1;
	           }
	        }
	        else if(middle==n-1)
	        {
	          if(a[middle]>a[middle-1]){
	              ans=a[middle];
	              break;
	          }  
	          else end=middle-1;
	        }
	        else if(a[middle-1]<=a[middle] && a[middle]<=a[middle+1])
	        {
	               start=middle+1;
	        }
	        else if(a[middle-1]>=a[middle] && a[middle]>=a[middle+1])
	        {
	            end=middle-1;
	        }
	        else if(a[middle-1]<=a[middle] && a[middle]>=a[middle+1])
	        {
	            ans=a[middle];
	            break;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends