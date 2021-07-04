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
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    while(n>0)
    {
        a.pb(n%10);
        n=n/10;
    }
    reverse(a.begin(),a.end());
    n=a.size();
    int validity=0;
    int zero=0;int two=0;int five=0;int seven=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==0)zero++;
        else if(a[i]==2)two++;
        else if(a[i]==5)five++;
        else if(a[i]==7)seven++;
    }
    if(zero>=2 || (two>=1 && five>=1) || (five>=1 && zero>=1) || (seven>=1 && five>=1))validity=1;
    if(validity==0)cout<<-1<<endl;
    else 
    {
        int zeroInd1=-1;int zeroInd2=-1;int twoInd=-1;int fiveInd=-1;int sevenInd=-1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==2)twoInd=i;
            else if(a[i]==5)fiveInd=i;
            else if(a[i]==7)sevenInd=i;
            //First zero
            else if(a[i]==0 && zeroInd1==-1)zeroInd1=i;
            //Two zeros
            else if(a[i]==0 && zeroInd1!=-1 && zeroInd2==-1)zeroInd2=i;
            else if(a[i]==0 && zeroInd1!=-1 && zeroInd2!=-1){
                zeroInd1=zeroInd2;
                zeroInd2=i;
            }
        }
        //Check formation of 00
        int ans=LLONG_MAX;
        if(zeroInd1!=-1 && zeroInd2!=-1)
        {
            ans=min(ans,n-1-zeroInd2 + n-2-zeroInd1);
        }
        //Check formation of 25
        if(twoInd!=-1 && fiveInd!=-1)
        {
            int addExtra=0;
            for(int i=0;i<a.size();i++)
            {
                if(i!=twoInd && i!=fiveInd && a[i]!=0){addExtra=i;break;}
            }
            int temp=n-1-fiveInd;temp+=addExtra;
            temp+=n-2-twoInd;
            if(fiveInd<twoInd)temp++;
            if(fiveInd<addExtra)temp--;
            if(twoInd<addExtra)temp--;
            ans=min(ans,temp);
        }
        //Check formation of 75
        if(sevenInd!=-1 && fiveInd!=-1)
        {
            int addExtra=0;
            for(int i=0;i<a.size();i++)
            {
                if(i!=sevenInd && i!=fiveInd && a[i]!=0){addExtra=i;break;}
            }
            int temp=n-1-fiveInd;temp+=addExtra;
            temp+=n-2-sevenInd;
            if(fiveInd<sevenInd)temp++;
            if(fiveInd<addExtra)temp--;
            if(sevenInd<addExtra)temp--;
            ans=min(ans,temp);
        }
        //Check formation of 50
        if(fiveInd!=-1 && zeroInd1!=-1)
        {
            int zeroIndex=zeroInd1;
            if(zeroInd2!=-1)zeroIndex=zeroInd2;
            int addExtra=0;
            for(int i=0;i<a.size();i++)
            {
                if(i!=fiveInd && a[i]!=0){addExtra=i;break;}
            }
            int temp=n-1-zeroIndex;temp+=addExtra;
            temp+=n-2-fiveInd;
            if(zeroIndex<fiveInd)temp++;
            if(fiveInd<addExtra)temp--;
            if(zeroIndex<addExtra)temp--;
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}