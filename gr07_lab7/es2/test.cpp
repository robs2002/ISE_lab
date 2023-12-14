#include "test.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "converter.h"
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>

int test::testfunct() {
    std::string nomeconversione;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    assert(input.is_open() && "File input non può essere aperto." );
    assert(output.is_open() && "File output non può essere aperto." );

    int numero_intero;
    std::string numero_bin_hex, stringa_num, line;
    bool isnumero = true;
    try{
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        assert(iss >> nomeconversione >> stringa_num && "Argomenti nella riga non corretti.");
        iss >> nomeconversione >> stringa_num;
        if (nomeconversione == "intToBin") {
            for (char carattere: stringa_num) {
                if (!std::isdigit(carattere))
                    isnumero = false;
            }
            assert(isnumero && "Numero non valido.\n" );
            numero_intero = std::stoi(stringa_num);
            numero_bin_hex = converter::intToBin(numero_intero);
            output << stringa_num << " (int) ------> " << numero_bin_hex << " (bin) " << std::endl;
            isnumero=true;
        }
        else if (nomeconversione == "binToInt") {
            numero_bin_hex=stringa_num;
            numero_intero = converter::binToInt(numero_bin_hex);
            output << stringa_num << " (bin) ------> " << numero_intero << " (int) " << std::endl;

        } else if (nomeconversione == "intToHex") {
            for (char carattere: stringa_num) {
                if (!std::isdigit(carattere))
                    isnumero = false;
            }
            assert(isnumero && "Numero non valido.\n" );
            numero_intero = std::stoi(stringa_num);
            numero_bin_hex = converter::intToHex(numero_intero);
            output << stringa_num << " (int) ------> " << numero_bin_hex << " (hex) " << std::endl;

        } else if (nomeconversione == "hexToInt") {
            numero_bin_hex=stringa_num;
            numero_intero = converter::hexToInt(numero_bin_hex);
            output << stringa_num << " (hex) ------> " << numero_intero << " (int) " << std::endl;

        } else {

            std::cerr << "Tipo di conversione non riconosciuta." << std::endl;

        }
    }}catch(const std::invalid_argument&){

            std::cerr << "Numero non valido." <<std::endl;

            }catch(...){
            std::cerr << "Errore non riconosciuto." <<std::endl;

    }
    input.close();
    output.close();

    return 0;

}
