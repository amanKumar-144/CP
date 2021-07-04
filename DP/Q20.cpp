// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

const int N=1e4+1;
int dp[N][N];

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n=S.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)dp[i][j]=1;
                else dp[i][j]=0;
            }
        }


        for(int ptr=1;ptr<n;ptr++)
        {
            for(int i=0;i<n && i+ptr<n;i++)
            {
                if(S[i]==S[i+ptr]){
                    if(i+1==i+ptr)dp[i][i+ptr]=1;
                    else if(i+1<=i+ptr-1 && dp[i+1][i+ptr-1]==1)
                    {
                        dp[i][i+ptr]=1;
                    }
                }
            }
        }
        
        
        int ans=0;
        int start=-1;
        int end=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1 && j-i+1>ans){
                    ans=j-i+1;
                    start=i;
                    end=j;
                }
            }
        }
        string answer;
        for(int i=start;i<=end;i++)answer+=S[i];
        return answer;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends