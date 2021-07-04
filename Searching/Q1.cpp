// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int start=0;int end=N-1;
        int ans=0;
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(Arr[middle]<k){
                ans=middle+1;
                start=middle+1;
            }
            else if(Arr[middle]==k){
                ans=middle;break;
            }
            else if(Arr[middle]>k){
                end=middle-1;
            }
        }
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
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends