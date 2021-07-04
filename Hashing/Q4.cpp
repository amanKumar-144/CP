// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ins insert
#define fi first
#define se second
#define mp make_pair

class Solution{
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int rem=nums[i]%k;
            auto itr=m.find(rem);
            if(itr==m.end())m.ins(mp(rem,1));
            else itr->se++;
        }
       
        int valid=1;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->fi==0){
                if(itr->se%2!=0)valid=0;
            }
            else{
                int rem1=itr->fi;
                int rem2=k-rem1;
                if(rem1==rem2)
                {
                    if(itr->se%2!=0)valid=0;
                }
                else{
                    auto it2=m.find(rem2);
                    if(it2==m.end() || it2->se!=itr->se)valid=0;
                }
            }
        }
        return valid;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends