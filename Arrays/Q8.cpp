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
vii a;
int n;
int inversionCount=0;
void combine(int l1,int r1,int l2,int r2)
{
    int ptr1=l1;int ptr2=l2;
    vii temp;
    while(ptr1<=r1 && ptr2<=r2)
    {
        if(a[ptr1]<=a[ptr2])
        {
            temp.pb(a[ptr1]);ptr1++;
        }
        else if(a[ptr1]>a[ptr2])
        {
            temp.pb(a[ptr2]);ptr2++;
            inversionCount+=(r1-ptr1+1);
        }
    }
   
    while(ptr1<=r1){temp.pb(a[ptr1]);ptr1++;}
    while(ptr2<=r2){temp.pb(a[ptr2]);ptr2++;}
    
    int ind=0;
    for(int i=l1;i<=r2;i++)
    {
        a[i]=temp[ind];
        ind++;
    }
}
void merge(int l,int r)
{
    int middle=l+(r-l)/2;
    
    if(l<middle)
        merge(l,middle);
    
    if(middle+1<r)
        merge(middle+1,r);

    combine(l,middle,middle+1,r);
}
int32_t main()
{
    FAST;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    merge(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}