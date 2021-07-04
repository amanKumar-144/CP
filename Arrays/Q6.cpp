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
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    int maxElement=INT_MAX;
    int maxIndex=n-1;int minIndex=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)//Max Element
        {
            a[i]=a[i]+(a[maxIndex]%maxElement)*maxElement;
            maxIndex--;
        }
        else{
            a[i]=a[i]+(a[minIndex]%maxElement)*maxElement;
            minIndex++;
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]/maxElement;
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}