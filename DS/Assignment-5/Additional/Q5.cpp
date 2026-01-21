#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int pow;
    Node *next;
};

// Function to create a new node
Node *newNode(int coeff, int pow)
{
    Node *node = new Node();
    node->coeff = coeff;
    node->pow = pow;
    node->next = NULL;
    return node;
}

// Function to insert node at end
void insertEnd(Node **head, int coeff, int pow)
{
    Node *node = newNode(coeff, pow);
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
}

// Function to print polynomial
void printPoly(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[" << temp->coeff << ", " << temp->pow << "]";
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two polynomial linked lists
Node *addPolynomials(Node *p1, Node *p2)
{
    Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            insertEnd(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            insertEnd(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            insertEnd(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL)
    {
        insertEnd(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insertEnd(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;

    int n1, n2, coeff, pow;

    cout << "Enter number of terms in 1st polynomial: ";
    cin >> n1;

    cout << "Enter terms as coefficient and power (in descending order of power):\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> coeff >> pow;
        insertEnd(&poly1, coeff, pow);
    }

    cout << "Enter number of terms in 2nd polynomial: ";
    cin >> n2;

    cout << "Enter terms as coefficient and power (in descending order of power):\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> coeff >> pow;
        insertEnd(&poly2, coeff, pow);
    }

    cout << "\nPolynomial 1: ";
    printPoly(poly1);
    cout << "Polynomial 2: ";
    printPoly(poly2);

    result = addPolynomials(poly1, poly2);

    cout << "\nResultant Polynomial: ";
    printPoly(result);

    return 0;
}
