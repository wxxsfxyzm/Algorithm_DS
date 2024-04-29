#include <bits/stdc++.h>
#include <algorithm>
#include "PerformanceMonitor.h"
using namespace std;
class Solution1 {
public:
    string removeDuplicates(string S) {
        PerformanceMonitor pm;
        stack<char> st;
        for (auto s : S) {
            if (st.empty() || s != st.top())
                st.push(s);
            else
                st.pop();
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution2 {
public:
    string removeDuplicates(string S) {
        PerformanceMonitor pm;
        string result;
        for (char s : S) {
            if (result.empty() || result.back() != s) {
                result.push_back(s);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};
int main(int argc, char const* argv[])
{
    Solution1 s1;
    Solution2 s2;
    string s = "abbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbaca";
    s1.removeDuplicates(s);
    s2.removeDuplicates(s);
    return 0;
}
