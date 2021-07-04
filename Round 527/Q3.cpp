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
    vector<pair<string,int>>storeString[n];
    
    for(int i=1;i<=2*n-2;i++)
    {
        string s;cin>>s;
        storeString[s.size()].pb(mp(s,i-1));
    }
    //4 strings possible
    //4(1)1(1)  4(1)1(2)  1(1)4(1) 1(2)4(1)
    vector<string>a;
    vector<int>valid;
    a.pb(storeString[n-1][0].fi+storeString[1][0].fi);valid.pb(1);
    a.pb(storeString[n-1][0].fi+storeString[1][1].fi);valid.pb(1);
    a.pb(storeString[1][0].fi+storeString[n-1][0].fi);valid.pb(1);
    a.pb(storeString[1][1].fi+storeString[n-1][0].fi);valid.pb(1);
    for(int i=0;i<4;i++)
    {
        string mainString=a[i];
        //cout<<"The mainString is "<<mainString<<endl;
        for(int j=1;j<=n-1;j++)
        {
            string pp=storeString[j][0].fi;
            string qq=storeString[j][1].fi;

            string checkPrefix=mainString.substr(0,j);
            string checkSuffix=mainString.substr(n-j,j);
            //cout<<"The prefix and suffix are "<<checkPrefix<<" and "<<checkSuffix<<endl;
            if( (pp==checkPrefix && qq==checkSuffix) || (pp==checkSuffix && qq==checkPrefix) )
            {
                valid[i]=1;
            }
            else
            {
                valid[i]=0;break;
            }
        }
    }
    string finalStr;
    for(int i=0;i<4;i++)
    {
        if(valid[i]==1){
            finalStr=a[i];
            break;
        }
    }
    //cout<<"The finalStr is "<<finalStr<<endl;

    string ans;
    for(int i=0;i<2*n-2;i++)ans+="a";

    for(int i=1;i<=n-1;i++)
    {
        string pp=storeString[i][0].fi;int ind1=storeString[i][0].se;
        string qq=storeString[i][1].fi;int ind2=storeString[i][1].se;

        string checkPrefix=finalStr.substr(0,i);
        string checkSuffix=finalStr.substr(n-i,i);

        if(pp==checkPrefix && qq==checkSuffix)  
        {
            ans[ind1]='P';
            ans[ind2]='S';
        }
        else if(pp==checkSuffix && qq==checkPrefix)
        {
            ans[ind1]='S';
            ans[ind2]='P';
        }
    }
    cout<<ans<<endl;
    return 0;
}