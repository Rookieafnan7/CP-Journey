// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

// Follow-up: Can you solve the problem in O(1) extra memory space?

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BestSolution
{
public:
    void printList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != NULL)
        {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    ListNode *reverseList(ListNode **P, ListNode **start, int k)
    {
        ListNode *prev = NULL;
        ListNode *cur = *start;
        for (int i = 0; i < k && cur != NULL; i++)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (*start != NULL)
        {
            (*start)->next = cur;
        }
        if (*P != NULL)
        {
            (*P)->next = prev;
        }

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head;
        ListNode *prev = NULL;
        head = reverseList(&prev, &cur, k);
        while (cur != NULL)
        {
            prev = cur;
            cur = cur->next;
            ListNode *test = cur;
            for (int i = 0; i < k - 1 && test != NULL; i++)
                test = test->next;
            if (test == NULL)
                break;
            reverseList(&prev, &cur, k);
        }

        return head;
    }
};

class MySolution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return NULL;
        ListNode *temp = head;
        int count = k;
        stack<ListNode *> q;
        while (count-- && temp)
        {
            q.push(temp);
            temp = temp->next;
        }
        ListNode *tempHead;
        if (++count == 0)
        {
            tempHead = q.top();
            for (int i = 0; i < k; i++)
            {
                ListNode *top = q.top();
                q.pop();
                if (i < k - 1)
                    top->next = q.top();
                else
                    top->next = reverseKGroup(temp, k);
            }
            return tempHead;
        }
        return head;
    }
};