
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Catalog
{
  public:
    string name;
    vector<string> reqs;
};

vector<string> split(string str)
{
  vector<string> strings;
  string temp_string;
  for(int i = 0; i < int(str.size()); ++i)
  {
    if(str[i] == ' ') 
    {
      strings.push_back(temp_string); 
      temp_string.clear();
    }
    else
      temp_string.push_back(str[i]);

  }
  strings.push_back(temp_string); 
  return strings;
}

vector<string> reqs_from_name(vector<Catalog> cat, string name)
{
  vector<Catalog>::iterator it_one;
  for(it_one =cat.begin(); it_one < cat.end(); ++it_one)
  {
  //cout << it_one->name << "(" << it_one->name.size() << ") == " << name << "(" <<
  //  name.size() << "); compare(" << 
  //  (it_one->name.compare(name) == 0) << ")" << " equality(" << 
  //  (it_one->name == name) << ")" << endl;
    if(it_one->name.compare(name) == 0)
      return it_one->reqs;
  }
  //cout << name << " wasn't found in catalog for reqs" << endl;
  vector<string> empty;
  return empty;
}

bool had_class(vector<string> courses_taken, string course)
{
  vector<string>::iterator it;
  for(it = courses_taken.begin(); it < courses_taken.end(); ++it)
  {
    if(*it == course) return true;
  }
  return false;
}

int main()
{
  string input;
  vector<Catalog> catalog;
  getline(cin, input);
  while(input != "")
  {
    //cout << "more catalog: " << input << endl;
    //getline(cin, input);
    vector<string> classes = split(input);
    //for(int i=0; i < int(classes.size()); ++i) cout << classes[i];
    //cout << endl;
    Catalog *temp_catalog = new Catalog;
    temp_catalog->name = classes[0];
    for(int i =1; i < int(classes.size()); ++i)
      temp_catalog->reqs.push_back(classes[i]);

    catalog.push_back(*temp_catalog);
    getline(cin, input);
  }
  //cout << endl;
  //cout << catalog.size() << endl;
//vector<Catalog>::iterator it_one;
//for(it_one =catalog.begin(); it_one < catalog.end(); ++it_one)
//{
//  cout << it_one->name << " requires:" << endl;
//  vector<string>::iterator it_two;
//  for(it_two =it_one->reqs.begin(); it_two < it_one->reqs.end(); ++it_two)
//  {
//    cout << "  " << *it_two << endl;
//  }
//  
//}

//cout << endl;
//cout << endl;

  vector<string> courses_taken;
  getline(cin, input);
  while(!cin.eof())
  {
    //cout << "more trans: " << input << endl;
    vector<string> this_qtr = split(input);
    vector<string>::iterator it;
    for(it = this_qtr.begin(); it < this_qtr.end(); ++it)
    {
      //cout << *it << endl;
      vector<string> reqs = reqs_from_name(catalog, *it);
      //cout << "reqs # " << reqs.size() << endl;
      if(int(reqs.size()) > 0)
      {
        vector<string>::iterator req_it;
        for(req_it = reqs.begin(); req_it < reqs.end(); ++req_it)
        {
          //cout << "checking " << *req_it << endl;
          if(! had_class(courses_taken, *req_it))
            cout << *it << " taken without prerequisite " << *req_it << endl;
        }
      }
    }
    for(it = this_qtr.begin(); it < this_qtr.end(); ++it)
      courses_taken.push_back(*it);
    getline(cin, input);
  }

  return 0;
}
