// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.

class BestMedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;
    int n;

public:
    MedianFinder()
    {
        n = 0;
    }

    void addNum(int num)
    {
        if (n % 2 == 0)
        {
            if (n == 0)
            {
                insertInMaxHeap(num);
            }
            else
            {
                int topOfMinHeap = getMinHeapTop();
                if (num >= topOfMinHeap)
                {
                    insertInMaxHeap(topOfMinHeap);
                    minHeap.pop();
                    insertInMinHeap(num);
                }
                else
                {
                    insertInMaxHeap(num);
                }
            }
        }
        else
        {
            int topOfMaxHeap = getMaxHeapTop();
            if (topOfMaxHeap < num)
            {
                insertInMinHeap(num);
            }
            else
            {
                maxHeap.pop();
                insertInMaxHeap(num);
                insertInMinHeap(topOfMaxHeap);
            }
        }
        n++;
    }

    double findMedian()
    {
        if (n % 2 == 1)
            return maxHeap.top();
        return (double)(getMaxHeapTop() + getMinHeapTop()) / 2;
    }

private:
    void insertInMaxHeap(int val)
    {
        maxHeap.push(val);
    }

    void insertInMinHeap(int val)
    {
        minHeap.push(-val);
    }

    int getMinHeapTop()
    {
        return -minHeap.top();
    }

    int getMaxHeapTop()
    {
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class BaadMedianFinder
{
public:
    vector<int> store;
    priority_queue<int> store;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (store.size() == 0)
        {
            store.push_back(num);
            return;
        }
        auto it = lower_bound(store.begin(), store.end(), num);
        if (it != store.end())
            store.insert(it, num);
        else
            store.push_back(num);
    }

    double findMedian()
    {
        int n = store.size();

        if (n % 2 == 0)
            return (store[n / 2] + store[n / 2 - 1]) / (double)2;
        else
            return store[n / 2];
        return 1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */