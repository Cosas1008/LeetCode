#include <iostream>
#include <string>

int main()
{
    int num_of_trial;
    std::cin >> num_of_trial;
    for (int i = 0; i < num_of_trial; ++i)
    {
        unsigned int low, high;
        std::cin >> low >> high;
        int num_tries;
        std::cin >> num_tries;
        unsigned int left, right;
        left = low + 1;
        right = high;
        while (num_tries--)
        {
            int m = (left + right) / 2;
            std::cout << m << std::endl;
            std::string ans;
            std::cin >> ans;
            if (ans == "CORRECT")
                break;
            else if (ans == "TOO_BIG")
                right = m - 1;
            else if (ans == "TOO_SMALL")
                left = m + 1;
            else
                break;
        }
    }
    return 0;
}