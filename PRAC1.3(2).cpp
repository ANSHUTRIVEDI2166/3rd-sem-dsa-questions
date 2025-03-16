#include<iostream>
using namespace std;

int Binarysearch(int arr[],int left,int right,int x)
{

    while(left<=right)

    {
        int mid = (left+right)/2;

        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[mid]<x)
        {
            left=mid+1; //(right-left)/2+left
        }else
        {
            right=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[10];
    cout<<"Enter 10 Elements"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"input element at index  "<<i<<endl;
        cin>>arr[i];
    }
    int n= sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"enter the number you want to find"<<endl;
    cin>>x;

    int result = Binarysearch(arr,0,n-1,x);
    {
        (result == -1) ? cout<<"not found" : cout<<" Elemnt is at index number " << result;
    }
}

