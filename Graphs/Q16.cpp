// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

const int N=26;
vector<int>graph[N];
vector<bool>check(N,false);
vector<int>ans;

void dfs(int v) 
{
    check[v]=true;
    for(int i=0;i<graph[v].size();i++) 
    {
        int u=graph[v][i];
        if(!check[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    check.assign(N, false);
    ans.clear();
    for (int i = 0; i < N; ++i) {
        if(!check[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

class Solution{
    public:
    string findOrder(string dict[], int n, int K) 
    {
        for(int i=0;i<n-1;i++)
        {
            int pt1=0;
            int pt2=0;
            while(pt1<dict[i].size() && pt2<dict[i+1].size())
            {
                if(dict[i][pt1]==dict[i+1][pt2]){
                    pt1++;pt2++;
                }
                else{
                    graph[dict[i][pt1]-'a'].pb(dict[i+1][pt2]-'a');
                    break;
                }
            }
        }
        topological_sort();
        string answer;
        for(int i=0;i<ans.size();i++)
        {
            char x=ans[i]+'a';answer+=x;
        }
        for(int i=0;i<N;i++)graph[i].clear();
        return answer;
    }
};


// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends