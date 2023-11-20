#include "StringVari.h"
#include <string>
#include <algorithm>

string reverseString(string s){
    char temp;
    for ( int jj = 0, j = size(s) - 1; jj < size(s)/2; jj++, j--)
    {
        temp = s[jj];
        s[jj] = s[j];
        s[j] = temp;
    }
    return s;
}

/// <summary>
/// Restituisce una copia del parametro con le r sostituite dalle l
/// </summary>
/// <param name="s"> testo da cinesizzare</param>
/// <returns>testo cinesizzato</returns>
string Cinesizza(string s)
{
    for (int i = 0; i < size(s); i++) {
        if (s[i]=='r'){
            s[i]='l';
        } else if (s[i]=='R'){
            s[i]='L';
        }
    }
    return s;
}

/// <summary>
/// restituisce la stringa s con tutti i caratteri in maiuscolo
/// se s finisce con un punto esclamativo, con tutti i caratteri
/// in minuscolo altrimenti
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string MaiuscCond(string s)
{
    if (s[size(s)-1]=='!'){
        transform(s.begin(), s.end(),s.begin(), ::tolower);
    } else {
        transform(s.begin(), s.end(),s.begin(), ::toupper);
    }
    return s;
}

/// <summary>
/// restituisce true se il parametro contiene almeno una vocale
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool ContieneVocali(string s)
{
    string vocali="aeiouAEIOU‡ËÏÚ˘È";
    for (int i = 0; i < size(s); i++) {
        for (int j = 0; j < size(vocali); j++) {
            if (s[i]==vocali[j]){
                return true;
            }
        }
    }
    return false;
}

/// <summary>
/// restituisce il numero di vocali presenti in s
/// </summary>
/// <param name="s"></param>
/// <returns>numero di vocali presenti</returns>
int NumeroDiVocali(string s)
{
    int voc=0;
    string vocali="aeiouAEIOU‡ËÏÚ˘È";
    for (int i = 0; i < size(s); i++) {
        for (int j = 0; j < size(vocali); j++) {
            if (s[i]==vocali[j]){
                voc++;
            }
        }
    }
    return voc;
}

/// <summary>
/// restituisce la stringa s con la prima vocale sostituita con "_"
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string SostPrimaVocale(string s)
{
    string vocali="aeiouAEIOU‡ËÏÚ˘È";
    for (int i = 0; i < size(s); i++) {
        for (int j = 0; j < size(vocali); j++) {
            if (s[i]==vocali[j]){
                s[i]='_';
                return s;
            }
        }
    }
    return s;
}

/// <summary>
/// restituisce true se la stringa Ë palindroma
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool Palindroma(string s)
{
    transform(s.begin(), s.end(),s.begin(), ::toupper);
    return (s==reverseString(s));//s == inverti(s);  // giusta?Ok, fate la funzione inverti()
}

/// <summary>
/// restituisce la stringa s con le due met‡ porzioniInvertite
/// pollo! => lo!pol
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string InvertiPorzioni(string s)
{
    string theSubString = s.substr(0,size(s)/2);
    string theSubStringv2 = s.substr(size(s)/2,size(s));
    s = theSubStringv2+theSubString;
    return s;
}
/// <summary>
/// restituisce la stringa s con le vocale sostituite dal carattere _
/// aiaiee => ______
/// lolloso => l_ll_s_
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string SostVocali(string s)
{
    string vocali="aeiouAEIOU‡ËÏÚ˘È";
    for (int i = 0; i < size(s); i++) {
        for (int j = 0; j < size(vocali); j++) {
            if (s[i]==vocali[j]){
                s[i]='_';
            }
        }
    }
    return s;
}
