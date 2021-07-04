// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int N=501;
int X[8]={0,1,1,1,0,-1,-1,-1};
int Y[8]={-1,-1,0,1,1,1,0,-1};
bool check[N][N];

bool isValid(int i,int j,int n,int m)
{
    if(i>=0 && i<n && j>=0 && j<m)return true;
    else return false;
}

void dfs(int i,int j,vector<vector<char>>&grid)
{
    check[i][j]=true;
    int n=grid.size();
    int m=grid[0].size();

    for(int k=0;k<8;k++)
    {
        int newX=i+X[k];int newY=j+Y[k];
        if(isValid(newX,newY,n,m) && check[newX][newY]==false && grid[newX][newY]=='1')
            dfs(newX,newY,grid);
    }
}



class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(check[i][j]==false && grid[i][j]=='1'){
                    dfs(i,j,grid);ans++;
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends