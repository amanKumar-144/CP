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


const int N=1001;
const int INF = 1e9;
vector<pair<int, int>> adj[N];

void dijkstraAlgo(int V,int s, vector<int> & d, vector<int> & p) {
    int n = V;
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}



class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adjGraph[], int S)
    {
        vii a;
        for(int i=0;i<V;i++){
            for(int j=0;j<adjGraph[i].size();j++)
            {
                vii b=adjGraph[i][j];
                int vert=b[0];
                int weight=b[1];
                adj[i].pb(mp(vert,weight));
            }
        }
        vii p;
        dijkstraAlgo(V,S,a,p);
        for(int i=0;i<V;i++){
            adjGraph[i].clear();
            adj[i].clear();
        }
        
        return a;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends