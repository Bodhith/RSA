


class IRSA
{
	public:
		
		virtual vector<double> Encrypt(string) = 0;

		virtual string Decrypt(vector<double>) = 0;
		
		virtual double Phi(double, double) = 0;
		
};



