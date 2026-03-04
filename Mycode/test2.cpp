#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            // 判断哪一半是有序的
            if (nums[left] <= nums[mid])
            { // 左半部分有序
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1; // target在左半
                }
                else
                {
                    left = mid + 1; // target在右半
                }
            }
            else
            { // 右半部分有序
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1; // target在右半
                }
                else
                {
                    right = mid - 1; // target在左半
                }
            }
        }

        return -1;
    }
};