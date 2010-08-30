//File:        main.cpp   
//       
//Version:     1.0
//Date:        
//Author:      
//
//Description: Main body for Program 2
//

#include <iostream>
#include <fstream>
#include <vector>
#include "string.h"
#include "logentry.h"


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
int main(int argc, char *argv[]) {
    vector<String> opt(3);     // options
    opt[0] = "all";
    opt[1] = "byes";
    opt[2] = "host";

    if (argc <= 2) {
        std::cerr << "usage: " << argv[0] << " [";
         for (int i = 0; i < opt.size() - 1; ++i)
	     std::cerr << opt[i] << " | ";
	 std::cerr << opt[opt.size() - 1] << " ]\n";
	 exit(1);
    }

    String file_name = getFileName(argc, argv);  // get file name
    std::ifstream in(file_name);
    vector<logEntry> log_entries = parse(in);
    in.close();

    String option(argv[2]);

    if (option == opt[0]) {              //First option
        output_all(std::cout, log_entries);
    }
    else if (option == opt[1]) {        //Second option
        std::cout << "Total number of bytes sent: " 
                  << byte_count(log_entries) << endl;
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


