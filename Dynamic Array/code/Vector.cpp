/**
 * @author: Ahmed Elshamy
 * @time: 18/04/2025  00:55 PM
 *
 * This program demonstrates the implementation of a dynamic vector with various operations
 * such as adding, removing, rotating, and finding elements. The Vector class allows flexibility
 * with dynamic resizing and efficient access to vector elements.
 */

#include <iostream>
#include <cassert>
#include <stdexcept> // For exception handling
#include <algorithm> // For std::reverse
using namespace std;

class Vector
{
private:
    int *arr = nullptr; // Pointer to the array holding vector elements
    int size = 0;       // Number of elements currently in the vector
    int capacity = 0;   // Capacity of the vector (maximum elements it can hold)

    // Expands the vector capacity when it's full
    void expand_capacity();

public:
    // Constructor to initialize the vector with a given size
    Vector(int si);
    // Copy constructor for deep copying
    Vector(const Vector &other);
    // Assignment operator for deep copying
    Vector &operator=(const Vector &other);
    // Destructor to free the dynamically allocated memory
    ~Vector();

    int front() const;               // Returns the first element of the vector
    int back() const;                // Returns the last element of the vector
    void set(int index, int val);    // Sets the element at a given index
    void push_back(int val);         // Adds a new element to the end of the vector
    void insert(int index, int val); // Inserts an element at a given index
    int get_size() const;            // Returns the current size of the vector
    int get(int index) const;        // Returns the element at a given index
    void print() const;              // Prints all elements in the vector
    int find(int val) const;         // Returns the index of the first occurrence of a value
    void right_rotate();             // Rotates the vector to the right by 1 position
    void right_rotate(int times);    // Rotates the vector to the right by 'times' positions
    void left_rotate();              // Rotates the vector to the left by 1 position
    int pop(int index);              // Removes and returns the element at the given index
    int find_transposition(int val); // Finds and moves a value closer to the front
};

// Expands the vector's capacity by doubling its current size
void Vector::expand_capacity()
{
    capacity = capacity == 0 ? 1 : capacity * 2; // Double capacity (or set to 1 if 0)
    int *temp_arr = new int[capacity]{};         // Allocate a new array with expanded capacity

    // Copy old array into the new array
    for (int i = 0; i < size; ++i)
    {
        temp_arr[i] = arr[i];
    }

    swap(arr, temp_arr); // Swap old array with the new one
    delete[] temp_arr;   // Free the old array
}

// Constructor to initialize vector with a specified size
Vector::Vector(int si)
{
    if (si <= 0)
    {
        si = 1; // Ensure size is at least 1
    }
    size = si;
    capacity = size * 2;       // Initial capacity is twice the size
    arr = new int[capacity]{}; // Allocate memory for the vector
}

// Copy constructor for deep copying
Vector::Vector(const Vector &other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

// Assignment operator for deep copying
Vector &Vector::operator=(const Vector &other)
{
    if (this == &other)
        return *this;

    delete[] arr;

    size = other.size;
    capacity = other.capacity;
    arr = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }

    return *this;
}

// Destructor to free the dynamically allocated memory
Vector::~Vector()
{
    delete[] arr;  // Deallocate the array memory
    arr = nullptr; // Prevent dangling pointer
    size = 0;
    capacity = 0;
}

// Returns the first element of the vector
int Vector::front() const
{
    if (size == 0)
        throw runtime_error("Vector is empty");
    return arr[0];
}

// Returns the last element of the vector
int Vector::back() const
{
    if (size == 0)
        throw runtime_error("Vector is empty");
    return arr[size - 1];
}

// Sets the element at the given index
void Vector::set(int index, int val)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    arr[index] = val;
}

// Adds a new element to the end of the vector
void Vector::push_back(int val)
{
    if (size == capacity)
    {
        expand_capacity(); // Expand capacity if full
    }
    arr[size++] = val;
}

// Returns the element at a given index
int Vector::get(int index) const
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return arr[index];
}

// Finds the index of the first occurrence of the given value
int Vector::find(int val) const
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == val)
        {
            return i; // Value found, return its index
        }
    }
    return -1; // Return -1 if value is not found
}

// Inserts an element at the given index
void Vector::insert(int index, int val)
{
    if (index < 0 || index > size)
        throw out_of_range("Index out of range");
    if (size == capacity)
    {
        expand_capacity(); // Expand capacity if necessary
    }
    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = val; // Insert the new element
    ++size;
}

// Prints all elements of the vector
void Vector::print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Rotates the vector to the right by one position
void Vector::right_rotate()
{
    if (size <= 1)
        return;

    int last = arr[size - 1];
    for (int i = size - 1; i > 0; --i)
    {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = last; // Move the last element to the front
}

// Rotates the vector to the right by a given number of positions
void Vector::right_rotate(int times)
{
    if (times <= 0 || size <= 1)
        return; // No need to rotate if times is 0 or size is 1

    times %= size; // Normalize the number of rotations

    // Reverse the entire array
    reverse(arr, arr + size);
    // Reverse the first 'times' elements
    reverse(arr, arr + times);
    // Reverse the remaining elements
    reverse(arr + times, arr + size);
}

// Rotates the vector to the left by one position
void Vector::left_rotate()
{
    if (size <= 1)
        return;

    int first = arr[0];
    for (int i = 0; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[size - 1] = first; // Move the first element to the end
}

// Removes and returns the element at the given index
int Vector::pop(int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");

    int element = arr[index]; // Store the element to return
    for (int i = index; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    --size; // Decrease the size of the vector
    return element;
}

// Finds the value and moves it closer to the front (transposition)
int Vector::find_transposition(int val)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == val)
        {
            if (i == 0)
                return i;             // If it's already at the front, return the index
            swap(arr[i], arr[i - 1]); // Swap with the previous element
            return i - 1;             // Return the new index
        }
    }
    return -1; // Return -1 if the value is not found
}

// Main function to test the Vector class
int main()
{
    // Create a vector of size 5 and initialize it
    Vector v(5);
    cout << "Initial vector (size 5): ";
    v.print();

    // Add elements to the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "After adding elements (10, 20, 30): ";
    v.print();

    // Access and modify elements
    cout << "First element (front): " << v.front() << '\n';
    cout << "Last element (back): " << v.back() << '\n';
    v.set(0, 99); // Modify the first element
    cout << "After setting the first element to 99: ";
    v.print();

    // Insert an element at a specific index
    v.insert(2, 50); // Insert 50 at index 2
    cout << "After inserting 50 at index 2: ";
    v.print();

    // Find an element
    int index = v.find(20);
    if (index != -1)
        cout << "Element 20 found at index: " << index << '\n';
    else
        cout << "Element 20 not found\n";

    // Test right rotation by 1
    v.right_rotate();
    cout << "After right rotation by 1: ";
    v.print();

    // Test right rotation by multiple positions
    v.right_rotate(3);
    cout << "After right rotation by 3: ";
    v.print();

    // Test left rotation
    v.left_rotate();
    cout << "After left rotation by 1: ";
    v.print();

    // Remove an element at a specific index
    int removed = v.pop(2); // Remove the element at index 2
    cout << "After removing element at index 2 (removed: " << removed << "): ";
    v.print();

    // Test find with transposition
    index = v.find_transposition(30);
    if (index != -1)
        cout << "Element 30 found and moved closer to the front. New index: " << index << '\n';
    else
        cout << "Element 30 not found\n";
    cout << "After find with transposition: ";
    v.print();

    // Test edge cases
    try
    {
        cout << "Accessing element at invalid index (-1): ";
        cout << v.get(-1) << '\n';
    }
    catch (const out_of_range &e)
    {
        cout << "Caught exception: " << e.what() << '\n';
    }

    try
    {
        cout << "Popping element at invalid index (100): ";
        v.pop(100);
    }
    catch (const out_of_range &e)
    {
        cout << "Caught exception: " << e.what() << '\n';
    }

    // Final state of the vector
    cout << "Final state of the vector: ";
    v.print();

    return 0;
}
