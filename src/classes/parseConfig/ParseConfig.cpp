#include "ParseConfig.hpp"

ParseConfig::ParseConfig(string configFile) : _configFile(configFile) {}
ParseConfig::~ParseConfig(){}

void checkBraces(stack<string> &bracesCheck, string word)
{
    if (word == "{")
        bracesCheck.push(word);
    else if (!bracesCheck.empty() && word == "}" && bracesCheck.top() == "{")
        bracesCheck.pop();
    else
        throw runtime_error("Error: Unmatched closing brace '}'");
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
                checkBraces(bracesCheck, word);
            _tokens.push_back(word);
        }
    }
    if (!bracesCheck.empty())
        throw runtime_error("Error: Unclosed brace '{' found");
}


