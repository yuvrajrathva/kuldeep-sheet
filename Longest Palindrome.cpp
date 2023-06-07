#include <iostream>
#include <unordered_set>
using namespace std;

// class Solution
// {
// public:
//     int longestPalindrome(string s)
//     {
//         int ascii[59] = {0}, count = 0;

//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] != '"')
//             {
//                 ascii[int(s[i]) - 65]++;
//             }
//             // cout<<int(s[i]-65)<<endl;
//         }

//         for (int i = 0; i < 59; i++)
//         {
//             if (ascii[i] != 0)
//             {
//                 count = count + ascii[i] / 2;
//             }
//             // cout<<ascii[i]<<endl;
//         }

//         if (2 * count < s.length())
//         {
//             return (2 * count + 1);
//         }
//         else
//         {
//             return (2 * count);
//         }
//     }
// };

// int main(){
//     string s;
//     cin >> s;
//     Solution sol;
//     cout<<sol.longestPalindrome(s);
//     return 0;
// }



// 2nd Method using hashset
class Solution {
public:
    int function(string s) {
        unordered_set<char> hashset;
        for (int i = 0; i < s.length(); i++) {
            if (hashset.find(s[i]) == hashset.end()) {
                hashset.insert(s[i]);
            } else {
                hashset.erase(s[i]);
            }
        }
        if(hashset.size()!=0){
            return s.length() - hashset.size() + 1;
        }else{
            return s.length() - hashset.size();
        }
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout<<sol.function(s);
    return 0;
}