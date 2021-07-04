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
    int a,b,c;cin>>a>>b>>c;
    int aReq=3;
    int bReq=2;
    int cReq=2;

    int minWeeks=min(a/aReq,min(b/bReq,c/cReq));
    a=a-minWeeks*aReq;
    b=b-minWeeks*bReq;
    c=c-minWeeks*cReq;
    int ans=0;
    for(int i=0;i<7;i++)
    {
        int count=0;
        int temp=minWeeks*7;
        int a1=a;int b2=b;int c3=c;
        for(int j=i;count<7;count++)
        {
            if(j==0 || j==3 || j==6)a1-=1;
            else if(j==1 || j==5)b2-=1;
            else if(j==2 || j==4)c3-=1;
            j=(j+1)%7;
            if(a1>=0 && b2>=0 && c3>=0)continue;
            else break;
        }
        temp+=(count);
        ans=max(ans,temp);
    }cout<<ans<<endl;
    return 0;
}