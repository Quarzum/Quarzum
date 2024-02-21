#include "./src/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
int main()
{   
    auto start = high_resolution_clock::now();
    qstring path = "../code.qz";
    Source source(path);
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
