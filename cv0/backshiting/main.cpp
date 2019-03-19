#include <iostream>
#include <vector>
#include <random>

std::random_device rd;

std::vector<std::vector<int> > pole;
std::vector<std::vector<bool> > stand;
int fill(const int i){
    pole.resize(i);
    for (int j = 0; j < i; ++j) {
        pole[j].resize(i);
    }
    if (i>10){
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < i; ++k) {
                pole[j][k]=rd()%9+1;
            }
        }
    }
    else {
        for (int k = 0; k < i; ++k) {
            for (int j = 0; j < i; ++j) {
                pole[k][j] = rd() % (i - 1)+1;
            }
        }
    }
}
void print(){
    for (int i = 0; i < pole.size(); ++i) {
        for (int j = 0; j < pole.size(); ++j) {
            std::cout   <<  pole[i][j]  <<  " ";
        }
        std::cout   <<  "\n";
    }
}
int main() {
    int i=0;
    std::cout << "Jak chces velke pole?" << std::endl;
    std::cin    >>  i;
    fill(i);
    print();
    return 0;
}