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
void getDivisors(int n,set<int> &divisors)
{
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            if(n/i == i)
            {
                divisors.ins(i);
            }
            else
            {
                divisors.ins(i);divisors.ins(n/i);
            }
        }
    }
}
int32_t main()
{
    FAST;
    int num1,num2;cin>>num1>>num2;
    set<int>a,b;
    getDivisors(num1,a);
    getDivisors(num2,b);
    set<int>store;
    for(auto it=a.begin();it!=a.end();it++)
    {
        auto it2=b.find(*it);
        if(it2!=b.end())
        {
            store.ins(*it);
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        auto it=store.lower_bound(r);
        if(*it==r)cout<<r<<endl;
        else if(it==store.end())//Larger than set of numbers
        {
            auto it1=store.rbegin();
            if(*it1>=l)cout<<*it1<<endl;
            else cout<<-1<<endl;
        }
        else if(it==store.begin())
        {
            if(*it>=l)cout<<*it<<endl;
            else cout<<-1<<endl;
        }
        else{
            it--;
            if(*it>=l)cout<<*it<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}