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
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    string s;cin>>s;
    string a="hello";
    int ptr=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==a[ptr])ptr++;
    }
    if(ptr==5)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}