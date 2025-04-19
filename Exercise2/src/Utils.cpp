#include "iostream"
#include "iomanip"
#include "fstream"
#include "sstream"

#include "Utils.hpp"

using namespace std;

bool ImportArrays(const string& inputFilePath,
				  double& S,
				  size_t& n,
				  double*& w,
				  double*& r)
{
	ifstream file;
	file.open(inputFilePath);

	if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	
	string line;
	char del = ';';
	getline(file, line, del);
	file >> S;
	getline(file, line, del);
	file >> n;
	getline(file, line);
	w = new double[n];
	r = new double[n];
	unsigned int i = 0;
	while(getline(file, line) && i < n)
	{
		istringstream iss(line);
		string w_str,r_str;
		if (getline(iss, w_str, del) && getline(iss, r_str)) {
            try {
                w[i] = stod(w_str);
                r[i] = stod(r_str);
                i++;
		}catch (const exception& e) {
                cerr << "Errore nella conversione in double alla riga " << i << ": " << e.what() << endl;
            }
        } else {
            cerr << "Formato invalido alla riga " << i << ": " << line << endl;
        }
	}
	
	
	return true;
}

bool ExportResult(const string& outputFilePath,
				  const size_t& n,
				  const double& S,
				  const double* const& w,
                  const double* const& r,
                  const double& rate,
                  const double& V)
{
	ostringstream out_S;
	ostringstream out_V;
	string str_w = ArrayToString(n, w);
	string str_r = ArrayToString(n, r);
	out_S << fixed << setprecision (2);
	out_S << "S = " << S;
	out_V << fixed << setprecision (2);
	out_V << "V: " << V;

	/* print results on screen */
	cout << out_S.str() << endl;
	cout << "n = " << n << endl;
	cout << "w = " << str_w << endl;
	cout << "r = " << str_r << endl;
	cout << "Rate of return of the portfolio: " << rate << endl;
	cout << out_V.str() << endl;
	
	/*print results on file*/
	ofstream file;
	file.open(outputFilePath);
	if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
    file << out_S.str() << ", n = " << n << endl;
    file << "w = " << str_w << endl;
    file << "r = " << str_r << endl;
    file << "Rate of return of the portfolio: " << rate << endl;
	file << out_V.str() << endl;
	
	return true;
}


double DotProduct(const size_t& n,
                        const double* const& w,
                        const double* const& r)
{
	double dotproduct = 0;
	for (unsigned int i = 0; i < n; i++)
	{
		dotproduct += w[i]*r[i];
	}
	return dotproduct;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
	string str;
    ostringstream toString;
    toString << "[ " << setprecision(2);
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}