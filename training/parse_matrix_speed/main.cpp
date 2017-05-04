#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    const int SIZE = 1000;

    int arr[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            arr[i][j] = rand();
        }
    }

    unsigned long v = 0;

    unsigned int start_time =  clock(); // начальное время

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            v+= arr[i][j];
        }
    }
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

    std::cout<< v << endl;
    std::cout<< "Time:" << search_time << endl;

    v = 0;

    start_time =  clock(); // начальное время
    for(size_t i = 0; i < SIZE; i++)
    {
        for(size_t j = 0; j < SIZE; j++)
        {
            v+= arr[j][i];
        }
    }
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время

    std::cout<< v << endl;
    std::cout<< "Time:" << search_time << endl;

    return 0;
}
