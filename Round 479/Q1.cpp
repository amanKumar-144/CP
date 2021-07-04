#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main()
{
    FAST;
    int n,k;
    cin>>n>>k;
    while(k--)
    {
        if(n%10!=0)n--;
        else n/=10;
    }
    cout<<n<<endl;
    return 0;
}