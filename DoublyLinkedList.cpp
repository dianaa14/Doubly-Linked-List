#include <iostream>
#include <limits.h>
#include <cassert>
#include"DoublyLinkedList.h"
#include"Node.h"
#include"Node.cpp"
using namespace std;

List::List()                                 //Constructorul fara parametrii
{
    head = NULL;// primul element
    tail = NULL;// utlimul element
  
    
}
List::List(int x)                             //constructorul pentru un obiect de tip List cu un singur element
{
    head= new Node(x, NULL, NULL);           //construim nodul start,care nu are vecini
    
    head->next = head->prev = head;          //ciclic
    tail = head;

}
List::List(const List& k) {
    head = NULL;               //initializam obiectul curent ca vid
    Node* p = k.head;
    while (p->next != k.head)         //copiem element cu element
    {
        insert(p->val);
        p = p->next;
    }
    insert(p->val);
}
//INSERT
void List::insert(int value)
{
    Node* ptr;
    ptr = head;
    // Daca lista e goala creez un singur nod
    // circular
    if (ptr == NULL)
    {
        Node* new_node = new Node;
        new_node->val = value;
        new_node->next = new_node->prev = new_node;
        head = new_node;
        tail = new_node;
        return;
    }

    // Daca lista nu e goala

    // Creez nodul dinamic
    Node* new_node = new Node;
    new_node->val = value;//ia valoarea value

    // nodul urmator pentru nodul curent va fi head
    new_node->next = head;

    // nodul anterior al lui head va fi noul nod
    head->prev = new_node;

    // nodul anterior nodului curent devine tail
    new_node->prev = tail;

    // nodul urmator pentru tail devine nodul curent, iar tail este actualizat cu acesta
    tail->next = new_node;
    tail = new_node;
}




//CAUTAREA UNUI ELEMENT
int List::search(int x)
{
    Node* curent = head; // Initializez nodul curent cu head 
    int p = 0;
    int ceva = 0;
    while (curent != tail)
    {
        p++;
        if (curent->val == x)
        {
            ceva = 1;
            return p;
        }
        curent = curent->next;
    }
    p++;
    if (curent->val == x)
    {
        return p;
        ceva = 1;

    }

    if (ceva == 0)
        cout << "Elementul nu exista" << endl;
    return 0;
}

void List::deleteNode(int del)
{ 
    int i = search(del);//aflu pozitia elementului
    if (i > 1 && i <= countNodes()) //sterg doar daca elementul exista in lista
    {
        
        Node* curent = head; // Initializez nodul curent cu head 
        while (curent != tail)
        {

            if (curent->val == del)
            {
                curent->prev->next = curent->next;// elementul precendent pointeaza catre adresa urmatorului element fata de cel curent 
                
            }


            curent = curent->next;
        }
        //ultimul element
        if (curent->val == del)
        {
            curent->prev->next = curent->next;// elementul precendent celui curent pointeaza catre adresa urmatorului element fata de cel curent 
        }
        delete curent;





        return;
    }
}
// SUMA ELEMENTELOR DIN LISTA

int List::sumOfList()
{
    Node* curent = head;
    int sum = 0;
    if (head != NULL) {
        do {
            curent = curent->next;
            sum += curent->val;
        } while (curent != head);
    }

    return sum;
}
//NUMARUL DE ELEMENTE DIN LISTA
int List::countNodes()
{
    Node* curr = head;
    int result = 0;
    if (head != NULL) { //daca lista nu e goala
        do {
            curr = curr->next; 
            result++; // numar nodurile
        } while (curr != head); // cat timp nu ajung iar la inceput
    }

    return result;

}
int List::Min()
{

    // verific daca lista e goala
    if (head == NULL) {
        return 0;
    }


    Node* curent;
    curent = head;

    // initializez min cu valoarea maxima 

    int min = INT_MAX;

    // Cat timp primul nod nu este atins
    do {

        if (curent->val < min) {
            min = curent->val;
        }


        
        curent = curent->next;
    } while (curent != head);

   return min;
 

}
int List::Max()
{
    //verific daca lista e goala
   
    if (head == NULL) {
        return 0;
    }


    Node* curent;
    curent = head;

    // initializez max cu valoarea minima 

    int max = INT_MIN;

    // Cat timp primul nod nu este atins
    do {

        if (curent->val > max) {
            max = curent->val;
        }



        curent = curent->next;
    } while (curent != head);

    return max;


}

void List::reverse()
{
      
        if (countNodes()> 1)        //facem modificari doar daca lista are cel putin 2 elemente
        {
            Node* a = head;
            Node* b = tail;
            int val1 = head->getVal();          //iterschimb valorile dintre primul nod si ultimul nod
            int val2 = b->getVal();
            head->setVal(val2);
            b->setVal(val1);
            a = a->next;                     //iterez din ambele capete
            while(a!=b) // interschimb pana ajung la mijloc
            {
                int val1 = a->getVal();
                int val2 = b->getVal();
                a->setVal(val2);
                b->setVal(val1);
                a = a->next;
                b = b->prev;
            }
        }


    }






            
    

//Supraincarcarea operatorilor
istream& operator >>(istream& in, List& l)  //supraincarcarea opreratorului >>
{
    int n;
    int x;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> x;
        l.insert(x);
    }
    return in;
}
ostream& operator <<(ostream& out, const List& l) // supraincarcarea operatorului <<
{
    Node* p = l.head;
    if (p == NULL)
    {
        out << "Lista este vida";
    }

    else if (p != NULL)
    {

        out << p->val << " ";
        p = p->next;
        while (p != l.head && p != NULL)
        {
            out << p->val << " ";
            p = p->next;
        }
        
        
    }
    return out;
}

List& List::operator=(const List& k)  // supraincarea operatorului =
{
    
        this->~List();   //stergem ce este in obiectul curent
        Node* aux = k.head;
        
        while (aux!=k.tail) //copiez toata informatia din k in obiectul curent
        {
            insert(aux->val);
            aux = aux->next;
            
        }
        
    
    return *this;
}

List List::operator+(List& k) // supraincarcarea operatorului +
{

    if ((k.countNodes() == 0 && countNodes() == 0) || (k.countNodes() > 0 && countNodes() == 0))   //in cazul in care obiectul de tip lista k si celalalt sunt liste vide sau doar celalalt este vid,returnam k
        return k;
    if (k.countNodes() == 0 && countNodes() > 0)          //daca k nu are elemente, dar celalalt are, returnam obiectul cu elemente fara a mai face reuniunea
        return *this;
    List rezultat(k);
    Node* p = this->head;
    for (int i = 1; i <= countNodes()+1; i++) // inserez valori in rezultat
    {
        rezultat.insert(p->val);
        p = p->next;
    }

    return rezultat;
}

int List::operator[](int i) // supraincarcarea operatorului []
{
    int c = 1;                   //ne luam un contor c care porneste de la 1 si parcurgem lista pana cand c==i.Cand am ajuns la pozitia ceruta returnam valoarea din nodul in care am ajuns
    Node* p = head;
    if (i <= countNodes() || c < i)        //daca pozitia dorita este mai mare decat lungimea listei sau daca este un nr.negativ nu mai efectuam
    {

        if (c == i)                    //pentru elementul de pe pozitia 1
        {
            int value = head->val;
            return value;
        }
        else                           //altfel parcurgem lista pana cand  c=i
        {
            while (c != i)
            {
                c++;
                p = p->next;
            }
            int a = p->val;
            return a;
        }
    }
}
bool List ::operator >(List& l) // supraincarcarea operatorului >
{
    if (sumOfList() > l.sumOfList())
        return 1;
    return 0;
}
bool List::operator <(List& l) // supraincarcarea operatorului <
{
    if (sumOfList() < l.sumOfList())
        return 1;
    return 0;
}
List& List::operator*(const int x) //supraincarcarea operatorului *
{
    if (countNodes() == 0)
    {

        //daca lista este vida
        if (countNodes() == 1)    //daca lista are un singur element
        {
            int i = head->val;
            head->val = i * x;
            return *this;
        }
        Node* p = head->next;   //in cazul in care lungimea listei>1,atunci valoarea stocata in val pentru fiecare nod se inmulteste cu scalarul
        int i = head->val;
        head->val = i * x;
        for (int i = 1; i < countNodes(); i++)
        {
            int j = p->val;     //preluam informatia curenta din fiecare nod
            p->val = i * x;        //setam noua valoare
            p = p->next;
        }
    }
    return *this;                   //returnam obiectul modificat
}
//Destructor
List::~List() {                   
    if (head == NULL)         //daca lista este vida nu mai apelez destructorul
        return;
    Node* a = head->getNext(); // pentru destructor am creat functia getNext() 
    if (a == NULL)     //daca avem doar un element
    {
        Node* b = a;
        delete b;
        head= NULL;
        

    }
    while (a != head) {
        Node* b = a;
        a = a->getNext();
        delete b;
    }
    Node* b = a;
    delete b;
    head = NULL;
    
}



void Test() {
    List a;


    a.insert(6);
    a.insert(8);
    a.insert(12);
    a.insert(18);
    cout << a;
    assert(a.search(20)==0);// Va afisa "Elementul nu exista"
    assert(a.search(6)==1);
    assert(a.search(18)==4);
    a.deleteNode(18);
    cout << a;
    assert(a.sumOfList()== 26);
    assert(a.countNodes() == 3);
    assert(a.Min()==6);
    assert(a.Max() == 12);
    List b;
    cin >> b;
    cout << b << endl;;
    List c;
    c = a + b;
    cout << c<<endl;
    c.~List();
    cout << c;
    assert(a[1] == 6);
    assert((a > b) == 1); //ii dau lui b valori mai mici
    a = b;
    
   
    

   
}

int main()
{
    Test();
    return 0;
}





