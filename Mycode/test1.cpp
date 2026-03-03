#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return {-1, -1};
        }

        // 找头
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] >= target)
            {
                r = mid - 1;
            }
        }
        // 头已经找到了，尾部分就不用判断了，尾部分最多重叠
        if (l >= nums.size() || nums[l] != target)
        {
            return {-1, -1};
        }
        int first = l;

        // 找尾
        l = 0;
        r = nums.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
        }
        int last = l - 1;

        vector<int> my_target;
        my_target.push_back(first);
        my_target.push_back(last);
        return my_target;
    }
};