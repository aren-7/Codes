// For each query print the sum between l & r in an array of n-integers.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    // Constructing Prefix-Sum array!
    int prefix[n];
    for(int i=0;i<n;i++)
    {
        if(i==0) prefix[i]=a[i];
        else
        {
            prefix[i]=prefix[i-1]+ a[i];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        // If every element from starting are included!
        int sum=prefix[r];
        // If sum elements from starting arae skipped!
        if(l>0)
        {
            sum-=prefix[l-1];
        }
        cout<<sum<<endl;;
    }
    return 0;
}
