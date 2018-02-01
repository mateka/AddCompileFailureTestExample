#include <sum.h>

class empty {};

int main() {
    empty a;
    empty b;
    empty c =  hlib::sum(a, b);
}