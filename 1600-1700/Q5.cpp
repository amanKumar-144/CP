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
    int ans=1;
    string s;cin>>s;
    int lastDigit;

    if(s[1]=='0')lastDigit=0;
    else lastDigit=1;

    int presentDigit;
    for(int i=2;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='0')presentDigit=0;
        else presentDigit=1;

        if(presentDigit==lastDigit)ans++;
        
        if(s[1]=='0')presentDigit=0;
        else presentDigit=1;
        lastDigit=presentDigit;
    }
    cout<<ans<<endl;
    return 0;
}