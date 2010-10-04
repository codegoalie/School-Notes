// Chris Marshall
//
// Operating Systems
// 9.16.2010
// Program 1

#include <iostream>
#include <cstdlib>
#include <tr1/unordered_map>


int main (void)
{
  srand(time(0));
  typedef std::tr1::unordered_map<int, int> hash_table;
  hash_table cache;

  int iterations = 10000;
  int not_in_cache = 0;
  int within_256 =0;
  int within_2048 = 0;
  int not_within_2048 = 0;

  int mem_loc = 256;

  for(int i=0; i < iterations; ++i)
  {
    int next_loc_group = rand() % 100;
    int mem_loc factor = 0;

    if(next_loc_group < 90)
    {
      ++within_256;
      mem_loc_factor = 256;
      
    }
    else if(mext_mem_group < 98)
    {
      ++within_2048;
      mem_loc_factor = 2048;
    }
    else
    {
      ++not_within_2048;
      mem_loc_factor = 2048*2; // this should be anywhere in the 1000 pages
    }

    mem_loc += rand() % mem_loc_factor - (mem_loc_factor/2);

    if(cache.find(mem_loc) == cache.end())
    {
      ++not_in_cache;
      cache[mem_loc] = mem_loc;
    }
  }

  std::cout.precision(3);
  std::cout << "Within 256: " << within_256 << " for " << (float)within_256/iterations*100 << "%" << std::endl;
  std::cout << "Within 2048: " << within_2048 << " for " << (float)within_2048/iterations*100 << "%" << std::endl;
  std::cout << "Not Within 2048: " << not_within_2048 << " for " << (float)not_within_2048/iterations*100 << "%" << std::endl;
  std::cout << std::endl << "Times not in cache: " << not_in_cache << " for " << (float)not_in_cache/iterations*100 << "%" << std::endl;
  return 0;
}
