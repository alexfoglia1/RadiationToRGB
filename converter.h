#ifndef CONVERTER_H
#define CONVERTER_H

#include <cstdint>
#include <limits>

struct Color
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

const auto lightspeed_m_s = 299792458.0;
const uint8_t max_rgb = std::numeric_limits<uint8_t>::max();

class Converter
{
public:
    Converter();
    Color convert(double frequency);

};

#endif // CONVERTER_H
