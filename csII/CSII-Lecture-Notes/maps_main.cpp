#include "map.hpp"

bool MapColor(int country, map& world)
{
  bool a_color_remaining  = true,
       done_coloring      = false;

  color hue;

  if(country < world.num_contries()) // not done coloring map
  {
    hue = red;
    while(!done_coloring && a_color_remaining) // Try alternative colors
    {
      if(world.valid_coloring(country, hue))
      {
        world.color_country(country, hue);
        done_coloring = MapColor(country+1, world);
      }
      
      if(hue == yellow) a_color_remaining = false;
      else hue++;
    }

    if(!done_coloring)
      world.colorCountry(country, color(none)); // hit deadend, uncolor and move back track (recursive)
  }
  else
    done_coloring = true;

  return done_coloring;
}
