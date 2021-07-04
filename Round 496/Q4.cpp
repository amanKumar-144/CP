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
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

const int N=200002;
vector<int>storeAns(N,-1);
vii a;
vii cumSum;
vii rem;
vector<int>storeRemIndex[3];

int compute(int start)
{
    int temp=LLONG_MIN;
    for(int i=start;i<a.size();i++)
    {
        int prev=cumSum[i]-cumSum[start]+a[start];
        int add=0;
        if(prev%3==0)add=1;
       
        if(storeAns[i+1]==-1 && i+1<a.size())
        {
            storeAns[i+1]=compute(i+1);
        }
        temp=max(temp,add+storeAns[i+1]);
    }
    storeAns[start]=temp;
    return temp;
}
void compute2()
{
    if(storeRemIndex[0][0]!=-1)storeAns[0]=1;
    else storeAns[0]=0;
    for(int i=1;i<a.size();i++)
    {
        //Add number or not
        //Don't add number
        storeAns[i]=storeAns[i-1];
        //Add number if possible
        int rems=rem[i];
        if(storeRemIndex[rems][i-1]!=-1)
        {
            storeAns[i]=max(storeAns[i],1+storeAns[storeRemIndex[rems][i-1]]);
        }
        int temp=1;
        if(cumSum[i]%3==0)storeAns[i]=max(storeAns[i],temp);
    }
}
int32_t main()
{
    FAST;
    string s;cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        a.pb(s[i]-'0');
    }
    cumSum.pb(a[0]);
    for(int i=1;i<n;i++)
    {
        cumSum.pb(cumSum[i-1]+a[i]);
    }    
    for(int i=0;i<n;i++)
    {
        rem.pb(cumSum[i]%3);
        storeRemIndex[0].pb(-1);
        storeRemIndex[1].pb(-1);
        storeRemIndex[2].pb(-1);
    }
    for(int i=0;i<n;i++)
    {
        if(i-1>=0)
        {
            storeRemIndex[0][i]=storeRemIndex[0][i-1];
            storeRemIndex[1][i]=storeRemIndex[1][i-1];
            storeRemIndex[2][i]=storeRemIndex[2][i-1];
        }
        if(rem[i]==0)storeRemIndex[0][i]=i;
        if(rem[i]==1)storeRemIndex[1][i]=i;
        if(rem[i]==2)storeRemIndex[2][i]=i;
    }
    compute2();
    cout<<storeAns[n-1]<<endl;
    return 0;
}