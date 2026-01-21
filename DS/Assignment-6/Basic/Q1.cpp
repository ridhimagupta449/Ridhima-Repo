#include<iostream>
using namespace std;

// -------------------- DOUBLY LINKED LIST --------------------
class DoublyLinkedList
{
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    void insertAfter(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << key << ".\n";
    }

    void insertBefore(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
        cout << "Inserted " << val << " before " << key << ".\n";
    }

    void deleteNode(int key)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node " << key << ".\n";
    }

    void searchNode(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display()
    {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// -------------------- CIRCULAR LINKED LIST --------------------
class CircularLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    void insertAfter(int key, int val)
    {
        if (!head)
        {
            cout << "List empty.\n";
            return;
        }
        Node *temp = head;
        do
        {
            if (temp->data == key)
            {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << val << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key)
    {
        if (!head)
        {
            cout << "List empty.\n";
            return;
        }
        Node *temp = head, *prev = nullptr;
        do
        {
            if (temp->data == key)
            {
                if (temp == head && temp->next == head)
                {
                    head = nullptr;
                }
                else
                {
                    if (temp == head)
                    {
                        Node *last = head;
                        while (last->next != head)
                            last = last->next;
                        head = head->next;
                        last->next = head;
                    }
                    else
                        prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void searchNode(int key)
    {
        if (!head)
        {
            cout << "List empty.\n";
            return;
        }
        Node *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == key)
            {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void display()
    {
        if (!head)
        {
            cout << "List empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Circular Linked List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};

// -------------------- MAIN MENU --------------------
int main()
{
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, key;

    while (true)
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Use Doubly Linked List\n";
        cout << "2. Use Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> listType;
        if (listType == 3)
            break;

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node (DLL only)\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "8. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (listType == 1)
        { // Doubly Linked List
            switch (choice)
            {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                dll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                dll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter key: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 6:
                cout << "Enter key: ";
                cin >> key;
                dll.searchNode(key);
                break;
            case 7:
                dll.display();
                break;
            }
        }
        else if (listType == 2)
        { // Circular Linked List
            switch (choice)
            {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                cll.insertAfter(key, val);
                break;
            case 5:
                cout << "Enter key: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter key: ";
                cin >> key;
                cll.searchNode(key);
                break;
            case 7:
                cll.display();
                break;
            }
        }
    }
    cout << "Program exited.\n";
    return 0;
}
