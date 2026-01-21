#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *prev, *next;
};

Node *head = NULL;

// Function to insert node at end
void insertEnd(char ch)
{
    Node *newNode = new Node{ch, NULL, NULL};
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to check if the list is palindrome
bool isPalindrome()
{
    if (head == NULL || head->next == NULL)
        return true;

    // Move to the last node
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
        right = right->next;

    // Compare from both ends
    while (left != right && right->next != left)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter characters for linked list: ";
    cin >> str;

    // Create doubly linked list from string
    for (char ch : str)
        insertEnd(ch);

    // Check palindrome
    if (isPalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
