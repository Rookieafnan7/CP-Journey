// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;
        stack<ListNode *> s;
        s.push(NULL);
        ListNode *temp = head, *prev = NULL, *curr = NULL;
        while (temp)
        {
            s.push(temp);
            temp = temp->next;
        }
        cout << s.size() << endl;
        while (n--)
        {
            prev = curr;
            curr = s.top();
            s.pop();
        }
        ListNode *top = s.top();
        if (!top)
        {
            return prev;
        }
        else
        {
            top->next = prev;
            curr->next = NULL;
            return head;
        }
        return head;
    }
};