#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        int t = n, num = 0;
        while (t != 1)
        {
            if (m[t] == 1)
                return false;
            else
                m[t]++;
            n = t;
            num = 0;
            while (n)
            {
                int temp = n;
                int rem = temp % 10;
                num += (rem * rem);
                n = n / 10;
            }
            t = num;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    Solution* soulution = new Solution;

    return 0;
}