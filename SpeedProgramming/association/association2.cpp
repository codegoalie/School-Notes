

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
  vector<AccessPoint*> access_points;
  vector<Client*> clients;

  while(!cin.eof()) 
  {
    getline(cin, input);
    if(input[0] == 'a')
    {
      fprintf(stderr, "Found an AccessPoint: %s", input.c_str());
      AccessPoint *ap = new AccessPoint(input);
      
      getline(cin, input);
      while(!cin.eof() && input != "")
      {
        ap->protocols.push_back(input);
        getline(cin, input);
      }
      access_points.push_back(ap);
    }
    else
    {
      fprintf(stderr, "Found a client: %s", input.c_str());
      Client *c = new Client(input);

      getline(cin, input);
      while(!cin.eof() && input[0] == 'p')
      {
        c->protocols.push_back(input);
        getline(cin, input);
      }
      

      stringstream stream_strength(input);
      stream_strength >> c->min_strength;
      getline(cin, input);
      while(!cin.eof() && input != "")
      {
        size_t space;
        space = input.find_first_of(" ", 0);
        string name = input.substr(0,space);
        int strength;
        stringstream ss(input.substr(space, 999));
        ss >> strength;
        c->access_points.push_back(new ClientAccessPoint(name, strength));
        getline(cin, input);
      }
      clients.push_back(c);
    }
  }

//for(int i =0; i < int(access_points.size()); ++i)
//{
//  AccessPoint *ap = access_points[i];
//  cout << ap->name << " - ";
//  for(int ii=0; ii < int(ap->protocols.size()); ++ii)
//    cout <<  " " << ap->protocols[ii];
//  cout << endl;
//}

//cout << endl;
//for(int i =0; i < int(clients.size()); ++i)
//{
//  Client * c = clients[i];
//  cout << c->name << '(' << c->min_strength << ") - ";
//  for(int ii=0; ii < int(c->protocols.size()); ++ii)
//    cout << " " << c->protocols[ii];
//  cout << endl;
//  for(int ii=0; ii < int(c->access_points.size()); ++ii)
//    cout << " " << (c->access_points[ii])->name << "(" << (c->access_points[ii])->strength << ")";

//  cout << endl;
//}
  
  
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

  return 0;
}
