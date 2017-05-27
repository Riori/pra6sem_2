#include "sha512.hpp"

#include <vector>
#include <sstream>

#include "types.h"

u64 rotr(u64 x, int n) {
    return x >> n | x << (8*sizeof(x) - n);
}

u64 rotl(u64 x, int n) {
    return x << n | x >> (8*sizeof(x) - n);
}

u64 s0(u64 x)
{
	return rotr(x, 1) ^ rotr(x, 8) ^ (x >> 7);
}

u64 s1(u64 x)
{
	return rotr(x, 19) ^ rotr(x, 61) ^ (x >> 6);
}

u64 Ch(u64 x, u64 y, u64 z)
{
	return (x & y) ^ (~x & z);
}

u64 Maj(u64 x, u64 y, u64 z)
{
	return (x & y) ^ (x & z) ^ (y & z);
}

u64 Sigma0(u64 x)
{
	return rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39);
}

u64 Sigma1(u64 x)
{
	return rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41);
}

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
