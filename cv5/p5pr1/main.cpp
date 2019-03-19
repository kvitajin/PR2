#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

class Client{
    static  int objectCount;
    int code;
    std::string name;
public:
    static int getObjectCount();
    Client(int c, std::string n);
    ~Client();
    int getCode();
    std::string getName();
};
int Client::objectCount=0;

Client::Client(int c, std::string n) {
    this->code=c;
    this->name= n;
    Client::objectCount++;
}

int Client::getCode()           {return this->code;}

std::string Client::getName()   {return this->name;}

int Client::getObjectCount()    {return Client::objectCount;}

Client::~Client()               {Client::objectCount--;}


class Account{
    static int accountCount;
    int number=0;
    double balance=0, interestRate=0;

    Client* owner= nullptr;
    Client* partner= nullptr;
public:
    static int getObjectCount();
    Account(int n, Client *c);
    Account(int n, Client *c, double ir);
    Account(int n, Client *c, Client *p);
    Account(int n, Client *c, Client *p, double ir);
    ~Account();

    int    getNumber();
    double getBalance();
    double getInterestRate();
    Client *getOwner();
    Client *getPartner();
    bool   canWithdraw(double a);

    void Deposit(double cash);
    bool Withdraw(double a);
    void AddInterest();
};
int Account::accountCount=0;

Account::Account(int n, Client *c)                          {
    this->number=n;
    this->owner=c;
    this->accountCount++;
}
Account::Account(int n, Client *c, double ir)               {
    this->number=n;
    this->owner=c;
    this->interestRate=ir;
    this->accountCount++;

}
Account::Account(int n, Client *c, Client *p)               {
    this->number=n;
    this->owner=c;
    this->partner=p;
    this->accountCount++;

}
Account::Account(int n, Client *c, Client *p, double ir)        {
    this->number=n;
    this->owner=c;
    this->partner=p;
    this->interestRate=ir;
    this->accountCount++;

}


double  Account::getBalance()           { return this->balance;}
int     Account::getNumber()            {return this->number;}
double  Account::getInterestRate()      {return this->interestRate;}
Client* Account::getOwner()             {return this->owner;}
Client* Account::getPartner()           { return this->partner;}
bool    Account::canWithdraw(double a)  {
    return a > Account::balance;
}

void Account::Deposit(double cash)      {
    balance+=cash;
}
bool Account::Withdraw(double a)        {
    if(canWithdraw(a)){
        balance-=a;
        return true;
    }
    else
        return false;
}
void Account::AddInterest()             {
    balance*=interestRate;
}

int Account::getObjectCount() {return Account::accountCount;}

Account::~Account() {Account::accountCount--;}

class Bank {
    Client** client;
    int clientCount;
    Account** accounts;
    int accountsCount;

public:
    Bank(int c, int a);
    ~Bank();

    Client* getClient(int c);
    Account* getAccount(int n);

    Client* createClient(int c, std::string n);
    Account* createAccount(int n, Client *c);
    Account* createAccount(int n, Client *c, double ir);
    Account* createAccount(int n, Client *c, Client *p);
    Account* createAccount(int n, Client *c, Client *p, double ir);

    void addInterest();
};

Bank::Bank(int c, int a){
    this->clientCount = 0;
    this->accountsCount = 0;
    this->client = new Client*[c];
    this->accounts = new Account*[a];
}
Bank::~Bank(){
    for (unsigned int i = 0; i < this->clientCount; i++) {
        delete this->client[i];
    }
    for (unsigned int i = 0; i < this->accountsCount; i++) {
        delete this->accounts[i];
    }
    delete[] this->client;
    delete[] this->accounts;
}

Client* Bank::createClient(int c, std::string n) {
    auto *NewClient= new Client(c, n);
    this->client[clientCount++]=NewClient;
    return NewClient;
}
Account* Bank::createAccount(int n, Client *c) {
    auto* newAcc=new Account(n, c);
    this->accounts[accountsCount++]=newAcc;
    return newAcc;
}
Account* Bank::createAccount(int n, Client *c, double ir) {

    auto* newAcc=new Account(n, c, ir);
    this->accounts[accountsCount++]=newAcc;
    return newAcc;
}

Account* Bank::createAccount(int n, Client *c, Client *p) {
    auto* newAcc=new Account(n, c, p);
    this->accounts[accountsCount++]=newAcc;
    return newAcc;
}
Account *Bank::createAccount(int n, Client *c, Client *p, double ir) {
    auto* newAcc=new Account(n, c, p, ir);
    this->accounts[accountsCount++]=newAcc;
    return newAcc;
}

Client* Bank::getClient(int c)   {

    for (int i = 0; i < this->clientCount; i++) {
        if (this->client[i]->getCode() == c) {
            return client[i];
        }
    }
    return nullptr;
}

void Bank::addInterest()         {
    for (int i = 0; i < this->accountsCount; ++i) {
            this->accounts[i]->AddInterest();
    }
}

Account *Bank::getAccount(int n) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i]->getNumber() == n) {
            return this->accounts[i];
        }
    }
    return nullptr;
}

int main() {

    Bank csob(10, 20);
    Bank UniCredit(10, 20);

    for (int i = 0; i < 10; ++i) {
        csob.createClient(i, "aaa");
    }
    for (int j = 0; j < 10; ++j) {
        UniCredit.createClient(j, "bbb");
    }
    for (int i = 1; i < 10; ++i) {
        csob.createAccount(i,csob.getClient(i+1));
        UniCredit.createAccount(i, UniCredit.getClient(i+6), UniCredit.getClient(i+1), 1.2);
        csob.getAccount(i)->Deposit(i*2000);
        UniCredit.getAccount(i)->Deposit(i*1000);
    }

    std::cout<<UniCredit.getClient(0)->getName()    <<  std::endl;
    UniCredit.addInterest();
    UniCredit.getAccount(4)->Withdraw(500);
    std::cout <<    csob.getAccount(7)->getBalance()<<  std::endl;




    return 0;
}