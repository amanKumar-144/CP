// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

const int M=1e6+1;
int dp[M];
int storeNum[M];
vector<int>nums={1,2,5,10,20,50,100,200,500,2000};
vector<int>check(M,false);


class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        for(int i=1;i<=N;i++)
        {
            int val=INT_MAX;
            int whichNum=-1;
            for(int j=0;j<nums.size();j++)
            {
                if(i==nums[j]){
                    val=1;
                    whichNum=-1;
                    break;
                }
                else if(i-nums[j]<0)continue;
                else
                {
                    if(1+dp[i-nums[j]]<val)
                    {
                        val=1+dp[i-nums[j]];
                        whichNum=i-nums[j];
                    }
                }
            }
            dp[i]=val;
            storeNum[i]=whichNum;
        }
        
        int hello=N;
        vii answer;
        while(storeNum[hello]!=-1)
        {
            answer.pb(hello-storeNum[hello]);
            hello=storeNum[hello];
        }
        answer.pb(hello);
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends