#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int low=0,high=n-1;
    int fl=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==x)
        {
            fl=mid;
            break;
        }
        else if(x>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(fl==-1) cout<<"Element not present\n";
    else cout<<fl;
    return 0;
}
