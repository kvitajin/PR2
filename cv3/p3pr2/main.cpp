#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <random>
std::random_device rd;
class PolozkaFaktury{
    std::string nazev;
    double cena=0;
public:
    double      getPrice();
    std::string getName();
    void        setPrice(double price);
    void        setName(std::string name);

};

class Osoba{
    std::string jmeno, adresa;
public:
    std::string getName();
    std::string getAdress();
    void setAdress(std::string adresa);
    void  setName(std::string jmeno);

};

std::string Osoba::getName() {return jmeno;}

std::string Osoba::getAdress() {return adresa;}

void Osoba::setAdress(std::string adresa) {this->adresa=adresa;}

void Osoba::setName(std::string jmeno) {this->jmeno=jmeno;}


class Faktura{
    int cislo=rd()%rd();

    std::vector<PolozkaFaktury> pff;
    //PolozkaFaktury* pff;

public:
    double sum();
    void addArticle(double price, std::string name);
};
double Faktura::sum() {
    double sum=0;
    for (auto &i : Faktura::pff) {
        sum+= i.getPrice();
    }
    return sum;
}
void Faktura::addArticle(double price, std::string name) {
    auto *tmp= new PolozkaFaktury;
    tmp->setName(name);
    tmp->setPrice(price);
    pff.push_back(*tmp);
}

std::string PolozkaFaktury::getName() {return this->nazev;}
double PolozkaFaktury::getPrice() { return this->cena;}

void PolozkaFaktury::setName(std::string name) {this->nazev= name;}
void PolozkaFaktury::setPrice(double price) {this->cena=price;}

int main() {
    Faktura a;
    for (int i = 0; i < 5; ++i) {
        a.addArticle(i*i+0.5, "aaa");
    }
    std::cout <<    a.sum() <<  "grlc"  <<   std::endl;

    return 0;
}