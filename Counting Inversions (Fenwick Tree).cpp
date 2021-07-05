// Given an array you need to find number of inversions.
// Time complexity is O(nlog(n))
// It is taking same time complexity as using Merge sort algorithm but here recursion is not there thus saving heap and stack space.

#include<bits/stdc++.h>
using namespace std;
int fen[10000005], freq[10000005],a[2*100004];
int n,maxi;
void update(int ind,int val)
{
    while(ind<=maxi)
    {
        fen[ind]+=val;
        ind=ind+(ind&(-ind));
    }
}
int sum(int ind)
{
    int s=0;
    while(ind>0)
    {
        s+=fen[ind];
        ind=ind-(ind&(-ind));
    }
    return s;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxi=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxi=max(maxi,a[i]);
        }
        for(int i=1;i<=maxi;i++)
        {
            fen[i]=freq[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            freq[a[i]]++;
            update(a[i],1);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            freq[a[i]]--;
            update(a[i],-1);
            cnt+=sum(a[i]-1);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
