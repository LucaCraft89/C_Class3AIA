#include <iostream>
#include <string>
#include <algorithm>
#include "StringVari.h"
#include "StringVari.cpp"

using namespace std;

int main()
{
    //      risultato ottenuto     risultato atteso
    cout << "TEST1" << endl;
    cout << (Cinesizza("Porro") == "Pollo") << endl;
    cout << (Cinesizza("PORRO") == "POLLO") << endl;
    cout << (Cinesizza("PORro") == "POLlo") << endl;
    cout << (Cinesizza("Salve") == "Salve") << endl;
    cout << (Cinesizza("")      == "")      << endl;

    cout << "TEST2" << endl;
    cout << (MaiuscCond("Abc!") == "abc!")  << endl;
    cout << (MaiuscCond("Abc")  == "ABC")   << endl;
    cout << (MaiuscCond("Schloß!") == "SCHLOSS!")   << endl;//Questo fallirà, è normale.
    
    cout << "TEST3" << endl;
    cout << (NumeroDiVocali("Aiuola") == 5) << endl;
    cout << (NumeroDiVocali("Informatica") == 5)    << endl;
    cout << (NumeroDiVocali("No")   == 1)   << endl;
    cout << (NumeroDiVocali("Sì")   == 1)   << endl;
    cout << (NumeroDiVocali("bcd")  == 0)   << endl;
    
    cout << "TEST4" << endl;
    cout << (ContieneVocali("Aiuola") == true)  << endl;
    cout << (ContieneVocali("Informatica") == true) << endl;
    cout << (ContieneVocali("No")   == true)    << endl;
    cout << (ContieneVocali("Sì")   == true)    << endl;
    cout << (ContieneVocali("bcd")  == false)   << endl;
    
    cout << "TEST5" << endl;
    cout << (Palindroma("ABA") == true)     << endl;
    cout << (Palindroma("ABB") == false)    << endl;
    cout << (Palindroma("ABa") == true)     << endl;
    
    cout << "TEST6" << endl;
    cout << (InvertiPorzioni("abcd") == "cdab")     << endl;
    cout << (InvertiPorzioni("abcde") == "cdeab")   << endl;
    cout << (InvertiPorzioni("") == "")     << endl;
    
    cout << "TEST7" << endl;
    cout << (SostPrimaVocale("bcd") == "bcd")   << endl;
    cout << (SostPrimaVocale("Pero") == "P_ro") << endl;
    cout << (SostPrimaVocale("A") == "_")   << endl;
    cout << (SostPrimaVocale("mA") == "m_") << endl;
    cout << (SostPrimaVocale("école") == "_cole")   << endl;
    cout << (SostPrimaVocale("è") == "_")   << endl;

    cout << "TEST8" << endl;
    cout << (SostVocali("albero") == "_lb_r_")  << endl;
    cout << (SostVocali("no") == "n_")  << endl;
    cout << (SostVocali("sì") == "s_")  << endl;
    cout << (SostVocali("bcd") == "bcd")    << endl;

}

