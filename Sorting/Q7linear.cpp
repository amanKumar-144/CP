// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

class Solution{
    public:

    int maxIndexDiff(int arr[], int n) 
    { 
        vector<pii>maxVal;
        maxVal.pb(mp(arr[n-1],n-1));
        int pt=0;
        for(int i=n-2;i>=0;i--){
            if(maxVal[pt].fi>arr[i])maxVal.pb(maxVal[pt]);
            else maxVal.pb(mp(arr[i],i));
            pt++;
        }
        reverse(maxVal.begin(),maxVal.end());

        vector<pii>minVal;
        minVal.pb(mp(arr[0],0));
        pt=0;
        for(int i=1;i<n;i++){
            if(minVal[pt].fi<arr[i])minVal.pb(minVal[pt]);
            else minVal.pb(mp(arr[i],i));
            pt++;
        }

        int ans=0;
        int minPtr=0;int maxPtr=0;
        while(minPtr<n && maxPtr<n)
        {
            if(minVal[minPtr]>maxVal[maxPtr])minPtr++;
            else{
                ans=max(ans,maxVal[maxPtr].se-minVal[minPtr].se);
                maxPtr++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends