// Given array you need to find count of triple inversion i.e i<j<k; a[i]>a[j]>a[k]
#include<bits/stdc++.h>
using namespace std;

int leftFen[100005],rightFen[100005];
void updateLeft(int ind,int val)
{
    while(ind<=100004)
    {
        leftFen[ind]+=val;
        ind=ind+(ind & -ind);
    }
}
int sumLeft(int ind)
{
    int s=0;
    while(ind>0)
    {
        s+=leftFen[ind];
        ind=ind-(ind & -ind);
    }
    return s;
}
void updateRight(int ind,int val)
{
    while(ind<=100004)
    {
        rightFen[ind]+=val;
        ind=ind+(ind & -ind);
    }
}
int sumRight(int ind)
{
    int s=0;
    while(ind>0)
    {
        s+=rightFen[ind];
        ind=ind-(ind & -ind);
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int leftFreq[100005]={0};
    int rightFreq[100005]={0};
    for(int i=1;i<=n;i++) 
    {
        rightFreq[a[i]]++;
        updateRight(a[i],1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        leftFreq[a[i]]++;
        updateLeft(a[i],+1);
        rightFreq[a[i]]--;
        updateRight(a[i],-1);

        // >a[i] get the element in the range (a[i+1]....10000)
        int c1=sumLeft(100000)-sumLeft(a[i]);
        // <a[i] get the element in the range (0....a[i-1])
        int c2=sumRight(a[i]-1);
        cnt+=c1*c2;
    }
    cout<<cnt<<endl;
}
