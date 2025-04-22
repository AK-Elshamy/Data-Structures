/**
 * Improved Doubly Linked List Implementation in Java
 */

public
class DoublyLinkedList
{
    /**
     * Node class for the doubly linked list
     */
private
    static class Node
    {
        int data;
        Node prev;
        Node next;

    public
        Node(int value)
        {
            this.data = value;
            this.prev = null;
            this.next = null;
        }
    }

    private Node head;
private
    Node tail;
private
    int length;

    /**
     * Constructor for empty list
     */
public
    DoublyLinkedList()
    {
        head = null;
        tail = null;
        length = 0;
    }

    /**
     * Links two nodes together
     * @param first First node to link
     * @param second Second node to link
     */
private
    void link(Node first, Node second)
    {
        if (first != null)
            first.next = second;
        if (second != null)
            second.prev = first;
    }

    /**
     * Inserts a node at the front of the list
     * @param data Data to insert
     */
public
    void insertFront(int data)
    {
        Node newNode = new Node(data);

        if (head == null)
        {
            head = tail = newNode;
        }
        else
        {
            link(newNode, head);
            head = newNode;
        }
        length++;
    }

    /**
     * Inserts a node at the back of the list
     * @param data Data to insert
     */
public
    void insertBack(int data)
    {
        Node newNode = new Node(data);

        if (tail == null)
        {
            head = tail = newNode;
        }
        else
        {
            link(tail, newNode);
            tail = newNode;
        }
        length++;
    }

    /**
     * Inserts a node in sorted order
     * @param data Data to insert
     */
public
    void insertSorted(int data)
    {
        if (length == 0 || data <= head.data)
        {
            insertFront(data);
            return;
        }

        if (data >= tail.data)
        {
            insertBack(data);
            return;
        }

        Node newNode = new Node(data);
        Node current = head;

        // Find the position to insert
        while (current != null && data >= current.data)
        {
            current = current.next;
        }

        // Insert between current.prev and current
        Node prev = current.prev;
        link(prev, newNode);
        link(newNode, current);
        length++;
    }

    /**
     * Deletes node from the front of the list
     */
public
    void deleteFront()
    {
        if (head == null)
        {
            return; // Nothing to delete
        }

        if (head == tail)
        {
            head = tail = null;
        }
        else
        {
            Node nextNode = head.next;
            nextNode.prev = null;
            head = nextNode;
        }
        length--;
    }

    /**
     * Deletes node from the back of the list
     */
public
    void deleteBack()
    {
        if (tail == null)
        {
            return; // Nothing to delete
        }

        if (head == tail)
        {
            deleteFront();
        }
        else
        {
            Node prevNode = tail.prev;
            prevNode.next = null;
            tail = prevNode;
            length--;
        }
    }

    /**
     * Deletes all nodes with the given value
     * @param data Value to delete
     */
public
    void deleteByValue(int data)
    {
        Node current = head;

        while (current != null)
        {
            if (current.data == data)
            {
                if (current == head)
                {
                    current = current.next;
                    deleteFront();
                }
                else if (current == tail)
                {
                    current = null; // Will exit the loop after deletion
                    deleteBack();
                }
                else
                {
                    Node nextNode = current.next;
                    link(current.prev, current.next);
                    current = nextNode;
                    length--;
                }
            }
            else
            {
                current = current.next;
            }
        }
    }

    /**
     * Prints the list from front to back
     */
public
    void print()
    {
        for (Node current = head; current != null; current = current.next)
        {
            System.out.print(current.data + " ");
        }
        System.out.println();
    }

    /**
     * Prints the list from back to front
     */
public
    void printReverse()
    {
        for (Node current = tail; current != null; current = current.prev)
        {
            System.out.print(current.data + " ");
        }
        System.out.println();
    }

    /**
     * Returns the current length of the list
     * @return List length
     */
public
    int size()
    {
        return length;
    }

    /**
     * Checks if the list is empty
     * @return True if empty, false otherwise
     */
public
    boolean isEmpty()
    {
        return length == 0;
    }

    /**
     * Clear the list, removing all nodes
     */
public
    void clear()
    {
        head = null;
        tail = null;
        length = 0;
        // Java's garbage collector will handle the memory cleanup
    }

    /**
     * Main method for testing the doubly linked list
     */
public
    static void main(String[] args)
    {
        DoublyLinkedList list = new DoublyLinkedList();

        // Demo inserting elements
        list.insertBack(10);
        list.insertBack(20);
        list.insertBack(30);
        list.insertFront(5);
        list.insertSorted(15);

        System.out.print("List after insertions: ");
        list.print();
        System.out.println("List size: " + list.size());

        // Demo deletion operations
        list.deleteFront();
        System.out.print("After deleting front: ");
        list.print();

        list.deleteBack();
        System.out.print("After deleting back: ");
        list.print();

        // Insert duplicates and delete by value
        list.insertBack(15);
        list.insertBack(15);
        System.out.print("With duplicates: ");
        list.print();

        list.deleteByValue(15);
        System.out.print("After deleting value 15: ");
        list.print();
        System.out.println("List size: " + list.size());
    }
}