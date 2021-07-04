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
const int N=1e6+1;
vii counting(N,0);
vii a;vii b;
int n,m;
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}
void merge()
{
    int ptr1=0;
    int ptr2=0;
    int ptr3=n-1;
    int size1=n;
    int size2=m;
    while(ptr1<=ptr3 && ptr2<=m-1)
    {
        if(a[ptr1]<b[ptr2])
        {
            ptr1++;
        }
        else if(a[ptr1]==b[ptr2])
        {
            ptr1++;ptr2++;
        }
        else if(a[ptr1]>b[ptr2])
        {
            int store=a[ptr3];
            a[ptr3]=b[ptr2];
            b[ptr2]=store;
            ptr3--;
            ptr2++;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    print(a);
    print(b);
    cout<<endl;
}
int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        b.pb(x);
    }
    merge();
    return 0;
}