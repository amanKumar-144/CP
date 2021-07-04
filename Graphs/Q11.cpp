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
const int INF=1e9;
bool isValid(int i,int j,int n,int m,vector<vector<int>>&A)
{
    if(i>=0 && i<n && j>=0 && j<m && A[i][j]==1)return true;
    else return false;
}

class Solution 
{
  public:
    int shortestDistance(int N, int M, vector<vector<int>> &A, int X, int Y) 
    {
        deque<pii>dq;
        dq.pb(mp(0,0));

        int moveX[4]={0,1,0,-1};
        int moveY[4]={-1,0,1,0};

        vector<int>dist[N];
        vector<bool>check[N];

        vector<bool>temp(M,false);
        vector<int>a(M,INF);

        for(int i=0;i<N;i++){
            check[i]=temp;
            dist[i]=a;
        }

        dist[0][0]=0;
        while(dq.size()>0)
        {
            pii top=dq.front();
            dq.pop_front();
            check[top.fi][top.se]=true;
            int d=dist[top.fi][top.se];

            for(int i=0;i<4;i++)
            {
                int newX=top.fi+moveX[i];
                int newY=top.se+moveY[i];

                if(isValid(newX,newY,N,M,A)==true && check[newX][newY]==false)
                {
                    check[newX][newY]=true;
                    dq.pb(mp(newX,newY));
                    dist[newX][newY]=1+d;
                }
            }
        }

        if(dist[X][Y]==INF || A[0][0]==0)return -1;
        else return dist[X][Y];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends