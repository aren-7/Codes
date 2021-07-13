// Given q-queries each query contains value of N (which is n*n matrix) and set of operations such as:
// SET for setting the value of matrix
// SUM for calculating the sum between given range 
// END for ending the process and jumping back to next query
// We need to output the sum corresponding to each SUM query
#include<bits/stdc++.h>
using namespace std;

int fen2d[1025][1025];
int n;
void update2d(int fenNo,int ind,int val)
{
    while(ind<=n)
    {
        fen2d[fenNo][ind]=val;
        ind=ind+(ind & -ind);
    }
}
int sum2d(int fenNo,int ind)
{
    int s=0;
    while(ind>0)
    {
        s+=fen2d[fenNo][ind];
        ind=ind-(ind & (-ind));
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
        // Rewrite the values in fenwick as 0 as previous state wud have left some values
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                fen2d[i][j]=0;
            }
        }
        while(1)
        {
            string s;
            cin>>s;
            if(s=="END") break;
            else if(s=="SET")
            {
                int x,y,val;
                cin>>x>>y>>val;
                x+=1;
                y+=1;
                update2d(x,y,val);
            }
            else
            {
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                x1+=1;
                y1+=1;
                x2+=1;
                y2+=1;
                // Iterate in all fenwick tree from x1 to x2
                // and get the sum of index between y1 & y2
                int s=0;
                for(int i=x1;i<=x2;i++)
                {
                    // get the sum in range [y1.....y2] in ith fenwick tree
                    s+=sum2d(i,y2)-sum2d(i,y1-1);
                }
                cout<<s<<endl;
            }
        }
    }
}
