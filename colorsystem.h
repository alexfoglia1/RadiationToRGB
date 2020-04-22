#ifndef COLORSYSTEM_H
#define COLORSYSTEM_H

struct Colorsystem
{
  double red_x, red_y, red_z;
  double green_x, green_y, green_z;
  double blue_x, blue_y, blue_z;
  double white_x, white_y, white_z;
};

const Colorsystem NTSC = {0.67, 0.33, (1 - 0.67 - 0.33),
                          0.21, 0.71, (1 - 0.21 - 0.71),
                          0.14, 0.08, (1 - 0.14 - 0.08),

#endif // COLORSYSTEM_H
