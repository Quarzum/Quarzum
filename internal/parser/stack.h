#define STACK_MAX 50
class Stack
{
public:
    Stack()
    {
        top = 0;
    }
    void push(string v)
    {
        st[++top] = v;
    }
    string pop()
    {
        return st[top--];
    }
    int getTop()
    {
        return top;
    }

private:
    string st[STACK_MAX];
    int top;
};