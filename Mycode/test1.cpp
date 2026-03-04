#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        // 旋转后的数组分为下标0~maxIndex，maxIndex+1~num.size()-1;

        int l, r, mid;
        // 左
        l = 0;
        r = maxIndex;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        // 右
        l = maxIndex + 1;
        r = nums.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};