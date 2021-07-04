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

bool isPrime(int n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if(n % 2 == 0 || n % 3 == 0)
        return false;
 
    for(int i = 5; i * i <= n; i = i + 6)
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

bool isThreeDisctFactors(long long n)
{
    int sq = (int)sqrt(n);
    if (sq*sq!=n)
        return false;

    return isPrime(sq) ? true : false;
}

int32_t main()
{
    FAST;
    int n;cin>>n;
    vii num;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        num.pb(x);
    }
    vector<string>ans;
    for(int i=0;i<num.size();i++)
    {
        if(isThreeDisctFactors(num[i]))ans.pb("YES");
        else ans.pb("NO");
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}