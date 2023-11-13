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
    bool isNElement(int i, char c)
    {
        return s[i] == c;
    }

private:
    string s;
};