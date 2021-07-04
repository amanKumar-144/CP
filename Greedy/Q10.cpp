// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

#define vii vector<int>
#define pb push_back

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vii a;
        for(int i=0;i<N;i++){
            a.pb(candies[i]);
        }
        sort(a.begin(),a.end());
        int start=0;
        int end=N-1;
        int ans1=0;
        while(start<=end)
        {
            ans1+=a[start];
            end=end-K;
            start++;
        }
        reverse(a.begin(),a.end());
        start=0;end=N-1;
        int ans2=0;
        while(start<=end){
            ans2+=a[start];
            end=end-K;
            start++;
        }
        vii ans;
        ans.pb(ans1);ans.pb(ans2);
        return ans;
    }
};




// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends