// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ins insert

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>counting(26,0);
        int n=S.size();
        int start=0;
        int ptr=1;
        int ans=1;
        counting[S[0]-'a']=1;
        while(ptr<n)
        {
            if(counting[S[ptr]-'a']==0)
            {
                counting[S[ptr]-'a']=1;
                ans=max(ans,ptr-start+1);
            }
            else
            {
                while(S[start]!=S[ptr] && start<=ptr)
                {
                    counting[S[start]-'a']=0;
                    start++;
                }
                start++;
                start=min(start,ptr);
                counting[S[ptr]-'a']=1;
                ans=max(ans,ptr-start+1);
            }
            ptr++;
        }
        ptr--;
        ans=max(ans,ptr-start+1);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends