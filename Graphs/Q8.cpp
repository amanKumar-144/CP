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
const int N=1e6+1;
vector<bool>check(N,false);
vector<int>graph[N];

void dfs(int v,vector<int>&comp)
{
    check[v]=true;
    comp.pb(v);
    for(int i=0;i<graph[v].size();i++)
    {
        int u=graph[v][i];
        if(check[u]==false)
        {
            dfs(u,comp);
        }
    }
}

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vii a=nums;
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==nums[i])continue;

            graph[a[i]].pb(nums[i]);
            graph[nums[i]].pb(a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(check[a[i]]==false)
            {
                vii comp;
                dfs(a[i],comp);
                ans=ans+(comp.size()-1);
                comp.clear();
            }
        }
        for(int i=0;i<n;i++){
            check[a[i]]=false;
            graph[a[i]].clear();
        }

        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends