#include <iostream>
//#include <isstream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class node
{
  public:
    node(int value, string input):val(value)
    {
      if(int(input.size()) > 1)
      {
        //fprintf(stderr, "Complex definition %s", input.c_str());
        string left_string = "";
        int i = 1, open_paren = 0;
        while(input[i] != ',' || open_paren > 0)
        {
          if(input[i] == '(') ++open_paren;
          if(input[i] == ')') --open_paren;

          left_string += input[i];
          ++i;
        }
        ++i;
        string right_string = "";
        open_paren = 0;
        while(input[i] != ')' || open_paren > 0)
        {
          if(input[i] == '(') ++open_paren;
          if(input[i] == ')') --open_paren;

          right_string += input[i];
          ++i;
        }
        //fprintf(stderr, "Before new allocate: %s - %s", left_string.c_str(), right_string.c_str());
        left = new node(0,left_string);
        right = new node(1,right_string);
        //fprintf(stderr, "after new allocate");
        name = "";
      }
      else
      {
        //fprintf(stderr, "Setting Name %s", input.c_str());
        name = input;
      }
    };

    string to_s()
    {
      if(name == "")
        return "(" + left->to_s() + "," + right->to_s() + ")";
      else
        return name;
    };
      
    int val;
    node *left;
    node *right;
    string name;
};

int main()
{
  string input;
  getline(cin, input);
  //fprintf(stderr, "Before init");
  node root(0,input);
  //fprintf(stderr, "After init");
  //cout << endl;
  //cout << root.to_s();
  //cout << endl;
  bool first = true;
  while(!cin.eof()) 
  {
    getline(cin, input);
    // decode
    node *current_node = &root;

    if(!first) cout << endl;
    else first = false;

    for(int i = 0; i < int(input.size()); ++i)
    {
      if(input[i] == '1') 
        current_node = current_node->right;
      else
        current_node = current_node->left;

      if(current_node->name != "")
      {
        cout << current_node->name;
        current_node = &root;
      }
    }
  }

  return 0;
}
