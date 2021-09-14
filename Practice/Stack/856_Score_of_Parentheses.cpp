/*
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Input: s = "(())"
Output: 2
Input: s = "(()(()))"
Output: 6
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c : s){
            if(c == '(')
                st.push(0);
            else{
                int v = st.top(); st.pop();
                int w = st.top(); st.pop();
                st.push(w + max(2*v, 1));
            }
        }
        return st.top();
    }
};