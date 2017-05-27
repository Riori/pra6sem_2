#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "types.h"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            throw std::logic_error("1 argument is required");
        }
        
        std::string path(argv[1]);
        
        std::string arg_prefix("--path=");
        
        auto iterators = std::mismatch(path.begin(), path.end(), arg_prefix.begin());
        
        if (iterators.second != arg_prefix.end())
        {
            throw std::logic_error("Not valid argument");
        }
        
        std::fstream f(std::string(iterators.first, path.end()));
        
        if (!f.good())
        {
            throw std::logic_error("File opening failed");
        }
        
        auto ii = std::istreambuf_iterator<char>(f.rdbuf());
        auto eof = std::istreambuf_iterator<char>();
        
        std::string input;
        
        copy_n(ii, 6, std::back_inserter(input));
        ii++;
        
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        
        if (input != std::string("INPUT="))
        {
            throw std::logic_error("Wrong file structure");
        }
        
        std::string message;
        
        std::getline(f, message);
        
        f << std::endl << "OUTPUT=" << sha512(message) << std::endl;
        
    } catch (std::logic_error e) {
        std::cerr << "ERROR!!! ";
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
