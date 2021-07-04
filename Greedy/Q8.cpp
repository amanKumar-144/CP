// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define vii vector<int>
#define pb push_back
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        vii a1,a2,b1,b2;
        for(int i=0;i<n;i++){
            a1.pb(a[i]);
            a2.pb(b[i]);
        }
      
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());reverse(a2.begin(),a2.end());
        long long int ans=0;
        for(int i=0;i<n;i++)ans=ans+a1[i]*a2[i];
        
      
        for(int i=0;i<n;i++){
            b1.pb(a[i]);
            b2.pb(b[i]);
        }
        sort(b2.begin(),b2.end());
        sort(b1.begin(),b1.end());reverse(b1.begin(),b1.end());
        long long int ans2=0;
        for(int i=0;i<n;i++)ans2=ans2+b1[i]*b2[i];
        return min(ans,ans2);
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}  // } Driver Code Ends