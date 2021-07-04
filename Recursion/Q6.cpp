// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
const int N=101;
int dp[N][N];
bool check[N][N];

void dfs(int x,int y,int n,int m,int oldCol,int newCol)
{
    
    dp[x][y]=newCol;
    check[x][y]=true;
    
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(newX>=0 && newY>=0 && newX<n && newY<m && check[newX][newY]==false && dp[newX][newY]==oldCol)
        {
            dfs(newX,newY,n,m,oldCol,newCol);
        }
    }
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                dp[i][j]=image[i][j];
                check[i][j]=false;
            }
        }
        
        int oldColor=dp[sr][sc];
        dfs(sr,sc,n,m,oldColor,newColor);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                image[i][j]=dp[i][j];
            }
        }
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends