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
vector<int>countingArray(26,0);
void solve()
{
    string s;cin>>s;
    char minValue='z';
    for(int i=0;i<s.size();i++)
    {
        if(minValue>s[i])
        {
            minValue=s[i];
        }
    }
    int n=s.size();
    int totSize=n+(minValue-'a');
    for(int i=0;i<s.size();i++)
    {
        countingArray[s[i]-'a']++;
    }
    int valid=1;
    int val=minValue-'a';
    for(int i=val;i<totSize;i++)
    {
        if(countingArray[i]==1)valid=1;
        else
        {
            valid=0;break;
        }
    }
    if(valid==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    for(int i=0;i<26;i++)countingArray[i]=0;
}
int32_t main()
{
    FAST;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}