#include "functions.h"

vector<string> SearchVector;


bool GetSearchesOfFile(const string& Path){
    
    ifstream FILE(Path);

    if (!FILE) {

        cerr << "Fail to load txt at (" << Path << ")\n";

        return 0;
    }


    //Saving each Search of the file

    string Search;


    while (getline(FILE, Search))
    {
        if (!Search.empty()) {

            SearchVector.push_back(Search);
        }
    }

    return 1;
}

void GetSearchesOfFile(){ GetSearchesOfFile("txtFolder/BingSearchScript.txt"); }