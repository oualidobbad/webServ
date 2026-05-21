#include "includes.hpp"

int main (int ac, char *av[])
{
    try
    {
    string fileName = "/home/oobbad/Desktop/webServ/resources/default.conf";
       if (ac == 2)
            fileName = av[1];
        ParseConfig *parseConfig = new ParseConfig(fileName);
        parseConfig->tokenize();
        delete parseConfig;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
