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
set<char>s;

class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        string small;
        for(int i=0;i<a.size();i++)
        {
            auto it=s.find(a[i]);
            if(it==s.end())
            {
                small+=a[i];
                s.ins(a[i]);
            }
        }
       
        string small2=small;
        sort(small2.begin(),small2.end());
        int change=-1;
        for(int i=0;i<small.size();i++)
        {
            if(small[i]!=small2[i]){
                change=i;break;
            }
        }
        if(change==-1)return a;
        else{
            char r1=small[change];
            char r2=small2[change];
            for(int i=0;i<a.size();i++){
                if(a[i]==r1)a[i]=r2;
                else if(a[i]==r2)a[i]=r1;
            }
            return a;
        }
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends