#include "./src/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
int main(int argc, char *argv[])
{   
    qstring str = "Hello world!";
    qstring str2= "i";
    qstring str3 = str + str2;
    cout << str3.value << str2.length() << str2.size() << endl;

     auto start = high_resolution_clock::now();
     Source source("../code.qz");

     Tokenizer t(source.getContent());
     Parser p(t.tokenize());

    createFile("out.asm", analyze(p.parse()));
     system("as -o out.o out.asm");
     system("ld -o out out.o");
     system("./out");
     auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << "\n";
    return 0;
}
