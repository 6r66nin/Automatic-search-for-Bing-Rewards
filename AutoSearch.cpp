#include "Functions.h"

/* 
    -p : set a path; example: AutoSearch -p "MyFolder/MyFile.txt"  
    -m : set limit of searches; example: AutoSearch -m 30 
    -t : Set time per search in ms; example: AutoSearch -t 8000 (8 seconds between each search)  
    ---------------------------------------------------------------------------------------------
    do not write nothing for default settings, just: AutoSearch

*/

void InitSearchLoop(int SearchsAmount, int TimePerSearch) {

    cout << "Searching... " << " TIME: " << TimePerSearch << " Search Aumount: " << SearchsAmount;

    for (int i = 0; i < SearchsAmount; i++)
    {

        string Search = SearchVector[i];

        FocusOnSearchBar();

        Sleep(870);

        WriteSearch(Search);

        Sleep(890);

        PressEnter();

        Sleep(TimePerSearch);


    }

}


int main(int argc, char* argvs[]) {

    // Pause to Open the Browser 
    
    Sleep(2000);


    // Setting default vars

    int SearchesAmount = 50;

    int TimePerSearch = 5000;

    //Checking Args Loop
    
    for (int i = 1; i < argc; i++)
    {

        if (strcmp(argvs[i], "-p") == 0) {

            if (i + 1 < argc)
            {
                string str(argvs[i + 1]);

                GetSearchesOfFile(str);

                continue;
            }
        }

        if (strcmp(argvs[i], "-m") == 0) {

            if (i + 1 < argc)
            {
                
                SearchesAmount = atoi(argvs[i + 1]);
                
                continue;
            }
        }

        if (strcmp(argvs[i], "-t") == 0) {

            if (i + 1 < argc)
            {

                TimePerSearch = atoi(argvs[i + 1]);

                continue;
            }
        }


    }

    if (argc == 1) {

        GetSearchesOfFile();

    }

    //Init Search Loop

    InitSearchLoop(SearchesAmount, TimePerSearch);

    
    return 0;
    
}


