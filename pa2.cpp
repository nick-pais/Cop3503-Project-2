//COP3503 Project 2
//Memory module management
//You can add and remove memory, and see how memory is allocated
//Choose best or worst fit to decide how to allocate memory
//You can also see the Fragmentation

#include <iostream>
#include <math.h>
#include <string>
#include "pa2.h"
#include <stdlib.h>
#include "stdio.h"
using namespace std;

//main
int main(int argc, char *argv[]){
  //method to allow user to choose best or worst in command line
	arguments(argc, argv);

	List list;
    for (int i = 0; i < 32; i++){
        list.addNode("Free");
    }
    cout << endl;
    //Menu text
    cout << "    1. Add a program\n    2. Kill a program\n    3. Fragmentation\n    4. Print memory\n    5. Exit" << endl;
    string nameOfProgram = "";

    char userChoice;
	int programSize;
	int pagesUsed;
  //start page value at 32 for empty
	int pagesAvailable = 32;
    do{

    	cout << "choice - ";
        cin >> userChoice;

        switch(userChoice){

            case '1':
                cout << "Program name - ";
                cin >> nameOfProgram;

				if (nameOfProgram == "Free"){
					cout << "\"Free\" Sorry, not valid program name" << endl;
					exit(EXIT_SUCCESS);
				}
                cout << "Program size (KB) - ";
                cin >> programSize;

                pagesUsed = ceil((double)programSize/4);


				if(string(argv[1]) == "worst"){
					if(list.worst(nameOfProgram, pagesUsed)){
						int initialIndex = list.worstIndex;
						int finalIndex = initialIndex + pagesUsed;
						while(initialIndex < finalIndex){
							list.replaceP(nameOfProgram, initialIndex);
							initialIndex++;
						}
						cout << "Program " << nameOfProgram << " added successfully: " << pagesUsed << " page(s) used." << endl;
						pagesAvailable -= pagesUsed;
						//break;
					}
					else{

					}

				}
				// Do best fit
				else {

					if(list.best(nameOfProgram, pagesUsed)){
						int initialIndex = list.bestIndex;
						int finalIndex = initialIndex + pagesUsed;
						while(initialIndex < finalIndex){
							list.replaceP(nameOfProgram, initialIndex);
							initialIndex++;
							pagesAvailable++;
						}
						cout << "Program " << nameOfProgram << " added successfully: " << pagesUsed << " page(s) used." << endl;
						pagesAvailable -= pagesUsed;
						//break;

					}
					else{

					}

				}
			break;

            case '2':
                cout << "Program name - ";
                cin >> nameOfProgram;

				if (nameOfProgram == "Free"){
					cout << "\"Free\" is not a valid name, sorry." << endl;
					exit(EXIT_SUCCESS);
				}


				if(list.removeP(nameOfProgram)){
	            	cout << "Program " << nameOfProgram << " has been killed" <<endl;
				}
				else{
					cout << "Program " << nameOfProgram << " Sadly doesn't exist, so kill not available" <<endl;
				}
                break;

            case '3':
				list.fragments();
				break;

            case '4':
				list.printList();
                break;

            case '5':
                exit(EXIT_SUCCESS);

			default:
				cout << "Enter valid menu choice" << endl;

        }
    }
    while(userChoice != 5);

	return 0;
}

//for arguments
void arguments(int argc, char *argv[]){
	if (argc != 2){
        cout << "Sorry wrong number of arguments" << endl;
        exit(EXIT_SUCCESS);
    }
    else if (string(argv[1]) == "worst"){
        cout << "Worst fit in use" << endl;

    }
    else if (string(argv[1]) == "best"){
        cout << "Best fit in use" << endl;

    }
    else {
        cout << "Sorry input is not valid" << endl;
        exit(EXIT_SUCCESS);
    }
}
