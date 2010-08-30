/* Double Linked List 
 * actions:
 *   create, delete, copy, assign, swap
 *   add item
 *    front
 *    back
 *    in middle
 *  delete
 *    front
 *    back
 *    at a particular point
 *  access [], modify []
 *  search, sort
 *  length
 */

template <typename T>
class dList
{
  public:
    dlist():begining(0):ending(0) {};
    dList(const dList<T>&);
    void swap(dList<T>&);
    dList<T> operator=(dList<T>);
   ~dList();

    bool            isEmpty() { return begining ==0; };
    int             sizeOf();
    dList_itor<T>   operator[](const int) const;
    dList_itor<T>   operator[](const int);
    dList_itor<T>   begin() const { return dList_itor(begining); };
    dList_itor<T>   begin()  { return dList_itor(begining); };
    dList_itor<T>   end() const { return dList_itor(ending); };
    dList_itor<T>   end()  { return dList_itor(ending); };
    T               front() const { return begining->data; };
    T&              front() { return begining->data; };
    T               back() const { return ending->data; };
    T&              back() { return ending->data; };

    void          insert_back(T);
    void          insert_front(T);
    void          insert_before(const T, dList_itor<T>);
    void          insert_after (const T, dList_itor<T>);
    void          insert(T, const dList_itor<T>&);
    void          remove(dList_itor<T>&);

  private:
    dList_itor<T> find(T);

  private:
    dNode<T> *begining, *ending;
};

template <typeclass T>
class dList_itor
{
  public:
    dList_itor();
    dList_itor(dNode<T> *ptr):current(ptr) {};
    void advance() { current = current->next };
    dList_itor<T> operator++() {current=current->next; return *this; };
    dList_itor<T> operator++(int) {dList_itor<T> orig(current); current=current->next; return orig; };
    dList_itor<T> operator--() {current=current->prev; return *this; };

    bool operator==(dList_itor<T> rhs) { return current == rhs,current; };
    T operator*() const { return current->data; };
    T& operator*() { return current->data; };


    dNode<T> *current;
};


template <typename T>
dList<T>::~dlist()
{
  while(begining != 0)
  {
    dNode<T> *temp = begining;
    begining = begining->next;
    delete temp;
  }
}

template <typename T>
dList<T>::dList(const dList<T>& actual)
{
  dNode<T> *temp = actual.begining;
  begining  = 0;
  ending    = 0;
  while(temp != 0)
  {
    if(begining == 0)
    {
      begining = new dNode<T>(temp->data);
      ending = begining;
    } 
    else
    {
      ending->next = new dNode<T>(temp->data);
      ending->next->prev = ending;
      ending = ending->next; 
    }
    temp = temp->next;
  }
}

template <typename T>
void dList<T>::insert_before(const T x, dList_itor<T> i)
{
  dNode<T> *temp = new dNode<T>(x);
  if(begining == i.current)
  {
    temp->next = begining;
    begining->prev = temp;
    begining = temp;
  }
  else
  {
    i->prev->next = temp; // don't need i.current b/c arrow operator is overloaded in itor
    temp->prev = i->prev;
    temp->next = i.current;
    i->prev = temp;
  }
}

template <typename T>
dList<T>::remove(dList_itor<T>& i)
{
  if(i.current == begining)
  {
    begining = begining->next;
    begining->prev = 0;
  }
  else if(i.current == ending)
  {
    ending = ending->prev;
    ending->next = 0;
  }
  else
  {
    i->prev->next = i->next;
    i->next->prev = i->prev;
  }

  delete i.current;
  i.current = 0;
}
