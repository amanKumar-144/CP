// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define vii vector<int>
#define pb push_back
#define ins insert
class Solution{
    public:
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
        // code here
        set<vii>answer;
        sort(A.begin(),A.end());
        for(int i=0;i<pow(2,N);i++)
        {
            int tempSum=0;
            for(int j=0;j<N;j++)
            {
                if( (i&(1<<j))!=0 )tempSum+=A[j];
            }
            if(tempSum==B)
            {
                vii temp;
                for(int j=0;j<N;j++)
                {
                    if( (i&(1<<j))!=0 )temp.pb(A[j]);
                }
                answer.ins(temp);
            }
        }
        vector<vii>finalAns;
        for(auto itr=answer.begin();itr!=answer.end();itr++)finalAns.pb(*itr);
        return finalAns;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, x, B;
        cin>>N;
        vector<int> A;
        for(int i = 0;i < N;i++)
        {
            cin>>x;
            A.push_back(x);
        }
        cin>>B;
        
        Solution ob;
        vector<vector<int>> result;
        result = ob.combinationSum(A, N, B);
        
        if(result.size() == 0)
        cout<<"Empty"<<endl;
        else{
            for(int i = 0;i < result.size(); i++){
                cout<<"(";
                for(int j = 0; j < result[i].size();j++){
                    cout<<result[i][j];
                    if(j < result[i].size() - 1)
                    cout<<" ";
                }
                cout<<")";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends