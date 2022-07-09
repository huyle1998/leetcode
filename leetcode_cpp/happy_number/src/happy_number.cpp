#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int num) {
        unordered_map<int, int> hash_map;
        while (num > 1)
        {
            int temp = 0;
            while (num > 0)
            {
                temp    += (num % 10) * (num % 10);
                num     = num / 10;
            }
            cout << "temp = " << temp << endl;
            if (1 == hash_map[temp])
            {
                return false;
            }
            else
            {
                hash_map[temp] = 1;
            }
            num = temp;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    Solution* solution  = new Solution;
    bool happy          = solution->isHappy(1029979);
    if (true == happy)
    {
        cout << "This is a happy number" << endl;
    }
    else
    {
        cout << "This is not a happy number" << endl;
    }
    delete solution;
    return 0;
}