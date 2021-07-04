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
#define endl "\n"
using namespace std;

int calc(char x,char y)
{
    int ans=min(abs(x-y),min(1+abs(x-'a')+abs('z'-y),1+abs(x-'z')+abs(y-'a')));
    return ans;
}

int32_t main()
{
    FAST;
    int n,p;cin>>n>>p;
    string s;cin>>s;
    p--;

    if(p>=n/2)
    {
        p=n-p-1;
    }

    int changeLeft=p;
    int changeRight=p;
    //Setting the pointers
    for(int i=p;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])changeRight=i;
    }
    for(int i=p;i>=0;i--)
    {
        if(s[i]!=s[n-i-1])changeLeft=i;
    }
    int answer=0;
    if(p!=n-p-1)
    {
        answer=calc(s[p],s[n-p-1]);
    }
    
    //Go Right
    int rightMoves=0;int leftMoves=0;
    for(int i=p+1;i<=changeRight;i++)
    {
        rightMoves++;
        char x=s[i];
        char y=s[n-i-1];
        rightMoves+=calc(x,y);
    }
    //Go Left
    for(int i=p-1;i>=changeLeft;i--)
    {
        leftMoves++;
        char x=s[i];
        char y=s[n-i-1];
        leftMoves+=calc(x,y);
    }
    
    answer+=rightMoves+leftMoves+min(changeRight-p,p-changeLeft);
    cout<<answer<<endl;
    return 0;
}