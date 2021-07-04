// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


const int N=5001;
#define pb push_back
vector<int>graph[N];
vector<int>revGraph[N];
vector<bool>used;
vector<int>order,component;

void dfs1(int v) 
{
    used[v] = true;
    for (auto u : graph[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) 
{
    used[v] = true;
    component.push_back(v);

    for (auto u : revGraph[v])
        if (!used[u])
            dfs2(u);
}

class Solution
{
	public:
    int kosaraju(int V, vector<int> adj[])
    {
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++)
            {
                int u=i;int v=adj[i][j];
                graph[u].pb(v);
                revGraph[v].pb(u);
            }
        }
        used.assign(V, false);

        for (int i = 0; i < V; i++)
            if (!used[i])
                dfs1(i);

        used.assign(V, false);
        reverse(order.begin(), order.end());
        int ans=0;
        for (int i=0;i<order.size();i++)
        {
            int v=order[i];
            if (!used[v]) 
            {
                dfs2 (v);
                component.clear();
                ans++;
            }
        }
        for(int i=0;i<V;i++){
            graph[i].clear();
            revGraph[i].clear();
        }
        order.clear();
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends