#include <bits/stdc++.h>

using namespace std;

#include "RSA.cpp"

int main(void)
{
	cout << fixed;
	cout << setprecision(0);

	srand(time(NULL));
 	
 	RSA model;
 	
 	vector<double> encryptedMessage = model.Encrypt("ASdas");
	
	cout << model.Decrypt(encryptedMessage) << '\n';
	
    return 0;
}

