#include "Base.h"
#include "windows.h" //used in this code to time program
#include <iomanip> //used in this program to change display
#include <fstream>//for using text files
#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

Base::Base()
{
    //ctor
}
void Base::verticalSpace(int n){
    space_n = n;
    for(int i=0; i<=space_n; i++){
        cout<<endl;
    }
}


void Base::loadingAnime(){
    verticalSpace(3);
    cout<<setw(75)<<"L O A D I N G ";
    for(int i=0; i<=4; i++){
        cout<<"> ";
        Sleep(500);
    }
    system("CLS");
}

int date_of_submission;
int d_o_s;
void Base::borrowBook(){
    verticalSpace(2);
    cout<<setw(85)<<"======================================================"<<endl;
    cout<<setw(85)<<"=    B O O K     M A N A G E M E N T   S Y S T E M   ="<<endl;
    cout<<setw(85)<<"======================================================"<<endl;
    verticalSpace(1);
    cout<<setw(85)<<"<------------ENTER THE FOLLOWING DETAILS------------->"<<endl;
    cout<<setw(43)<<"Student ID: ";
    cin>>studID;
    cin.ignore();
    cout<<setw(45)<<"Student Name: ";
    getline(cin,studName);
    cout<<setw(40)<<"Book ID: ";
    cin>>bookID;
    cin.ignore();
    cout<<setw(45)<<"Name of Book: ";
    getline(cin, bookName);
    cout<<setw(50)<<"Name of Librarian: ";
    getline(cin, libName);
    cout<<setw(45)<<"Days Allowed: ";
    cin>>daysAllowed;
    date_of_submission = daysAllowed + local_time ->tm_mday;
    int d_o_s = date_of_submission;


    //file stream for students id

    studIDFile.open("studIDFile.txt", ios::app);
    studIDFile << studID << endl;
    studIDFile.close();
    //file stream for students name

    studNameFile.open("studNameFile.txt", ios::app);
    studNameFile << studName << endl;
    studNameFile.close();
    //file stream for books id

    bookIDFile.open("bookIDFile.txt", ios::app);
    bookIDFile << bookID << endl;
    bookIDFile.close();
    //file stream for books name

    bookNameFile.open("bookNameFile.txt", ios::app);
    bookNameFile << bookName << endl;
    bookNameFile.close();
    //file stream for librarian name

    libFile.open("libFile.txt", ios::app);
    libFile << libName << endl;
    libFile.close();

    //file stream for students id

    dateFile.open("dateFile.txt", ios::app);
    dateFile << d_o_s << endl;
    dateFile.close();
    //show loading animation
    loadingAnime();
    verticalSpace(5);
    cout<<setw(85)<<"O P E R A T I O N      S U C C E S S F U L"<<endl;
    verticalSpace(1);
    cout<<setw(70)<<"Book to be submitted on: "<<d_o_s<<"-"<<local_time->tm_mon<<"-"<<1900+local_time->tm_year<<endl;
    Sleep(5000);
    system("CLS");
    homePage();
}

void Base::borrowedBooks(){
    char go_back;
    string myLineA;
    string myLineB;
    string myLineC;
    string myLineD;
    string myLineE;
    string myLineF;
    studIDFile.open("studIDFile.txt");
    studNameFile.open("studNameFile.txt");
    bookIDFile.open("bookIDFile.txt");
    bookNameFile.open("bookNameFile.txt");
    libFile.open("libFile.txt");
    dateFile.open("dateFile.txt");

    if(studIDFile.is_open() && studNameFile.is_open() && bookIDFile.is_open() && bookNameFile.is_open() && libFile.is_open() && dateFile.is_open())
    {
        int index = 1;
        // Keep reading the file
        while(studIDFile && studNameFile && bookIDFile && bookNameFile && libFile && dateFile)
        {
            getline(studIDFile, myLineA);
            getline(studNameFile, myLineB);
            getline(bookIDFile, myLineC);
            getline(bookNameFile, myLineD);
            getline(libFile, myLineE);
            getline(dateFile, myLineF);
            cout<<index<<". Student ID: "<<myLineA << endl;
            index ++;
            cout<<index<<". Student Name: "<<myLineB << endl;
            index ++;
            cout<<index<<". Book ID: "<<myLineC << endl;
            index ++;
            cout<<index<<". Book Name: "<<myLineD << endl;
            index ++;
            cout<<index<<". Librarian: "<<myLineE << endl;
            index = 1;
            cout<<index<<". Date to be returned: "<<myLineF<<"-"<<local_time->tm_mon<<"-"<<1900+local_time->tm_year<<endl;
            cout<<endl;
        }
    // File Close
    studIDFile.close();
    studNameFile.close();
    bookIDFile.close();
    bookNameFile.close();
    libFile.close();
    dateFile.close();
    }
    else
    {
        cout << "Unable to open the file!";
    }
                verticalSpace(1);
                cout<<"Press (b) to go back: ";
                cin>>go_back;
                if(go_back == 'b'){
                    system("CLS");
                    homePage();
                }
}

void Base::returnBook(){
    int current_date = local_time ->tm_mday;
    verticalSpace(2);
    cout<<setw(85)<<"======================================================"<<endl;
    cout<<setw(85)<<"=    B O O K     M A N A G E M E N T   S Y S T E M   ="<<endl;
    cout<<setw(85)<<"======================================================"<<endl;
    verticalSpace(1);
    cout<<setw(85)<<"<-------------ENTER THE FOLLOWING DETAIL------------->"<<endl;
    cout<<setw(43)<<"Student ID: ";
    cin>>studID;
    loadingAnime();
    system("CLS");
    studIDFile.open("studIDFile.txt");
    studNameFile.open("studNameFile.txt");
    bookIDFile.open("bookIDFile.txt");
    bookNameFile.open("bookNameFile.txt");
    libFile.open("libFile.txt");
    dateFile.open("dateFile.txt");
    if(studIDFile.is_open() && studNameFile.is_open() && bookIDFile.is_open() && bookNameFile.is_open() && libFile.is_open() && dateFile.is_open())
    {
        int index = 0;
        int my_index;
        char go_back;
        string myLine1;
        string myLine2;
        string myLine3;
        string myLine4;
        string myLine5;
        string myLine6;
        // Keep reading the file
        while(studIDFile)
        {
            index++;
            getline(studIDFile, myLine1);
            if(studID == myLine1){
                my_index = index;
            }
        }
        index = 0;
        while(studIDFile || studNameFile || bookIDFile || bookNameFile || libFile)
        {
            index++;
            getline(studIDFile, myLine1);
            getline(studNameFile, myLine2);
            getline(bookIDFile, myLine3);
            getline(bookNameFile, myLine4);
            getline(libFile, myLine5);
            getline(dateFile, myLine6);
            if(my_index == index){
                verticalSpace(1);
                cout<<"Student ID: "<<myLine1<<endl;
                cout<<"Student Name: "<<myLine2<<endl;
                cout<<"Book ID: "<<myLine3<<endl;
                cout<<"Book Name: "<<myLine4<<endl;
                cout<<"Name of Librarian: "<<myLine5<<endl;
                int subDate = stoi(myLine6);
                if(current_date == subDate || current_date <= subDate){
                    cout<<"Book returned on time"<<endl;
                }else{
                    cout<<"Book not returned on time"<<endl;
                }
                verticalSpace(1);
                cout<<"Press (b) to go back: ";
                cin>>go_back;
                if(go_back == 'b'){
                    system("CLS");
                    homePage();
                }
            }
        }
    // File Close
    studIDFile.close();
    studNameFile.close();
    bookIDFile.close();
    bookNameFile.close();
    libFile.close();
    dateFile.close();
    }
}


void Base::homePage(){
    verticalSpace(1);
    cout<<setw(85)<<"======================================================"<<endl;
    cout<<setw(85)<<"=    B O O K     M A N A G E M E N T   S Y S T E M   ="<<endl;
    cout<<setw(85)<<"======================================================"<<endl;
    cout<<setw(85)<<"=                     W E L C O M E                  ="<<endl;
    cout<<setw(85)<<"======================================================"<<endl;
    verticalSpace(1);
    cout<<setw(85)<<"======================================================"<<endl;
    cout<<setw(85)<<"=                   O  P  T  I  O  N  S              ="<<endl;
    cout<<setw(85)<<"======================================================"<<endl;
    verticalSpace(1);
    cout<<setw(85)<<"|*| B O R R O W   B O O K      [1]                    "<<endl;
    cout<<setw(85)<<"|*| R E T U R N   B O O K      [2]                    "<<endl;
    cout<<setw(85)<<"|*| B O R R O W E D   B O O K S[3]                    "<<endl;
    cout<<setw(85)<<"|*| S I G N O U T  OR E X I T  [4]                    "<<endl;
    verticalSpace(1);
    cout<<setw(58)<<"|*| E N T E R  O P T I O N: ";
    cin>>option;
    loadingAnime();
    switch(option){
    case 1:
        borrowBook();
        break;
    case 2:
        returnBook();
        break;
    case 3:
        borrowedBooks();
        break;
    case 4:
        break;
    default:
        homePage();
    }
}


void Base::GetandVerifyLib(){
    string libpswd;
    verticalSpace(5);
    cout<<setw(85)<<"=============================================="<<endl;
    cout<<setw(85)<<"=    L O G I N    A S    L I B R A R I A N   ="<<endl;
    cout<<setw(85)<<"=============================================="<<endl;
    verticalSpace(3);
    cout<<setw(85)<<"=============================================="<<endl;
    cout<<setw(50)<<"Username: ";
    cin.ignore();
    getline(cin, libName);
    cout<<endl;
    cout<<setw(50)<<"Password: ";
    cin>>libpswd;
    cout<<endl;
    loadingAnime();

    string pswd = "@Book";
    if(libpswd == pswd){
        while(libpswd == pswd){
        system("CLS");
        verticalSpace(5);
        cout<<setw(85)<<"=============================================="<<endl;
        cout<<setw(85)<<"=    Y O U    A R E    L O G G E D   I N     ="<<endl;
        cout<<setw(85)<<"=============================================="<<endl;
        verticalSpace(5);
        Sleep(1500);
        system("CLS");
        break;
        }
        homePage();
    }else{
        while(libpswd != pswd){
        verticalSpace(5);
        cout<<setw(85)<<"=============================================="<<endl;
        cout<<setw(85)<<"=      W R O N G         P A S S W O R D     ="<<endl;
        cout<<setw(85)<<"=============================================="<<endl;
        verticalSpace(5);
        Sleep(1500);
        system("CLS");
        GetandVerifyLib();
        }
    }
}





