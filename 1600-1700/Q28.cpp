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
    int n,k;cin>>n>>k;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vii storeSum(n,0);
    int tot=0;
    for(int i=0;i<k;i++)tot+=a[i];

    storeSum[0]=tot;
    for(int i=1;i<n;i++)
    {
        int next=i+k-1;
        if(next>=n)break;
        int newValue=tot-a[i-1]+a[next];
        storeSum[i]=newValue;
        tot=newValue;
    }
    vii backSumMax(n,0);
    backSumMax[n-1]=storeSum[n-1];
    for(int i=n-2;i>=0;i--)backSumMax[i]=max(backSumMax[i+1],storeSum[i]);
    int finalAns=0;
    int index1=-1;int index2=-1;
    for(int i=0;i<n;i++)
    {
        int sum1=storeSum[i];
        int next=i+k;
        if(next>=n)break;
        int sum2=backSumMax[next];
        if(sum1+sum2>finalAns)
        {
            finalAns=sum1+sum2;
            index1=i;
            index2=next;
        }
    }
    for(int i=index2;i<n;i++){
        if(storeSum[i]==backSumMax[index2])
        {
            index2=i;break;
        }
    }
   
    cout<<index1+1<<" "<<index2+1<<endl;
    return 0;
}