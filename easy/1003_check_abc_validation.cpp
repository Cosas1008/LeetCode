class Solution {
public:
    struct Count{
        char character;
        int count;
    };
    bool isValid(string S) {
        Count a,b,c;
        a.count = b.count = c.count = 0;
        for(int i = 0 ; i < S.length(); i++)
        {
            char tmp = S[i];
            switch(tmp){
                case 'a':
                    a.count++;
                    break;
                case 'b':
                    b.count++;
                    break;
                case 'c':
                    c.count++;
                    break;
                default:
                    break;
            }
            if(a.count < b.count || b.count < c.count) return 0;
        }
        cout << "a: " << a.count << " b: " << b.count << " c: " << c.count << endl;
        if(a.count != b.count || a.count != c.count) return 0;
        return 1;
    }
};