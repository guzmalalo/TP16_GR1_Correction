#include <stdio.h>

void func(int *p) {
    *p *= 2;
}

int main() {
    int *p =NULL;
    func(p);
    printf("%d\n", *p);
    return 0;
}
