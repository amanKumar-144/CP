// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++


const int N=26;
vector<int>counting(N,0);


class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        for(int i=0;i<N;i++)counting[i]=0;

        for(int i=0;i<arr.size();i++)
        {
            counting[arr[i]-'a']++;
        }
        string answer;
        for(int i=0;i<N;i++)
        {
            int count=counting[i];
            while(count--)answer+=('a'+i);
        }
        return answer;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends