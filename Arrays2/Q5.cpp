// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

#define vii vector<long long int>
#define pb push_back
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vii ans;
        long long int prod=1;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                prod=prod*nums[i];
            else zero++;
        }
        for(int i=0;i<n;i++)
        {
            if(zero==1)
            {
                if(nums[i]!=0)ans.pb(0);
                else ans.pb(prod);
            }
            else if(zero>1)ans.pb(0);
            else
                ans.pb(prod/nums[i]);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends