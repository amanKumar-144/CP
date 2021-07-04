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
    int totalSum=0;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
        totalSum+=x;
    }
    vii forward(n,0);
    vii backward(n,0);

    for(int i=0;i<n;i=i+2)
    {
        if(i==0)forward[i]=a[i];
        else
        {
            forward[i]=forward[i-2]+a[i];
        }
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(i%2==0 && i+2<n)
        {
            backward[i]=backward[i+2]+a[i];
        }
        else if(i%2==0 && i+2>=n)
        {
            backward[i]=a[i];
        }
        if(i%2==1 && i+2<n)
        {
            backward[i]=backward[i+2]+a[i];
        }
        else if(i%2==1 && i+2>=n)
        {
            backward[i]=a[i];
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)//We are removing element at even position
        {
            int leftVal=forward[i]-a[i];
            int rightVal=0;
            if(i+1<n)
                rightVal=backward[i+1];

            int sum=totalSum-a[i]-leftVal-rightVal;
            if(sum==leftVal+rightVal)count++;
        }
        else if(i%2==1)//We are removing element at odd position
        {
            int leftVal=forward[i-1];
            int rightVal=0;
            if(i+2<n)rightVal=backward[i+2];
            int sum=totalSum-a[i]-leftVal-rightVal;
            if(sum==leftVal+rightVal)count++;
        }
    }
    cout<<count<<endl;
    return 0;
}