// Maximum Subarray sum of size-k.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=k-1;
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=a[i];
    }
    int maxi = sum;
    // Main Sliding Window Logic!
    while(r!=(n-1))
    {
        sum-=a[l];
        l++;
        r++;
        sum+=a[r];
        maxi=max(sum,maxi);
    }
    cout<<maxi;
    return 0;
}
