//File:        main.cpp   
//       
//Version:     1.0
//Date:        3.21.2010
//Author:      Chris Marshall
//
//Description: Main body for Program 2
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "string.hpp"
#include "logentry.hpp"

/*
int main()
{
  String s("Host 1 2 3 4 Get mpgfree.com 200 40 900");
  std::cout << s << std::endl;
  logEntry l(s);
  std::cout << l << std::endl;

  return 0;
};
*/

////////////////////////////////////////////////////////////
String getFileName(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: command line file name required, exiting."
                  << std::endl;
        exit(1);
    }
    return String(argv[1]);
}


////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) 
{
  /*
  char a('a');
  String s("a");
  for(int i=0; i < 2000; ++i)
    s += String(a);
  std::cout << "Got through 2000";
  return 0;
  */
  std::vector<String> opt(3);     // options
    opt[0] = "all";
    opt[1] = "bytes";
    opt[2] = "host";

    if (argc <= 2) {
        std::cerr << "usage: " << argv[0] << " filename [";
         for (int i = 0; i < (int)opt.size() - 1; ++i)
	     std::cerr << opt[i] << " | ";
	 std::cerr << opt[opt.size() - 1] << " ]\n";
	 exit(1);
    }

    //String file_name = getFileName(argc, argv);  // get file name
    if (argc < 2) {
        std::cerr << "Error: command line file name required, exiting."
                  << std::endl;
        exit(1);
    }
    //return String(argv[1]);
    std::ifstream in(argv[1]);
    std::vector<logEntry> log_entries = parse(in);
    in.close();
    
    /*std::cout << "Parsed " << log_entries.size() << " log entries" << std::endl;
    for(int i=0; i < (int)log_entries.size(); ++i)
      std::cout << log_entries[i] << std::endl;
    std::cout << std::endl;
    */
    String option(argv[2]);

    if (option == opt[0]) {              //First option
        output_all(std::cout, log_entries);
    }
    else if (option == opt[1]) {        //Second option
        std::cout << "Total number of bytes sent: " 
                  << byte_count(log_entries) << std::endl;
    }
    else if (option == opt[2]) {        //Thrid option
        by_host(std::cout, log_entries);
    }
    else    {                           //Error, bad option
        std::cerr << "Unrecognized option: " << option << std::endl;
        std::cerr << "Recognized options: " 
             << opt[0] << " "
             << opt[1] << " "
             << opt[2] << std::endl;
    }
    
    return 0;
}


