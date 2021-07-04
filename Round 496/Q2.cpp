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
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    string s,t;cin>>s>>t;
    int moves=0;
    int minLength=min(s.size(),t.size());
    int sItr=0;int tItr=0;

    sItr=s.size()-minLength;
    tItr=t.size()-minLength;
    moves=sItr+tItr;
    int extra=-1;
    for(int i=0;i<minLength;i++)
    {
        if(s[sItr]!=t[tItr])
        {
            extra=i;
        }
        sItr++;tItr++;
    }
    moves=moves+(extra+1)*2;
    cout<<moves<<endl;
    return 0;
}