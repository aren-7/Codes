// In 2-D Matrix find sum between given indices of matrix in q-queries using PREFIX SUM.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int prefix[n][m];
    // Taking input of 2D Matrix!
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    // Forming 2D Prefix array of given matrix!
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) prefix[i][j]=a[i][j];
            else if(i==0) prefix[i][j]=a[i][j]+prefix[i][j-1];
            else if(j==0) prefix[i][j]=a[i][j]+prefix[i-1][j];
            else
            {
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+a[i][j]-prefix[i-1][j-1];
            }
        }
    }
    int q;
    cin>>q;
    // In each query computing the sum between ranges using precomputed prefix array!
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int sum=prefix[x2][y2];
        if(x1>0) sum-=prefix[x1-1][y2];
        if(y1>0) sum-=prefix[x2][y1-1];
        if(x1>0 && y1>0) sum+=prefix[x1-1][y1-1];
        cout<<sum<<endl;
    }
    return 0;
}
