
#include "SUPPORT.cpp"
#include "IRSA.cpp"

class RSA : public IRSA
{
    private:
		
		double e;
		double n;
		double k;
		double d;
	
	public:
		
		RSA()
		{
			seive<LL>(1000000);
			
			double p, q, phi;
			LL primeSet, pIndex, qIndex;
			
			p = q = 1;
			
			this->e = 2;
			this->k = 1;
			
			primeSet = primes.size();
			
			pIndex = rand()%primeSet+1;
			
			p = primes[pIndex];	// f
			
			while( p == q or q == 1 )
			{	
				qIndex = rand()%primeSet+1;
				
				q = primes[qIndex];
			}
			
			this->n = p * q;
			
			phi = this->Phi(p, q);
			
			while( __gcd((LL)phi, (LL)this->e) != 1 )		this->e++;
			
			this->d = (k*phi + 1)/this->e;
			
			while( floor(this->d) != this->d )	this->d = (++k*phi + 1)/this->e;
			
			cout << "primeSetSize = " << primes.size() << '\n';
			cout << "Primeset(" << pIndex << ", " << qIndex << ")" << '\n';
			cout << "p = " << p << " q = " << q << '\n';
			cout << "n = " << n << '\n';
			cout << "e = " << e << '\n';
			cout << "phi = " << phi << '\n';
			cout << "k = " << k << '\n';
			cout << "d = " << d << '\n';
			
			cout << "\n \n";
		}
		
		vector<double> Encrypt(string message)
		{
			vector<double> encryptedMessage;
			double offset;
			
			for(char x: message)
			{
				if( isupper(x) )	offset = 63;
				
				else	offset = 95;
				
				encryptedMessage.push_back(fmod(pow((x-offset), this->e), this->n));
			}
			
			for(double x: encryptedMessage)
   			    cout << x << ' ';
   			    
			cout << "\n \n";
			
			return encryptedMessage;
		}
		
		string Decrypt(vector<double> encryptedMessage)
		{
			string message;
			
			for(double x: encryptedMessage)
   				message += powerMod<LL>(x, this->d, this->n)+95;
			
			return message;
		}
		
		double Phi(double p, double q)
		{
			return ((p-1)*(q-1));
		}

};

