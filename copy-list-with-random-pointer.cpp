// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// Example 1:

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:

// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:

// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

// Constraints:

// 0 <= n <= 1000
// -104 <= Node.val <= 104
// Node.random is null or is pointing to some node in the linked list.

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class MySolution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> m;
        Node *rhead = new Node(head->val);
        m[head] = rhead;
        while (head)
        {
            if (!m.count(head))
                m[head] = new Node(head->val);
            if (head->next && !m.count(head->next))
                m[head->next] = new Node(head->next->val);
            if (head->next)
                m[head]->next = m[head->next];
            else
                m[head]->next = NULL;
            if (head->random && !m.count(head->random))
                m[head->random] = new Node(head->random->val);
            if (head->random)
                m[head]->random = m[head->random];
            else
                m[head]->random = NULL;
            head = head->next;
        }
        return rhead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class BetterSolution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> storage;
        Node *temp = head;
        Node *newTail = NULL;
        Node *curNew = new Node(-1);
        Node *newHead = curNew;

        while (temp)
        {
            Node *New = new Node(temp->val);
            curNew->next = New;
            curNew = curNew->next;

            // storage[curNew->val] = curNew;
            storage.emplace(temp, curNew);
            temp = temp->next;
        }

        temp = head;
        curNew = newHead->next;

        while (temp)
        {

            (temp->random == NULL) ? curNew->random = NULL : curNew->random = storage[temp->random];

            temp = temp->next;
            curNew = curNew->next;
        }

        Node *Head = newHead->next;
        delete newHead;
        return Head;
    }
};