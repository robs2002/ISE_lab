#include "converter.h"
#include <stdexcept>
#include <string>

std::string converter::intToBin(int num){
std::string bin;
while(num>0){
    bin=std::to_string(num % 2)+bin;
    num=num/2;
}
    return bin.empty() ? "0" : bin;
};

int converter::binToInt(const std::string& bin){
    int result=0;
    int power=1;
    for(int i= bin.length()-1; i>= 0; i-- ){
    if(bin[i]=='1'){
    result+=power;
    } else if (bin[i]!='0'){
        throw std::invalid_argument("Numero bin non valido.\n");
    }
    power*=2;
    }
    return result;
};

std::string converter::intToHex(int num){
    std::string hex;
    int resto;
    if(num)
    while(num>0){
        resto=(num % 16);
        num=num/16;
        if(resto<10){
            hex=char('0'+resto)+hex;
        } else{
            hex=char('A'+resto-10)+hex;
        }
    }
    return hex.empty() ? "0" : hex;
};

int converter::hexToInt(const std::string& hex){
    int result=0,hexnum=0, power=1;
    for(int i= hex.length()-1; i>= 0; i-- ){
        if (hex[i] >= '0' && hex[i] <= '9') {
            hexnum=hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            hexnum=hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            hexnum=hex[i] - 'a' + 10;
        } else {
        throw std::invalid_argument("Numero hex non valido.\n");
        }
        result+=hexnum*power;
        power*=16;
    }
    return result;
};
