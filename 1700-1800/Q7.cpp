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
    int one=0;
    int zero=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')zero++;
        else one++;
    }
    int index=-1;
    if(zero==0)index=0;//Only ones
    else
    {
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                index=i;break;
            }
        }
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(i==index)continue;
        else cout<<s[i];
    }cout<<endl;
    return 0;
}