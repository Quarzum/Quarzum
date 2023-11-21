#define NC "\e[0m"
#define RED_BG "\e[31m"
#define YELLOW_BG "\e[93m"
#define GREEN_BG "\e[30;102m"
#define TEAL "\e[36;40m"
#define YELLOW "\e[93;40m"
#define GRAY "\e[90;40m"
typedef unsigned char uint8;
class Buffer
{
public:
    // Adds a new char to the buffer
    void add(char c)
    {
        s += c;
    }
    // Reads the buffer and returns the content
    string read()
    {
        return s;
    }
    // Delete all the content inside the buffer
    void clear()
    {
        s.clear();
    }
    // Returns true if the N element is the provided
    bool isFirstElement(char c)
    {
        return s[0] == c;
    }

private:
    string s;
};

class Collection
{
public:
    Collection(map<string, uint8> map) : content(move(map)) {}
    // Returns true if a provided string exists
    bool find(string s)
    {
        return content.find(s) != content.end();
    }
    // Returns the index of the provided element
    uint8 index(string s)
    {
        return content.at(s);
    }

private:
    map<string, uint8> content;
};

enum MessageType
{
    SUCCESS = 10001,
    WARN = 10002,
    ERR = 10003
};

class Message
{
public:
    Message(MessageType t, string c, string errt)
    {
        type = t;
        content = c;
        errtype = errt;
    }

    // Show in console the formatted message
    void print()
    {
        switch (type)
        {
        case SUCCESS:
            cout << GREEN_BG "Success! | " NC;
            cout << content << endl;
            break;
        case WARN:
            cout << YELLOW_BG "Warning! | " NC;
            cout << content << endl;
            break;
        case ERR:
            cout << RED_BG "Error! | " NC;
            cout << errtype << ": " << content << endl;
            break;
        }
    }

private:
    MessageType type;
    string content, errtype;
};

class MessageStack
{
public:
    // Add a new success message to the stack
    void success(string content)
    {
        add(SUCCESS, content, "");
    }
    // Add a new warning to the stack
    void warn(string content)
    {
        add(WARN, content, "");
    }
    // Add a new error to the stack
    void err(string content, string errt)
    {
        add(ERR, content, errt);
        errcount++;
    }
    // Print all the stored messages
    void print()
    {
        for (size_t i = 0; i < stack.size(); i++)
        {
            stack[i].print();
        }
        if (errcount > 0)
        {
            cerr << "Process finished with " << errcount << " error" << (errcount > 1 ? "s" : "") << endl
                 << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            errcount = 0;
            stack.clear();
        }
    }

private:
    deque<Message> stack;
    int errcount = 0;
    // Add a new message to the stack
    void add(MessageType t, string content, string errt)
    {
        Message msg = Message(t, content, errt);
        stack.push_back(msg);
    }
};
static MessageStack Debug = MessageStack();
