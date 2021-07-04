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
const int N=200001;
int dp[N][3];//R,G,B
int colourPos[N][3];//Store next colour
int32_t main()
{
    FAST;
    for(int i=0;i<N;i++)
    {
        dp[i][0]=-1;
        dp[i][1]=-1;
        dp[i][2]=-1;
    }

    int n;cin>>n;
    string s;cin>>s;

    dp[n-1][0]=1;dp[n-1][1]=1;dp[n-1][2]=1;

    if(s[n-1]=='R')dp[n-1][0]=0;
    else if(s[n-1]=='G')dp[n-1][1]=0;
    else if(s[n-1]=='B')dp[n-1][2]=0;

    for(int i=n-2;i>=0;i--)
    {
        if(dp[i+1][1]<dp[i+1][2])
        {
            colourPos[i][0]=1;
        }
        else colourPos[i][0]=2;

        if(dp[i+1][0]<dp[i+1][2])
        {
            colourPos[i][1]=0;
        }
        else colourPos[i][1]=2;

        if(dp[i+1][0]<dp[i+1][1])
        {
            colourPos[i][2]=0;
        }
        else colourPos[i][2]=1;

        dp[i][0]=(s[i]!='R')+min(dp[i+1][1],dp[i+1][2]);
        dp[i][1]=(s[i]!='G')+min(dp[i+1][0],dp[i+1][2]);
        dp[i][2]=(s[i]!='B')+min(dp[i+1][0],dp[i+1][1]);
    }
    int ans=min(min(dp[0][0],dp[0][1]),dp[0][2]);
    cout<<ans<<endl;

    vector<int>storeColourIndex;
    if(dp[0][0]==ans)storeColourIndex.pb(0);
    else if(dp[0][1]==ans)storeColourIndex.pb(1);
    else if(dp[0][2]==ans)storeColourIndex.pb(2);

    for(int i=0;i<=n-2;i++)
    {
        int nextColour=colourPos[i][storeColourIndex[i]];
        storeColourIndex.pb(nextColour);
    }
    string hello;
    for(int i=0;i<storeColourIndex.size();i++)
    {
        if(storeColourIndex[i]==0)hello+='R';
        else if(storeColourIndex[i]==1)hello+='G';
        else hello+='B';
    }
    cout<<hello<<endl;
    return 0;
}