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
int32_t main()
{
    FAST;
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        if(s[0]=='X' && s[1]=='+' && s[2]=='+')ans++;
        else if(s[0]=='+' && s[1]=='+' && s[2]=='X')ans++;
        else ans--;
    }
    cout<<ans<<endl;
    return 0;
}