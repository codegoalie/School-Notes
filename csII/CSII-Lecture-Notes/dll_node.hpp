/* Double Linked List node
 * Chris Marshall
 * 4.5.2010
 */

template <typename T>
class dNode
{
  public:
    dNode():next(0):prev(0) {};
    dNode(T v):data(v):next(0):prev(0) {};

    T data;
    nNode<T> *noxt, *prev;
}
