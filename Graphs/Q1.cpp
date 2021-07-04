#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=1e4+1;
vector<bool>check(N,false);
void dfs(int v,vector<int>graph[],vii &a)
{
  
    check[v]=true;
    a.pb(v);
    for(int i=0;i<graph[v].size();i++)
    {
      
        if(check[graph[v][i]]==false)
        {
            dfs(graph[v][i],graph,a);
        }
    }
}
class Solution 
{
    public:
    
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vii answer;
	    for(int i=0;i<V;i++)
	    {
	        if(check[i]==false)
	            dfs(i,adj,answer);
	    }
	    return answer;
	}
};


int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
       
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}