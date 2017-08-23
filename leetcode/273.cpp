string below_20[20] =  {"", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string below_100[19] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
class Solution {
public:
    string numberToWords(int num) {
  		if (!num)	return "Zero";
		else return work(num).substr(1);
    }
	string work(int x) {
		if (x >= (int)1e9)	return work(x / 1e9) + " Billion" + work(x - x / (int)1e9 * (int)1e9);
		if (x >= (int)1e6)	return work(x / 1e6) + " Million" + work(x - x / (int)1e6 * (int)1e6);
		if (x >= 1000)	return work(x / 1000) + " Thousand" + work(x - x / 1000 * 1000);
		if (x >= 100)	return work(x / 100) + " Hundred" + work(x - x / 100 * 100);
		if (x >= 20)	return " " + below_100[x / 10] + work(x - x / 10 * 10);
		if (x >= 1)	return " " + below_20[x];
		return "";
	}
};