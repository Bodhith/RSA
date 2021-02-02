
#define LL long long int
#define INF (LL) 1e+9

/*
==========================================================================================================================================================================================
*/

vector<bool> primesOrNot(INF+1, true);
vector<LL> primes;
long long int maxCalculatedPrimes = 0;

template <typename T>
void seive(T n)
{
    if( n < maxCalculatedPrimes )
    {
        return ;
    }

    T i, j, sn;

    for(i=2, sn=sqrt(n)+1, primesOrNot[0]=primesOrNot[1]=false; i<sn; i++)
    {
        if( primesOrNot[i] == true )
        {
            primes.push_back(i);

            for(j=maxCalculatedPrimes+2*i; j<=n; j+=i)
            {
                primesOrNot[j] = false;
            }
        }
    }
    
    for(LL x: primes) cout << x << '\n';
    
    cout << '\n';

    maxCalculatedPrimes = n;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<int> multiply(vector<int> first, vector<int> second, bool reversed)
{
	LL nFirst, nSecond, i, j;
	
	nFirst = first.size();
	nSecond = second.size();
	
	if( !reversed )
	{
		reverse(first.begin(), first.end());
		reverse(second.begin(), second.end());
	}
	
	vector<int> product(nFirst+nSecond, 0);
	
	for(i=0; i<nFirst; i++)
	{
	    for(j=0; j<nSecond; j++)
	    {
	        product[i+j] += first[i]*second[j];
	        product[i+j+1] = product[i+j+1]+product[i+j]/10;
	        product[i+j] %= 10;
	    }
	}
	
	if( product[nFirst+nSecond-1] == 0 )	product.erase(product.begin()+nFirst+nSecond-1);
	
	reverse(product.begin(), product.end());
	
	return product;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
vector<int> power(vector<int> base, T power)
{
	vector<int> product;
	
	if( power == 0 ){	product.push_back(0);	return product;	}
	
	else if( power == 1 )	return base;
	
	power -= 2;
	
	product = multiply(base, base, false);
	
	while(power--)		product = multiply(product, base, false);
	
	return product;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


template <typename T>
LL powerMod(T base, T power, T modNumber)
{
	LL product;
	
	if( power == 0 )	return 1;
	
	else if( power == 1 )	return base % modNumber;
	
	product = base % modNumber;
	
	product = (product*product)%modNumber;
	
	power -= 2;
	
	while( power-- )	product = (product * base%modNumber)%modNumber;
		
	return product;
}












