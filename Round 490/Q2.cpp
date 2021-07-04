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

vii divisors;
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
void printDivisors(int n) 
{ 
    for(int i=1;i<=sqrt(n);i++) 
    { 
        if(n%i==0) 
        { 
            if(n/i==i)divisors.pb(i);
            else {divisors.pb(i);divisors.pb(n/i);}
        } 
    } 
} 
int32_t main()
{
    FAST;
    int n;cin>>n;
    string s;cin>>s;
    printDivisors(n);
    sort(divisors.begin(),divisors.end());
    for(int i=0;i<divisors.size();i++)
    {
        int num=divisors[i];
        reverse(s.begin(),s.begin()+num);
    }
    cout<<s<<endl;
    return 0;
}