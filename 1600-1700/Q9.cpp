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
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        if(s.size()<=10)cout<<s<<endl;
        else
        {
            int gap=s.size();gap-=2;
            cout<<s[0]<<""<<gap<<""<<s[s.size()-1]<<endl;
        }
    }
    return 0;
}