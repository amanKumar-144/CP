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
    int n,m;cin>>n>>m;
    int moves=0;
    int valid=1;
    if(m%n!=0)valid=0;
    else if(m==n)moves=0;
    else
    {
        int gap=m/n;
        while(gap%2==0)
        {
            gap=gap/2;
            moves++;
        }
        while(gap%3==0)
        {
            gap=gap/3;
            moves++;
        }
        if(gap!=1)valid=0;
    }
    if(valid==0)cout<<-1<<endl;
    else cout<<moves<<endl;
    return 0;
}