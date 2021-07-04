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
#define ins insert



class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int target=0;
        vector<pii>a;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            {
                int leftRange=max(0,i-gallery[i]);
                int rightRange=min(n-1,i+gallery[i]);
                a.pb(mp(leftRange,rightRange));
            }
        }
        sort(a.begin(),a.end());
        int valid=1;
        int ans=0;
        int i=0;
        while(target<n)
        {
            int backRange=-1;
            int select=-1;
            for(int j=i;j<a.size();j++)
            {
                if(a[j].fi<=target && a[j].se>backRange)
                {
                    backRange=a[j].se;
                    select=j;
                }
            }
            if(select==-1){
                valid=0;break;
            }
            else{
                i=select+1;
                target=a[select].se+1;
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