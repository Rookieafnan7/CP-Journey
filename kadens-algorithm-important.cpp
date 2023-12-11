// C++ program to print largest contiguous array sum


// sum_carry is set to zero when the previous sum is negative
// this is because carrying a negative value will only decrease the sum when the index moves


#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, sum_carry = 0;

	for (int i = 0; i < size; i++) {
		sum_carry = sum_carry + a[i];
		if (max_so_far < sum_carry)
			max_so_far = sum_carry;

		if (sum_carry < 0)
			sum_carry = 0;
	}
	return max_so_far;
}

int start;
int ansStart,ansEnd;

int maxSubArraySumWithIndex(int a[], int size)
{
	int max_so_far = INT_MIN, sum_carry = 0;
    
	for (int i = 0; i < size; i++) {
        if(sum_carry == 0) start = i;
    	sum_carry = sum_carry + a[i];
		if (max_so_far < sum_carry){
            max_so_far = sum_carry;
            ansStart = start;
            ansEnd = i;
        }
			

		if (sum_carry < 0)
			sum_carry = 0;
	}
	return max_so_far;
}


// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
