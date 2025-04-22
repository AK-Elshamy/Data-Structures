/* 
 * @author: Ahmed Elshamy
 *
 * This program demonstrates the implementation of a dynamic vector with various operations
 * such as adding, removing, rotating, and finding elements. The Vector class allows flexibility
 * with dynamic resizing and efficient access to vector elements.
*/

import java.util.Arrays;

public class Vector {
    // Internal array to store elements
    private int[] arr;
    // Current number of elements in the vector
    private int size;
    // Total capacity of the internal array
    private int capacity;

    /**
     * Constructor to initialize vector with given size
     * If size is invalid (<=0), defaults to 1
     */
    public Vector(int si) {
        if (si <= 0) {
            si = 1;
        }
        size = si;
        capacity = size * 2;
        arr = new int[capacity];
    }

    /**
     * Copy constructor - creates a new vector as a copy of another
     */
    public Vector(Vector other) {
        this.size = other.size;
        this.capacity = other.capacity;
        this.arr = Arrays.copyOf(other.arr, capacity);
    }

    /**
     * Returns the first element of the vector
     * Throws exception if vector is empty
     */
    public int front() {
        if (size == 0)
            throw new RuntimeException("Vector is empty");
        return arr[0];
    }

    /**
     * Returns the last element of the vector
     * Throws exception if vector is empty
     */
    public int back() {
        if (size == 0)
            throw new RuntimeException("Vector is empty");
        return arr[size - 1];
    }

    /**
     * Sets the value at specified index
     * Throws exception if index is out of range
     */
    public void set(int index, int val) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        arr[index] = val;
    }

    /**
     * Adds a new element to the end of the vector
     * Expands capacity if necessary
     */
    public void pushBack(int val) {
        if (size == capacity) {
            expandCapacity();
        }
        arr[size++] = val;
    }

    /**
     * Inserts an element at specified index
     * Shifts elements to make space
     * Throws exception if index is out of range
     */
    public void insert(int index, int val) {
        if (index < 0 || index > size)
            throw new IndexOutOfBoundsException("Index out of range");
        if (size == capacity) {
            expandCapacity();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        size++;
    }

    /**
     * Returns the current size of the vector
     */
    public int getSize() {
        return size;
    }

    /**
     * Returns the element at specified index
     * Throws exception if index is out of range
     */
    public int get(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        return arr[index];
    }

    /**
     * Finds the first occurrence of a value
     * Returns the index if found, -1 otherwise
     */
    public int find(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }

    /**
     * Prints all elements of the vector
     */
    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    /**
     * Rotates all elements one position to the right
     * Last element becomes the first
     */
    public void rightRotate() {
        if (size <= 1)
            return;
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }

    /**
     * Rotates elements to the right by specified number of positions
     * Uses the three-reverse method for efficiency
     */
    public void rightRotate(int times) {
        if (times <= 0 || size <= 1)
            return;
        times %= size;
        reverse(0, size - 1);
        reverse(0, times - 1);
        reverse(times, size - 1);
    }

    /**
     * Rotates all elements one position to the left
     * First element becomes the last
     */
    public void leftRotate() {
        if (size <= 1)
            return;
        int first = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first;
    }

    /**
     * Removes and returns the element at specified index
     * Shifts elements to fill the gap
     * Throws exception if index is out of range
     */
    public int pop(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of range");
        int element = arr[index];
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return element;
    }

    /**
     * Finds a value and moves it one position closer to the front (transposition)
     * Used as a heuristic to improve future search performance
     * Returns the new index if found, -1 otherwise
     */
    public int findTransposition(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                if (i == 0)
                    return i;
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1;
            }
        }
        return -1;
    }

    /**
     * Helper method to reverse a portion of the array
     * Used by rightRotate method
     */
    private void reverse(int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    /**
     * Doubles the capacity of the internal array
     * Used when more space is needed
     */
    private void expandCapacity() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        arr = Arrays.copyOf(arr, capacity);
    }

    public static void main(String[] args) {
        Vector v = new Vector(5);
        System.out.print("Initial vector (size 5): ");
        v.print();

        v.pushBack(10);
        v.pushBack(20);
        v.pushBack(30);
        System.out.print("After adding elements (10, 20, 30): ");
        v.print();

        System.out.println("First element (front): " + v.front());
        System.out.println("Last element (back): " + v.back());
        v.set(0, 99);
        System.out.print("After setting the first element to 99: ");
        v.print();

        v.insert(2, 50);
        System.out.print("After inserting 50 at index 2: ");
        v.print();

        int index = v.find(20);
        if (index != -1)
            System.out.println("Element 20 found at index: " + index);
        else
            System.out.println("Element 20 not found");

        v.rightRotate();
        System.out.print("After right rotation by 1: ");
        v.print();

        v.rightRotate(3);
        System.out.print("After right rotation by 3: ");
        v.print();

        v.leftRotate();
        System.out.print("After left rotation by 1: ");
        v.print();

        int removed = v.pop(2);
        System.out.println("After removing element at index 2 (removed: " + removed + "): ");
        v.print();

        index = v.findTransposition(30);
        if (index != -1)
            System.out.println("Element 30 found and moved closer to the front. New index: " + index);
        else
            System.out.println("Element 30 not found");
        System.out.print("After find with transposition: ");
        v.print();

        try {
            System.out.println("Accessing element at invalid index (-1): " + v.get(-1));
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Caught exception: " + e.getMessage());
        }

        try {
            System.out.print("Popping element at invalid index (100): ");
            v.pop(100);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Caught exception: " + e.getMessage());
        }

        System.out.print("Final state of the vector: ");
        v.print();
    }
}