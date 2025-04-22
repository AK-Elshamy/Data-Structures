# 💼 Linked List Interview Questions: Top 20 Companies' Insights

These 20 questions on **Linked Lists** are commonly asked in interviews at top companies like FAANG, and the answers are explained with modern methods and deep research.

---

## 1. **Q: (Google)** What is a linked list, and why is it better than an array in certain situations?

**Answer:**
A **linked list** is a linear data structure where elements (nodes) are connected using pointers. Each node contains data and a pointer to the next node. Unlike arrays, linked lists do not require a contiguous block of memory. This provides significant flexibility for dynamic data storage. Arrays are fixed in size and require shifting elements for insertion or deletion. In contrast, linked lists allow for **O(1)** insertions and deletions at both ends (especially the head), without the need to shift elements. However, they lack **O(1)** random access like arrays, making them unsuitable for situations requiring frequent index-based access.

---

## 2. **Q: (Facebook)** Explain the difference between a singly linked list and a doubly linked list.

**Answer:**
- A **singly linked list** consists of nodes where each node points to the next node. It only allows forward traversal, making insertion and deletion simpler but traversal limited to one direction.
- A **doubly linked list** has nodes with two pointers: one pointing to the next node and one pointing to the previous node. This allows traversal in both directions (forward and backward), which is useful for algorithms that need to traverse both ways, such as undo functionality in applications.

---

## 3. **Q: (Amazon)** How would you reverse a singly linked list?

**Answer:**
To reverse a singly linked list, you need to iterate through the list and reverse the direction of the pointers. The process involves:
1. Initialize three pointers: `prev` as `NULL`, `current` as the head of the list, and `next` as `NULL`.
2. Traverse the list, updating the `current.next` pointer to point to `prev` and move `prev` and `current` forward.
3. Continue until all nodes have been processed. The `prev` pointer will eventually point to the new head of the reversed list.

```java
public Node reverse(Node head) {
    Node prev = null;
    Node current = head;
    while (current != null) {
        Node next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
```

---

## 4. **Q: (Apple)** What is the time complexity of accessing an element in a linked list?

**Answer:**
The time complexity for accessing an element in a linked list is **O(n)** in the worst case. Since linked lists don't provide direct indexing like arrays, to find an element, you must traverse the list from the head node until the desired element is found. This results in a linear time complexity for access.

---

## 5. **Q: (Microsoft)** How would you detect a cycle in a linked list?

**Answer:**
The best way to detect a cycle in a linked list is using Floyd’s **Tortoise and Hare** algorithm. You maintain two pointers:
1. A slow pointer (`slow`) which moves one step at a time.
2. A fast pointer (`fast`) which moves two steps at a time.

If there’s a cycle, the `fast` pointer will eventually meet the `slow` pointer. If the `fast` pointer reaches `NULL`, there is no cycle.

---

## 6. **Q: (Netflix)** Can you explain how you would implement a linked list in Java?

**Answer:**
To implement a linked list in Java, you create a `Node` class with two fields: `data` and `next`. The `LinkedList` class maintains a reference to the head node and supports operations such as insertion, deletion, and traversal.

```java
class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;
    
    // Insert at the end
    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }
    
    // Traverse the list
    void traverse() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
```

---

## 7. **Q: (Google)** How do you find the middle of a linked list?

**Answer:**
You can find the middle of a linked list using the two-pointer method:
1. Initialize two pointers: `slow` and `fast`.
2. Move `slow` one step at a time and `fast` two steps at a time.
3. When `fast` reaches the end of the list, `slow` will be at the middle.

This has a time complexity of **O(n)** and space complexity of **O(1)**.

---

## 8. **Q: (Facebook)** What is the time complexity of insertion and deletion in a linked list?

**Answer:**
- **Insertion at the head**: O(1) — You simply adjust the head pointer to the new node.
- **Insertion at the tail**: O(n) — You need to traverse the list to reach the last node unless you maintain a reference to the tail node.
- **Deletion at the head**: O(1) — You just need to adjust the head pointer.
- **Deletion at the tail**: O(n) — You must traverse the list to find the node before the tail.

---

## 9. **Q: (Apple)** How would you merge two sorted linked lists?

**Answer:**
You can merge two sorted linked lists by comparing the nodes of both lists and linking them in sorted order. The process involves:
1. Initialize a dummy node to act as the merged list’s head.
2. Compare nodes from both lists, adding the smaller node to the merged list.
3. Once one list is exhausted, append the remaining elements of the other list.

```java
public Node mergeSortedLists(Node l1, Node l2) {
    Node dummy = new Node(0);
    Node current = dummy;
    while (l1 != null && l2 != null) {
        if (l1.data < l2.data) {
            current.next = l1;
            l1 = l1.next;
        } else {
            current.next = l2;
            l2 = l2.next;
        }
        current = current.next;
    }
    current.next = (l1 != null) ? l1 : l2;
    return dummy.next;
}
```

---

## 10. **Q: (Amazon)** What are the advantages of using a linked list over an array?

**Answer:**
- **Dynamic Size**: Linked lists can grow and shrink dynamically without the need for resizing, unlike arrays which need to be preallocated.
- **Efficient Insertions/Deletions**: Linked lists allow for O(1) insertions and deletions, especially at the beginning or middle, while arrays can be inefficient for these operations due to the need to shift elements.
- **No Wasted Space**: Linked lists do not require contiguous memory blocks, whereas arrays require a contiguous block of memory, which can lead to wasted space.

---

## 11. **Q: (Microsoft)** How do you remove the nth node from the end of a linked list?

**Answer:**
You can remove the nth node from the end of the list by using the two-pointer technique:
1. Initialize two pointers, `first` and `second`, both at the head.
2. Move `first` n steps ahead.
3. Then, move both pointers one step at a time until `first` reaches the end of the list. The `second` pointer will be at the node just before the one to be removed.

```java
public Node removeNthFromEnd(Node head, int n) {
    Node dummy = new Node(0);
    dummy.next = head;
    Node first = dummy, second = dummy;
    
    for (int i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    
    second.next = second.next.next;
    return dummy.next;
}
```

---

## 12. **Q: (Google)** Can you explain how to implement a circular linked list?

**Answer:**
In a **circular linked list**, the last node points to the head node, forming a circle. This can be useful for applications like a round-robin scheduler or a buffer for streaming data. The implementation is very similar to a singly linked list, but when inserting or deleting nodes, the last node’s `next` pointer must be updated to point to the head node.

---

## 13. **Q: (Facebook)** What is the space complexity of a linked list?

**Answer:**
The space complexity of a linked list is **O(n)**, where `n` is the number of nodes in the list. Each node in the linked list requires additional memory to store the `data` and the pointer(s) to the next node(s). For a singly linked list, it's just one pointer per node, while for a doubly linked list, it requires two pointers.

---

## 14. **Q: (Netflix)** How do you handle null pointers in a linked list?

**Answer:**
Null pointers are common in linked lists. A null pointer in the `next` field of a node indicates the end of the list (in singly linked lists). It’s important to always check for null before attempting to access the `next` field to avoid null pointer exceptions. In code, this is typically done using conditionals such as `if (node != null)`.

---

## 15. **Q: (Apple)** How would you implement a stack using a linked list?

**Answer:**
You can implement a **stack** using a linked list by using the head of the list to represent the top of the stack. The push operation is O(1) as you insert at the head, and the pop operation is also O(1) as you remove from the head.

```java
class Stack {
    Node top;
    
    void push(int data) {
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
    }
    
    int pop() {
        if (top == null) throw new EmptyStackException();
        int data = top.data;
        top = top.next;
        return data;
    }
}
```

---

## 16. **Q: (Microsoft)** Explain how you would implement a queue using a linked list.

**Answer:**
A **queue** follows FIFO (First-In, First-Out). Using a linked list, you can implement a queue by maintaining a reference to both the head (front) and the tail (back) of the list. Enqueue is done by inserting at the tail (O(1)), and dequeue is done by removing from the head (O(1)).

```java
class Queue {
    Node front, rear;
    
    void enqueue(int data) {
        Node newNode = new Node(data);
        if (rear != null) rear.next = newNode;
        rear = newNode;
        if (front == null) front = newNode;
    }
    
    int dequeue() {
        if (front == null) throw new EmptyQueueException();
        int data = front.data;
        front = front.next;
        return data;
    }
}
```

---

## 17. **Q: (Google)** How would you implement a Linked List with a sentinel node?

**Answer:**
A **sentinel node** is a dummy node that simplifies operations, particularly insertion and deletion. The sentinel node is not part of the actual data but helps eliminate edge cases like empty list or single-element lists. It simplifies logic by ensuring that the list never has a `null` head or tail.

---

## 18. **Q: (Facebook)** Can you explain the concept of a skip list and how it relates to linked lists?

**Answer:**
A **skip list** is a multi-level linked list used for faster searching. Each level of the skip list is a linked list, and higher levels act as "express lanes" to skip over multiple elements, allowing for faster searches. While a linked list provides **O(n)** search time, a skip list improves this to **O(log n)**.

---

## 19. **Q: (Amazon)** How do you implement a priority queue using a linked list?

**Answer:**
A **priority queue** can be implemented using a linked list by ensuring the nodes are ordered based on their priority. When inserting, you traverse the list to find the correct position based on the priority of the element, ensuring that the list is sorted. This allows efficient access to the element with the highest priority.

---

## 20. **Q: (Apple)** How would you handle memory management in a linked list to avoid memory leaks?

**Answer:**
In languages with manual memory management (like C/C++), it’s important to ensure that each node is properly deallocated when no longer needed. This involves using **free** or **delete** to release memory for nodes after they are removed from the list. In garbage-collected languages like Java, memory is managed automatically, but developers must still ensure that references to nodes are removed to allow garbage collection.

