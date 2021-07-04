// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++

#define vii vector<int>
#define pb push_back

class Solution{
public:

	void rearrange(int a[], int n) 
	{
	    vii pos;
	    vii neg;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)pos.pb(a[i]);
	        else neg.pb(a[i]);
	    }
	    int ptr1=0;int ptr2=0;
	    int i=0;
	    while(ptr1<pos.size() && ptr2<neg.size())
	    {
	        a[i]=pos[ptr1];i++;
	        a[i]=neg[ptr2];i++;
	        ptr1++;
	        ptr2++;
	    }
	    while(ptr1<pos.size()){
	        a[i]=pos[ptr1];i++;
	        ptr1++;
	    }
	    while(ptr2<neg.size()){
	        a[i]=neg[ptr2];i++;
	        ptr2++;
	    }
	   
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends