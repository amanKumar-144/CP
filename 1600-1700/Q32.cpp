#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int calc(char x,char y)
{
    int dist=100;
    dist=min(abs(y-x),1+min(abs(x-'a')+abs(y-'z'),abs(x-'z')+abs(y-'a')));
    return dist;
}

int32_t main()
{
    FAST;
    int n,p;cin>>n>>p;
    p--;
    string s;cin>>s;
    if(n%2==0)
    {
        if(p>=n/2)p=n-p-1;
    }
    else if(n%2==1)
    {
        if(p>n/2)p=n-p-1;
    }
    //Go left
    int leftPtr=p;int leftChanges=0;
    for(int i=p;i>=0;i--)
    {
        if(s[i]!=s[n-i-1])
        {
            leftChanges+=calc(s[i],s[n-i-1]);
            leftPtr=i;
        }
    }
    //Go right
    int rightPtr=p+1;int rightChanges=0;
    for(int i=p+1;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            rightChanges+=calc(s[i],s[n-i-1]);
            rightPtr=i;
        }
    }
    int goLeft=leftChanges+(p-leftPtr);
    int goRight=rightChanges+(rightPtr-(p+1));

    int ans1=goLeft;
    if(goRight!=0)ans1+=(p-leftPtr)+1+goRight;

    int ans2=goRight;
    if(ans2!=0)ans2++;
    if(goLeft!=0)ans2+=(rightPtr-(p+1))+1+goLeft;
    cout<<min(ans1,ans2)<<endl;

    return 0;
}