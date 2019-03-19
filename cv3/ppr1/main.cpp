#include <iostream>

class KeyValue{
    int key;
    double value;
public:
    KeyValue    (int k, double v);
    int         GetKey();
    double      GetValue();
};

class listKeyValue{
    KeyValue** keyValues;
    int count;
public:
    listKeyValue(int n);
    ~listKeyValue();
    KeyValue* CreateObject(int k, double v);
    KeyValue* SearchObject(int k);
    KeyValue* RemoveObject(int k);
    KeyValue* PrintAll();

    int Count();
};

KeyValue::KeyValue(int k, double v) {
    this->key=k;
    this->value=v;
}

int KeyValue::GetKey() {
    return this->key;
}
double KeyValue::GetValue() {
    return this->value;
}

listKeyValue::listKeyValue(int n) {
    this->keyValues=new KeyValue*[n];
    this->count=0;
}
listKeyValue::~listKeyValue() {
    for (int i = 0; i < this->count; ++i) {
        delete this->keyValues[i];
    }
    delete[] this->keyValues;
}
int listKeyValue::Count() {
    return this->count;
}
KeyValue* listKeyValue::CreateObject(int k, double v) {
    auto *newObject= new KeyValue(k, v);
    this->keyValues[this->count]=newObject;
    this->count +=1;
    return newObject;
}

KeyValue* listKeyValue::SearchObject(int k) {
    for (int i = 0; i < this->count; ++i) {
        if (this->keyValues[i]->GetKey()==k){
            return this->keyValues[i];
        }
    }
    return nullptr;
}
KeyValue* listKeyValue::RemoveObject(int k){
    //std::cout<<SearchObject(k)<<" hovno"    <<  std::endl;                     //TODO dodelat
    delete SearchObject(k);
    listKeyValue::count--;
    return this->keyValues[k];

}
KeyValue* listKeyValue::PrintAll() {
    for (int i = 0; i < this->count; ++i) {
        std::cout<<this->keyValues[i]->GetKey()<<std::endl;
    }
}
int main (){
    const int N=10;
    auto* myKeyValues = new listKeyValue(N);
    //KeyValue* myKeyValue=myKeyValues->CreateObject(0,0.5);
    //std::cout   << myKeyValue->GetValue()   <<  std::endl;
    for (int i = 0; i < N; ++i) {
        myKeyValues->CreateObject(i, i+0.5);
    }
    std::cout<<myKeyValues->RemoveObject(2)<<std::endl;
    myKeyValues->PrintAll();
    //std::cout   <<  myKeyValues->SearchObject(4)->GetValue()<<std::endl;
    //delete myKeyValues;
    return 0;
}