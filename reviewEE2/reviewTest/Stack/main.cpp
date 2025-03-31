#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() ;
    ~Stack();
    void push(int value);
    int pop();
    bool isEmpty() ;
    int getTopValue();
    void duplicateTop();
    void removeAndPush();
    void clear();
};

Stack::~Stack() {
    clear();
}
Stack::Stack() {
    top = nullptr;
}
bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) pop();
}

void Stack::push(int value) {
    Node *newNode = new Node{value, top};
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) return 0;
    int value = top->value;
    Node *temporary = top;
    top = top->next;
    delete temporary;
    return value;
}

int Stack::getTopValue() {
  if (isEmpty()){
    return -1;
  } else{
    return top->value;
  }
}

void Stack::duplicateTop() {
    if (!isEmpty()) push(getTopValue());
}

void Stack::removeAndPush() {
    if (top == nullptr || top->next == nullptr)
        return;

    int top1 = pop();
    int top2 = pop();

    push(top1 + top2);
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int &v : values) cin >> v;

    Stack stack;
    string commands;
    int lastValue = -1;

    for (int i = 0; i < n; i++) {
        int target = values[i];

        if (lastValue == target) {
            stack.duplicateTop();
            commands += "d";
        } else {
            stack.clear();
            commands += "1";
            stack.push(1);

            while (stack.getTopValue() < target) {
                commands += "1";
                stack.push(1);
                commands += "+";
                stack.removeAndPush();
            }
        }

        lastValue = target;
    }

    cout << commands << endl;
    return 0;
}
