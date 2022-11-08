 /*********************************************************************************************
 *   author: sanket lokhande
 *   email:  slokhande@nevada.unr.edu
 *   Description: This code reads a text file containing doubles and puts them into 2D vector
 **********************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

#define NUM_COLUMNS  12U
using namespace std;


//// Read file and return the data in a vector
void ReadInDoubles( const string& filename , vector <double> &result)
{

    double          d;
    ifstream        inf( filename.c_str() );
    while (inf >> d)
    {
        result.push_back( d );
    }
    inf.close();
}

////Make a return type of 2d array
double ** reformatData(vector<double> &data)
{
    int dataCol = NUM_COLUMNS;
    int dataRows = data.size() / dataCol;
    double **array2D = new double*[dataRows];
    for(int i=0; i<dataRows; i++)
    {
        array2D[i] = new double[dataCol];
    }
    memcpy(&**array2D, &data[0], sizeof(double)*data.size());
    return array2D;
}


int main()
{
    string fname = "../logs/playback.txt";

    std::vector<double> data;
    ReadInDoubles(fname, data);

    double ** myVector= reformatData(data);

    data.clear();

    double myMatrix[250][12];

    memcpy(&myMatrix[0][0], &**myVector, sizeof(double)*3000);


    return 0;
}

