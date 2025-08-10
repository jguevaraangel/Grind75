#include<iostream>
#include<stack>
using namespace std;

class MyQueue {

stack<int> input;
stack<int> output;
public:
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                int t = input.top();
                input.pop();
                output.push(t);
            }
            int p = output.top();
            output.pop();
            return p;
        }
        int p = output.top();
        output.pop();
        return p;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                int t = input.top();
                input.pop();
                output.push(t);
            }
            return output.top();
        }
        return output.top();
    }
    
    bool empty() {
        if ((input.empty()) && (output.empty())) {
            return true;
        }
        return false;
    }
};

int main () {
  MyQueue* obj = new MyQueue();
  int x = 3;
  cout << "Pushing x =" << x << endl;
  obj->push(x);
  int param_2 = obj->pop();
  cout << "Popping..." << param_2 << endl;
  bool param_4 = obj->empty();
  cout << "Is empty?: " << param_4 << endl;
  return 0;
}
