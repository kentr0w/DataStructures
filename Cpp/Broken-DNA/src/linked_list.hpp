////////////////////////////////////////////////////////////////////////////////
// Module Name:  linked_list.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
//
// Отделенная часть заголовка шаблона класса "Связанный список"
//
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>

namespace xi {

    template <typename T>
    LinkedList<T>::LinkedList( xi::LinkedList<T>& other)
    {
        this->_preHead=new Node<T>;
        if(other.getPreHead()->next)
        {
            Node<T>* obj = other.getPreHead()->next;
            do {
                this->addElementToEnd(obj->value);
                obj=obj->next;
            } while (obj != nullptr);
        }
    }
    template <typename T>
    LinkedList<T>& LinkedList<T>::operator=( xi::LinkedList<T>& other)
    {
        LinkedList copy(other);
        this->swap(*this, copy);
        return *this;
    }

    template <typename T>
    const void LinkedList<T>::swap(xi::LinkedList<T>& obj_1, xi::LinkedList<T>& obj_2) {
        Node<T>* qwe=obj_1.getPreHead();
        obj_1._preHead=obj_2._preHead;
        obj_2._preHead=qwe;
    }

    template <class T>
    LinkedList<T>::LinkedList()
    {
        _preHead = new Node<T>;
        _preHead->next= nullptr;
        // TODO: Write your code here
        // ...
    }


    template <class T>
    LinkedList<T>::~LinkedList()
    {
        Node<T>* obj=_preHead;
        while(obj!= nullptr)
        {
            Node<T>* obj_1=obj->next;
            delete  obj;
            obj=obj_1;
        }
        // TODO: Write your code here

        // на забудьте удалить искусственный элемент
    }
    template <typename T>
    T& LinkedList<T>::operator[](int i)
    {
        if(i>=size() || i<0)
            throw std::out_of_range("ERROR");
        Node<T>* obj=_preHead;
        for(int j=0; j<=i; j++)
            obj=obj->next;
        return obj->value;
    }
    template <typename T>
    Node<T>* LinkedList<T>::getPreHead()
    {
        return _preHead;
    }
    template <typename T>
    int LinkedList<T>::size()
    {
        Node<T>* obj=_preHead;
        int count = 0;
        while (obj->next!= nullptr){
            obj=obj->next;
            count++;
        }
        return count;
    }
    template <typename T>
    void LinkedList<T>::addElementToEnd(T &value)
    {
        Node<T>* obj= new Node<T>();
        obj->value=value;
        obj->next= nullptr;
        if(size()==0)
            _preHead->next = obj;

        else
        {
            Node<T>* current=_preHead->next;
            while(current->next){
                current=current->next;
            }
            current->next=obj;
        }
    }
    template <typename T>
    void LinkedList<T>::deleteNodes(xi::Node<T> *pNodeBefore, xi::Node<T> *pNodeLast)
    {
        if(!pNodeBefore->next && !pNodeLast)
            return;
        Node<T>* finish=pNodeLast->next;
        while(pNodeBefore->next!=finish)
            deleteNextNode(pNodeBefore);

    }
    template <typename T>
    void LinkedList<T>::deleteNextNode(xi::Node<T>* pNodeBefore)
    {
        if(pNodeBefore && pNodeBefore->next)
        {
            Node<T>* obj = pNodeBefore->next;
            if (obj->next)
            {
                pNodeBefore->next = obj->next;
                delete obj;
            }
            else
            {
                pNodeBefore->next = nullptr;
                delete obj;
            }
        }
    }
    template <typename T>
    void LinkedList<T>::moveNodesToEnd(xi::Node<T>* pNodeBefore, xi::Node<T>* pNodeLast)
    {
        Node<T>* obj=pNodeBefore;
        do
            moveNodeToEnd(obj);
        while(obj->next!=pNodeLast->next);
    }
    template <typename T>
    void LinkedList<T>::moveNodeToEnd(xi::Node<T>* pNodeBefore)
    {
        Node<T>* obj_1=pNodeBefore->next;
        if(pNodeBefore && obj_1)
        {
            addElementToEnd(obj_1->value);
            pNodeBefore->next= obj_1->next;
        }
    }
    template <typename T>
    void LinkedList<T>::moveNodeAfter(xi::Node<T>* pNode, xi::Node<T>* pNodeBefore)
    {
        if(!pNode && !pNodeBefore->next)
            return;
        Node<T>* object=pNodeBefore->next;
        pNodeBefore->next=object->next;
        object->next=pNode->next;
        pNode->next=object;
    }

    template <typename T>
    void LinkedList<T>::moveNodesAfter(xi::Node<T>* pNode, xi::Node<T>* pNodeBefore, xi::Node<T>* pNodeLast)
    {
        if(!pNode && !pNodeBefore && !pNodeLast)
            return;
        Node<T>* object=pNodeBefore->next;
        pNodeBefore->next=pNodeLast->next;
        object->next=pNode->next;
        pNode->next=object;
    }
    // TODO: Write your code here

} // namespace xi