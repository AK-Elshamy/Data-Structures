/**
 * Improved Doubly Linked List Implementation (Integer-based)
 */
#include <iostream>
#include <stdexcept>

/**
 * Node structure for doubly linked list
 */
struct Node
{
    int data;
    Node *prev;
    Node *next;

    explicit Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

/**
 * Doubly Linked List class with various operations
 */
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

    /**
     * Links two nodes together
     * @param first First node to link
     * @param second Second node to link
     */
    void link(Node *first, Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Destructor - clean up memory
    ~DoublyLinkedList()
    {
        clear();
    }

    /**
     * Clears the list, removing all elements
     */
    void clear()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        length = 0;
    }

    /**
     * Inserts a node at the front of the list
     * @param data Data to insert
     */
    void insertFront(int data)
    {
        Node *newNode = new Node(data);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            link(newNode, head);
            head = newNode;
        }
        ++length;
    }

    /**
     * Inserts a node at the back of the list
     * @param data Data to insert
     */
    void insertBack(int data)
    {
        Node *newNode = new Node(data);

        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            link(tail, newNode);
            tail = newNode;
        }
        ++length;
    }

    /**
     * Inserts a node in sorted order
     * @param data Data to insert
     */
    void insertSorted(int data)
    {
        if (!length || data <= head->data)
        {
            insertFront(data);
            return;
        }

        if (data >= tail->data)
        {
            insertBack(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = head;

        // Find the position to insert
        while (current && data >= current->data)
        {
            current = current->next;
        }

        // Insert between current->prev and current
        Node *prev = current->prev;
        link(prev, newNode);
        link(newNode, current);
        ++length;
    }

    /**
     * Deletes node from the front of the list
     */
    void deleteFront()
    {
        if (!head)
        {
            return; // Nothing to delete
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *nextNode = head->next;
            nextNode->prev = nullptr;
            delete head;
            head = nextNode;
        }
        --length;
    }

    /**
     * Deletes node from the back of the list
     */
    void deleteBack()
    {
        if (!tail)
        {
            return; // Nothing to delete
        }

        if (head == tail)
        {
            deleteFront();
        }
        else
        {
            Node *prevNode = tail->prev;
            prevNode->next = nullptr;
            delete tail;
            tail = prevNode;
            --length;
        }
    }

    /**
     * Deletes all nodes with the given value
     * @param data Value to delete
     */
    void deleteByValue(int data)
    {
        Node *current = head;

        while (current)
        {
            if (current->data == data)
            {
                Node *toDelete = current;

                if (current == head)
                {
                    current = current->next;
                    deleteFront();
                }
                else if (current == tail)
                {
                    current = nullptr; // Will exit the loop after deletion
                    deleteBack();
                }
                else
                {
                    Node *nextNode = current->next;
                    link(current->prev, current->next);
                    current = nextNode;
                    delete toDelete;
                    --length;
                }
            }
            else
            {
                current = current->next;
            }
        }
    }

    /**
     * Prints the list from front to back
     */
    void print() const
    {
        for (Node *current = head; current; current = current->next)
        {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }

    /**
     * Prints the list from back to front
     */
    void printReverse() const
    {
        for (Node *current = tail; current; current = current->prev)
        {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }

    /**
     * Returns the current length of the list
     * @return List length
     */
    int size() const
    {
        return length;
    }

    /**
     * Checks if the list is empty
     * @return True if empty, false otherwise
     */
    bool isEmpty() const
    {
        return length == 0;
    }
};

/**
 * Example main function demonstrating list operations
 */
int main()
{
    DoublyLinkedList list;

    // Demo inserting elements
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);
    list.insertSorted(15);

    std::cout << "List after insertions: ";
    list.print();
    std::cout << "List size: " << list.size() << std::endl;

    // Demo deletion operations
    list.deleteFront();
    std::cout << "After deleting front: ";
    list.print();

    list.deleteBack();
    std::cout << "After deleting back: ";
    list.print();

    // Insert duplicates and delete by value
    list.insertBack(15);
    list.insertBack(15);
    std::cout << "With duplicates: ";
    list.print();

    list.deleteByValue(15);
    std::cout << "After deleting value 15: ";
    list.print();
    std::cout << "List size: " << list.size() << std::endl;

    return 0;
}
c