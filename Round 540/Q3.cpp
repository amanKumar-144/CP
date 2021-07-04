#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
map<int,int>storeFreq;
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n*n;i++){
        int x;cin>>x;
        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())storeFreq.ins(mp(x,1));
        else itr->se++;
    }

    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            matrix[i][j]=0;
    }
    int valid;
    if(n%2==0)
    {
        int row=0;
        int col=0;
        valid=1;
        for(auto itr=storeFreq.begin();itr!=storeFreq.end();)
        {
            if(itr->se%4==0)
            {
                int element=itr->fi;
                matrix[row][col]=element;
                matrix[row][n-1-col]=element;
                matrix[n-1-row][col]=element;
                matrix[n-1-row][n-1-col]=element;
                col++;
                if(col==n/2)
                {
                    col=0;row++;
                }
                if(row==n/2)break;
                itr->se-=4;
                if(itr->se==0)itr++;
            }
            else{
                valid=0;break;
            }
        }
    }
    else if(n%2==1)
    {
        int row=0;
        int col=0;
        valid=1;
        int once=0;
        int rowFilled=0;
        int rowPtr=0;int colPtr=0;
        for(auto itr=storeFreq.begin();itr!=storeFreq.end();)
        {
            if(itr->se%4==0 && row<n/2)
            {
                int element=itr->fi;
                matrix[row][col]=element;
                matrix[row][n-1-col]=element;
                matrix[n-1-row][col]=element;
                matrix[n-1-row][n-1-col]=element;
                col++;
                if(col==n/2)
                {
                    col=0;row++;
                }
                itr->se-=4;
                if(itr->se==0)itr++;
            }
            else if(itr->se%2==1 && once==0)
            {
                matrix[n/2][n/2]=itr->fi;
                itr->se--;
                if(itr->se==0)itr++;
                once=1;
            }
            else if(itr->se%2==0)
            {
                if(rowFilled==0)
                {
                    matrix[n/2][rowPtr]=itr->fi;
                    matrix[n/2][n-1-rowPtr]=itr->fi;
                    itr->se-=2;
                    if(itr->se==0)itr++;
                    rowPtr++;
                    if(rowPtr==n/2)rowFilled=1;
                }
                else if(colPtr<n/2)
                {
                    matrix[colPtr][n/2]=itr->fi;
                    matrix[n-1-colPtr][n/2]=itr->fi;
                    colPtr++;
                    itr->se-=2;
                    if(itr->se==0)itr++;
                }
                else
                {
                    valid=0;break;
                }
            }
            else{
                valid=0;break;
            }
        }
    }
    if(valid==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<matrix[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}