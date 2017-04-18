#ifndef PA2_H
#define PA2_H
#include <iostream>

#include "stdio.h"

using namespace std;

//creates linked list
void initializeLinkedList();
//for user menu
void menu(char *argv[]);
//for initail command line arguments "best" or "worst"
void arguments(int argc, char *argv[]);


class List{
  //private function list
private:

    typedef struct node{
        string d;
        node *next;
		bool isFree;
    }* nodePtr;

    nodePtr head;
    nodePtr current;
    nodePtr temp;
//public function list
public:
    List();
	bool best(string programName, int pagesUsed);
	bool worst(string programName, int pagesUsed);
    void addNode(string addd);
    bool removeP(string dToRemove);
	void fragments();
    void printList();
	int bestIndex;
	int worstIndex;
	void replaceP(string programName, int index);
};


List::List(){
    head = NULL;
    current = NULL;
    temp = NULL;
}


void List::addNode(string addd){
    nodePtr n = new node;
    n->next = NULL;
    n->d = addd;
    if (head != NULL){
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = n;
    }
    else {
        head = n;
    }
}


bool List::best(string programName, int pagesUsed){
	current = head;
	int minPages = 0;
	int count = 1;
	int beginning = 0;
	int initial = 0;

	for (int i = 0; i < 32; i++){


		if (current->d == programName){
			cout << "Error. Program " << programName << " already running." << endl;;
			return false;
		}

		if(current->d == "Free"){
			beginning = i;

			while(current->d == "Free"){
				if (current->next != NULL){
					current = current->next;
					count++;
				}

				else{
					break;
				}
			}


			if (count >= pagesUsed){
				if(initial == 0){
					bestIndex = beginning;
					minPages = count;
					initial++;
				}


				if(count < minPages){
					bestIndex = beginning;
					minPages = count;
				}
			}


			count = 0;
		}
		else if (current->next != NULL){
			current = current->next;
		}
	}

	if (minPages >= pagesUsed){
		return true;
	}
	else{

		cout << "Error, Not enough memory for Program " << programName << "." << endl;
		return false;
	}
}

bool List::worst(string programName, int pagesUsed){
	int maxPages = 0;
	int count = 1;
	int beginning = 0;
	current = head;
	for (int i = 0; i < 32; i++){
		if (current->d == programName){
			cout << "Error. Program " << programName << " already running." << endl;;
			return false;
		}
		if (current->d == "Free"){
			beginning = i;

			while (current->d == "Free"){
				if (current->next != NULL){
					count++;
					current = current->next;
				}
				else{
					break;
				}
			}
			if (count > maxPages){
				maxPages = count;
				worstIndex = beginning;
			}
			count = 0;

		}
		else if(current->next != NULL){
			current = current->next;
		}
	}
	if (maxPages >= pagesUsed){
		return true;
	}
	else {
		cout << "Cannot add program." << endl;
		return false;
	}
}

void List::replaceP(string programName, int initialIndex){
	current = head;
	int count = 0;
	// while
	while (count < initialIndex){
		current = current->next;
		count++;
	}
	current->d = programName;
}
bool List::removeP(string dToRemove){
	current = head;
	bool result = false;
	for (int i = 0; i < 32; i++){
		if (current->d == dToRemove){
			current->d = "Free";
			result = true;
		}

		if(current->next != NULL){
			current = current->next;
		}
	}
	if(result){
		return result;
	}
	else{
		return result;
	}
}

void List::fragments() {

    current = head;
	  string name;
    int fragments = 0;
	while (current != NULL){
		if (current->d == "Free" && name!= "Free"){
			name = "Free";
			fragments++;
		}
		else if (current->d != name){
			current = current->next;
		}
		else{
			current = current->next;
		}
	}
	cout << "There are " << fragments << " fragment(s)" << endl;
}



void List::printList(){
    current = head;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 8; j++){
			if (current->d == "Free"){
            	cout << current->d << " ";
        		current = current->next;
			}
			else{
				cout << current->d << "   ";
				current = current->next;
			}
		}
		cout << "\n";
    }
}
#endif
