#include "hash.hpp"
using namespace std;
string string_to_hex(const std::string &input)
{ // CONVERT SYMBOL TO HEX
	static const char hex_digits[] = "0123456789ABCDEF";

	std::string output;
	output.reserve(input.length() * 2);
	for (unsigned char c : input)
	{
		output.push_back(hex_digits[c >> 4]);
		output.push_back(hex_digits[c & 15]);
	}
	return output;
}
string hash_function(string hashInput)
{
	string hash = "DB1C5DAB6DAFFE28BC1C5D6BC8F912995A2C2AA62E60FEEA036931F9F85EC770"; // SEED
	int tmp = 0;
	for (int i = 1; i < 64; i++)					// hash function
	{ 
		for (int j = 0; j < hashInput.size(); j++)
		{
			tmp = hash[i];
			tmp = tmp ^ int(hashInput[j]);
			hash[i] = char(tmp);
			hash[i - 1] += i ^ j;
		}
		hash[i] = int(hash[i]) + int(hash[64 - i]);
	}
	hash = string_to_hex(hash);
	hash.resize(64);
    return hash;
}