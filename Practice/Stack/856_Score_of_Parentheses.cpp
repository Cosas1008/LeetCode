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
    // Stack TimeComplexity O(n) Space O(n)
    int scoreOfParentheses(string s){
        stack<int> stack;
        int cur = 0;
        for(char c : s){
            if(c == '('){
                stack.push(cur);
                cur = 0;
            }else{
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        }
        return cur;
    }
    
    // Optimize 1: Space O(1)
    int scoreOfParentheses(string s){
        int cur = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') cur++; else cur--;
            if(s[i] == ')' && s[i-1] == '(') ans += 1 << cur;
        }
        return ans;
    }

    // Optimize 2: 1 pass
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