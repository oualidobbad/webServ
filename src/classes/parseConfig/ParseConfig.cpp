#include "ParseConfig.hpp"

ParseConfig::ParseConfig(string configFile) : _configFile(configFile) {}
ParseConfig::~ParseConfig(){}

void ParseConfig::tokenize(){

    ifstream file(_configFile.c_str());
    if (!file.is_open()){
        throw runtime_error("Error: Could not open config file: " + _configFile);
    }
    string line;
    stack<string> bracesCheck;

    while (getline(file, line)) {
        size_t commentPos = line.find('#');
        if (commentPos != string::npos) {
            line = line.substr(0, commentPos);
        }
        if (line.empty()) continue;
        for (size_t i = 0; i < line.length(); ++i) {
            if (line[i] == '{' || line[i] == '}' || line[i] == ';') {
                line.insert(i + 1, " "); // Space after
                line.insert(i, " ");     // Space before
                i += 2;                  // Skip over the two new spaces
            }
        }
        istringstream iss(line);
        std::string word;
        
        while (iss >> word) {
            if (word == "{" || word == "}")
            {
                if (word == "{")
                    bracesCheck.push(word);
                else if (!bracesCheck.empty() && word == "}" && bracesCheck.top() == "{")
                    bracesCheck.pop();
                else
                    throw runtime_error("Error: Unmatched closing brace '}'");
            }
            _tokens.push_back(word);
        }
    }
    if (!bracesCheck.empty())
        throw runtime_error("Error: Unclosed brace '{' found");
}

void ParseConfig::parseServer(Server& server, size_t &i){
    if (i >= _tokens.size())
        throw invalid_argument("block not completed !");
    else if (_tokens[i++] != "{")
        throw invalid_argument("config file syntax error must found braces follow server like -> 'server {'");

    while (i < _tokens.size())
    {
        
    }
    
}

void ParseConfig::parse(){
    size_t i = 0;
    while (i < _tokens.size()){
        Server server;
        if (_tokens[i++] == "server"){
           parseServer(server, i);
        }else{
            throw invalid_argument("config file must start with [server] not " + _tokens[i]);
        }
    }
}

