// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array


class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int nextIndex=0+arr[0];
        int nextValidIndex=-1;
        int ans=1;
        for(int i=1;i<=nextIndex;i++)
        {
            int next=i+arr[i];
            nextValidIndex=max(nextValidIndex,next);
            if(i==nextIndex){
                ans++;
                nextIndex=nextValidIndex;
                nextValidIndex=-1;
            }
            if(nextIndex>=n-1)break;
        }
        if(nextIndex<n-1)return -1;
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends