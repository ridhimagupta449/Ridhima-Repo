#include <iostream>
#include <stack>
using namespace std;

void dailyTemperatures(int temp[], int n, int answer[]) {
    stack<int> st;  

    for (int i = n - 1; i >= 0; i--) {
        // pop all colder or equal days
        while (!st.empty() && temp[st.top()] <= temp[i]) {
            st.pop();
        }

        // if stack is empty -> no warmer day
        if (st.empty())
            answer[i] = 0;
        else
            answer[i] = st.top() - i;

        // push current day index
        st.push(i);
    }
}

int main() {
    int temp[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temp) / sizeof(temp[0]);
    int answer[n];

    dailyTemperatures(temp, n, answer);

    cout << "Result: ";
    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";
    cout << endl;

    return 0;
}

