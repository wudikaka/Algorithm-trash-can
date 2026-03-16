#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 用数组代替哈希表（字符的 ASCII 范围是 0-127）
        int need[128] = {0}; // 记录 t 中每个字符还需要多少
        int needCount = 0;   // 记录 t 中不同字符的种类数

        // 初始化 need 数组
        for (char c : t)
        {
            if (need[c] == 0)
                needCount++; // 遇到新字符，种类数+1
            need[c]++;
        }

        int left = 0, right = 0;
        int have[128] = {0}; // 记录当前窗口中有需要的字符的数量
        int haveCount = 0;   // 记录当前窗口已经满足了多少种字符

        int minLen = INT_MAX;
        int start = 0; // 记录最短子串的起始位置

        while (right < s.length())
        {
            char c = s[right];

            // 如果这个字符是 t 需要的
            if (need[c] > 0)
            {
                have[c]++;

                // 如果这个字符的数量已经达到要求
                if (have[c] == need[c])
                {
                    haveCount++;
                }
            }

            // 当所有字符都满足要求时，尝试缩小左边界
            while (haveCount == needCount && left <= right)
            {
                // 更新最小长度
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                // 移动左边界
                char leftChar = s[left];
                if (need[leftChar] > 0)
                {
                    if (have[leftChar] == need[leftChar])
                    {
                        haveCount--;
                    }
                    have[leftChar]--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};