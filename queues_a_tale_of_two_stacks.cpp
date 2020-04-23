/* Implement a queue using two stacks. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class MyQueue {
    private:
        stack<T> stack_newest_on_top, stack_oldest_on_top;   
        void loadQueue() {
            if (stack_oldest_on_top.empty()) {
                while(!stack_newest_on_top.empty()) {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
        }
    public:
        void enqueue(T x) {
            stack_newest_on_top.push(x);
        }
        void dequeue() {
            loadQueue();
            stack_oldest_on_top.pop();
        }
        void print() {
            loadQueue();
            cout << stack_oldest_on_top.top() << endl;
        }
};

int main() {
    MyQueue<int> q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.enqueue(x);
        }
        else if(type == 2) {
            q1.dequeue();
        }
        else q1.print();
    }
    return 0;
}
