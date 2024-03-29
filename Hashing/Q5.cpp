// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ins insert

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int valid=0;
        
        for(int i=0;i<n;i++)
        {
            int sum=X-A[i];
            unordered_set<int>s;
            for(int j=i+1;j<n;j++)
            {
                if(s.find(sum-A[j])!=s.end())
                {
                    valid=1;
                    break;
                }
                s.ins(A[j]);
            }
            if(valid==1)break;
        }
        return valid;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends