#define STACK_MAX 50
class Stack
{
public:
    Stack()
    {
        top = 0;
    }
    void push(char v)
    {
        st[++top] = v;
    }
    char pop()
    {
        return st[top--];
    }
    int getTop()
    {
        return top;
    }

private:
    char st[STACK_MAX];
    int top;
};