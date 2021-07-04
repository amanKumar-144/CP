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

void printMax(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
    }cout<<endl;
}

void printMin(vii &a)
{
    int size=a.size()-1;
    for(int i=size;i>=0;i--)
    {
        cout<<a[i];
    }cout<<" ";
}

int32_t main()
{
    FAST;
    int length,sum;
    cin>>length>>sum;

    vii number;
    int valid=1;
    int maxNumberPossible=9*length;
    if(length==1 && sum==0){cout<<0<<" "<<0<<endl;return 0;}

    if(sum==0 || sum>maxNumberPossible)valid=0;
    if(valid==0)cout<<-1<<" "<<-1<<endl;
    else
    {
        int count=0;
        while(sum>9)
        {
            number.pb(9);
            sum-=9;
            count++;
        }
        
        if(count+1==length)
        {
            number.pb(sum);
            sum=0;

            printMin(number);
            printMax(number);
        }
        else
        {
            vii store;
            store=number;

            //Get minimum Number
            int firstNum=1;
            int secondNum=sum-1;
            number.pb(secondNum);
            count++;
            while(count+1<length)
            {
                number.pb(0);
                count++;
            }
            number.pb(firstNum);
            printMin(number);
            
            store.pb(sum);
            while(store.size()!=length)store.pb(0);
            for(int i=0;i<store.size();i++)
            {
                cout<<store[i];
            }cout<<endl;
        }
    }
    return 0;
}