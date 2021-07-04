// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define vii vector<int>
#define pb push_back
#define ins insert
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
class Solution{
public:
    int maxBalls(int N, int M, int a[], int b[]){
        // code here
        set<int>store1,store2,store;
        
        for(int i=0;i<N;i++)store1.ins(a[i]);
        for(int i=0;i<M;i++)store2.ins(b[i]);
        for(auto it=store1.begin();it!=store1.end();it++)
        {
            auto it2=store2.find(*it);
            if(it2!=store2.end())store.ins(*it);
        }

        vii mark1;vii mark2;
        int pt1=N-1;int pt2=M-1;
        for(auto itr=store.rbegin();itr!=store.rend();itr++)
        {
           
            while(a[pt1]!=*itr)
            {
                pt1--;
            }
            mark1.pb(pt1);
            while(b[pt2]!=*itr)
            {
                pt2--;
            }
            mark2.pb(pt2);

            pt1--;pt2--;
        }
        sort(mark1.begin(),mark1.end());sort(mark2.begin(),mark2.end());
        
        //print(mark1);
        //print(mark2);
        int prev1=0;int prev2=0;
        int finalAns=0;
        for(int i=0;i<mark1.size();i++)
        {
            int p1=mark1[i];
            int p2=mark2[i];
            int sum1=0;int sum2=0;
            for(int i=p1-1;i>=prev1;i--)sum1+=a[i];
            for(int i=p2-1;i>=prev2;i--)sum2+=b[i];
            prev1=p1+1;
            prev2=p2+1;
            finalAns+=max(sum1,sum2);
        }
        int sum1=0;int sum2=0;
        for(int i=prev1;i<N;i++)sum1+=a[i];
        for(int i=prev2;i<M;i++)sum2+=b[i];
        finalAns+=max(sum1,sum2);
        for(auto itr=store.begin();itr!=store.end();itr++)finalAns+=*itr;
        return finalAns;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        int a[N], b[M];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends