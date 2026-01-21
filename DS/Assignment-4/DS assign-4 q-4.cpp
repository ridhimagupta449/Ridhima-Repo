#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str)
{
    unordered_map<char, int> freq; // frequency map
    queue<char> q;                 // queue to store characters

    for (char ch : str)
    {
        if (ch == ' ')
            continue; // skip spaces if input has them

        // update frequency
        freq[ch]++;

        // push into queue
        q.push(ch);

        // remove all characters from front that are repeating
        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }

        // print first non-repeating
        if (q.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    cout << "Output: ";
    firstNonRepeating(str);

    return 0;
}
