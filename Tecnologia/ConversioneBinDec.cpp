//
// Created by lucac on 10/17/2023.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const string hex0="0000";
const string hex1="0001";
const string hex2="0010";
const string hex3="0011";
const string hex4="0100";
const string hex5="0101";
const string hex6="0110";
const string hex7="0111";
const string hex8="1000";
const string hex9="1001";
const string hexA="1010";
const string hexB="1011";
const string hexC="1100";
const string hexD="1101";
const string hexE="1110";
const string hexF="1111";

const string oct0="000";
const string oct1="001";
const string oct2="010";
const string oct3="011";
const string oct4="100";
const string oct5="101";
const string oct6="110";
const string oct7="111";


char binToHex(char bin1, char bin2, char bin3, char bin4) {
    string hexOne;
    hexOne=hexOne.append(1, bin1);
    hexOne=hexOne.append(1, bin2);
    hexOne=hexOne.append(1, bin3);
    hexOne=hexOne.append(1, bin4);
    if (hexOne.compare(hex0)==0){return '0';}
    else if (hexOne.compare(hex1)==0) {return '1';}
    else if (hexOne.compare(hex2)==0) {return '2';}
    else if (hexOne.compare(hex3)==0) {return '3';}
    else if (hexOne.compare(hex4)==0) {return '4';}
    else if (hexOne.compare(hex5)==0) {return '5';}
    else if (hexOne.compare(hex6)==0) {return '6';}
    else if (hexOne.compare(hex7)==0) {return '7';}
    else if (hexOne.compare(hex8)==0) {return '8';}
    else if (hexOne.compare(hex9)==0) {return '9';}
    else if (hexOne.compare(hexA)==0) {return 'A';}
    else if (hexOne.compare(hexB)==0) {return 'B';}
    else if (hexOne.compare(hexC)==0) {return 'C';}
    else if (hexOne.compare(hexD)==0) {return 'D';}
    else if (hexOne.compare(hexE)==0) {return 'E';}
    else if (hexOne.compare(hexF)==0) {return 'F';}
}

string hexToBin(char Hex1) {
    if (Hex1=='0'){return hex0;}
    else if (Hex1=='1') {return hex1;}
    else if (Hex1=='2') {return hex2;}
    else if (Hex1=='3') {return hex3;}
    else if (Hex1=='4') {return hex4;}
    else if (Hex1=='5') {return hex5;}
    else if (Hex1=='6') {return hex6;}
    else if (Hex1=='7') {return hex7;}
    else if (Hex1=='8') {return hex8;}
    else if (Hex1=='9') {return hex9;}
    else if (Hex1=='A') {return hexA;}
    else if (Hex1=='B') {return hexB;}
    else if (Hex1=='C') {return hexC;}
    else if (Hex1=='D') {return hexD;}
    else if (Hex1=='E') {return hexE;}
    else if (Hex1=='F') {return hexF;}
}

string octToBin(char Oct1) {
    if (Oct1=='0'){return oct0;}
    else if (Oct1=='1') {return oct1;}
    else if (Oct1=='2') {return oct2;}
    else if (Oct1=='3') {return oct3;}
    else if (Oct1=='4') {return oct4;}
    else if (Oct1=='5') {return oct5;}
    else if (Oct1=='6') {return oct6;}
    else if (Oct1=='7') {return oct7;}
}

char binToOct(char bin1, char bin2, char bin3) {
    string octOne;
    octOne=octOne.append(1, bin1);
    octOne=octOne.append(1, bin2);
    octOne=octOne.append(1, bin3);
    if (octOne.compare(oct0)==0){return '0';}
    else if (octOne.compare(oct1)==0) {return '1';}
    else if (octOne.compare(oct2)==0) {return '2';}
    else if (octOne.compare(oct3)==0) {return '3';}
    else if (octOne.compare(oct4)==0) {return '4';}
    else if (octOne.compare(oct5)==0) {return '5';}
    else if (octOne.compare(oct6)==0) {return '6';}
    else if (octOne.compare(oct7)==0) {return '7';}
}

int main() {
    string bin, binar;
    char temp, hex1, hex2, oct1, oct2, oct3;
    int inter=0, repeat, sel;
    cout << "Da quale vuoi convertire (1=bin, 2=hex, 3=oct)\n -:";
    cin >> sel;
    switch (sel) {
        case 1:
            cout << "immettere bin (non più di 8 bit)\n -:";
            fflush(stdin);
            getline(cin, bin);
            if (bin.length()>8){
                cout << "Ho detto sono 8 bit!!!!!!!!!\n";
                main();
            }
            else if (bin.length()<8) {
                cout << "aggiungere 0 per formare 8 bit grazie\n";
                main();
            }
            break;
        case 2:
            cout << "immettere hex (non più di 2 cifre)\n -:";
            fflush(stdin);
            getline(cin, bin);
            if (bin.length()>2){
                cout << "Ho detto sono 8 bit!!!!!!!!!\n";
                main();
            }
            else if (bin.length()<2) {
                cout << "aggiungere 0 per formare 8 bit grazie\n";
                main();
            }
            break;
        case 3:
            cout << "immettere oct (non più di 3 cifre con max 377)\n -:";
            fflush(stdin);
            getline(cin, bin);
            if (bin.length()>3){
                cout << "Ho detto sono 8 bit!!!!!!!!!\n";
                main();
            }
            else if (bin.length()<3) {
                cout << "aggiungere 0 per formare 8 bit grazie\n";
                main();
            }
            break;
        default:
            cout << "Input sbagliato\n";
            main();
    }

    if (sel==2){
        binar=binar+hexToBin(bin[0]);
        binar=binar+hexToBin(bin[1]);
        bin=binar;
    } else if (sel==3) {
        binar=binar+octToBin(bin[0]);
        binar.erase(0, 1);
        binar=binar+octToBin(bin[1]);
        binar=binar+octToBin(bin[2]);
        bin=binar;
    }
    hex1 = binToHex(bin[0], bin[1], bin[2], bin[3]);
    hex2 = binToHex(bin[4], bin[5], bin[6], bin[7]);
    cout << "HEX: " << hex1 << hex2 << endl;
    oct1 = binToOct('0', bin[0], bin[1]);
    oct2 = binToOct(bin[2], bin[3], bin[4]);
    oct3 = binToOct(bin[5], bin[6], bin[7]);
    cout << "OCT: " << oct1 << oct2 << oct3 << endl;
    cout << "BIN: " << bin << endl;
    for ( int jj = 0, j = 8 - 1; jj < 8/2; jj++, j--)
    {
        temp = bin[jj];
        bin[jj] = bin[j];
        bin[j] = temp;
    }
    for (int i = 0; i < 8; ++i) {
        if (bin[i-1]=='1'){
            inter = inter + pow(2, i-1);
        }
    }
    if (bin[7]=='1'){
        inter = inter + pow(2, 7);
    }
    cout << "DEC: " << inter << endl;

    cout << "Convertire un'altro? (1 si. 0 no)\n -:";
    cin >> repeat;
    if (repeat){
        main();
    }
    return 0;
}
