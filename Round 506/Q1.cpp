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
    int n,k;cin>>n>>k;
    string a;cin>>a;
    int p=0;

    int startVertex=0;
    for(int i=1;i<n;i++)
    {
        int size=n-i;
        int valid=1;
        int p=i;
        for(int j=0;j<size;j++)
        {
            if(a[p]==a[j])valid=1;
            else {valid=0;break;}
            p++;
        }
        if(valid==1)
        {
            startVertex=size;
            break;
        }
    }
    string subStr;
    if(startVertex==0)
    {
        subStr=a;
    }
    else
    {   
        for(int i=startVertex;i<n;i++)subStr.pb(a[i]);
    }
    string finalAns;finalAns=a;
    for(int i=1;i<=k-1;i++)
    {
        finalAns+=subStr;
    }
    cout<<finalAns<<endl;
    return 0;
}