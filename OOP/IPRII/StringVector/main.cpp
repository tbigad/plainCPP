#include <iostream>
#include "stringvector.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    StringVector vec("Hello");
    vec.pushBack("world");
    vec << "my" << "dear" << "friend";
    int i = vec.size();
    while (i!=0) {
        cout<< vec[i-1]<<'\n';
        i--;
    }

    cout<<'\n';
    i = vec.size();
    while (i!=0) {
        cout<< vec.popFront_C_str()<<'\n';
        i--;
    }
    return 0;
}
