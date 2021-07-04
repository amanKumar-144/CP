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
map<pii,int>storeFreq;//(num,den)->frequency
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    vii b;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;b.pb(x);
    }
    int extra=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0 && b[i]!=0)continue;
        else if(a[i]==0 && b[i]==0){extra++;continue;}
        int gcdValue=__gcd(abs(a[i]),abs(b[i]));
        int negValue=0;
        if((b[i]>0 && a[i]>0) || (b[i]<0 && a[i]<0))negValue=1;
        int num=abs(b[i])/gcdValue;
        int den=abs(a[i])/gcdValue;
        if(negValue==1)num=-num;
        pii a=mp(num,den);
        auto itr=storeFreq.find(a);
        if(itr==storeFreq.end())storeFreq.ins(mp(a,1));
        else itr->se++;
    }
    int answer=0;
    for(auto it=storeFreq.begin();it!=storeFreq.end();it++)
    {
        answer=max(answer,it->se);
    }
    cout<<answer+extra<<endl;
    return 0;
}