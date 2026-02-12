#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        int slowIndex = 0;
        int fastIndex = 1;
        bool check = 1;
        for (; fastIndex < size; fastIndex++)
        {
            if (nums[fastIndex] == nums[slowIndex] && check)
            {
                for (int i = fastIndex; i < size - 1; i++)
                {
                    nums[i] = nums[i + 1];
                }
                size--;
                fastIndex--;
            }
            else
            {
                slowIndex++;
            }
        }
        return size;
    }
};