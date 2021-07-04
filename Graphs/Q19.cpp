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
const int N=101;
vector<int>graph[N];
vector<bool>check(N,false);
int valid=1;
set<int>s;
void dfs(int start)
{
    check[start]=true;
    s.ins(start);
    for(int i=0;i<graph[start].size();i++)
    {
        int u=graph[start][i];
        if(check[u]==false)dfs(u);
        else{
            auto it=s.find(u);
            if(it!=s.end())valid=0;
        }
    }
    s.erase(start);
}
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
    {
	    for(int i=0;i<prerequisites.size();i++)
        {
            pii a=prerequisites[i];
            graph[a.se].pb(a.fi);
        }
        valid=1;
        for(int i=0;i<N;i++){
            if(check[i]==false)dfs(i);
        }

        for(int i=0;i<N;i++){
            check[i]=false;
            graph[i].clear();
        }
        s.clear();

        if(valid==1)return true;
        else return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends