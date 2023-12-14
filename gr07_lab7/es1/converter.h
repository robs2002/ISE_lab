#ifndef LAB6_CONVERTER_H
#define LAB6_CONVERTER_H

#include <string>

class converter {

public:

    static std::string intToBin(int num);
    static int binToInt(const std::string& bin);
    static std::string intToHex(int num);
    static int hexToInt(const std::string& hex);

};

#endif
