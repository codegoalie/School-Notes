
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Box
{
  public:
    vector<int> v;
    int id;

    Box(vector<int> p_v) : v(p_v) {};
    Box(int p_id) : id(p_id) {};

    int size() { return int(v.size()); };
    int operator[](int i) { return v[i]; };

    void push_back(int dim) { v.push_back(dim); };

    void print() const
    {
      for(int i = 0; i < int(v.size()); ++i)
      {
        cout << " " <<  v[i];
      }
    };

    bool operator<(const Box &rhs)
    {
      cout << "op: ";
      print();
      cout << " < ";
      rhs.print();
      cout << " == ";
      for(int i = 0; i < int(v.size()); ++i)
      {
        if(rhs.v[i] != v[i]) 
        {
          cout << (rhs.v[i] < v[i]) << '\n';
          return rhs.v[i] < v[i];
        }
      }
      cout << "false\n";
      return false;
    }
    
    void sort() { sort(0); };
    void sort(int start)
    {
      //cout << "  Starting sort" << endl;
      if(start != int(v.size())-1)
      {
        int max = v[start], max_i= start;
        for(int i = start+1; i < int(v.size()); ++i)
        {
          //cout << "  " << v[i] << " < " << max << endl;
          if(v[i] > max)
          {
            max = v[i];
            max_i = i;
          }
        }
        //cout << " " << max_i << " " << start << endl;
        if(start != max_i)
        {
          //cout << "  Swapping " << start << " and " << max_i << endl;
          v[max_i] = v[start];
          v[start] = max;
        }
        sort(start+1);
      }
    };
};

void sort(int start, vector<Box> &v)
{
  //cout << "  Starting sort" << endl;
  if(start != int(v.size())-1)
  {
    Box max = v[start];
    int max_i = start;
    for(int i = start+1; i < int(v.size()); ++i)
    {
      //cout << "  " << v[i] << " < " << max << endl;
      if(v[i] < max)
      {
        max = v[i];
        max_i = i;
      }
    }
    //cout << " " << max_i << " " << start << endl;
    if(start != max_i)
    {
      //cout << "  Swapping " << start << " and " << max_i << endl;
      v[max_i] = v[start];
      v[start] = max;
    }
    sort(start+1, v);
  }
};

vector<int> streak_builder(Box current_box, vector<Box> smaller_boxes)
{
  vector<int> best_streak;
  for(int i = 0; i < int(smaller_boxes.size()); ++i)
  {
    if(smaller_boxes[i] < current_box)
    {
      vector<Box> new_smaller = smaller_boxes;
      new_smaller.erase(smaller_boxes.begin());
      vector<int> new_streak = streak_builder(smaller_boxes[i], new_smaller);
      if(int(best_streak.size()) < int(new_streak.size()))
        best_streak = new_streak;
    }
  }
  return best_streak;
};

int main()
{
  int box_count, dims;

  cin >> box_count;
  cin >> dims;

  while(!cin.eof())
  {

    vector<Box> boxes;
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

    for(int i = 0; i < int(boxes.size()); ++i)
    {
      boxes[i].sort();
    }

    sort(0, boxes);


    vector<int> streak, best_streak;
    vector<Box>::iterator it = boxes.begin();
    for(int i = 0; i < int(boxes.size()); ++i)
    {
      vector<Box> smaller_boxes = boxes;
      smaller_boxes.erase(it);
      streak = streak_builder(boxes[i], smaller_boxes);
      if(int(best_streak.size()) < int(streak.size()))
        best_streak = streak;
      ++it;
    }
    cout << "Best: " << best_streak.size() << " -- ";
    for(int i = 0; i < int(best_streak.size()); ++i)
      cout << " " << best_streak[i];
    cout << endl;

    cout << "Read all boxes:\n";
    for(int i = 0; i < int(boxes.size()); ++i)
    {
      cout << "Box " << boxes[i].id << endl << " ";
      boxes[i].sort();
      for(int ii = 0; ii < boxes[i].size(); ++ii)
      {
        cout << " " << boxes[i][ii];
      }
      cout << endl << endl;
    }

    cin >> box_count;
    cin >> dims;
  }

  return 0;
}
