template <typename T>
class btree
{
  public:
    btree():left(0), right(0), empty(true) {};
    btree(T x):data(x), left(0), right(0), empty(false) {};
   ~btree();
    btree(const btree<T>&);
    swap(btree<T>&);
    btree<T>& operator=(btree <T>);

    void    InOrder(std::ostream&) const;
    void    preOrder(std::ostream&) const;
    void    postOrder(std::ostream&) const;

    bool    is_empty() const { return empty; };
    bool    bsearch(T) const;
    void    binsert(T);


  private:
    T data;
    btree<T> *left, *right;
    bool empty;

    btree<T>* copybtree();
    void      deletebtree();
}

template <typename T>
btree<T>::btree(const btree<T>& actual)
{
  data = actual.data;
  empty = actual.empty;

  if(actual.left) left = actual.left->copybtree();
  else left = 0;

  if(actual.right) right = actual.right->copybtree();
  else right =0;
}

template <typename T>
btree<T>* btree<T>::copybtree()
{
  btree<T>* temp = new btree<T>(data);
  if(left) temp.left = left->copybtree();
  if(right) temp.right = right->copybtree();
  return temp;
}

template <typename T>
btree<T>::~btree()
{
  if(!empty)
  { 
    if(left) left->deltetebtree();
    if(right) right->deletebtree();
    empty = true;
  }
}

template <typename T>
void btree<T>::deletebtree()
{
  if(!empty)
  {
    if(left) left->deletebtree();
    if(right) right->deletebtree();
    empty = true;
    delete this;
}

template <typename T>
void btree<T>::swap(btree<T> &x)
{
  T tempdata; btree<T> *templeft; btree<T> *tempright; bool tempempty;
  tempdata = x.data;
  tempempty = x.empty;
  templeft = x.left;
  tempright = x.right;

  x.data = data;
  x.empty = empty;
  x.left = left;
  x.right = right;

  data = tempdata;
  empty = tempempty;
  left = templeft;
  right = tempright;
}

template <typename T>
btree<T>& btree<T>::operator=(btree<T> rhs)
{
  swap(rhs);
  return *this;
}

template <typename T>
void btree<T>::InOrder(ostream & out)
{
  if(left) left->InOrder(out);
  out << data;
  if(right) right->InOrder(out);
}

template <typename T>
bool btree::bsearch(T key)
{
  if(! empty && this !=0)
  {
    if(key == data) return true;
    
    if(key < data)
      return left->bsearch(key);
    else
      return right->bsearch(key);
  }
  return false;
}
