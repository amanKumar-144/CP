// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long

#define pb push_back
#define mp make_pair
#define vii vector<long long>
const int N=1001;
vii a[N];


class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        a[0].pb(1);
        a[1].pb(1);a[1].pb(1);
        a[2].pb(1);a[2].pb(2);a[2].pb(1);

        for(int i=3;i<=n;i++)
        {
            vii temp;
            temp.pb(1);
            for(int j=1;j<a[i].size();j++)
            {
                int sum=a[i][j]+a[i][j-1];
                temp.pb(sum);
            }
            temp.pb(1);
            for(int j=0;j<temp.size();j++){
                a[i].pb(temp[j]);
            }
        }
        return a[n];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends