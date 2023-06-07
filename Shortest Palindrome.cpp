#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int max = 0;
        string output = "";
        for (int i = 1; i < s.length(); i++)
        {
            int start = 0;
            int end = i;
            while (s[end] == s[start] && start <= end)
            {
                start++;
                end--;
            }
            if (start >= end && i > max)
            {
                max = i;
            }
        }
        for (int i = s.length() - 1; i > max; i--)
        {
            output.push_back(s[i]);
        }
        for (int i = 0; i < s.length(); i++)
        {
            output.push_back(s[i]);
        }
        return output;
    }
};

int main()
{
    string input;
    cin >> input;
    Solution sol;
    cout << sol.shortestPalindrome(input);
    return 0;
}