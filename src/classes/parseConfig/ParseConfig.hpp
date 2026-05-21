#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
#include <stack>

using namespace std;

class ParseConfig
{
    private:
        string _configFile;
        vector<string> _tokens;

    public:
        ParseConfig(string configFile);
        void tokenize();
        void print();
        ~ParseConfig();
};
