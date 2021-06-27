#include<bits/stdc++.h>
using namespace std;
int fen[100005],a[100005];
int n;

void update(int ind,int val)
{
    while(ind<=n)
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
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int ind,val;
            cin>>ind>>val;
            update(ind,val-a[ind]);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
    }
    return 0;
}
