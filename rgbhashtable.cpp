#include "rgbhashtable.h"

RGBHashTable::RGBHashTable()
{

}

void RGBHashTable::add(uint8_t r, uint8_t g, uint8_t b, double f)
{
    QString c = "%1 %2 %3";
    c = c.arg(r).arg(g).arg(b);
    if (map.find(c) == map.end())
    {
        map[c].push_back(f);
    }
}

std::vector<double>* RGBHashTable::get(uint8_t r, uint8_t g, uint8_t b)
{
    QString c = "%1 %2 %3";
    c = c.arg(r).arg(g).arg(b);

    std::vector<double>* frequencies = new std::vector<double>();
    for(double f : map[c])
    {
        frequencies->push_back(f);
    }
    return frequencies;
}
