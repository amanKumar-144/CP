// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        int start=0;
        int end=0;
        int finalAns=-1;
        for(int i=0;i<n;i++)end=max(end,tree[i]);
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=max(0,tree[i]-middle);
            }
            if(ans==k)
            {
              finalAns=middle;break;  
            }
            else if(ans<k)end=middle-1;
            else if(ans>k)start=middle+1;
        }
        return finalAns;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends