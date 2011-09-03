
#include <iostream>
//#include <isstream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class AccessPoint {
  public:
    AccessPoint(string n):name(n) {};
    string name;
    vector<string> protocols;
};
class ClientAccessPoint {
  public:
    ClientAccessPoint(string n, int s):name(n),strength(s) {};
    string name;
    int strength;
};
class Client {
  public:
    Client(string n):name(n) {};
    string name;
    int min_strength;
    vector<string> protocols;
    vector<ClientAccessPoint*> access_points;
};

int main() {
  string input;
  string line;
  vector<AccessPoint*> access_points;
  vector<Client*> clients;

  //input.open("input.txt");
  //if(input.is_open())
  //{
    while(!cin.eof())
    {
      getline(cin, line);
      if(line[0] == 'a') // found access point
      {
        AccessPoint *ap = new AccessPoint(line);
        getline(cin, line);
        while(line != "")
        {
          ap->protocols.push_back(line);
          getline(cin, line);
        }
        access_points.push_back(ap);
      }
      else if(line[0] == 'c')
      {
        Client *c = new Client(line);
        getline(cin, line);
        while(line != "")
        {
          while(line[0] == 'p')
          {
            c->protocols.push_back(line);
            getline(cin, line);
          }
          stringstream ss(line);
          ss >> c->min_strength;
          getline(cin, line);
          while(line[0] == 'a')
          {
            size_t space;
            space = line.find_first_of(" ", 0);
            string name = line.substr(0,space);
            int strength;
            stringstream ss(line.substr(space, 999));
            ss >> strength;
            c->access_points.push_back(new ClientAccessPoint(name, strength));
            getline(cin, line);
          }
        }
        clients.push_back(c);
      }
    }

    vector<AccessPoint*>::iterator ap_it;
    vector<ClientAccessPoint*>::iterator cap_it;
    vector<Client*>::iterator c_it;

    //for(cap_it=(*c_it)->access_points.begin(); cap_it < (*c_it)->access_points.end(); cap_it++)
    //{
    //}
    bool found = false;
    for(c_it=clients.begin(); c_it < clients.end(); c_it++)
    {
      //cout << ( *c_it )->name << endl;
      for(cap_it=(*c_it)->access_points.begin(); cap_it < (*c_it)->access_points.end(); cap_it++)
      {
        //cout << (*c_it)->min_strength << ": " << (*cap_it)->name << "(" <<
        //  (*cap_it)->strength << ")" << endl;
        if((*c_it)->min_strength <= (*cap_it)->strength)
        {
          for(ap_it=access_points.begin(); ap_it < access_points.end() && !found; ap_it++)
          {
            if((*ap_it)->name == (*cap_it)->name)
            {
              vector<string>::iterator aprot_it;
              for(aprot_it=(*ap_it)->protocols.begin(); aprot_it < (*ap_it)->protocols.end() && !found; aprot_it++)
              {
                vector<string>::iterator cprot_it;
                for(cprot_it=(*c_it)->protocols.begin(); cprot_it < (*c_it)->protocols.end() && !found; cprot_it++)
                {
                  if((*aprot_it) == (*cprot_it))
                  {
                    cout << "client " << (*c_it)->name << " associates with AP " <<
                      (*ap_it)->name << " using protocol " << (*aprot_it) << " at signal strength " <<
                      (*cap_it)->strength << endl;
                    found = true;
                    break;
                  }
                }
              }
            }
          }
        }
        //cout << ( *ap_it )->name << endl;
      }
      found = false;
    }
  //}
  //else cout << "Unable to open file.";

  return 0;
}
