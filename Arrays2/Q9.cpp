// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int a[], int n, int m) 
    {
        int count=0;
        int start=0;int end=0;
        int ans=0;
        while(start<=end && end<=n-1 && start<=n-1)
        {
            if(a[end]==0)count++;
            
            if(count<=m)
            {
                //cout<<"The start and end are ->"<<start<<":::"<<end<<endl;
                ans=max(ans,end-start+1);
                end++;
            }
            else if(count==m+1)
            {
                //Move start
                while(start<=end && start<=n-1)
                {
                    if(a[start]==0)
                    {
                        count--;
                        start++;
                        break;
                    }else start++;
                }
                //cout<<"The start and end are "<<start<<":::"<<end<<endl;
                ans=max(ans,end-start+1);
                end++;
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
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends