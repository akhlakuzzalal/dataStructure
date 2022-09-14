#include <bits/stdc++.h>
#include "stack.h"

using namespace std;

int main()
{
    Stack<float> st;
    st.push(6.45);
    st.push(4.65);

    // cout << "pop: " << st.pop() << endl;
    cout << "SIze: " << st.size() << endl;
    cout << "pop: " << st.pop() << endl;
    cout << "pop: " << st.pop() << endl;
    cout << "SIze: " << st.size() << endl;
    cout << "pop: " << st.Top() << endl;
    return 0;
}