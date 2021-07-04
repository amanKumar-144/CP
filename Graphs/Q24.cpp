// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


const int N=501;
bool check[N][N];
int X[8]={0,1,1,1,0,-1,-1,-1};
int Y[8]={-1,-1,0,1,1,1,0,-1};

int dfs(int i,int j,int n,int m,vector<vector<int>>&grid,int *ans)
{
    check[i][j]=true;
    *ans=*ans+1;
    for(int k=0;k<8;k++){
        int newX=i+X[k];
        int newY=j+Y[k];
        if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && check[newX][newY]==false)
        {
            dfs(newX,newY,n,m,grid,ans);
        }
    }
}
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(check[i][j]==false && grid[i][j]==1)
                {
                    int x=0;
                    dfs(i,j,n,m,grid,&x);
                    ans=max(ans,x);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                check[i][j]=false;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends