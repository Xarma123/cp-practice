/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *h=new ListNode();
        ListNode *cur = h;
        int c = 0;
        while (1)
        {
            int v = 0;
            if (l1 != nullptr)
            {
                v += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                v += l2->val;
                l2 = l2->next;
            } 
            v+=c;
            cur->val = v % 10;
            c = v / 10;
            if (c == 0 && l1 == nullptr && l2 == nullptr)
                break;
             ListNode *n=new ListNode();
            cur->next = n;
            cur = cur->next;
        }

        return h;
    }
};
// @lc code=end
