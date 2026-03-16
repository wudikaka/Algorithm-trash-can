#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // 初始化x
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // 无头节点，或只有头节点
        if (head == nullptr || head->next == nullptr)
        {
            return 0;
        }

        // 快慢指针
        ListNode *slow = head;
        ListNode *fast = head;

        // 快指针本身不越界，快指针下一个节点也不越界，即快指针只能停留在最后一个节点
        while (fast != nullptr && fast->next != nullptr)
        {
            // 注意这里移动不能用++和--，因为是链表，不是数组
            slow = slow->next;
            fast = fast->next->next;

            // 如果快慢指针相遇，说明是环
            if (slow == fast)
            {
                return 1;
            }
        }

        // 循环结束还没相遇，则无环
        return 0;
    }
};