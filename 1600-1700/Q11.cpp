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
    vector<string>store;
    int start=0;
    for(int i=0;i<s.size();i++)
    {
        if(i+2<s.size() && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')i=i+2;
        else
        {
            start=i;break;
        }
    }
    
    string word;
    for(int i=start;i<s.size();i++)
    {
        if(i+2<s.size() && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            i=i+2;
            store.pb(word);
            word="";
        }
        else
        {
            word+=s[i];
        }
    }store.pb(word);
    for(int i=0;i<store.size();i++)
    {
        if(store[i]!="")cout<<store[i]<<" ";
    }cout<<endl;
    return 0;
}