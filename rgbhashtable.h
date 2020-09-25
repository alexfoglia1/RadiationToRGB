#ifndef RGBHASHTABLE_H
#define RGBHASHTABLE_H

#include <vector>
#include <cstdint>
#include <map>
#include <QString>

class RGBHashTable
{
public:
    RGBHashTable();
    void add(uint8_t r, uint8_t g, uint8_t b, double f);
    std::vector<double>* get(uint8_t r, uint8_t g, uint8_t b);

private:
    std::map<QString, std::vector<double>> map;
};

#endif // RGBHASHTABLE_H
