//Given a number you need to find Prime Factorization of number
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1) cout<<n;
    return 0;
}
