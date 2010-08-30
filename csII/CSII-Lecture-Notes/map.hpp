
enum theColors { red, blue, green, yellow };

class color 
{
  public:
    color() {hue = none;};
    color(theColors c) { hue = c; };
    color& operator=(theColors c) {hue = c; return *this; };
    color& operator++(int) { hue = theColors(int(hue)+1); return *this;};
    bool   operator==(theColors c) { return hue == c; };
    friend std::ostream& operator<<(std::ostream&, color);
    
  private:
    theColors hue;
};

const int MAPSIZE = 10;

class map
{
  public:
    map();
    int number_of_countries() const;
    bool valid_coloring(int, color) const;
    void color_country(int country, color hue) {coloring[country] = hue; };
    friend std::istream& operator>>(std::istream&, const map&);
    friend std::ostream& operator<<(std::ostream&, const map&);

  private:
    int num_countries;
    int neighbor[MAPSIZE][MAPSIZE];
    color coloring[MAPSIZE];
};

map::map()
{
  for(int i =0; i < MAPSIZE; ++i)
  {
    coloring[i] = none;
    for(int ii=0; ii < MAPSIZE; ++ii)
      neighbor[i][ii] = false;
  }
}

bool map::valid_coloring(int country, color hue) const
{
  for(int i=0; i < num__countries; ++i)
    if(neighbor[country][i] && hue == coloring[i])
      return false;
  return true;
}
