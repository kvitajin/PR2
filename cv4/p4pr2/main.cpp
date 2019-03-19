#include <iostream>
#include <cstring>
class Nadstavba{
    std::string JmenoNadstavby;
    int cnt=0;
    int cislo;
public:
    std::string getName();
    Nadstavba getName(std::string jmenoNadstavby);
    Nadstavba(int cislo);
};

std::string Nadstavba::getName() {return this->JmenoNadstavby;}

Nadstavba::Nadstavba(int cislo) {
    this->cislo=cislo;
    ++cnt;
  switch (cislo){
      case 0: this->JmenoNadstavby="Cinnamon";
          break;
      case 1: this->JmenoNadstavby="MATE";
          break;
      case 2: this->JmenoNadstavby="Xfce";
          break;
      case 3: this->JmenoNadstavby="KDE";
          break;
      case 4: this->JmenoNadstavby="Gnome";
          break;
      default: this->JmenoNadstavby="Unity";
  }
}

Nadstavba Nadstavba::getName(std::string jmenoNadstavby) {
    this->JmenoNadstavby=jmenoNadstavby;
}

class Distro{
    std::string JmenoDistra;
    Nadstavba* JmenoNadstavby;
public:
    std::string getDistroName();
    Distro(std::string jmenoDistra);
    Distro(std::string jmenoDistra, std::string JmenoNadstavby);
};

std::string Distro::getDistroName() {return this->JmenoDistra;}

Distro::Distro(std::string jmenoDistra) {
    this->JmenoDistra=jmenoDistra;
}
Distro::Distro(std::string jmenoDistra, std::string JmenoNadstavby) {
    this->JmenoDistra=jmenoDistra;
    //this->JmenoNadstavby=
}


class Branch{
    std::string JmenoVetve;
    int potomci=0;
public:
    std::string getBranchName();
    int getDescedant();
    Branch(std::string JmenoVetve);
    Distro* createDistro(std::string name);
    Distro* createDistro(std::string name, std::string nadstavba);
};

std::string Branch::getBranchName() {return this->JmenoVetve;}

Branch::Branch(std::string JmenoVetve) {
    this->JmenoVetve=JmenoVetve;
}

Distro* Branch::createDistro(std::string name) {
    this->JmenoVetve=name;
}
Distro* Branch::createDistro(std::string name, std::string nadstavba) {
    this->JmenoVetve=name;

}

int Branch::getDescedant() { return this->potomci;}




int main() {



    return 0;
}