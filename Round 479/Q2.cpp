#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main()
{
    FAST;
    int t;cin>>t;
    string s;cin>>s;
    int ans=0;
    char ans1,ans2;
    for(int i=0;i<t;i++)
    {
        if(i+1==t)break;
        char a1=s[i];
        char a2=s[i+1];
        int temp=0;
        for(int j=i;j<t;j++)
        {
            if(j+1<t && s[j]==a1 && s[j+1]==a2)temp++;
        }
        if(temp>ans)
        {
            ans1=a1;
            ans2=a2;
            ans=temp;
        }
    }
    cout<<ans1<<ans2<<endl;
    return 0;
}