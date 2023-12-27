// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BetterSolution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return mergeListHelper(lists, 0, lists.size() - 1);
    }

    ListNode *mergeListHelper(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
            return nullptr;
        if (start == end)
            return lists[start];

        int mid = start + (end - start) / 2;
        ListNode *left = mergeListHelper(lists, start, mid);
        ListNode *right = mergeListHelper(lists, mid + 1, end);
        return mergeList(left, right);
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *ans_head, *ans_tail;
        if (l1->val <= l2->val)
        {
            ans_head = l1;
            ans_tail = l1;
            l1 = l1->next;
        }
        else
        {
            ans_head = l2;
            ans_tail = l2;
            l2 = l2->next;
        }

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ans_tail->next = l1;
                ans_tail = l1;
                l1 = l1->next;
            }
            else
            {
                ans_tail->next = l2;
                ans_tail = l2;
                l2 = l2->next;
            }
        }

        if (l1 == nullptr)
            ans_tail->next = l2;
        if (l2 == nullptr)
            ans_tail->next = l1;
        return ans_head;
    }
};

class MYSolution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                pq.push(make_pair(lists[i]->val, i));

        ListNode *start = NULL;
        ListNode *prev = NULL;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ListNode *temp = NULL;
            if (!start)
                start = lists[top.second];
            if (prev)
                prev->next = lists[top.second];
            prev = lists[top.second];
            if (lists[top.second]->next)
                pq.push(make_pair(lists[top.second]->next->val, top.second));
            lists[top.second] = lists[top.second]->next;
        }
        return start;
    }
};