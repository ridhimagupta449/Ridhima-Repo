#include <iostream>
#include <cstring>   
#include <algorithm> 
using namespace std;

int main() {
    char a[50], b[50];

    cout << "Enter first string: ";
    cin.getline(a, 50);

    cout << "Enter second string: ";
    cin.getline(b, 50);

    
    if (strlen(a) != strlen(b)) {
        cout << "The strings are not anagrams." << endl;
        return 0;
    }

    sort(a, a + strlen(a));
    sort(b, b + strlen(b));

    if (strcmp(a, b) == 0)
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}

