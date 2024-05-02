#include <bits/stdc++.h>
#include "../../../PerformanceMonitor.h"
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        PerformanceMonitor pm;
        if (s.size() % 2 == 1) return false; // 如果字符串长度为奇数，直接返回 false
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if (st.empty()) return false;
                if (ch == ')' && st.top() != '(') return false;
                if (ch == ']' && st.top() != '[') return false;
                if (ch == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

class OtherSolution {
public:
    bool isValid(string s) {
        PerformanceMonitor pm;
        if (s.size() % 2 != 0)
            return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(')');
            else if
                (s[i] == '{') st.push('}');
            else if
                (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i])
                return false;
            else
                st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};

int main(int argc, char const* argv[])
{
    Solution s;
    OtherSolution os;
    string str;
    cout << "String: ";
    cin >> str;
    cout << "代码 1：" << endl;
    if (s.isValid(str))
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    cout << "代码 2：" << endl;
    if (os.isValid(str))
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    return 0;
}

