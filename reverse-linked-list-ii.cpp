// https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

// Follow up: Could you do it in one pass?

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// just traverse and do instead of recursion;
class BetterSolution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL)
            return head;
        cout << "done" << endl;
        if (head->next == NULL)
            return head;
        cout << "done2" << endl;
        int l = left;
        ListNode *prev = NULL;
        ListNode *ans = head;

        while (l > 1)
        {
            prev = head;
            head = head->next;
            l--;
        }

        cout << head->val;
        int loop = right - left + 1;
        ListNode *pre = NULL;
        ListNode *nex;
        ListNode *last;
        ListNode *prev2 = head;

        while (loop)
        {
            if (head)
            {
                nex = head->next;
                head->next = pre;
                pre = head;
                head = nex;
            }

            loop--;
        }
        if (prev != nullptr)
        {
            if (pre != nullptr)
            {
                prev->next = pre;
            }

            else
                prev->next = NULL;
        }
        else
            ans = pre;
        prev2->next = head;

        return ans;
    }
};

class MySolution
{
    ListNode *before = NULL;
    ListNode *start = NULL;
    ListNode *end = NULL;
    ListNode *prev = NULL;
    int count = 0;

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int index = ++count;
        if (!head || index > right)
        {
            if (!end)
                end = head;
            if (start)
                start->next = end;
            if (prev && before)
                before->next = prev;
            return prev;
        }
        else if (index >= left && index <= right)
        {
            if (!start)
                start = head;
            ListNode *temp = head->next;
            if (prev)
                head->next = prev;
            prev = head;
            return reverseBetween(temp, left, right);
        }
        else
        {
            before = head;
            reverseBetween(head->next, left, right);
            return head;
        }
    }
};