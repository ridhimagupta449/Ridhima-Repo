/*The school cafeteria offers circular and square sandwiches at lunch break, referred to by
numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
sandwiches are placed in a stack. At each step:
● If the student at the front of the queue prefers the sandwich on the top of the stack, they
will take it and leave the queue.
● Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus
unable to eat
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudents(int students[], int sandwiches[], int n)
{
    queue<int> q;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
        s.push(sandwiches[i]);

    for (int i = 0; i < n; i++)
        q.push(students[i]);

    int count = 0;

    while (!q.empty() && !s.empty())
    {
        if (q.front() == s.top())
        {

            q.pop();
            s.pop();
            count = 0;
        }
        else
        {

            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;

            if (count == q.size())
                break;
        }
    }

    return q.size();
}

int main()
{
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = sizeof(students) / sizeof(students[0]);

    int result = countStudents(students, sandwiches, n);
    cout << result;

    return 0;
}
