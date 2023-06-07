#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> b(n);
        return b.count();
    }
};

int main(){
    uint32_t n = 11111111111111111111111111111101;
    Solution sol;

    cout << sol.hammingWeight(n); 
    return 0;
}