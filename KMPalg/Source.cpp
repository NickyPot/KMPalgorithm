#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> skipValueKmp;

void createLookUpKmp(string pat) {


	int j = 0;//character being tested to
	skipValueKmp.push_back(0);//put in 0 for the 1st character
	int i = 1;//character being tested

	//testing loop
	while ( i < pat.length()) {

		
		
		//if the chars match
		if (pat[i] == pat[j]) {
			skipValueKmp.push_back(j + 1);
			j++;
			i++;
			
		}

		else {
			
			if (j > 0) {
				j = skipValueKmp[j - 1];
			}

			else if (j == 0) {
				skipValueKmp.push_back(0);
				i++;
				

			}
			
			
			
		
		}
	}

}

void stringSearchKmp() {




}

int main() {

	string pat;
	cin >> pat;

	createLookUpKmp(pat);

	for (auto i = skipValueKmp.begin(); i != skipValueKmp.end(); ++i)
		std::cout << *i << ' ';
	cin >> pat;


}