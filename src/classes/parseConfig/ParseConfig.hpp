#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <list>
#include "Server.hpp"

class ParseConfig
{
    private:
        string _configFile;
        vector<string> _tokens;
        list<Server> servers;

        void parseServer(Server& server, size_t& i);

    public:
        ParseConfig(string configFile);
        void tokenize();
        void parse();
        void debug(){
            for (vector<string>::iterator it = _tokens.begin(); it != _tokens.end(); it++){
                cout << *it << endl;
            }
        }
        ~ParseConfig();
};
