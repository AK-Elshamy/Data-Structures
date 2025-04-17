# Vector Interview Questions from Top Tech Companies

---

## Q1. What is the time complexity of accessing an element in a vector by index?  
**Company**: Google  
**Answer**: O(1), since a vector allows random access to elements by index in constant time.

---

## Q2. What happens when a vector exceeds its capacity?  
**Company**: Amazon  
**Answer**: When a vector exceeds its current capacity, it reallocates its memory to a larger block, typically doubling the capacity. This involves copying the elements to the new location, which results in an amortized O(1) time complexity for each insertion.

---

## Q3. How do you implement dynamic resizing in a vector?  
**Company**: Facebook  
**Answer**: When the size of the vector exceeds its current capacity, the vector typically doubles its capacity. This resizing strategy minimizes the number of reallocations, making the time complexity for an insertion amortized O(1).

---

## Q4. What is the time complexity of inserting an element at the beginning of a vector?  
**Company**: Microsoft  
**Answer**: O(n), because elements after the inserted element need to be shifted to make room for the new element.

---

## Q5. How does vector differ from an array in terms of resizing?  
**Company**: Apple  
**Answer**: Vectors automatically resize when they reach capacity, whereas arrays have a fixed size once defined. In a vector, resizing usually involves allocating new memory and copying the old elements to the new memory.

---

## Q6. When should you use a vector over an array?  
**Company**: Google  
**Answer**: Use vectors when you need a dynamic, resizable container that grows as needed. Arrays are suitable for cases where the size is known upfront and won't change.

---

## Q7. Can you describe the trade-off between space and time complexity in vectors?  
**Company**: IBM  
**Answer**: Vectors optimize for fast random access (O(1)) but use more memory due to internal storage resizing. The trade-off is a balance between increased space usage for fast operations and occasional overhead for resizing.

---

## Q8. How do you handle resizing if you want to minimize the overhead?  
**Company**: Amazon  
**Answer**: One strategy is to resize the vector's capacity in smaller increments instead of doubling each time. This reduces memory overhead but can increase the frequency of reallocations.

---

## Q9. What are the advantages and disadvantages of vectors compared to linked lists?  
**Company**: Microsoft  
**Answer**: Vectors provide fast random access and better cache locality but may incur higher costs when inserting or deleting elements in the middle of the vector. Linked lists provide O(1) insertions and deletions but are slower for random access.

---

## Q10. How do you handle out-of-bound errors in vectors?  
**Company**: Facebook  
**Answer**: Use the `at()` function instead of the `[]` operator in C++ for bounds-checking. This ensures that accessing an out-of-bounds element throws an exception (`std::out_of_range`).

---

## Q11. How does vector resizing affect the performance of an application?  
**Company**: Google  
**Answer**: Vector resizing can temporarily degrade performance due to the need to copy elements to a new memory block. However, this is amortized over many insertions, so the average time complexity per insertion remains O(1).

---

## Q12. What is the worst-case time complexity for inserting an element in the middle of a vector?  
**Company**: Apple  
**Answer**: O(n), because all elements after the insertion point need to be shifted.

---

## Q13. How can you optimize memory usage when working with vectors?  
**Company**: Amazon  
**Answer**: You can optimize memory usage by using `shrink_to_fit()` in C++ to release unused memory after elements are removed, or by setting the initial capacity to an appropriate value to avoid frequent reallocations.

---

## Q14. How do you find the minimum or maximum element in a vector?  
**Company**: Microsoft  
**Answer**: Use the `min_element()` and `max_element()` functions provided by the C++ standard library, which run in O(n) time complexity by iterating through the vector.

---

## Q15. Can you explain the concept of "capacity" and "size" in a vector?  
**Company**: IBM  
**Answer**: The "size" refers to the number of elements currently in the vector, while "capacity" is the total number of elements that the vector can hold before needing to reallocate. The capacity is always greater than or equal to the size.

---

## Q16. What is the time complexity of the `push_back()` operation in a vector?  
**Company**: Google  
**Answer**: O(1) on average, but can be O(n) in the worst case when the vector needs to resize.

---

## Q17. How do you ensure that the vector does not exceed a certain size?  
**Company**: Facebook  
**Answer**: You can use the `reserve()` method to pre-allocate memory and ensure the vector does not resize automatically when you exceed a certain threshold. This helps avoid resizing overhead.

---

## Q18. How do you perform a binary search on a vector?  
**Company**: Microsoft  
**Answer**: You can use the `std::binary_search()` function or implement your own binary search algorithm. Binary search works on a sorted vector in O(log n) time.

---

## Q19. How do you efficiently remove elements from a vector?  
**Company**: Amazon  
**Answer**: Removing an element from a vector involves shifting all the subsequent elements. To remove elements efficiently, use the `erase()` function for a single element or a range of elements.

---

## Q20. What happens if you try to access a vector element that has been deleted?  
**Company**: IBM  
**Answer**: Accessing a deleted element results in undefined behavior, as the memory where the element was stored may no longer be valid.

---
