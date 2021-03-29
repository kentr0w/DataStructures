///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains pseudo-implementation part of bidirectional list structure
/// template declared in the file's h-counterpart
///
/// © Sergey Shershakov 2015–2017.
///
/// This code is for educational purposes of the course "Algorithms and Data
/// Structures" provided by the School of Software Engineering of the Faculty
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>


//==============================================================================
// class BidiList<T>::Node
//==============================================================================


template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::Node::insertAfterInternal(Node* insNode)
{
// here we use "this" keyword for enhancing the fact we deal with curent node!
    Node* afterNode = this->_next; // an element, which was after node
// !...
// Здесь вырезана часть кода. Ее необходимо реализовать
// См. документацию к методу insertAfterInternal() и insertAfter()
// !...

    Node* obj=insNode;
    this->_next=obj;
    obj->_prev=this;
    obj->_next=afterNode;
    afterNode->_prev=obj;
    return obj;

}

//==============================================================================
// class BidiList<T>
//==============================================================================

template <typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}

template <typename T>
void BidiLinkedList<T>::insertNodesAfter(BidiLinkedList<T>::Node *node, BidiLinkedList<T>::Node *beg,
                                         BidiLinkedList<T>::Node *end) {
    if(!node)
        throw std::invalid_argument("Error");
    Node* obj_1=beg->_prev;
    if(end->_next)
    {
        obj_1->_next=end->_next;
        end->_next->_prev=obj_1;
    }
    else
        obj_1->_next=nullptr;

    Node* obj_2=node->_next;
    node->_next=beg;
    beg->_prev=node;
    end->_next=obj_2;
}

template <typename T>
void BidiLinkedList<T>::clear()
{
    Node* obj_1=_head;
    while(obj_1){
        Node* obj_2=obj_1->_next;
        delete obj_1;
        obj_1=obj_2;
    }
    _head=_tail= nullptr;
    invalidateSize();
// !...
// Метод необходимо реализовать целиком!
// !...
}

template <typename T>
size_t BidiLinkedList<T>::getSize()
{
    if (_size == NO_SIZE)
        calculateSize();
    return _size;
}

template <typename T>
void BidiLinkedList<T>::calculateSize()
{
    Node* obj=_head;
    int count=1;
    if(!obj)
        _size=0;
    else {
        while (obj->_next){
            count++;
            obj=obj->_next;
        }
        _size = count;
    }
// !...
// Метод необходимо реализовать целиком!
// !...
}


template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::getLastNode() const
{
    return _tail;
// !...
// Метод необходимо реализовать целиком!
// !...
}


template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);

// !...
// Здесь вырезана часть кода. Ее необходимо реализовать
// !...
// inserts after last node, size if going to e invalidated there
    return insertNodeAfter(getLastNode(), newNode);
}


// возможно, этот метод даже не надо изменять
template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::insertNodeAfter(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

// check if a node is alone
    if (insNode->_next || insNode->_prev)
        throw std::invalid_argument("`insNode` has siblings. It seems it isn't free");


    if (!node)
        node = getLastNode();

// if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
    {
        _head = insNode;
        _tail = insNode;
    }
    else
    {
        Node* obj_1=node->_next;
        node->_next=insNode;
        insNode->_prev=node;
        if(obj_1){
            insNode->_next=obj_1;
            obj_1->_prev=insNode;
        }
        //node->insertAfterInternal(insNode);
// If there is no one on the right from the inserted, update _tail.
        if (!insNode->_next)
            _tail = insNode;
    }
    invalidateSize();
    return insNode;
}




// !...
// Здесьдолжна быть реализация метода BidiLinkedList<T>::insertNodesAfter().
// В отличие от других методов, здесь не представлен даже заголовок, поэтому придется потрудиться!
// !...


// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
// !...
// Реализуй метод, если хочешь получит оценку повыше!
// !...
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
// !...
// Реализуй метод, если хочешь получит оценку повыше!
// !...
}

#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");
// !...
// Здесь вырезана часть кода. Ее необходимо реализовать
// !..

    if(beg==_head)
    {
        if(end->_next){
        Node* obj=end->_next;
        obj->_prev= nullptr;
        _head=obj;
        }
        else{
            clear();
        }
    }
    else{
        if(end->_next){
            Node* obj_1=beg->_prev;
            Node* obj_2=end->_next;
            obj_1->_next=obj_2;
            obj_2->_prev=obj_1;
        }
        else{
            Node* obj=beg->_prev;
            obj->_next= nullptr;
            _tail=obj;
        }

    }

    invalidateSize();

}



template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::cutNode(Node* node)
{
    if(!node)
        throw std::invalid_argument("Error");
    if(_size==1){
        Node* obj=_head;
        clear();
        invalidateSize();
        return obj;

    }

    if(node==_head){
        Node* obj=node->_next;
        obj->_prev= nullptr;
        _head=obj;
        invalidateSize();
        return node;
    }
    if(node->_next) {

        Node *obj_1 = node->_prev;
        Node *obj_2 = node->_next;
        obj_1->_next = obj_2;
        obj_2->_prev = obj_1;
    }
    else{

        Node *obj_1 = node->_prev;
        obj_1->_next = nullptr;
    }
    invalidateSize();
    return node;
// !...
// Метод необходимо реализовать целиком!
// !...
}


template <typename T>
typename BidiLinkedList<T>::Node*
BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    if (!startFrom)
        return nullptr;

    Node* obj_1=startFrom;
    if(_size==1)
        if(_head->_val==val)
            return _head;

    do{
        if(obj_1->_val==val)
            return obj_1;
        obj_1=obj_1->_next;
    }while(obj_1);
// !...
// Здесь вырезана часть кода. Ее необходимо реализовать
// !...

    return nullptr; // not found
}



template <typename T>
typename BidiLinkedList<T>::Node**
BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

// try not to use any standard containers. create an array only when found a first occurence
    Node** res = nullptr;
    size = 0;

    while (startFrom) {
        if (startFrom->_val == val)
        {
            Node** array;
            if(!res) {
                array = new Node *[size + 1];
            }
            else
                array=res;

            res = new Node*[size+1];
            res=array;
            res[size]=startFrom;
            ++size;
        }
        startFrom = startFrom->_next;
// !...
// Здесь вырезана часть кода. Ее необходимо реализовать
// !...
    }

// recreates array if created
    if (res)
    {
// !...
// А здесь вырезана еще одна часть кода. И ее тоже необходимо реализовать
// !...
    }

    return res;
}


template <typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::begin() {
    return iterator(_head);
}

template <typename T>
typename BidiLinkedList<T>::iterator BidiLinkedList<T>::end() {
    Node* obj= new Node();
    _tail->_next=obj;
    obj->_prev=_tail;
    return iterator(obj);
}

template <typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cbegin() {

    return const_iterator(_head);
}

template <typename T>
typename BidiLinkedList<T>::const_iterator BidiLinkedList<T>::cend() {
    return const_iterator(_tail);
}

template <typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rbegin() {

    return reverse_iterator(_head);
}

template <typename T>
typename BidiLinkedList<T>::reverse_iterator BidiLinkedList<T>::rend() {
    return reverse_iterator(_tail);
}





// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS

template <typename T>
typename BidiLinkedList<T>::Node**
BidiLinkedList<T>::cutAll(Node* startFrom, const T& val, int& size)
{
// !...
// Реализуй метод, если хочешь получит оценку повыше!
// !...
}

#endif // IWANNAGET10POINTS
