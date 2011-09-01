
#include <iostream>
//#include <isstream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class AccessPoint {
  public:
    AccessPoint(std::string n):name(n) {};
    std::string name;
    std::vector<std::string> protocols;
};
class ClientAccessPoint {
  public:
    ClientAccessPoint(std::string n, int s):name(n),strength(s) {};
    std::string name;
    int strength;
};
class Client {
  public:
    Client(std::string n):name(n) {};
    std::string name;
    int min_strength;
    std::vector<std::string> protocols;
    std::vector<ClientAccessPoint*> access_points;
};

int main() {
  fprintf(stderr, "program started");
  std::ifstream input;
  std::string line;
  std::vector<AccessPoint*> access_points;
  std::vector<Client*> clients;

  //input.open("input.txt");
  //if(input.is_open())
  //{
    while(std::cin)
    {
      fprintf(stderr, "Start of loop");
      getline(std::cin, line);
      if(line[0] == 'a') // found access point
      {
        AccessPoint *ap = new AccessPoint(line);
        getline(std::cin, line);
        while(line != "" && input.good())
        {
          ap->protocols.push_back(line);
          getline(std::cin, line);
        }
        access_points.push_back(ap);
      }
      else if(line[0] == 'c')
      {
        Client *c = new Client(line);
        getline(std::cin, line);
        while(line != "" && input.good())
        {
          while(line[0] == 'p' && input.good())
          {
            c->protocols.push_back(line);
            getline(std::cin, line);
          }
          std::stringstream ss(line);
          ss >> c->min_strength;
          getline(std::cin, line);
          while(line[0] == 'a' && input.good())
          {
            size_t space;
            space = line.find_first_of(" ", 0);
            std::string name = line.substr(0,space);
            int strength;
            std::stringstream ss(line.substr(space, 999));
            ss >> strength;
            c->access_points.push_back(new ClientAccessPoint(name, strength));
            getline(std::cin, line);
          }
        }
        clients.push_back(c);
      }
    }
    //input.close();
    fprintf(stderr, "input loop ended");

    std::vector<AccessPoint*>::iterator ap_it;
    std::vector<ClientAccessPoint*>::iterator cap_it;
    std::vector<Client*>::iterator c_it;

    //for(cap_it=(*c_it)->access_points.begin(); cap_it < (*c_it)->access_points.end(); cap_it++)
    //{
    //}
    bool found = false;
    for(c_it=clients.begin(); c_it < clients.end(); c_it++)
    {
      //std::cout << ( *c_it )->name << std::endl;
      for(cap_it=(*c_it)->access_points.begin(); cap_it < (*c_it)->access_points.end(); cap_it++)
      {
        //std::cout << (*c_it)->min_strength << ": " << (*cap_it)->name << "(" <<
        //  (*cap_it)->strength << ")" << std::endl;
        if((*c_it)->min_strength <= (*cap_it)->strength)
        {
          for(ap_it=access_points.begin(); ap_it < access_points.end() && !found; ap_it++)
          {
            if((*ap_it)->name == (*cap_it)->name)
            {
              std::vector<std::string>::iterator aprot_it;
              for(aprot_it=(*ap_it)->protocols.begin(); aprot_it < (*ap_it)->protocols.end() && !found; aprot_it++)
              {
                std::vector<std::string>::iterator cprot_it;
                for(cprot_it=(*c_it)->protocols.begin(); cprot_it < (*c_it)->protocols.end() && !found; cprot_it++)
                {
                  if((*aprot_it) == (*cprot_it))
                  {
                    std::cout << "client " << (*c_it)->name << " associates with AP " <<
                      (*ap_it)->name << " using protocol " << (*aprot_it) << " at signal strength " <<
                      (*cap_it)->strength << std::endl;
                    found = true;
                    break;
                  }
                }
              }
            }
          }
        }
        //std::cout << ( *ap_it )->name << std::endl;
      }
      found = false;
    }
  //}
  //else std::cout << "Unable to open file.";

  return 0;
}
