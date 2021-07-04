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
    string s;cin>>s;
    vector<string>storeString;

    string a1="RGB";string a2="RBG";
    string a3="BGR";string a4="BRG";
    string a5="GBR";string a6="GRB";

    storeString.pb(a1);storeString.pb(a2);storeString.pb(a3);
    storeString.pb(a4);storeString.pb(a5);storeString.pb(a6);

    int divide=n/3;
    string ans;
    int validity=LLONG_MAX;

    for(int i=0;i<storeString.size();i++)
    {
        string x="";
        for(int j=0;j<divide;j++)
        {
            x+=storeString[i];
        }
        for(int j=0;j<n%3;j++)
        {
            x+=storeString[i][j];
        }
        int score=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]!=x[j])score++;
        }
        if(score<validity)
        {
            validity=score;
            ans=x;
        }
    }
    cout<<validity<<endl;
    cout<<ans<<endl;
    return 0;
}