#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
#define NUM_MOTORS  12U

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

double** reformatData(vector<double> data)
{
    int dataCol = NUM_MOTORS;
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
    return sendData;
}

int main()
{

   string fname = "playback.txt";
   auto data = ReadInDoubles(fname);
   double myPData[data.size() / NUM_MOTORS][NUM_MOTORS];
   double** myData = reformatData(data);
   memcpy(&myPData[0][0], &myData[0][0], sizeof(myPData));
   
    for(int i=0; i<(data.size()/NUM_MOTORS) ; i++)
    {
        cout << myPData[i][3] << endl;
    }


    return 0;
}
