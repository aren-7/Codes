// In this we are not using any inbult function
// An array is given and we need to find all possible combinations of that array.
// Time complexity of this approch is O(n!)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void solve(vector<int> &nums, int idx)
{
    if(idx==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++)
    {
        swap(nums[i],nums[idx]);
        solve(nums,idx+1);
        swap(nums[i],nums[idx]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    solve(nums,0);
    for(auto it:ans)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
