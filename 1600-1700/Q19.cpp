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
    string s1,s2;
    cin>>s1>>s2;

    int finalPos=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='+')finalPos++;
        else finalPos--;
    }

    double num=0;
    double den=1;
    int blanks=0;
    int tempPos=0;

    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]=='?')blanks++;
        else if(s2[i]=='+')tempPos++;
        else tempPos--;
    }
    den=pow(2,blanks);
  
    for(int i=0;i<(1<<blanks);i++)
    {
        int hello=tempPos;
        for(int j=0;j<blanks;j++)
        {
            if((i&(1<<j)))hello++;
            else hello--;
        }
        if(hello==finalPos)
        {
            num++;
        }
    }
    double ans=num/den;
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}