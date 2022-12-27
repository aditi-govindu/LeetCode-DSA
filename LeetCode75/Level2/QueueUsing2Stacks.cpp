/*
Q232. Description: Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
*/

class MyQueue 
{
public:
    stack<int> s1;
    stack<int> s2;
    int front;
    
    void push(int x) 
    {
        // Add elements to 1 stack
        s1.push(x);
    }
    
    int pop() 
    {
        peek();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() 
    {
        // Transfer elements to empty stack and return value at top
        if(s2.empty())
        {
            while(!s1.empty())
            {   
                s2.push(s1.top());
                s1.pop();
             }
        }
        return s2.top();
    }
    
    bool empty() 
    {
        // If both stacks are empty, queue is empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */