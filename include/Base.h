#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>//for using text files
#include <time.h>
using namespace std;

class Base
{
    public:
        Base();

        void GetandVerifyLib();
        void verticalSpace(int);
        void loadingAnime();
        void homePage();
        void borrowBook();
        void returnBook();
        void borrowedBooks();

    protected:
        int space_n;
        int option;
        string libName;
        string libpswd;
        string studName;
        string studID;
        string bookID;
        string bookName;
        int daysAllowed;
        fstream studIDFile;
        fstream studNameFile;
        fstream bookIDFile;
        fstream bookNameFile;
        fstream libFile;
        fstream dateFile;
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);

    private:
};

#endif // BASE_H
