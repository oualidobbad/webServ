#include <iostream>
#include <vector>

using namespace std;

class ParseConfig
{
    private:
        string _configFile;
        vector<string> _tokens;

    public:
        ParseConfig(string configFile);
        
        ~ParseConfig();
};


ParseConfig::ParseConfig(string configFile){
    this->_configFile = configFile;
}
