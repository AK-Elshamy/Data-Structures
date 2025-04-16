Q&A for Time Complexity
<aside> 💡 **Q1.** What is the time complexity based on?
Answer: The time complexity is based on the number of primitive operations performed by the algorithm.

</aside>
Q2. Time Complexity of Recursive Factorial Function
cpp
Copy
Edit
int f(int n) 
{
 	if(n <= 1)
 		return 1;
 	return n * f(n-1);
}
Answer: O(n)

Explanation: This function is recursive, with one recursive call for each value of n. Therefore, the time complexity is linear O(n).

Q3. Time Complexity of Loop with Variable Increment
cpp
Copy
Edit
int f(int n) 
{
	int sum = 0;
	for (int i = 0; i < n; i += n / 10)
 		sum += i * i;
 	return sum;
}
Answer: O(1)

Explanation: The loop increments i by a constant fraction of n, so the number of iterations does not grow linearly with n. Hence, this is a constant time complexity O(1).

Q4. Time Complexity of Simple While Loop
cpp
Copy
Edit
void f(int n) 
{
	int start = 0;
	int end = 100000;	
	while(start < end)
		start += 100;
}
Answer: O(1)

Explanation: This loop runs a constant number of times (1000 iterations), which is independent of n. Therefore, the time complexity is O(1).

Q5. Time Complexity of expand_capacity Function
cpp
Copy
Edit
class Vector 
{
 private:
 	int *arr { nullptr };
 	int size { 0 };			
	int capacity { };		
 	void expand_capacity() 
{
		capacity *= 2;
		int *arr2 = new int[capacity] { };
 		for (int i = 0; i < size; ++i)
 			arr2[i] = arr[i];	
 		swap(arr, arr2);
 		delete[] arr2;
}
Answer: O(n)

Explanation: In the expand_capacity function, the time complexity is dominated by the for loop, which iterates over the size of the vector, making the time complexity O(n).

Q6. Time Complexity of Nested Loops
cpp
Copy
Edit
void f(int n) 
{
	int cnt = 0;
	for (int i = 0; i < 5 * n; ++i)
		for (int j = 0; j < 3 * n; ++j)
			for (int k = 0; k < i + j; ++k)
 				cnt++;	
}
Answer: O(n^3)

Explanation: The number of iterations for the innermost loop depends on i and j, and the total number of iterations will be approximately O(n^3).

Q7. Time Complexity of Nested Loops with Constant Inner Loop
cpp
Copy
Edit
void f(int n) 
{
	int cnt = 0;
	for (int i = 0; i < 5 * n; ++i)
		for (int j = 0; j < 3 * n; ++j)
			for (int k = 0; k < 1000000; ++k)
 				cnt++;	
}
Answer: O(n^2)

Explanation: The innermost loop is a constant and does not depend on n. Thus, the time complexity is O(n^2), as the outer two loops iterate over 5n and 3n.

Q8. Understanding Big O Notations
Statement: If some function is O(n^2), it is also O(n^3) and above, but we use a tight order.

Answer: True

Explanation: Big O notation describes an upper bound, so if a function is O(n^2), it can be considered O(n^3), but this is not a tight bound. We use O(n^2) because it gives a better understanding of the algorithm’s behavior.

Q9. Time Complexity of Nested Loops with Square Operations
cpp
Copy
Edit
int f(int x) 
{
	int s = 0, n = 0;
 	for (int i = 0; i < x; ++i) {
 		for (int j = 0; j < x; ++j) {
			s += i * j;
 			n += 1;
		}
 	}
 	return s / n;
}
Answer: O(n^2)

Explanation: This function has two nested loops, each iterating x times, so the time complexity is O(x^2), which is O(n^2) when considering x = n.

Advanced Interview Questions (From Top Tech Companies)
Q10. Amazon - Searching in a Rotated Sorted Array
Problem: Given a rotated sorted array, find the minimum element.

Example:
Input: [4, 5, 6, 7, 0, 1, 2]
Output: 0

Time Complexity: O(log n)

Explanation: This problem can be solved using binary search in O(log n) time, as the array is partially sorted and rotated.

Q11. Google - Find the Longest Increasing Subsequence
Problem: Given an integer array, find the length of the longest increasing subsequence.

Example:
Input: [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4
Explanation: [2, 3, 7, 101] is the longest increasing subsequence.

Time Complexity: O(n log n)

Explanation: This can be solved using dynamic programming combined with binary search for better efficiency.

Q12. Microsoft - Merge Intervals
Problem: Given a collection of intervals, merge all overlapping intervals.

Example:
Input: [[1, 3], [2, 4], [5, 7]]
Output: [[1, 4], [5, 7]]

Time Complexity: O(n log n)

Explanation: First, the intervals need to be sorted, which takes O(n log n). Then we can merge the intervals in O(n) time.

Q13. Apple - Search in a Binary Search Tree
Problem: Given a binary search tree (BST) and a value, find the node containing that value.

Time Complexity: O(log n) for a balanced BST, O(n) for a skewed tree.

Explanation: If the tree is balanced, the time complexity is O(log n), but in the worst case (a skewed tree), it can become O(n).

Q14. Facebook - Rotate Image
Problem: Given an n x n matrix, rotate it 90 degrees clockwise.

Example:
Input: [[1, 2, 3], [4, 5, 6], [7, 8, 9]] Output: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

Time Complexity: O(n^2)

Explanation: Each element of the matrix must be moved to a new position, resulting in O(n^2) operations for an n x n matrix.

Q15. IBM - Dynamic Programming Problem
Problem: Given a list of integers, find the maximum sum of a non-adjacent subsequence.

Example:
Input: [2, 4, 6, 2, 5]
Output: 13
Explanation: The maximum sum is 2 + 6 + 5 = 13`

Time Complexity: O(n)

Explanation: This can be solved using dynamic programming in linear time.