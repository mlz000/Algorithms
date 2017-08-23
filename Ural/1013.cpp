#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) {return a > b ? a : b;}
const int MAXLEN = 1900;
class BigInt
{
public:
	int data[MAXLEN];
	BigInt(const int n = 0)
	{
		memset(data, 0, sizeof(data));
		data[0] = 1;
		data[1] = n;
	}
	BigInt operator = (const int n)
	{
		return *this = BigInt(n);
	}
	BigInt operator = (const BigInt &ob)
	{
		memcpy(data, ob.data, sizeof(data));
		return *this;
	}
	BigInt operator + (const BigInt &ot)
	{
		BigInt sum;
		int i;
		sum.data[0] = data[0]>ot.data[0] ? data[0] : ot.data[0];
		for (i = 1; i <= sum.data[0]; ++ i)
		{
			sum.data[i] += data[i] + ot.data[i];
			sum.data[i+1] += sum.data[i] / 10;
			sum.data[i] %= 10;
		}
		while (sum.data[i] != 0)
		{
			sum.data[i+1] += sum.data[i] / 10;
			sum.data[i] %= 10;
			i += 1;
		}
		sum.data[0] = i - 1;
		sum.data[0] = i-1;
		while(sum.data[sum.data[0]] == 0 && sum.data[0] > 1)
			sum.data[0] -= 1;
		return sum;
	}
	BigInt operator * (const int n)
	{
		BigInt product;
		int i;
		for (i = 1; i <= data[0]; ++ i)
		{
			product.data[i] += data[i] * n;
			product.data[i+1] += product.data[i] / 10;
			product.data[i] %= 10;
		}
		while (product.data[i] != 0)
		{
			product.data[i+1] += product.data[i] / 10;
			product.data[i] %= 10;
			i += 1;
		}
		product.data[0] = i-1;
		while(product.data[product.data[0]] == 0 && product.data[0] > 1)
			product.data[0] -= 1;
		return product;
	}
	friend ostream& operator << (ostream &os, BigInt &ob)
	{
		for (int i = ob.data[0]; i >= 1; -- i)
			os << ob.data[i];
		return os;
	}
};

BigInt f[2], tmp[2];
int main()
{
	int n, k;
	cin >> n >> k;
	f[0] = 0; f[1] = k-1;
	for (int i = 2; i <= n; ++ i)
	{
		tmp[0] = f[0]; tmp[1] = f[1];
		f[0] = tmp[1];
		f[1] = (tmp[0] + tmp[1]) * (k-1);
	}
	BigInt ans = (f[0]+f[1]);
	cout << ans << endl;
}

