#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> output(n, 0);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                output[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return output;
    }
};

int main()
{
    vector<int> temperatures = {30,40,50};

    Solution sol;
    vector<int> ans = sol.dailyTemperatures(temperatures);
    // sol.dailyTemperatures(temperatures);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}