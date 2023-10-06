
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

class WordFreqPair {
public:
	string word;
	int count;
	WordFreqPair(string Wordinput) {
		word = Wordinput;
		count = 1;
	}
};
bool valid = true;
int counter = 0;
string HoldsCurrentWord;
string HoldsCurrentFreq;
string text;
int numberOfWords = 0;
int numberOfSentences = 0 ;
string filename = "input.txt";
vector<WordFreqPair> wordList;
int pointer = 0;
string wordnum;
string spaces;
int spacenum;


int main()
{
	ifstream fileReader(filename);
	while (getline (fileReader, text)) {
		for (int i = 0; i < text.size(); i++) {
			if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
				numberOfSentences++;
				numberOfWords++;
				for (pointer; pointer < i; pointer++) {
					HoldsCurrentWord = HoldsCurrentWord + text[pointer];
				}
				pointer = i + 1;
				for (auto savedWord : wordList) {
					if (savedWord.word == HoldsCurrentWord) {
						savedWord.count++;
						wordList[counter].count++;
						valid = false;
					}
					counter++;
				}
				if (valid == true) {
					wordnum = to_string(numberOfWords);
					WordFreqPair wordnum(HoldsCurrentWord);
					wordList.push_back(wordnum);
				}
				valid = true;
				HoldsCurrentWord.clear();
				counter = 0;
			}
			else if (text[i] == ' ' || text[i] == ',') {
				numberOfWords++;
				for (pointer; pointer < i; pointer++) {
					HoldsCurrentWord = HoldsCurrentWord + text[pointer];
				}
				pointer = i + 1;

				for (auto savedWord : wordList) {
					if (savedWord.word == HoldsCurrentWord) {
						savedWord.count++;
						wordList[counter].count++;
						valid = false;
					}
					counter++;
				}
				if (valid == true) {
					wordnum = to_string(numberOfWords);
					WordFreqPair wordnum(HoldsCurrentWord);
					wordList.push_back(wordnum);
				}
				valid = true;
				HoldsCurrentWord.clear();
				counter = 0;
			}	
		}
		pointer = 0;
	}
	cout << "number of sentences is " << numberOfSentences << endl;
	cout << "number of words is " << numberOfWords << endl;
	for (auto savedWord : wordList) {
		spacenum = 8 - savedWord.word.length();
		for (int i = 0; i <= spacenum; i++) {
			spaces = spaces + ' ';
		}
		cout << savedWord.word << spaces << savedWord.count << endl;
		spaces.clear();
	}
	fileReader.close();
}

