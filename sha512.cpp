#include "sha512.hpp"

#include <vector>
#include <sstream>

#include "types.h"

u8 symbol_to_hex(char c)
{
    if (c >= 'a' && c <= 'f')
    {
        return (char) 10 + c - 'a';
    }
    if (c >= 'A' && c <= 'F')
    {
        return (char) 10 + c - 'A';
    }
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    throw std::logic_error("Invalid hex character");
}

std::string sha512(std::string message) {
    std::stringstream ss(message);
    
    std::vector<u8> digits;
    char cur_symbol;
    
    while (ss >> cur_symbol) {
        digits.push_back(symbol_to_hex(cur_symbol));
    }
    
    digits.push_back(0x10);
    
    while (digits.size() % 16 != 0) {
        digits.push_back(0x00);
    }
    
    std::vector<u64> longs(digits.size()/16);

    for (int i=0; i<digits.size(); i+=16) {
        u64 res = 0;
        for (int j=0; j<16; ++j) {
            res |= u64(digits[i+j]) << (64 - 4*(j+1));
        }
    }
    
    while (longs.size() % 16 != 14) {
        longs.push_back(0x0);
    }
    
    longs.push_back(0x0);
    longs.push_back(message.length()*4);
    
    
};
