#include <iostream>
#include <limits.h>
#include "Node.h"
using namespace std;

class List
{
private:
    Node* head, * tail;
public:
    //Constructori
    List();                      //constructor fara parametrii
    List(int);                  //constructor cu un parametru
    List(const List&);		//constructor de copiere

    ~List();	//destructorul

    void insert(int);
    int  search(int);
    void deleteNode(int);
    int sumOfList();
    int countNodes();
    int Min();
    int Max();
    void reverse();



    //Supraincarcarea operatorilor
    friend istream& operator >>(istream&, List&);			//supraincarcarea operatorului de citire
    friend ostream& operator <<(ostream&, const List&);     //supraincarcarea operatorului de afisare
    List& operator=(const List&);	                        //supraincarcarea operatorului =
    List operator +(List&);		                            //supraincarcarea operatorului +
    int operator[](int);		                            //supraincararea operatorului []
    bool operator >(List&);
    bool operator <(List&);		                            //supraincarcarea operatorilor <,> pentru compararea a doua liste
    List& operator *(const int);                            //supraincarcarea operatorului * pentru inmultirea cu un scalar

    
};