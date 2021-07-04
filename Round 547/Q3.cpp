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
    for(int i=1;i<=n-1;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vii diffArray;
    diffArray.pb(0);
    for(int i=0;i<n-1;i++)
    {
        diffArray.pb(diffArray[i]+a[i]);
    }
    int index=-1;int valueStart=-1;
    int temp=LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        if(diffArray[i]<temp)
        {
            temp=diffArray[i];
            index=i;
        }
    }
    valueStart=1-diffArray[index];
    vii answerArray;
    for(int i=0;i<n;i++)
    {
        answerArray.pb(valueStart+diffArray[i]);
    }
    vii b=answerArray;
    sort(b.begin(),b.end());
    int valid=1;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]==i+1)continue;
        else valid=0;
    }
    if(valid==0)cout<<-1<<endl;
    else
    print(answerArray);
    return 0;
}