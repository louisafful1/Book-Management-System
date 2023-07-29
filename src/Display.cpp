#include "Display.h"
#include "windows.h" //used in this code to time program
#include <iomanip> //used in this program to change display
#include <iostream>

using namespace std;

Display::Display()
{
    //ctor
}


void Display::showTitle(){
    for(int i=0; i<3; i++){
        Sleep(500);
        verticalSpace(10);
        cout<<setw(85)<<" *********************************************** "<<endl;
        cout<<setw(85)<<"|                                               |"<<endl;
        cout<<setw(85)<<"| B O O K    M A N A G E M E N T    S Y S T E M |"<<endl;
        cout<<setw(85)<<"|                                               |"<<endl;
        cout<<setw(85)<<" *********************************************** "<<endl;
        verticalSpace(10);
        Sleep(1000);
        system("CLS");
    }
}

