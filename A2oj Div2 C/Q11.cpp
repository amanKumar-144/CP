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
int32_t main()
{
    FAST;
    string s;cin>>s;
    int n=s.size();
    string ans;
    
    for(int i=0;i<n;i++)
    {
        if(i+2<n && s[i]==s[i+1] && s[i+1]==s[i+2])
        {
           continue;
        }
        else
        {
            ans+=s[i];
        }
    }
    string finalAns;
    n=ans.size();
    for(int i=0;i<n;i++)
    {
        if(i+3<n && ans[i]==ans[i+1] && ans[i+2]==ans[i+3])
        {
            finalAns+=ans[i];finalAns+=ans[i+1];finalAns+=ans[i+2];
            i=i+3;
        }
        else finalAns+=ans[i];
    }
    cout<<finalAns<<endl;
    return 0;
}