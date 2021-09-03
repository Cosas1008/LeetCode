/*
Input: arr = [3,5,1,2,4], m = 1
Output: 4
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "00101", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "11101", groups: ["111", "1"]
Step 5: "11111", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.
*/
class Solution
{
public:
    int findLatestStep(vector<int>& A, int m) {
        int res = -1;
        int n = A.size();
        vector<int> length(n+2), count(n+1);
        for(int i = 0; i < n; i++){
            int a = A[i];
            int left = length(a-1);
            int right = length(a+1);
            length[a] = length[a - left] = length[a + right] = left + right + 1;
            count[left]--;
            count[right]--;
            count[length[a]]++;
            if(count[m])
                res = i+1;
            cout << "Length" <<  endl;
            for(int i = 0; i < n; i++)
                count << length[i] << " ";
            cout << endl;
            for(int i = 0; i < n; i++)
                count << count[i] << " ";
            cout << endl;
        }
        return res;  
    }
};

/*
    arr = [3,5,1,2,4]
    initial len = [0,0,0,0,0,0,0] 
    initial cnt = [0,0,0,0,0,0] 
    
    Step 1:
    a = 3, left = 0 right = 0      //int a = arr[i], left = length[a - 1], right = length[a + 1];
    len = [0,0,0,1,0,0,0]         //length[a] = length[a - left] = length[a + right] = left + right + 1;
    cnt = [-2,1,0,0,0,0]         // count[left]--;   count[right]--; count[length[a]]++;
    res = 1                     // if (count[m]) res = i + 1;
    
    Step 2:
    a = 5, left = 0 right = 0       //int a = arr[i], left = length[a - 1], right = length[a + 1];
    len = [0,0,0,1,0,1,0]          //length[a] = length[a - left] = length[a + right] = left + right + 1;
    cnt = [-4,2,0,0,0,0]          // count[left]--;   count[right]--; count[length[a]]++;
    res = 2                      // if (count[m]) res = i + 1;
    
    Step 3:
    a = 1, left = 0 right = 0           //int a = arr[i], left = length[a - 1], right = length[a + 1];
    len = [0,1,0,1,0,1,0]              //length[a] = length[a - left] = length[a + right] = left + right + 1;
    cnt = [-6,3,0,0,0,0]              // count[left]--;   count[right]--; count[length[a]]++;
    res = 3                          // if (count[m]) res = i + 1;
    
    Step 4:
    a = 2, left = 1 right = 1       //int a = arr[i], left = length[a - 1], right = length[a + 1];
    len = [0,3,3,3,0,1,0]          //length[a] = length[a - left] = length[a + right] = left + right + 1;
    cnt = [-6,1,0,1,0,0]          // count[left]--;   count[right]--; count[length[a]]++;
    res = 4                      // if (count[m]) res = i + 1;
    
    Step 5:
    a = 4, left = 3 right = 1        //int a = arr[i], left = length[a - 1], right = length[a + 1];
    len = [0,5,3,3,5,5,0]           //length[a] = length[a - left] = length[a + right] = left + right + 1;
    cnt = [-6,0,0,0,0,1]           // count[left]--;   count[right]--; count[length[a]]++;
    res = 4                       // if (count[m]) res = i + 1;
    
*/