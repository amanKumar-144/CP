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
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
    }cout<<endl;
}

int32_t main()
{
    FAST;
    int z;int o;
    cin>>z>>o;

    int zA,oA;int zB,oB;
    zA=z;zB=z;
    oA=o;oB=o;

    int valid=0;
    int correctA=0;int correctB=0;
    vii finalA,finalB;

    //Build 010101
    vii first;
    while(zA>0 && oA>0)
    {
        first.pb(0);first.pb(1);
        zA--;oA--;
    }
    if(oA==0 && zA==0)
    {
        correctA=1;
        finalA=first;
    }
    else if(oA==0 && zA==1)
    {
        first.pb(0);
        zA--;
        correctA=1;
        finalA=first;
    }
    else if(oA==0 && zA>1)
    {
        correctA=0;
    }
    else if(oA!=0 && zA==0)
    {
        finalA.pb(1);oA--;
        if(oA>0){finalA.pb(1);oA--;}
        int p=0;
        while(oA>0 && p<first.size())
        {
            finalA.pb(first[p]);
            if(first[p]==0){
                finalA.pb(1);oA--;
            }
            p++;
        }
        if(oA==0)correctA=1;
        while(p<first.size()){
            finalA.pb(first[p]);p++;
        }
    }




    //Build 101010
    vii second;
    while(zB>0 && oB>0)
    {
        second.pb(1);second.pb(0);
        zB--;oB--;
    }
    if(oB==0 && zB==0)
    {
        correctB=1;
        finalB=second;
    }
    else if(oB==0 && zB==1)
    {
        zB--;
        correctB=1;
        finalB.pb(0);
        for(int i=0;i<second.size();i++){
            finalB.pb(second[i]);
        }
    }
    else if(oB==0 && zB>1)
    {
        correctB=0;
    }
    else if(oB>1 && zB==0)
    {
        int p=0;
        while(oB>0 && p<second.size())
        {
            finalB.pb(second[p]);
            if(second[p]==1)
            {
                finalB.pb(1);
                oB--;
            }
            p++;
        }
        if(oB==0)correctB=1;
        while(p<second.size()){
            finalB.pb(second[p]);p++;
        }
    }

    if(correctA==1)
        print(finalA);
    else if(correctB==1)
        print(finalB);
    else cout<<-1<<endl;
    return 0;
}