#include <iostream>
#include <iomanip>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    cout  <<"C++ style: "<< setprecision(25) << 0.1 + 0.2 <<'\n' ;
    cout  <<"C style:   ";
    printf("%.25f\n", .1+.2);
    return 0;
}
