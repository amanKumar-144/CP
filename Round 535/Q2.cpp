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
vii divisorList;
void printDivisors(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            if(n/i == i)
            {
                divisorList.pb(i);
            }
            else 
            {
                divisorList.pb(i);
                divisorList.pb(n/i);
            }
        }
    }
}
void solve()
{
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vector<pii>a;//Number,Validity
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(mp(x,1));
    }
    sort(a.begin(),a.end());
    int x=a[a.size()-1].fi;
    printDivisors(x);
    for(int i=0;i<divisorList.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            if(divisorList[i]==a[j].fi)
            {
                a[j].se=0;break;
            }
        }
    }
    int y;
    for(int i=0;i<a.size();i++)
    {
        if(a[i].se==1)y=a[i].fi;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}