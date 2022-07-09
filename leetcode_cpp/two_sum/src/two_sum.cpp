#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret = { 0, 0 };
        unordered_map<int, int> hash_map;
        int current = 0, pair = target - current;
        for (unsigned int i = 0; i < nums.size(); i++)
        {
            current = nums[i];
            pair = target - current;
            if (hash_map.find(pair) != hash_map.end())
            {
                ret[0] = i;
                ret[1] = hash_map[pair];
                break;
            }
            hash_map[current] = i;
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution*       soulution   = new Solution;
    vector<int>     nums        = { 1,2,0,4,5,6 };
    unsigned int    target      = 7;
    for (int i : soulution->twoSum(nums, target))
    {
        cout << "i = " << i << endl;
    }
    delete soulution;
    return 0;
}
