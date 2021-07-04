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
void printInc(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
void printDec(vii &a)
{
    int size=a.size();
    for(int i=size-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    map<int,int>freq;

    int valid=1;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        auto itr=freq.find(x);
        if(itr==freq.end())freq.ins(mp(x,1));
        else 
        {
            itr->se++;
            if(itr->se > 2)valid=0;
        }
    }


    if(valid==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        vii inc;
        vii dec;
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            if(it->se==1)inc.pb(it->fi);
            else if(it->se==2)
            {
                inc.pb(it->fi);
                dec.pb(it->fi);
            }
        }
        cout<<inc.size()<<endl;
        printInc(inc);
        cout<<dec.size()<<endl;
        printDec(dec);
    }
    return 0;
}