// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

#define vii vector<long long>
#define pb push_back

const long long int N=1e5+1;
long long int fact[N], invfact[N];
const long long int MOD=1e9+7;

void precompute(int n)
{
	fact[0]=fact[1]=1;
	for(int i=2;i<=n;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
}


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
        long long int maxElement=0;
        for(int i=0;i<n;i++)maxElement=max(maxElement,a[i]);
        precompute(maxElement);
        vii ans;
        for(int i=0;i<n;i++)ans.pb(fact[a[i]]);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends