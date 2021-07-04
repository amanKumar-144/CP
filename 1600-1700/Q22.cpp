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

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    if(n <= 3)
        return true;
 
    if(n % 2 == 0 || n % 3 == 0)
        return false;
 
    for(int i = 5; i * i <= n; i = i + 6)
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
bool checkFunction(int x)
{
    int sqt=sqrt(x);
    if(sqt*sqt==x)
    return isPrime(sqt);
    else return false;
}
void print(vector<string>&a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vector<string>ans;
    for(int i=0;i<a.size();i++)
    {
        bool check=checkFunction(a[i]);
        if(check==true)ans.pb("YES");
        else ans.pb("NO");
    }
    print(ans);
    return 0;
}