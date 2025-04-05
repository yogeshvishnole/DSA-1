#include <iostream>
using namespace std;

int main(int, char **)
{
    int *p = nullptr;
    int *q = nullptr;
    bool ans = p == q == nullptr;
    cout << ans;
    cout << "Hello, from dsa!\n";
    return 0;
}
