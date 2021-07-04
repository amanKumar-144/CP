// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

#define ins insert
#define mp make_pair
#define pb push_back
#define fi first
#define se second


class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
        
        int valid=0;

        set<int>s;
        for(int i=0;i<n;i++)
        {
            int req=x-arr[i];
            auto itr=s.find(req);
            if(itr!=s.end())valid=1;
            else{
                s.ins(arr[i]);
            }
        }
        
        return valid;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends