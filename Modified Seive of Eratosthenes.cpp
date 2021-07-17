//MODIFIED SEIVE OF ERATOSTHENES
//Given q-queries each containing a number you need to find the prime factorization of that number
#include<bits/stdc++.h>
using namespace std;

int N=1000001;
int prime[1000001];
void modified_seive()
{
    for(int i=0;i<N;i++) prime[i]=i;
    for(int i=2;i*i<N;i++)
    {
        if(prime[i]==i)
        {
            for(int j=i*i;j<N;j+=i)
            {
                if(prime[j]==j)
                {
                    prime[j]=i;
                }
            }
        }
    }
}

int main()
{
    int q;
    cin>>q;
    modified_seive();
    while(q--)
    {
        int n;
        cin>>n;
        while(prime[n]!=1)
        {
            cout<<prime[n]<<"*";
            n=n/prime[n];
        }
        cout<<1<<endl;;
    }
    return 0;
}
