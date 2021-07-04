#include <stdio.h>
#include <stdbool.h>


int majorityElement(int a[], int size)
{
        
    int element=a[0];int count=1;
    for(int i=1;i<size;i++)
    {
        if(a[i]!=element)
        {
            count--;
            if(count==0)
            {
                element=a[i];count=1;
            }
        }
        else count++;
    }
    int check=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==element)check++;
    }
    if(check>size/2)return element;
    else return -1;
}

int main()
{

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
