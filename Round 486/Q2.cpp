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
//Check is s1 is substring of s2
int isSubstring(string s1,string s2)
{
    if(s1.size() > s2.size())return 0;
    else 
    {
        //s2 is big string
        for(int i=0;i<s2.size();i++)
        {
            int p=0;
            for(int j=i;j<s2.size();j++)
            {
                if(s1[p]!=s2[j])
                {
                    break;
                }
                p++;
                if(p==s1.size())return 1;
            }
            if(p==s1.size())return 1;
        }
        return 0;
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vector<string>storeStrings;
    vector<pair<int,string>>ans;

    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        storeStrings.pb(s);
    }
    for(int i=0;i<storeStrings.size();i++)
    {
        string check1=storeStrings[i];
        int a=0;
        for(int j=0;j<storeStrings.size();j++)
        {
            string check2=storeStrings[j];
            int valid=isSubstring(check1,check2);
            if(valid==1)a++;
        }
        ans.pb(mp(a,check1));
    }
   
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());

    int valid=1;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].fi<n-i)
        {
            valid=0;
        }
    }
    if(valid==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].se<<endl;
        }
    }
    return 0;
}