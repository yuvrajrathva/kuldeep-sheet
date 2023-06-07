#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.length() <= 10)
        {
            vector<string> output;

            return output;
        }
        else
        {
            unordered_map<char, int> s_mapCode = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
            vector<int> s_inCode;
            unordered_set<long long> hashcodes;
            unordered_set<string> output_set;

            for (int i = 0; i < s.length(); i++)
            {
                s_inCode.push_back(s_mapCode[s[i]]);
            }

            long long hashcode = 0;
            for (int i = 0; i < s_inCode.size() - 9; i++)
            {
                if (i == 0)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        hashcode = hashcode + s_inCode[j] * pow(4, 9 - j);
                    }
                }
                else
                {
                    // cout<<hashcode<<endl;
                    hashcode = (hashcode - (s_inCode[i - 1] * pow(4, 9))) * 4 + s_inCode[i + 9];
                }
                if (hashcodes.find(hashcode) != hashcodes.end())
                {
                    output_set.insert(s.substr(i, 10));
                }
                hashcodes.insert(hashcode);
            }

            // unordered_set<long long>::iterator itr2;
            // for(itr2 = hashcodes.begin();itr2 != hashcodes.end();itr2++){
            //     cout<<*itr2<<endl;
            // }
            // cout<<"END"<<endl;
            vector<string> output;
            unordered_set<string>::iterator itr;
            for (itr = output_set.begin(); itr != output_set.end(); itr++)
            {
                output.push_back(*itr);
            }
            return output;
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    vector<string> result = sol.findRepeatedDnaSequences(s);
    for (const string &pattern : result)
    {
        cout << pattern << endl;
    }
    return 0;
}

// Other method

// class Solution
// {
// public:
//     vector<string> findRepeatedDnaSequences(string s)
//     {
//         unordered_map<char, long long> ump = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
//         long long hs = 4, hsl = pow(hs, 10);
//         long long n = s.length();
//         vector<long long> num;
//         for (long long i = 0; i < n; i++)
//         {
//             num.push_back(ump[s[i]]);
//         }
//         unordered_set<string> stringSet;
//         unordered_set<long long> hashSet;

//         long long h = 0;
//         for (long long i = 0; i < n - 10 + 1; i++)
//         {
//             if (i == 0)
//             {
//                 for (long long j = 0; j < 10; j++)
//                 {
//                     h = h + num[j] * pow(hs, 10 - 1 - j);
//                 }
//             }
//             else
//             {
//                 h = h * hs - num[i - 1] * hsl + num[i + 10 - 1];
//             }

//             if (hashSet.find(h) != hashSet.end())
//             {
//                 //   cout<<s.substr(i,i+10)<<endl;
//                 stringSet.insert(s.substr(i, 10));
//             }
//             // cout<<h<<endl;
//             hashSet.insert(h);
//         }
//         vector<string> v;
//         unordered_set<string>::iterator itr;
//         for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
//             v.push_back(*itr);
//         return v;
//     }
// };

// int main()
// {
//     string s;
//     cin >> s;
//     Solution sol;
//     vector<string> result = sol.findRepeatedDnaSequences(s);
//     for (const string &pattern : result)
//     {
//         cout << pattern << endl;
//     }
//     // cout << result.size();
//     return 0;
// }