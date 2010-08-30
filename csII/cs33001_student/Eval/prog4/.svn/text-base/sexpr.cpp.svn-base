#include "sexpr.h"
///////////////////////////////////////////////////
//
// File:        sexpr.cpp
//              Program 4 CS II
// Programmer:  J. Maletic
// Date:        4/20/2010
//
// Description: Implementation of a class for a Lisp S-expression.
//              Used in conjunction with class lispnode.
//
//              Destructor (garbage collection) must be explicitly
//              called.



//////////////////////////////////////////////////////////
// A destructor (for lispnode) to be called explicitly.
//
// PRE:  Assigned(ptr)
// POST: All memory ptr points to is deleted.
//
void garbageCollect(lispnodeptr &ptr) {

    //*************NEED TO IMPLEMENT***********************

}


//////////////////////////////////////////////////////////
// Free function for reading in an Atom.
// PRE:  (ch == first character of atom)
// POST: (RETVAL == atom) && (ch == next character from input)
string getAtom(/*IN/OUT*/ std::istream& in, 
               /*IN/OUT*/ char &ch) {
    string result;
    result = ch;
    in.get(ch);
    while ((ch != ' ') && (ch != ')') && (ch != '(') && (ch != '\n')) {
        result = result + ch;
        in.get(ch);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// Free function to convert int to string.
// PRE:  assigned(n).
// POST: Return a text version of integer.
// //itoa(n, result.str, 10); -- not working on g++
string int_to_string(int n) {
    string result, sign;
    
    if (n == 0) return string("0");
    if (n < 0) { 
        sign = "-"; 
        n = -n;  
    }
    while (n > 0) {
        result = char(int('0') + (n%10)) + result;
        n = n / 10;
    }  
    return sign + result;
}



//////////////////////////////////////////////////////////
// Input a S-expression
// PRE:  s should not be pointing to anything.
// POST: s->lisp expression.
std::istream& operator>>(std::istream& in, lispnodeptr& s) {
    char        ch;
    bool        endOfExpression = false;
    lispnode    *temp = 0,
                *ptr = 0;

    in >> ch;
    while (!endOfExpression)
        switch(ch) {
        case ' ':  //Skip blanks.
            in >> ch;
            break;

        case '(':  //New list.
            temp = new lispnode(aList);
            in >> temp->sublist;
            if (s == 0)  s = temp;
            else ptr->next = temp;
            ptr = temp;
            in >> ch;
            break;

        case ')':  //End of a list.
            endOfExpression = true;
            break;

        default:   //An atom.
            temp = new lispnode(anAtom);
            temp->sym = getAtom(in, ch);  //Returns ch!
            if (s == 0) s = temp;
            else ptr->next = temp;
            ptr = temp;
       }
    return in;
}

//////////////////////////////////////////////////////////
// PRE:  Assigned(s)
// POST: Lisp expression is printed.
std::ostream& operator<<(std::ostream& out, const lispnodeptr s) {
    lispnodeptr temp = s;
    bool onlyOne = true;

    while (temp != 0) {
        switch (temp->identity)
        {
        case anAtom:
            if (onlyOne) out << temp->sym;
            else out << " " << temp->sym;
            onlyOne = false;
            break;
        case aList:
            if (onlyOne) out << "(";
            else out << " (";
            out << temp->sublist;
            onlyOne = false;
            out << ")";
            break;
        }
        temp = temp->next;
    }
    return out;
}



//////////////////////////////////////////////////////////
// Constructor - numeric atom
//
sexpr::sexpr(const int val) {  
    identity = anAtom;
    symbol = int_to_string(val);
    lst      = 0;
}




//////////////////////////////////////////////////////////
// A destructor to be called explicitly.
//
void sexpr::garbageCollection() {
    garbageCollect(lst);
    identity = aList;
    symbol   = "";
    lst      = 0;
}


//////////////////////////////////////////////////////////
//Evaluate a Lisp S-expression.
//
//PRE:  s.identity == aList
//POST: returns an sexpr
sexpr eval(const sexpr& s) 
{
  if (s.lst == 0) return sexpr();

  if(s.lst->sym == "bye")
    return sexpr("bye");

  if (s.lst->sym == "quote") {
    //RETURN THE SECOND ITEM IN LIST
    return s.lst->next->sublist;
  } else {
    //THE FIRST ITEM IS A FUNCTION, CALL IT
    // WITH THE EVAL(SECOND), EVAL(THRID) ITEMS
    // AS PARAMETERS
    if(s.lst->sym == "first")
    {
      sexpr temp(s.lst->next->sublist);
      return first(eval(temp));
    }
    else if(s.lst->sym == "rest")
      return rest(eval(s.lst->next->sublist));
    else if(s.lst->sym == "length")
      return length(eval(s.lst->next->sublist));
  }
  return sexpr();  //return nil
}

//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (first (quote (a b c))) == a
sexpr first(const sexpr& s) {
  if(s.lst->identity == anAtom)
    return sexpr(s.lst->sym);
  else
    return sexpr(s.lst->sublist);
}

//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (rest (quote (a b c))) == (b c)
sexpr rest(const sexpr& s)
{
  return sexpr(s.lst->next);
}


//////////////////////////////////////////////////////////
// PRE:  s.identity == aList
// POST: (length (quote (a b (c d)))) == 3
sexpr length(const sexpr& s) 
{
  int i=1;
  lispnodeptr itr = s.lst;
  while(itr->next != 0)
  {
    ++i;
    itr = itr->next;
  }

  return sexpr(i);
}

//////////////////////////////////////////////////////////
// PRE:  none
// POST: (list (quote a) (quote (b c)) ) == (a (b c))
sexpr list(const sexpr& a, const sexpr& b) {
    //*************NEED TO IMPLEMENT***********************
    return sexpr();
}

//////////////////////////////////////////////////////////
// PRE:  b.identity == aList
// POST: (cons (quote a) (quote (b c)) ) == (a b c)
sexpr cons(const sexpr& a, const sexpr& b) {
    //*************NEED TO IMPLEMENT***********************
    return sexpr();
}


//////////////////////////////////////////////////////////
// Are two sexpr equal at TOP level? (eq)
// 
bool sexpr::operator== (const sexpr& s)  const {
    if ((identity == s.identity) &&
        (lst == s.lst) &&
        (symbol == s.symbol))
        return true;
    else
        return false;
}


//////////////////////////////////////////////////////////
// Input. (read)
// PRE:  none
// POST: A S-expression is read in. 
std::istream& operator>>(std::istream& in, sexpr& s) {
    char        ch;

    in >> ch;
    switch(ch) {
    case '(':  //New list.
        s.identity  = aList;
        in >> s.lst;
        break;
    default:   //An atom.
        s.identity  = anAtom;
        s.symbol    = getAtom(in, ch);
    }
    return in;
}


//////////////////////////////////////////////////////////
// Output (print)
// PRE:  Assigned (s)
// POST: The S-expression is printed out.
std::ostream& operator<<(std::ostream& out, const sexpr& s) {
    if (s.identity == anAtom)
        out << s.symbol;
    else
        out << "(" << s.lst << ")";
    return out;
}
