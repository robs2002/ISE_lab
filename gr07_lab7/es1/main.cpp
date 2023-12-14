#include <iostream>
#include <string>
#include <stdexcept>
#include "converter.h"
#include <cctype>

int main() {

    try {
        std::string nomeconversione;
        std::cout << "Che conversione vuoi fare?" << std::endl;
        std::cin >> nomeconversione;
        int numero_intero;
        std::string numero_bin_hex, stringa_num;
        bool isnumero = true;

        if(nomeconversione=="intToBin"){
            std::cout << "Che numero vuoi convertire?" << std::endl;
            std::cin >> stringa_num;
            for(char carattere : stringa_num) {
                if (!std::isdigit(carattere))
                isnumero = false;
            }
            if(isnumero) {
                numero_intero= std::stoi(stringa_num);
                numero_bin_hex = converter::intToBin(numero_intero);
                std::cout << "Numero convertito: " << numero_bin_hex << std::endl;
            }else{
                std::cerr << "Numero non valido." << std::endl;
            }

        }else if(nomeconversione=="binToInt") {
            std::cout << "Che numero vuoi convertire?" << std::endl;
            std::cin >> numero_bin_hex;
            numero_intero=converter::binToInt(numero_bin_hex);
            std::cout << "Numero convertito: " << numero_intero << std::endl;

        }else if(nomeconversione=="intToHex") {
            std::cout << "Che numero vuoi convertire?" << std::endl;
            std::cin >> stringa_num;
            for(char carattere : stringa_num) {
                if (!std::isdigit(carattere))
                    isnumero = false;
            }
            if(isnumero) {
                numero_intero = std::stoi(stringa_num);
                numero_bin_hex = converter::intToHex(numero_intero);
                std::cout << "Numero convertito: " << numero_bin_hex << std::endl;
            }else{
                std::cerr << "Numero non valido." << std::endl;
            }

        }else if(nomeconversione=="hexToInt") {
            std::cout << "Che numero vuoi convertire?" << std::endl;
            std::cin >> numero_bin_hex;
            numero_intero=converter::hexToInt(numero_bin_hex);
            std::cout << "Numero convertito: " << numero_intero << std::endl;

        }else{

            std::cerr << "Conversione non riconosciuta." << std::endl;

        }

    }catch(const std::invalid_argument&){

        std::cerr << "Numero non valido." <<std::endl;

    }catch(...){
        std::cerr << "Errore non riconosciuto." <<std::endl;

    }
    return 0;
}
