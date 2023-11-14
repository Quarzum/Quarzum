#define NC "\e[0m"
#define RED_BG "\e[30;41m"
#define YELLOW_BG "\e[30;103m"
#define GREEN_BG "\e[30;102m"
#define TEAL "\e[36;40m"
#define YELLOW "\e[93;40m"
#define GRAY "\e[90;40m"

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
    Collection(map<string, unsigned __int8> map) : content(move(map)) {}
    // Returns true if a provided string exists
    bool find(string s)
    {
        return content.find(s) != content.end();
    }
    // Returns the index of the provided element
    unsigned __int8 index(string s)
    {
        return content.at(s);
    }

private:
    map<string, unsigned __int8> content;
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
    Message(MessageType t, string c, string errtype = "")
    {
        type = t;
        content = c;
        errtype = errtype;
    }

    // Show in console the formatted message
    void print()
    {
        switch (type)
        {
        case SUCCESS:
            cout << GREEN_BG "[SUCCESS]" NC;
            cout << " " + content << endl;
            break;
        case WARN:
            cout << YELLOW_BG "[SUCCESS]" NC;
            cout << " " + content << endl;
            break;
        case ERR:
            cout << RED_BG "[ERROR]" NC;
            cout << " " + errtype << ": " << content << endl;
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
        add(SUCCESS, content);
    }
    // Add a new warning to the stack
    void warn(string content)
    {
        add(WARN, content);
    }
    // Add a new error to the stack
    void err(string content, string errtype)
    {
        add(ERR, content, errtype);
    }
    // Print all the stored messages
    void print()
    {
        for (size_t i = 0; i < stack.size(); i++)
        {
            stack[i].print();
        }
    }

private:
    deque<Message> stack;

    // Add a new message to the stack
    void add(MessageType t, string content, string errtype = "")
    {
        Message msg = Message(t, content, errtype);
        stack.push_back(msg);
    }
};