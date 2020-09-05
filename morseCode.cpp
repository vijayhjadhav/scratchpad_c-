#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> decode_all_words(string code)
{
	map<string, char> morseCharmp;
	morseCharmp["---"] = 'O';
	morseCharmp[".--."] = 'P';
	morseCharmp["-"] = 'T';
	morseCharmp[".."] = 'I';
	morseCharmp["...-"] = 'V';
	morseCharmp["."] = 'E';
	morseCharmp[".-."] = 'R';
	size_t size_code = code.size();
	vector<string> translations;

	for (auto numChars = 1; numChars <= 4; numChars++)
	{
		string translation;
		auto index2 = 0;
		for (; index2 < size_code; index2 = index2 + numChars)
		{
			auto itr = find(morseCharmp.begin(), morseCharmp.end(), code[index2]);
			if (itr != morseCharmp.end())
				translation.push_back((*itr).second);
			else
				break;
		}

		if (index2 == size_code)
			translations.push_back(translation);
	}
	return translations;
}

int main()
{
	return 0;
}