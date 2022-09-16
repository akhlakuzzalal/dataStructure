#include <bits/stdc++.h>
#include "stack.h"

using namespace std;

int checkPrecidence(char a);
string prefixConvert(string infix);
int calculatePrefix(string s);

int checkPrecidence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
        return -1;
}

string prefixConvert(string infix)
{
    string result;
    Stack<char> st;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i <= infix.length() - 1; i++)
    {
        if ((infix[i] >= '0') && (infix[i] <= '9'))
        {
            result += infix[i];
        }
        else
        {
            if (infix[i] == ')')
            {
                st.push(infix[i]);
            }
            else if (infix[i] == '(')
            {
                while (!st.isEmpty() && st.Top() != ')')
                {
                    result += st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.isEmpty() && checkPrecidence(st.Top()) > checkPrecidence(infix[i]))
                {
                    result += st.pop();
                }
                st.push(infix[i]);
            }
        }
    }
    while (!st.isEmpty())
    {
        result += st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}

int calculatePrefix(string s)
{
    Stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push((int)(s[i] - '0'));
        }
        else
        {
            int a = st.pop();
            int b = st.pop();
            switch (s[i])
            {
            case '^':
                st.push(pow(a, b));
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;

            default:
                break;
            }
        }
    }
    return st.pop();
}

int main()
{
    string st;
    cout << "inter a infix string" << endl;
    cin >> st;
    string prefix = prefixConvert(st);
    cout << endl
         << prefix << endl
         << endl
         << calculatePrefix(prefix) << endl;

    return 0;
}