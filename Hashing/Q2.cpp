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

class Solution{
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int,int>m;
        set<pii>s;
        for(int i=0;i<nums.size();i++)
        {
            auto it=m.find(nums[i]);
            if(it==m.end())m.ins(mp(nums[i],1));
            else it->se++;
        }
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            s.ins(mp(itr->se,itr->fi));
        }
        vii ans;
        int count=0;
        for(auto it=s.rbegin();it!=s.rend();it++)
        {
            if(count==k)break;
            else ans.pb(it->se);
            count++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends