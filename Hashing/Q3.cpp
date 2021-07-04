// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


set<int>s1,s2;
#define ins insert

class Solution{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
        s1.clear();
        s2.clear();
        for(int i=0;i<n;i++)s1.ins(a[i]);
        for(int i=0;i<m;i++)s2.ins(b[i]);
        
        
        int answer=0;
        for(auto itr=s1.begin();itr!=s1.end();itr++)
        {
            auto it=s2.find(*itr);
            if(it!=s2.end())answer++;
        }
        
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
		Solution ob;
		cout << ob.NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
}  // } Driver Code Ends