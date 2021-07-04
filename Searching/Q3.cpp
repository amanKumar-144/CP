// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        //Find first Index
        int n=v.size();
        int start=0;
        int end=n-1;
        pair<long,long>a=make_pair(-1,-1);
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(v[middle]<x)start=middle+1;
            else if(v[middle]>=x){
                end=middle-1;
                if(v[middle]==x)
                a.first=middle;
            }
        }
        //Find last Index
        start=0;end=n-1;
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(v[middle]<=x)
            {
                start=middle+1;
                if(v[middle]==x)
                a.second=middle;
            }
            else if(v[middle]>x){
                end=middle-1;
            }
        }
        
        return a;
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends