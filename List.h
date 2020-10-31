//
// Created by djnic on 31.10.2020.
//

#ifndef SUFFIXTABLE_LIST_H
#define SUFFIXTABLE_LIST_H

template<typename T>
struct Node {
    T data;
    Node *next;
};

template<typename T>
class List {
    Node<T> *head;
public:
    List() : head(nullptr) {};

    void pushToList(T val){
        Node<T> *n = new Node<T>();
        n->data=val;
        n->next=head;
        head=n;
    }

    T pop(){
        if(head){
            T p = head->data;
            head=head->next;
            return p;
        }
    }

    bool search(T val){
        Node<T> *temp = head;
        while(temp->next){
            if(temp->data==val)return true;
            else temp=temp->next;
        }
        delete temp;
        return false;
    }

};


#endif //SUFFIXTABLE_LIST_H
