// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

#define vii vector<int>
#define pb push_back

class Solution {
  public:
    int maxValue(int arr[], int N) {
        vii a,b;
        //a[i]+i,a[i]-i
        
        int maxA=INT_MIN;int minA=INT_MAX;
        int maxB=INT_MIN;int minB=INT_MAX;
        for(int i=0;i<N;i++)
        {
            a.pb(arr[i]+i);
            b.pb(arr[i]-i);
            maxA=max(maxA,arr[i]+i);minA=min(minA,arr[i]+i);
            maxB=max(maxB,arr[i]-i);minB=min(minB,arr[i]-i);
        }
        int ans1=max(abs(maxA-minA),abs(maxB-minB));
        return ans1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends