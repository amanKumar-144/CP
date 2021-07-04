// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

bool comp(pii &a,pii &b)
{
    if(a.se<b.se)return true;
    else if(a.se>b.se)return false;
    else{
        if(a.fi<b.fi)return true;
        else return false;
    }
}

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pii>a;
        for(int i=0;i<n;i++){
            a.pb(mp(start[i],end[i]));
        }
        sort(a.begin(),a.end(),comp);
        int finishTime=a[0].se;
        int ans=1;
        for(int i=1;i<n;i++){
            if(a[i].fi>finishTime)
            {
                ans++;finishTime=a[i].se;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends