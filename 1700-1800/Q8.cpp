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
#define endl "\n"
using namespace std;

int32_t main()
{
    FAST;
    string a;string b;
    cin>>a;
    cin>>b;
    int dest=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='+')dest++;
        else dest--;
    }
    int n=a.length();
    

    //+ ->1
    //- ->0
    //? ->1,0
    double totalPaths=0;
    double possiblePaths=0;

    for(int i=0;i<(1<<n);i++)
    {
        int dist=0;
        int valid=1;
        for(int index=0;index<n;index++)
        {
            if(valid==0)break;

            if( (i&(1<<index)) ) //1 located
            {
                if(b[index]=='+' || b[index]=='?')
                {
                    dist++;
                }
                else valid=0;
            }
            else //0 located
            {
                if(b[index]=='-' || b[index]=='?')
                {
                    dist--;
                }
                else valid=0;
            }
        }
        if(valid==1)
        {
            totalPaths++;
            if(dest==dist)possiblePaths++;
        }
    }
   
    double ans=(double)possiblePaths/totalPaths;
    cout<<setprecision(12)<<ans<<endl;
    return 0;
}