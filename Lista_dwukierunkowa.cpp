#include <iostream>
#include <stdlib.h>

using namespace std;

class Node {
    unsigned long long int data;
    Node* next;
    Node* prev;
    public:
        Node(unsigned long long int data = 0, Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
        void setData(unsigned long long int data) { this->data = data; }
        unsigned long long int getData() { return this->data; }
        Node* getNext() { return this->next; }
        Node* getPrev() { return this->prev; }
        void setNext(Node* next) { this->next = next; }
        void setPrev(Node* prev) { this->prev = prev; }
};

void insertAfter(Node* prevNode, Node** beg, Node** end,  unsigned long long int newData) {
    Node* newNode = new Node();
    newNode->setData(newData);
    newNode->setNext(NULL);
    if (prevNode == NULL || prevNode == *beg) {
        newNode->setPrev(NULL);
        *beg = newNode;
        *end = newNode;
        return;
    }

    newNode->setPrev(prevNode);
    if (prevNode->getNext() != NULL) {
        newNode->setNext(prevNode->getNext());
        newNode->getNext()->setPrev(newNode);
    }
    else (*end) = newNode;
    prevNode->setNext(newNode);
}

void insertBefore(Node* node, Node** head, unsigned long long int newData) {
    if (node == NULL) return;
    Node* newNode = new Node();
    newNode->setNext(node);
    newNode->setData(newData);
    newNode->setPrev(node->getPrev());
    node->setPrev(newNode);
    if (newNode->getPrev() == NULL) return;
    newNode->getPrev()->setNext(newNode);
}

void removeNode(Node** beg, Node **end, Node* node) {
    if (node == NULL || *beg == NULL) return;
    if ((*beg) == node)
        (*beg) = node->getNext();
    else if (node == (*end)) (*end) = node->getPrev();
    if (node->getNext() != NULL)
        node->getNext()->setPrev(node->getPrev());
    if (node->getPrev() != NULL)
        node->getPrev()->setNext(node->getNext());
    delete node;
}

void addFirst(Node** head, Node** end, int newData) {
    Node* newNode = new Node();

    newNode->setData(newData);
    newNode->setNext((*head));
    newNode->setPrev(NULL);

    if ((*head) != NULL)
        (*head)->setPrev(newNode);
    else (*end) = newNode; 

    (*head) = newNode;
}

void addLast(Node** beg, Node** end, int newData) {
    Node* newNode = new Node();
    newNode->setData(newData);
    newNode->setNext(NULL);

    if ((*beg) == NULL) {
        newNode->setPrev(NULL);
        *beg = newNode;
        *end = newNode;
    }

    while ((*end)->getNext() != NULL)
        (*end) = (*end)->getNext();

    (*end)->setNext(newNode);
    newNode->setPrev((*end));
    (*end) = newNode;
    (*end)->setNext(NULL);
}

void printList(Node* beg, Node* end) {
    if (beg == NULL);
    else if (beg == end) cout << " " << beg->getData() << endl;
    else {
        while (beg != end) {
            cout << " " << beg->getData() << " ";
            beg = beg->getNext();
        }
        cout << end->getData() << endl;
    }
}

void insertB(char x, Node* iterator[], Node** beg, Node** end) {
    long long unsigned int y;
    char c;
    if (x == 'B' || x == 'E') {
        cin >> c >> c >> y;
        if (x == 'B') addFirst(beg, end, y);
        else insertBefore(*end, beg, y);
    }
    else {
        int number = atoi(&x);
        cin >> y;
        insertBefore(iterator[number], beg, y);
    }
}

void insertA(char x, Node** iterator, Node** beg, Node** end) {
    unsigned long long int y;
    char c;
    if (x == 'B' || x == 'E') {
        cin >> c >> c >> y;
        if (x == 'B') insertAfter(*beg, beg, end,  y);
        else addLast(beg, end, y);
    }
    else {
        int number = atoi(&x);
        cin >> y;
        insertAfter(iterator[number], beg, end, y);
    }
}

void printing(char p, Node* iterator, Node* beg, Node* end) {
    if (p == 'A') {
        cin >> p >> p;
        printList(beg, end);
    }
    else {
        int number = atoi(&p);
        cout << iterator[number].getData() << endl;
    }
}

void removing(Node** iterator, Node** beg, Node** end) {
    Node* tmp = *iterator;
    if (tmp->getNext() != NULL) *iterator = tmp->getNext();
    else if (tmp->getPrev() != NULL) *iterator = tmp->getPrev();
    removeNode(beg, end, tmp);
}

void initIterator(int x, Node** iterator, Node** beg, Node** end) {
    unsigned long long int ile = 0;
    char x2, sth;
    cin >> x2;
    if (x2 == 'B' || x2 == 'E') {
        cin >> sth >> sth;
        if (x2 == 'B') *iterator = *beg;
        else *iterator = *end;
    }
    else {
        Node* node = *beg;
        while (ile < x) {
            if (node == NULL) {
                cout << "BLAD " << endl;
                break;
            }
            node = node->getNext();
            ile++;
        }
        *iterator = node;
    }
}

void moveForward(int x, Node** iterator) {
    if (iterator[x] == NULL);
    else if (iterator[x]->getNext() == NULL);
    else iterator[x] = iterator[x]->getNext();
}

void moveBack(int x, Node** iterator) {
    if (iterator[x] == NULL);
    else if (iterator[x]->getPrev() == NULL);
    else iterator[x] = iterator[x]->getPrev();
}

int main()
{
    Node* beg = NULL;
    Node* end = NULL;
    Node** iterator = new Node*[10];
    for (int i = 0; i < 10; i++) {
        iterator[i] = nullptr;
    }
    char c, x, p;
    int q;

    while (cin) {
        cin >> c;
        switch (c) {
        case '.':
            cin >> c >> x;
            insertB(x, iterator, &beg, &end);
            break;
        case 'A':
            cin >> c >> x;
            insertA(x, iterator, &beg, &end);
            break;
        case 'i':
            cin >> q;
            initIterator(q, &iterator[q], &beg, &end);
            break;
        case 'I':
            cin >> q;
            break;
        case '+':
            cin >> q;
            moveForward(q, iterator);
            break;
        case '-':
            cin >> q;
            moveBack(q, iterator);
            break;
        case 'R':
            cin >> x;
            if ((x == 'E') || (x == 'B')) {
                cin >> c >> c;
                if (x == 'B') removeNode(&beg, &end, beg);
                else removeNode(&beg, &end, end);
            }
            else {
                int n = atoi(&x);
                for (int i = 0; i < 10; i++) {
                    if (i == n) continue;
                    if (iterator[i] == iterator[n]) {
                        Node** tmp = &iterator[i];
                        if ((*tmp)->getNext() != NULL) iterator[i] = (*tmp)->getNext();
                        else if ((*tmp)->getPrev() != NULL) iterator[i] = (*tmp)->getPrev();
                        else iterator[i] = nullptr;
                    }
                        
                }
                removing(&iterator[n], &beg, &end);
            }
            break;
        case 'P':
            cin >> p;
            if (p == 'A') printing(p, *iterator, beg, end);
            else {
                int n = atoi(&p);
                if (iterator[n] == nullptr);
                else cout << iterator[n]->getData() << endl;
            }
            break;
        }
        c = NULL;
    }

    return 0;
}