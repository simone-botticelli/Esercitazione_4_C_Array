#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.txt";
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;
    
    if (!ImportArrays(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
    	cout << "Import successful: " << endl;
    
    
    double rate = DotProduct(n, w, r);
    
    double V = (1 + rate)*S;
    
    
    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, S, w, r, rate, V))
    {
        cerr << "Something goes wrong with export" << endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;        
    return 0;
}

