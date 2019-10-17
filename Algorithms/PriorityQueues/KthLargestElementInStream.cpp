#include<iostream>
using namespace std;

void findKthLargest(int arr[],int n,int k)
{
    int temp[k]={0};
    for(int i=0;i<n;i++)
    {
        if(temp[0]<arr[i])
        {
            temp[0]=arr[i];
            for(int j=0;j<k-1;j++)
                for(int z=0;z<k-1-j;z++)
                    if(temp[z]>temp[z+1])
                    {
                        int t=temp[z];
                        temp[z]=temp[z+1];
                        temp[z+1]=t;
                    }
        }
        if(i<k-1)
            cout<<arr[0]<<" ";
        else
            cout<<temp[0]<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    cout<<"Enter array elements : ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Enter Kth largest : ";
    cin>>k;
    findKthLargest(arr,n,k);
}
