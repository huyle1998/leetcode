#define arr_type	double

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	// Algorithm 
	// -------------------------------------------------
 
	//arr_type fdata[] = {19.2, 87.4, 30.6, 55.0, 75.6};
	//sort(fdata, fdata + _countof(fdata), greater<arr_type>());
	//for (int i = 0; i < _countof(fdata); i++)
	//{
	//	cout << fdata[i] << endl;
	//}

	// ------------------------------------------------



	// Vectors
	// -------------------------------------------------

	vector<int> V;
	V.push_back(10);
	V.push_back(2);
	V.push_back(4);
	V.push_back(0);
	V.push_back(9);

	V[2] = 5;
	V[4] = 6;

	for (int i = 0; i < V.size(); i++)
	{
		cout << "V[" << i << "] = " << V[i] << endl;
	}
			
	// -------------------------------------------------

	return 0;
}