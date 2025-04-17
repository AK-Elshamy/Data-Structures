# Dynamic Array (Vector)

A **Vector** is a dynamic array that automatically resizes itself when the number of elements grows or shrinks. It combines the fast random access of arrays (O(1)) with the flexibility of dynamic memory management.

## 📌 How It Works
- **Contiguous Storage**: Stores elements in a continuous memory block, enabling constant-time access by index.
- **Size vs. Capacity**:
  - **Size**: The number of elements currently in the vector.
  - **Capacity**: The total number of elements it can hold before needing to resize.
- **Automatic Resizing**: When size reaches capacity, the vector allocates a new block (usually double the previous capacity) and copies all existing elements into it. This growth strategy ensures that individual insertions remain efficient on average.

## 🔑 Key Operations & Complexities
| Operation         | Description                         | Time Complexity      |
|-------------------|-------------------------------------|----------------------|
| `push_back(x)`    | Append element `x` at the end       | Amortized O(1)       |
| `pop_back()`      | Remove the last element             | O(1)                 |
| `operator[]`      | Access element by index             | O(1)                 |
| `size()`          | Get current number of elements      | O(1)                 |
| `capacity()`      | Get current capacity                | O(1)                 |
| `clear()`         | Remove all elements                 | O(n)                 |

## 📈 Amortized Analysis
While a single `push_back` that triggers a resize takes O(n) (copying all elements), doubling the capacity on each resize ensures that the **amortized** cost per insertion remains O(1) over a sequence of operations.

## 🎯 When to Use
- When you need a resizable array with O(1) random access.
- Prefer over raw arrays when size is unpredictable.
- Ideal for implementing stacks, queues, or any sequence container where elements are frequently added or removed.

## 📋 Examples
### C++
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " "; // Output: 10 20 30
}
```

### Java
```java
import java.util.ArrayList;

public class VectorExample {
    public static void main(String[] args) {
        ArrayList<Integer> v = new ArrayList<>();
        v.add(10);
        v.add(20);
        v.add(30);

        for (int x : v) {
            System.out.print(x + " "); // Output: 10 20 30
        }
    }
}
```

---

*Simple, powerful, and versatile!*

