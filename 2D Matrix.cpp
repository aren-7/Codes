// In 2-D Matrix find sum between given indices of matrix in q-queries.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    // Taking input of 2D-Matrix!
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int q;
    cin>>q;
    // In each query computing the sum between the given range!
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int sum=0;
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                sum+=a[i][j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
// Time complexity is q*n*m!
