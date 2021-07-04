// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int canReach(long long a, long long b, long long x) {
        int minVal=abs(a)+abs(b);
        if(minVal>x)return 0;
        else{
            int diff=x-minVal;
            if(diff%2==0)return 1;
            else return 0;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,x;
        
        cin>>a>>b>>x;

        Solution ob;
        cout << ob.canReach(a,b,x) << endl;
    }
    return 0;
}  // } Driver Code Ends