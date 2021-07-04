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
        cout<<a[i];
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;string s;
    cin>>n>>s;

    vii a;
    int countZero=0;
    int countOne=0;
    int countTwo=0;
    int required=n/3;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'){a.pb(0);countZero++;}
        else if(s[i]=='1'){a.pb(1);countOne++;}
        else {a.pb(2);countTwo++;}
    }
    if(countZero<required)
    {
        for(int i=0;i<a.size();i++)
        {
            if(countZero==required)break;
            if(a[i]==1 && countOne>required)
            {
                countZero++;a[i]=0;countOne--;
            }
            else if(a[i]==2 && countTwo>required)
            {
                countZero++;a[i]=0;countTwo--;
            }
        }
    }
    if(countTwo<required)
    {
        for(int i=a.size()-1;i>=0;i--)
        {
            if(countTwo==required)break;
            if(a[i]==1 && countOne>required)
            {
                a[i]=2;countOne--;countTwo++;
            }
            else if(a[i]==0 && countZero>required)
            {
                a[i]=2;countZero--;countTwo++;
            }
        }
    }
    if(countOne<required)
    {
        for(int i=0;i<a.size();i++)
        {
            if(countOne==required)break;
            if(a[i]==2 && countTwo>required)
            {
                a[i]=1;countOne++;countTwo--;
            }
        }
        for(int i=a.size()-1;i>=0;i--)
        {
            if(countOne==required)break;
            if(a[i]==0 && countZero>required)
            {
                a[i]=1;countZero--;countOne++;
            }
        }
    }
  
    print(a);
    return 0;
}