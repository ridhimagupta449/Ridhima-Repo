#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int possible = 0; 
    
    for (int i = 0; i < s.length(); i++) {
        int count = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[i] == s[j]) {
                count++;
            }
        }
        if (count >= 3) {
            possible = 1;
            break;
        }
    }

    if (possible == 1)
        cout << "Possible to split the string" << endl;
    else
        cout << " NOT possible to split the string" << endl;

    return 0;
}

