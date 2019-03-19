#include <iostream>
#include <cstdio>

class Vertex{
    int data;
    int id;

    int sibCount;

    Vertex* next;
    Vertex* prev;

    Vertex** siblings;

public:
    Vertex(int, int);
    ~Vertex();
    void    setData (int data)      {this->data=data;}
    int     getData ()              {return (this->data);}

    void    setId   (int id)        {this->id=id;}
    int     getId   ()              {return(this->id);}
    void    setNext (Vertex* next)  {this->next=next;}
    Vertex* getNext ()              {return(this->next);}
    void    setPrev (Vertex* prev)  {this->prev=prev;}
    Vertex* getPrev ()              {return(this->prev);}

    void insertSibling(Vertex* sibling);
};
Vertex::Vertex(int id, int data) {
    this->id=id;
    this->data=data;

    this->next= nullptr;
    this->prev= nullptr;

    this->sibCount=10;

    this->siblings=new Vertex*[sibCount];

    for (int i = 0; i < this->sibCount; ++i) {
        this->siblings[i]= nullptr;
    }
}

Vertex::~Vertex(){
    delete [] this->siblings;
    this->siblings= nullptr;
}

void Vertex::insertSibling(Vertex* sibling){
    int i=0;
    while(i<this->sibCount && this->siblings[i]!= nullptr){++i;}

    if (i>=this->sibCount){
        std::cout   <<  "no more siblings"  <<  std::endl;
        return;
    }

    this->siblings[i]=sibling;

}
class List
    {
    private:
    Vertex* head;

    void internalInsertItem(Vertex* item, Vertex* lastItem);

    public:
    List();
    List(Vertex* head);

    Vertex* getNextItem(Vertex* item);
    Vertex* getPrev();
    void insertItem(Vertex* item);
    void deleteItem(int value);
    Vertex* findItem(int id);

    /* NEW */
    Vertex* getHead(void) { return(this->head); };
    void eraseList(void);
    };

List::List()
{
    this->head = NULL;
}

List::List(Vertex* item)
{
    this->head = head;
}

void List::insertItem(Vertex* item)
{
    if (this->head == NULL)
    {
        this->head = item;
        return;
    }

    internalInsertItem(item, this->head);
}

void List::internalInsertItem(Vertex* item, Vertex* lastItem)
{
    if (lastItem == NULL)
    {
        lastItem = item;
        return;
    }

    if (lastItem->getNext() == NULL)
    {
        lastItem->setNext(item);
        item->setPrev(lastItem);
        return;
    }

    internalInsertItem(item, lastItem->getNext());
    return;
}

void List::deleteItem(int value)
{
    Vertex* item = findItem(value);

    if (item == NULL)
        return;

    if (item->getPrev() != NULL)
    {
        item->getPrev()->setNext(item->getNext());
    }

    if (item->getNext() != NULL)
        item->getNext()->setPrev(item->getPrev());

    if (item == this->head)
        this->head = item->getNext();

    delete(item);

    return;
}

/* NEW */
void List::eraseList(void)
{
    if (this->head == NULL)
        return;

    Vertex* current = this->head;
    Vertex* next;

    while(current != NULL)
    {
        next = current->getNext();
        delete(current);
        current = next;
    }

    this->head = NULL;
}

Vertex* List::findItem(int id)
{
    Vertex* lastItem = this->head;

    while(lastItem != NULL)
    {
        if (lastItem->getId() != id)
        {
            lastItem = lastItem->getNext();
        }
        else
            break;
    }

    return(lastItem);
}

Vertex* List::getNextItem(Vertex* item)
{
    return(item->getNext());
}

class Graph{
    List verticies;
public:
    void insert(Vertex*);
    void insert(Vertex*, int*, int);
};

void Graph::insert(Vertex *vertex) {
    this->verticies.insertItem(vertex);
    return;
}
void Graph::insert(Vertex *vertex, int *siblings, int count) {
    this->insert(vertex);
    for (int i = 0; i < count; ++i) {
        Vertex* sibling=this->verticies.findItem(siblings[i]);
        if (sibling != nullptr){
            vertex->insertSibling(sibling);
            if (vertex!=sibling){                  //kdyby byla smycka, tak abych ji nezavedl dvakrat
                sibling->insertSibling(vertex);

            }
        }
    }

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
