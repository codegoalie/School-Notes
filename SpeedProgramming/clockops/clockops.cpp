
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int parse_time(string time, int, int, int);
void print(int, int, int);

int main()
{
  int base_h, base_m, base_s;

  base_h = 24;
  base_m = 60;
  base_s = 60;
  string command, first_time, second_time;
  while(cin >> command)
  {
    fprintf(stderr, "Start of loop\n");
    if(command == "base")
    {
      cin >> base_h;
      cin >> base_m;
      cin >> base_s;
      fprintf(stderr, "Set Base to: %d:%d:%d\n", base_h, base_m, base_s);
    }
    else 
    {
      cin >> first_time;
      cin >> second_time;

      // split string
      int l_time = parse_time(first_time, base_h, base_m, base_s);
      int r_time = parse_time(second_time, base_h, base_m, base_s);


      unsigned int final_time;
      if(command == "add")
      {
        fprintf(stderr, "Adding %d + %d\n", l_time, r_time);
        final_time = l_time + r_time;
      }
      else if(command == "mul")
      {
        fprintf(stderr, "Multiplying %d * %d\n", l_time, r_time);
        final_time = l_time * r_time;
      }
      else if(command == "exp")
      {
        fprintf(stderr, "Exponentiating %d ^ %d\n", l_time, r_time);
        int base = base_h * base_m * base_s;
        int i;
        final_time = 1;
        for(i = 0; i < r_time; ++i)
        {
          final_time = final_time * l_time;
          final_time = final_time % base;
        }
        fprintf(stderr, "Ticker %d\n", i);
        fprintf(stderr, "Exponentiated %d\n", final_time);
      }

      while(final_time > (base_h * base_m * base_s))
        final_time -= (base_h * base_m * base_s);

      int fh = final_time / (base_m * base_s);
      final_time -= (fh * (base_m * base_s));

      int fm = final_time / base_s;
      final_time -= fm * base_s;
      int fs = final_time;
      print(fh, fm, fs);
    }
  }

  return 0;
}

int parse_time(string time, int base_h, int base_m, int base_s)
{
  string lh = "", lm = "", ls = "";
  bool h_done = false, m_done = false;
  for(int i = 0; i < int(time.size()); ++i)
  {
    if(time[i] == ':')
      if(h_done)
        m_done = true;
      else
        h_done = true;
    else
      if(!h_done)
        lh += time[i];
      else if(!m_done)
        lm += time[i];
      else
        ls += time[i];
  }
  int h, m, s;
  std::stringstream sh(lh);
  sh >> h;
  std::stringstream sm(lm);
  sm >> m;
  std::stringstream ss(ls);
  ss >> s;
  fprintf(stderr, "Set lh to: %d:%d:%d\n", h, m, s);

  return (s + (((h*base_m)+m)*base_s));
}

void print(int h, int m, int s)
{
  cout << 
    (h < 10 ? " " : "") << h << ':' << 
    (m < 10 ? "0" : "") << m << ':' << 
    (s < 10 ? "0" : "") << s << endl;
}
