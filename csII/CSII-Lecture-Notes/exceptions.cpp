// exceptions are ONLY to be used in exceptional cases
// when you don't know what else to do
// there is no way to fix it
// errors that CANNOT be handled locally
//
// upon detecting an error, we can
//  terminate program
//  return an error code (c way)
//  return a legal value and leave program in illegal state
//  call a function (supplied) to deal with the mess


try
{
  // call fucntions that may throw exceptions
  throw(exception);
}

catch(exception)
{
  // handle errors
}

// if you throw, you'd better catch, else abort();

cout << "Enter a number betweem 1 and 10: ";
cin >> x;
if(x < 1 || x > 10)
{
  //easy to handle locally
  //ask again, etc.
}

// ***********************

template <typename T>
T stack::pop()
{
  if(empty)
  {
    //error
    // no idea how to handle 
    
  }
  else
    // remove item;
}

class error
{
  public:
    errro() {};
    virtual std::string report() { return "Error-unknown"; }
}

class underflow : public error 
{
  public:
    underflow():error() {};
    virtual std::string report() { return "ERROR-underflow"; };
}

class overflow : public error
{
  public:
    overflow():error() {};
    virtual std::string report() { return "ERROR-overflow"; };
}

template <typename T>
T stack::pop()
{
  if(empty)
    throw underflow();
  return s[tos--];
}

tempplate <typename T>
void stack::push(T x)
{
  if(is_full())
    throw overflow();
  s[++tos] = x;
}

int main()
{
  try
  {
    stack <int> s;
    s.pop();
  }

  // also catched underflows and overflows
  // now as ref, polymorphic call
  catch(error &er)
  {
    cerr << er.report();
  }
}
