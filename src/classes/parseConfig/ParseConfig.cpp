#include "ParseConfig.hpp"

ParseConfig::ParseConfig(string configFile) : _configFile(configFile) {}
ParseConfig::~ParseConfig(){}

void checkBraces(stack<string> &bracesCheck, string word)
{
    if (word == "{")
        bracesCheck.push(word);
    else if (word == "}" && bracesCheck.top() == "{")
        bracesCheck.pop();
    else
        throw runtime_error("Error: braces error");
}

void ParseConfig::tokenize(){

    ifstream file(_configFile.c_str());
    if (!file.is_open()){
        throw runtime_error("Error: Could not open config file: " + _configFile);
    }
    string line;
    stack<string> bracesCheck;

    while (getline(file, line))
    {
        if (line.empty()) continue;
        
        istringstream iss(line);
        std::string word;
        
        while (iss >> word) {
            if (word == "{" || word == "}")
                checkBraces(bracesCheck, word);
            _tokens.push_back(word);
        }
    }
    if (!bracesCheck.empty())
        throw runtime_error("Error: braces error");
}