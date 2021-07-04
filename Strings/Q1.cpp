// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pb push_back

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string>a;
        
        string temp;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='.')temp+=S[i];
            else{
                a.pb(temp);
                temp="";
            }
        }
        a.pb(temp);
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i];
            if(i<a.size()-1)cout<<".";
        }cout<<endl;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends