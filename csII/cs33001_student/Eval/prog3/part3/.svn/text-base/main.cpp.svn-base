/* Testing for Stack Implementation
 * Chris Marshall
 * 4.4.2010
 */

#include "stack.hpp"
#include "string.hpp"
#include <iostream>
#include <fstream>

void evaluate(String, std::ofstream&);

int main()
{
  std::ifstream in("infixes.txt");
  std::ofstream out("assembly.txt");
  while(! in.eof())
  {
    char temp;
    String raw("");
    in >> temp;
    while(temp != '\n' && !in.eof())
    {
      raw += String(temp);
      in.get(temp);
    }

    if(raw != String())
    {
      std::vector<String> tokens = raw.split(' ');
      tokens.pop_back(); // remove ;
      Stack<String> stack;

      for(int i=0; i < (int)tokens.size(); ++i)
      {
        String t = tokens[i];
        if(t == ")")
        {
          String right = stack.pop();
          String oper = stack.pop();
          String left = stack.pop();
          String sep = ' ';
          String sum = left + sep + right + sep + oper;
          stack.push(sum);
        }
        else
          if(t != "(") stack.push(t);
      }
      String postfix = stack.pop();
      //std::cout << std::endl << raw << " converted to " << postfix;
      out << "Infix Expression: " << raw << "\nPostfix Expression: " 
        << postfix << "\n\n";
      evaluate(postfix, out);
      out << "\n\n\n";
    }
  }
  in.close();

  return 0;
}

void evaluate(String postfix, std::ofstream& out)
{
  std::vector<String> tokens = postfix.split(' ');
  Stack<String> stack;
  int var_index = 1;

  for(int i=0; i < (int)tokens.size(); ++i)
  {
    if(tokens[i] == "*" || tokens[i] == "+" || 
        tokens[i] == "-" || tokens[i] == "/")
    {
      String op;
      if(tokens[i] == "*") op = "MUL";
      else if(tokens[i] == "+") op = "ADD";
      else if(tokens[i] == "-") op = "SUB";
      else op = "DIV";

      String right = stack.pop();
      String left  = stack.pop();

      out << "   LOD   " << left;
      if(left  == "TMP") out << (var_index - 2);

      out << "\n   " << op << "   " << right;
      if(right == "TMP") out << (var_index - 1);
      out << "\n   STR   TMP" << var_index << std::endl;
      stack.push("TMP");
      ++var_index;
    }
    else
      stack.push(tokens[i]);
  }
}
