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
int32_t main()
{
    FAST;
    string s;cin>>s;
    int n=s.size();
    vector<int>storeRem(n,-1);
    vector<int>storeRemBack(n,-1);
    int a,b;cin>>a>>b;

    storeRem[0]=(s[0]-'0')%a;
    for(int i=1;i<n;i++)
    {
        storeRem[i]=(storeRem[i-1]*10+(s[i]-'0'))%a;
    }

    storeRemBack[n-1]=(s[n-1]-'0')%b;
    int prev=10;
    for(int i=n-2;i>=0;i--)
    {
        int val1=storeRemBack[i+1];
        int val2=prev*(s[i]-'0');
        val1%=b;val2%=b;
        storeRemBack[i]=(val1+val2)%b;
        prev*=10;
        prev%=b;
    }


    int ptr1=-1;int ptr2=-1;
    for(int i=0;i<n-1;i++)
    {
        if(storeRem[i]==0 && storeRemBack[i+1]==0 && s[i+1]!='0'){
            ptr1=i;
            ptr2=i+1;
        }
    }
    if(ptr1==-1 && ptr2==-1)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<=ptr1;i++)cout<<s[i];
        cout<<endl;
        for(int i=ptr2;i<n;i++)cout<<s[i];
        cout<<endl;
    }
    return 0;
}