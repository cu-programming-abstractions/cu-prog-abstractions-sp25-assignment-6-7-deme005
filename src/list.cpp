
#include "list.h"
#include <stdexcept>

// === LinkedList core ===
LinkedList::LinkedList() = default;


LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);


}


LinkedList& LinkedList::operator=(LinkedList rhs) {
    std::swap(head, rhs.head);
    return *this;
}

LinkedList::~LinkedList() { freeChain(head); }

void LinkedList::prepend(int value) {
    head = new Node{value, head};
}



void LinkedList::append(int value) {
    Node* node = new Node{value, nullptr};
    node->data = value;

    if(!head)
    {
        head = node;
        return;
    }

    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = node;
}



int LinkedList::removeFront() {
    if (isEmpty()) throw runtime_error("removeFront on empty list");

    Node* oldhead = head;
    int data = oldhead->data;
    head = head->next;
    delete oldhead;
    return data;
}

bool LinkedList::isEmpty() const { return head == nullptr; }

void LinkedList::print(ostream& out) const {
    out << '[';
    for (Node* cur = head; cur; cur = cur->next) {
        out << cur->data;
        if (cur->next) out << " → ";
    }
    out << ']';
}


LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if(src == nullptr) return nullptr;

    Node* list = new Node{src->data, deepCopy(src->next)};
    return list;

}

void LinkedList::freeChain(Node* n) {
    while (n) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
