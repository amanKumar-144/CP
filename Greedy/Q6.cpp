// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define vii vector<int>
#define pb push_back

class Solution{
public:
    string findLargest(int N, int S)
    {
        if(S==0 && N>1)
        {
            string ans;ans="-1";
            return ans;
        }
        vii a;
        while(S>0)
        {
            if(S>=9)
            {
                a.pb(9);
                S-=9;
            }
            else {
                a.pb(S);
                S=0;
            }
        }
        int valid=1;
        N=N-a.size();
        if(N<0)valid=0;
        else{
            while(N--)a.pb(0);
        }
        string answer;
        if(valid==0)answer="-1";
        else{
            for(int i=0;i<a.size();i++)
            {
                char x=a[i]+'0';
                answer+=x;
            }
        }
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends