//Give q-queries each contaning a number you need to tell if that is prime or not
#include<bits/stdc++.h>
using namespace std;

int prime[1000001];
int N=1000001;
void seive()
{
    for(int i=2;i<N;i++) prime[i]=1;
    for(int i=2;i*i<N;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<N;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int main()
{
    int q;
    cin>>q;
    seive();
    while(q--)
    {
        int n;
        cin>>n;
        if(prime[n]==1) cout<<"Prime number"<<endl;
        else cout<<"Not Prime"<<endl;
    }
    return 0;
}
