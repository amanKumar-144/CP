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
    string s;cin>>s;
    vii a;

    for(int i=0;i<s.size();i++){
        if(s[i]=='0')a.pb(0);
        else a.pb(1);
    }

    int moves=0;
    int prev=a[0];
    int count=1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]==prev)
        {
            count++;
        }
        else count=1;
        
        prev=a[i];
        if(count>=7)moves=1;
    }
    if(count>=7)moves=1;
    if(moves==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}