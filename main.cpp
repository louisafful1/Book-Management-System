#include <iostream>
#include <stdlib.h> //used in this code to clear screen
#include <fstream> //used for working with files
#include <Display.h>
using namespace std;



int main()
{

    Display disp;

    Base bse;

    disp.showTitle();

    bse.GetandVerifyLib();

    return 0;
}
