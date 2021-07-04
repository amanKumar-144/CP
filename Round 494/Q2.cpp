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
void print(vii &a)
{
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
}
int32_t main()
{
    FAST;
    //a->zero,b->one
    int a,b,x;cin>>a>>b>>x;
    vii hello;
    
    int storeChanges=x;
    if(storeChanges>1)
    {
        storeChanges--;
        hello.pb(1);b--;
        hello.pb(0);a--;
    }

    int lastDigit=0;
    while(storeChanges>1)
    {
        if(lastDigit==0)
        {
            lastDigit=1;
            hello.pb(1);b--;
            storeChanges--;
        }
        else if(lastDigit==1)
        {
            lastDigit=0;
            hello.pb(0);a--;
            storeChanges--;
        }
    }
    //Now storeChanges=1
    vii top;
    if(lastDigit==0)
    {
        if(b>=1)
        {
            while(a--)hello.pb(0);
            while(b--)hello.pb(1);
        }
        else if(b==0)
        {
            while(a--)top.pb(0);
        }
    }
    else if(lastDigit==1)
    {
        while(b--)hello.pb(1);
        while(a--)hello.pb(0);
    }
    print(top);print(hello);cout<<endl;
    return 0;
}