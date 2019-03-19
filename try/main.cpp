#include <iostream>

int main() {
    int S=10, R=50;
    auto** pole= new int * [S];
    for (int j = 0; j < S; ++j) {
        pole[j]=new int[R];
    }
    for (int i = 0; i < S; ++i) {
        delete[] pole [i];
    }
    return 0;
}