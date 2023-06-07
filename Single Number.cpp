#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                s.erase(nums[i]);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            return *it;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1};

    Solution sol;
    cout << sol.singleNumber(nums);
    return 0;
}