#include <iostream>
#include <string>
#include <algorithm>   
using namespace std;

int main() {
    char a[50], b[50];
    cout << "Enter first string: ";
    cin.getline(a, 50);
    cout << "Enter second string: ";
    cin.getline(b, 50);

    // (a) Concatenate
    string s1 = a;
    string s2 = b;
    string concat = s1 + s2;
    cout << "\nConcatenated string = " << concat << endl;

    // (b) Reverse the first string
    int c = 0;
    for (int i = 0; a[i] != '\0'; i++)
        c++;
    cout << "Reversed first string: ";
    for (int i = c - 1; i >= 0; i--)
        cout << a[i];
    cout << "\nLength of first string = " << c << endl;

    // (c) Delete vowels from first string
    string result = "";
    int vowelCount = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||
            a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U') {
            vowelCount++;
        } else {
            result += a[i];
        }
    }
    cout << "Number of vowels deleted = " << vowelCount << endl;
    cout << "String after deleting vowels: " << result << endl;

    // (d) Sort strings alphabetically
    string arr[2] = {s1, s2};
    sort(arr, arr + 2);
    cout << "\nStrings in alphabetical order: " << arr[0] << ", " << arr[1] << endl;

    // (e) Convert uppercase to lowercase
    string lower = s1;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "First string in lowercase: " << lower << endl;

    return 0;
}

