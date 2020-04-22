#include "converter.h"

Converter::Converter()
{

}

Color Converter::convert(double frequency)
{

    double wavelength_m = lightspeed_m_s / frequency;
    double wavelength_nm = wavelength_m * 1e9;
    double red,green,blue;

    if((wavelength_nm >= 380) && (wavelength_nm < 440))
    {
        red = -(wavelength_nm - 440) / (440 - 380);
        green = 0.0;
        blue = 1.0;
    }
    else if((wavelength_nm >= 440) && (wavelength_nm < 490))
    {
        red = 0.0;
        green = (wavelength_nm - 440) / (490 - 440);
        blue = 1.0;
    }
    else if((wavelength_nm >= 490) && (wavelength_nm < 510))
    {
        red = 0.0;
        green = 1.0;
        blue = -(wavelength_nm - 510) / (510 - 490);
    }
    else if((wavelength_nm >= 510) && (wavelength_nm < 580))
    {
        red = (wavelength_nm - 510) / (580 - 510);
        green = 1.0;
        blue = 0.0;
    }
    else if((wavelength_nm >= 580) && (wavelength_nm < 645))
    {
        red = 1.0;
        green = -(wavelength_nm - 645) / (645 - 580);
        blue = 0.0;
    }
    else if((wavelength_nm >= 645) && (wavelength_nm < 781))
    {
        red = 1.0;
        green = 0.0;
        blue = 0.0;
    }
    else
    {
        red = 0.0;
        green = 0.0;
        blue = 0.0;
    }

    Color rgb;
    rgb.red = red == 0.0 ? 0 : static_cast<uint8_t>(max_rgb * red);
    rgb.green = green == 0.0 ? 0 : static_cast<uint8_t>(max_rgb * green);
    rgb.blue = blue == 0.0 ? 0 : static_cast<uint8_t>(max_rgb * blue);

    return rgb;
}
