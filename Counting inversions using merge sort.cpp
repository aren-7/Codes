#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv_count=inv_count + (mid-i);
        }
    }
    while(i <= mid-1)
    {
        temp[k++]=arr[i++];
    }
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

int _mergeSort(int a[],int temp[],int left,int right)
{
    int mid,inv_count=0;
    if(right > left)
    {
        mid=(right+left)/2;
        inv_count += _mergeSort(a,temp,left,mid);
        inv_count += _mergeSort(a,temp,mid+1,right);

        inv_count += merge(a,temp,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int temp[n];
    int ans=_mergeSort(a,temp,0,n-1);
    cout<<"Number of inversions are: "<<ans;
    return 0;
}
