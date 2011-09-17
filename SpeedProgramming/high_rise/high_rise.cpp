
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;
  vector<int> buildings;
  int building, building_count;
  cin >> input; 

  while(!cin.eof()) 
  {
    if(input[0] == 'r')
    {
      buildings.clear();
      cin >> building_count;
      for(int i = 0; i < building_count; ++i)
      {
        cin >> building;
        buildings.push_back(building);
      }
    //cout << "Buildings: ";
    //for(int i = 0; i < int(buildings.size()); ++i)
    //  cout << buildings[i];
    //cout << endl;
    }
    else if(input[0] == 'v')
    {
      int first, second;
      cin >> first;
      first--;
      cin >> second;
      second--;
      //cout << endl << "Comparing " << first << " to " << second;
      
      int max_height, less_height;
      string dir;
      if(buildings[first] > buildings[second])
      {
        max_height = buildings[first];
        dir = "down";
        less_height = buildings[second];
      }
      else
      {
        max_height = buildings[second];
        dir = "up";
        less_height = buildings[first];
      }

      //cout << "max: " << max_height << " less: " << less_height << " dir: " << dir << endl;

      double slope = (max_height - less_height)/ (second - first + 0.0);
      //cout << " slope is " << slope << endl;

      double sight_height = buildings[first];
      //cout << "sight height: " << sight_height << endl;
      bool blocked = false;
      for(int i = first+1; i < second; ++i)
      {
        if(dir == "down")
          sight_height -= slope;
        else
          sight_height += slope;

        //cout << "sight height at " << i << ": " << sight_height << endl;
        if(sight_height < buildings[i])
        {
          blocked = true;
          //cout << "blocked at " << i << endl;
          break;
        }
      }

      if(blocked)
       cout << "no" << endl;
      else
        cout << "yes" << endl;
    }
    cin >> input; 
  }

  return 0;
}
