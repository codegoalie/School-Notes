
#include <iostream>
#include <list>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool sort_desc(int a, int b)
{
  return a > b;
};

class Box
{
  public:
    list<int> v;
    int id;

    Box(list<int> p_v) : v(p_v) {};
    Box(int p_id) : id(p_id) {};

    int size() { return int(v.size()); };

    void push_back(int dim) { v.push_back(dim); };

    void print() const 
    {
      for(list<int>::const_iterator i = v.begin(); i != v.end(); ++i)
      {
        cout << " " <<  *i;
      }
    };

    bool operator<(const Box &rhs) { return v < rhs.v; }
    bool operator>(const Box &rhs) { return v > rhs.v; }

    bool fits_inside_of(const Box &rhs)
    {
      list<int>::const_iterator r = rhs.v.begin();
      for(list<int>::const_iterator i = v.begin(); i != v.end(); ++i)
      {
        if((*r) <= (*i)) 
        {
          //cout << "\nFISO failed on " << (*r) << " < " << (*i) << endl;
          return false;
        }
        ++r;
      }
      return true;
      
    };

    
    void sort() { v.sort(sort_desc); };
};

//list<int> streak_builder(Box current_box, list<Box> smaller_boxes)
//{
//  list<int> best_streak;
//  for(int i = 0; i < int(smaller_boxes.size()); ++i)
//  {
//    if(smaller_boxes[i] < current_box)
//    {
//      list<Box> new_smaller = smaller_boxes;
//      new_smaller.erase(smaller_boxes.begin());
//      list<int> new_streak = streak_builder(smaller_boxes[i], new_smaller);
//      if(int(best_streak.size()) < int(new_streak.size()))
//        best_streak = new_streak;
//    }
//  }
//  return best_streak;
//};


int main()
{
  int box_count, dims;

  cin >> box_count;
  cin >> dims;

  while(!cin.eof())
  {

    list<Box> boxes;
    for(int i = 0; i < box_count; ++i)
    {
      Box box(i+1);
      for(int ii = 0; ii < dims; ++ii)
      {
        int temp;
        cin >> temp;
        box.push_back(temp);
      }
      boxes.push_back(box);
    }

    for(list<Box>::iterator i = boxes.begin(); i != boxes.end(); ++i)
    {
      i->sort();
    }

    boxes.sort();


 // cout << "Read all boxes:\n";
 // for(list<Box>::iterator i = boxes.begin(); i != boxes.end(); ++i)
 // {
 //   cout << "Box " << i->id << endl << " ";
 //   for(list<int>::iterator ii = i->v.begin(); ii != i->v.end(); ++ii)
 //   {
 //     cout << " " << *ii;
 //   }
 //   cout << endl << endl;
 // }

    list<Box> streak;
    do
    {
      //cout << "\nStreaking at " << i->id << ", ";
      list<Box> current_streak;
      current_streak.push_back(boxes.front());
      list<Box>::iterator ii = boxes.begin();
      ++ii;
      for(; ii != boxes.end(); ++ii)
      {
        //cout << " %" << current_streak.back().id << ":" << ii->id << "% ";
        if((current_streak.back()).fits_inside_of(*ii))
        {
          //cout << ii->id << ", ";
          current_streak.push_back(*ii);
        }
      }
      if(current_streak.size() > streak.size())
        streak = current_streak;
    }while ( next_permutation(boxes.begin(), boxes.end()));

    cout << streak.size() << endl;
    for(list<Box>::iterator i = streak.begin(); i != streak.end(); ++i)
    {
      cout << i->id << " ";
    }
    cout << endl;


    cin >> box_count;
    cin >> dims;
  }

  return 0;
}
