#pragma once

#include <iostream>

using namespace std;

bool ImportArrays(const string& inputFileName,
                  double& S,
                  size_t& n,
 				  double*& w,
				  double*& r);


bool ExportResult(const string& outputFilePath,
				  const size_t& n,
				  const double& S,
				  const double* const& w,
                  const double* const& r,
                  const double& Rate,
                  const double& V);


double DotProduct(const size_t& n,
				  const double* const&,
				  const double* const& r);


string ArrayToString(const size_t& n,
                     const double* const& v);