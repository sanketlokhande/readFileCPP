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
vector <double> ReadInDoubles( const string& filename )
{
    vector <double> result;
    double          d;
    ifstream        inf( filename.c_str() );
    while (inf >> d)
    {
        result.push_back( d );
    }
    return result;
}

////Make a return type of 2d array
double** reformatData(vector<double> data)
{
    int dataCol = NUM_COLUMNS;
    int dataRows = data.size() / dataCol;
    double** sendData ; //[dataRows][dataCol];
    sendData = new double*[dataCol];
    int count = 0;
    for( int j =0; j<dataCol; j++)
    {
        sendData[j] = new double[dataRows];
        for (int i=0; i<dataRows ; i++)
        {
            sendData[j][i] = data[count];
            count++;
        }
    }
    cout << "Read the datafile" << endl;
    return sendData;
}

int main()
{
    string fname = "playback.txt";
    auto data = ReadInDoubles(fname);
    double myPData[data.size() / NUM_COLUMNS][NUM_COLUMNS];
//    double** myData = reformatData(data);
 //   memcpy(&myPData[0][0], &myData[0][0], sizeof(myPData));

//// Simple route
    int count = 0;
    for (int i=0 ; i < (data.size() / NUM_COLUMNS); i++)
    {
        for(int j=0 ; j< (NUM_COLUMNS) ; j++)
        {
            myPData[i][j] = data[count++];
        }
    }

    for(int i=0; i<(data.size()/NUM_COLUMNS) ; i++)
    {
        cout << myPData[i][3] << endl;
    }

    return 0;
}
