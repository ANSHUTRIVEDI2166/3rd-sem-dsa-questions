#include<iostream>
using namespace std;

int search(int arr[],int n,int x)
{
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,5,6,7,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    int x = 10;

    int result = search(arr,n,x);
    {
        (result == -1) ? cout<<"not found" : cout<<" Elemnt is at index number " << result;
    }
}
