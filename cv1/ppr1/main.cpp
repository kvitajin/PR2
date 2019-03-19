#include <iostream>
#include <vector>
#include <random>

std::random_device rd;
std::vector<int> pole;

void fill(){
    int i;

    do{
        i=rd()%100;
        pole.push_back(i);
    }
    while (i!=0);
}
int sum(){
    int sum=0;
    for (int i : pole) {
        sum+= i;
    }
    return sum;
}

void print(){
    std::cout   <<  "Array of size "    <<  pole.size() <<  " contains: ";
    for (int i : pole) {
        std::cout   << i <<   ",";
    }
    std::cout   <<  std::endl   << "Sum of items is: " <<  sum();
}

int main() {
    fill();
    print();

    return 0;
}