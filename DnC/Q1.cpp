// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int start=0;int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(middle%2==0)
            {
                if(middle+1<n && arr[middle]==arr[middle+1]) start=middle+1;
                else if(middle-1>=0 && arr[middle-1]==arr[middle]) end=middle-1;
                else
                {
                    ans=middle;
                    break;
                }
            }
            else if(middle%2==1)
            {
                if(arr[middle-1]==arr[middle]) start=middle+1;
                else if(middle+1<n && arr[middle+1]==arr[middle]) end=middle-1;
                else
                {
                    ans=middle;
                    break;
                }
            }
        }
        return arr[ans];
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends