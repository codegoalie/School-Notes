#ifndef _SEXPR_H_
#define _SEXPR_H_
///////////////////////////////////////////////////
//
// File:        sexpr.h
//              Program 4 CS II
// Programmer:  J. Maletic 
// Date:        4/20/2010
//
// Description: A class for a Lisp S-expression.
//              sexrp and lispnode work together to implement
//              A simple Lisp interpreter
//

#include <iostream>
using std::string;

class    sexpr;
class    lispnode;

enum     nodeType      {anAtom, aList};
typedef  lispnode*     lispnodeptr;
string   getAtom       (std::istream&, char&);  
string   int_to_string (int);
  
////////////////////////////////////////////////////
// CLASS INV: Assigned(next, identity, sym, sublist)
//
//
class lispnode {
public:
                lispnode    () : next(0), identity(aList), sym(), sublist(0) {};
                lispnode    (const nodeType t) : next(0), identity(t), sym(), sublist(0) {};
                lispnode    (const nodeType t, const string name, const lispnodeptr lst)
                               : next(0), identity(t), sym(name), sublist(lst) {};
                ~lispnode   () {};             //Does nothing!
    friend void garbageCollect (lispnodeptr&); //For destruction

    friend std::istream& operator>>  (std::istream&, lispnodeptr&);
    friend std::ostream& operator<<  (std::ostream&, const lispnodeptr);

//Attributes:
    lispnode        *next;          //Next node in sexpr
    nodeType        identity;       //What type of node?
    string          sym;            //Atom
    lispnode        *sublist;       //List


};



////////////////////////////////////////////////////
// CLASS INV: Assigned (identity && symbol && lst)
// 
//
class sexpr {
public:
                     sexpr      () : identity(aList), symbol(), lst(0) {};
                     sexpr      (const lispnodeptr ptr) : identity(aList), symbol(), lst(ptr) {};
                     sexpr      (const string name) : identity(anAtom), symbol(name), lst(0) {};
                     sexpr      (const int);
                     ~sexpr             () {}; //Does Nothing!
            void     garbageCollection  ();    //For Destruction.

    friend  sexpr    eval       (const sexpr&);
    friend  sexpr    first      (const sexpr&);
    friend  sexpr    rest       (const sexpr&);
    friend  sexpr    length     (const sexpr&);
    friend  sexpr    list       (const sexpr&,  const sexpr&);
    friend  sexpr    cons       (const sexpr&,  const sexpr&);
            bool     operator== (const sexpr&)  const;
    
    friend  std::istream& operator>> (std::istream&,      sexpr&);
    friend  std::ostream& operator<< (std::ostream&,      const sexpr&);

private:
    nodeType         identity;    //What type of node? (atom or list)
    string           symbol;      //Name of Atom
    lispnode         *lst;        //Pointer to the List
};


#endif
