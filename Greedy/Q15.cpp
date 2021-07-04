// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#define vii vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

bool comp(pair<pii,int>&a,pair<pii,int>&b)
{
    if(a.fi.fi<b.fi.fi)return true;
    else if(a.fi.fi>b.fi.fi)return false;
    else{
        if(a.fi.se>b.fi.se)return true;
        else return false;
    }
}

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int target=0;
        vector<pair<pii,int>>a;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            {
                int leftRange=max(0,i-gallery[i]);
                int rightRange=min(n-1,i+gallery[i]);
                a.pb(mp(mp(leftRange,rightRange),i));
            }
        }
        sort(a.begin(),a.end(),comp);
        int valid=1;
        int ans=0;
        while(target<n)
        {
            int select=-1;int backRange=-1;
            for(int i=0;i<a.size();i++)
            {
                if(a[i].se!=-1)
                {
                    if(a[i].fi.fi<=target && a[i].fi.se>backRange)
                    {
                        select=i;
                        backRange=a[i].fi.se;
                    }
                }
            }
            if(select==-1){
                valid=0;break;
            }
            else{
                target=a[select].fi.se+1;
                a[select].se=-1;
                ans++;
            }
        }
        if(valid==0)return -1;
        else return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
  // } Driver Code Ends