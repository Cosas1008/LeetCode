class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int ans = 0;
        int bal = 0;
        for(int i = 0, j = n - 1; i < j; i++){
            bal += s[i] == '['? 1 : -1;
            if(bal < 0){
                for(int k = 0; k >= 0; j--)
                    k += s[j] == ']'? 1 : -1;
                bal = 1;
                ans++;
                swap(s[i], s[j+1]);
            }
        }
        return ans;
    }
    // Stack ( Optimized )
    int minSwaps(string s){
        int stack_size = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '[')
                stack_size++;
            else{
                if(stack_size > 0)
                    stack_size--;
            }
        }
        return (stack_size + 1) / 2;
    }
};