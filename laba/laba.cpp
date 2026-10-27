/************************************
* Автор: Горбунова Настя            *
* Задание: Строки, векторы и словари*
* Вариант: 5                        *
************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
  /****
  * A *
  ****/
  string userString;
  cout << "Enter the string: ";
  getline(cin, userString);

  if (userString.length() > 200) {
	cout << "INVALID\n";
	return 0;
  }

  int spaceCount = 0;
  for (const auto& symbol : userString) {
	if (symbol == ' ') {
	  spaceCount++;
	}
  }
  cout << "\nAnswer: " << spaceCount << "n\n";

  /****
  * B *
  ****/
  vector<int> userVector, uniqueVector;
  int elementCount, tempElement;

  cout << "Enter the number of elements : ";
  cin >> elementCount;

  if (elementCount < 0 || elementCount > 100) {
	cout << "INVALID\n";
	return 0;
  }

  for (int rowIndex = 0; rowIndex < elementCount; ++rowIndex) {
	cin >> tempElement;
	userVector.push_back(tempElement);
  }

  for (const auto& symbol : userVector) {
	bool isFound = false;
	for (const auto& uniqueSymbol : uniqueVector) {
	  if (symbol == uniqueSymbol) {
		isFound = true;
		break;
	  }
	}
	if (!isFound) {
	  uniqueVector.push_back(symbol);
	}
  }

  cout << "Answer: ";
  for (const auto& symbol : uniqueVector) {
	cout << symbol << " ";
  }
  cout << "\n\n";

  /****
  * C *
  ****/
  map<string, int> userMap;
  int dictionaryCount;
  string keyMap;
  int valueMap;

  cout << "Enter n: ";
  cin >> dictionaryCount;

  if (dictionaryCount < 0 || dictionaryCount > 100) {
	cout << "INVALID\n";
	return 0;
  }

  for (int rowIndex = 0; rowIndex < dictionaryCount; ++rowIndex) {
	cin >> keyMap >> valueMap;
	userMap[keyMap] = valueMap;
  }

  string bestKey = "";
  int bestValue = -1001;

  for (const auto& couplesElement : userMap) {
	if (couplesElement.second > bestValue) {
	  bestValue = couplesElement.second;
	  bestKey = couplesElement.first;
	}
  }

  cout << "Answer: " << bestKey << " " << bestValue << "\n";

  /****
  * D *
  ****/
  vector<map<string, string >> userRecords;
  int recordCount;
  string subjectInput, topicInput;

  cout << "Enter n: ";
  cin >> recordCount;
  cin.ignore();

  for (int rowIndex = 0; rowIndex < recordCount; ++rowIndex) {
	getline(cin, subjectInput);
	getline(cin, topicInput);

	userRecords.push_back({ {"subject", subjectInput}, {"topic", topicInput} });
  }

  vector<string> subjectOrder;
  for (const auto& record : userRecords) {
	bool isFound = false;
	for (const auto& item : subjectOrder) {
	  if (item == record.at("subject")) {
		isFound = true;
		break;
	  }
	}
	if (!isFound) {
	  subjectOrder.push_back(record.at("subject"));
	}
  }

  cout << "Answer:\n";
  for (const auto& subject : subjectOrder) {
	cout << subject << ": ";
	bool isFirst = true;
	for (const auto& record : userRecords) {
	  if (record.at("subject") == subject) {
		if (!isFirst) {
		  cout << ", ";
		}
		cout << record.at("topic");
				isFirst = false;
	  }
	}
	cout << "\n";
  }
}