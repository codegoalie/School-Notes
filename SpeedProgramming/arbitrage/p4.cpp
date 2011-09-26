
#include <list>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int country_count;
  cin >> country_count;
  while(!cin.eof())
  {
    vector< vector<double> > table;
    list<int> countries;
    for(int i = 0; i < country_count; ++i)
    {
      countries.push_back(i);
      vector<double> row;
      for(int ii = 0; ii < country_count; ++ii)
      {
        double rate;
        if(i == ii) rate = 1;
        else 
        {
          cin >> rate;
        }
        row.push_back(rate);
      }
      table.push_back(row);
    }

  //cout << "Read all rates:\n";
  //for(int i = 0; i < country_count; ++i)
  //{
  //  for(int ii = 0; ii < country_count; ++ii)
  //  {
  //    cout << table[i][ii] << " ";
  //  }
  //  cout << endl;
  //}
  
    list<int> arb;
    for(int i = 0; i < int(countries.size()); ++i) arb.push_back(i);
    arb.push_back(0);
    do
    {
      list<int> sequence; 
      sequence.push_back(countries.front());
      
      double profit = 1;
      for(list<int>::iterator i = ++countries.begin(); i != countries.end(); ++i)
      {
        profit = profit * table[sequence.back()][*i];
        sequence.push_back(*i);
      //for(list<int>::iterator s = sequence.begin(); s != sequence.end(); ++s)
      //  cout << *s + 1 << " ";
      //cout << sequence.front() + 1 << " yields " << profit * table[*i][sequence.front()] 
      //  << endl;

        if(profit * table[*i][sequence.front()] >= 1.01 && sequence.size() < arb.size())
        {
          arb = sequence;
          continue;
        }
      }
    } while ( next_permutation(countries.begin(), countries.end()));

    for(list<int>::iterator i = arb.begin(); i != arb.end(); ++i)
      cout << *i + 1 << " ";
    cout << arb.front() + 1 << endl;

    cin >> country_count;
  }

  return 0;
}
