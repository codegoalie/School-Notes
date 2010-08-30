/* Testing for Stack Implementation
 * Chris Marshall
 * 4.4.2010
 */

#include "stack.hpp"
#include "string.hpp"
#include <iostream>
#include <fstream>

int main()
{
  std::ifstream in("infixes.txt");
  std::ofstream out("postfixes.txt");
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
      std::cout << std::endl << raw << " converted to " << postfix;
      out << postfix << '\n';
    }
  }
  in.close();
  std::cout << std::endl;
  return 0;
}
