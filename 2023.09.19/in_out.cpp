//
// Created by lucac on 9/19/2023.
//
#include <iostream>

using namespace std;

void cpp(){
    cout << R"(
                                       ///
                                  /////////////
                             //////////////////////
                         ///////////////////////////////
                     ///////////////////////////////////////
                 ///////////////////////////////////////////////
            /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////
    ///////////////////////////                   ///////////////////////////
 /////////////////////////                             ////////////////////////&
///////////////////////                                   /////////////////%%%%%
////////////////////                                         //////////%%%%%%%%%
//////////////////                                             ///%%%%%%%%%%%%%%
/////////////////                   /////////                 %%%%%%%%%%%%%%%%%%
////////////////                /////////////////         %%%%%%%%%%%%%%%%%%%%%%
///////////////              */////////////////////* #%%%%%%%%%%%%%%%%%%%%%%%%%%
//////////////              /////////////////////%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//////////////             //////////////////%%%%%%%%%%%%%%%%   %%%%%%%%   %%%%%
//////////////             /////////////%%%%%%%%%%%%%%%%%%         %%         %%
//////////////             /////////%%%%%%%%%%%%%%%%%%%%%%%%%   %%%%%%%%   %%%%%
//////////////              ////%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
///////////////              (%%%%%%%%%%%%%%%%%%%%%. .%%%%%%%%%%%%%%%%%%%%%%%%%%
////////////////                %%%%%%%%%%%%%%%%%         %%%%%%%%%%%%%%%%%%%%%%
/////////////////                   %%%%%%%%%                 %%%%%%%%%%%%%%%%%%
//////////////%%%%.                                           *%%%%%%%%%%%%%%%%%
//////////%%%%%%%%%%                                        .%%%%%%%%%%%%%%%%%%%
(/////%%%%%%%%%%%%%%%%%                                   %%%%%%%%%%%%%%%%%%%%%%
 %%%%%%%%%%%%%%%%%%%%%%%%%                             %%%%%%%%%%%%%%%%%%%%%%%%&
    %%%%%%%%%%%%%%%%%%%%%%%%%%%                  ,%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&
                 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                              %%%%%%%%%%%%%%%%%%%%%
                                  %%%%%%%%%%%%%
    )" << '\n';
}

void cat(){
    cout << R"(
 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-
 )" << '\n';
}

int main() {
    int sel;
    cout << "what do you want to display?\n -:";
    cin >> sel;
    switch (sel) {
        case 1:
            cpp();
        case 2:
            cat();
    }
    return 0;
}
