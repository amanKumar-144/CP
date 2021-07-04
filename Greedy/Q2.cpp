// { Driver Code Starts
#include <bits/stdc++.h>
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
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends