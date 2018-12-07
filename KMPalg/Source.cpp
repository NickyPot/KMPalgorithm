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

int stringSearchKmp(string pat, string txt) {

	createLookUpKmp(pat);
	int txtPosition = 0;
	int patPosition = 0;

	while (txtPosition <= txt.length() - 1) {
	
		//if the two chars match
		if (pat[patPosition] == txt[txtPosition]) {
		
			//if you've reached the end of the pattern string the return the position of the txt string
			if (patPosition == pat.length() - 1) {
			
				return txtPosition;
			
			}

			//if not then continue to the next character
			txtPosition++;
			patPosition++;

		}


		else {
		
			if (patPosition == 0) {
			
				txtPosition++;
			}

			else {
			
				patPosition = skipValueKmp[patPosition - 1];
			
			}
		
		
		}
	
	}



}

int main() {
	string txt;
	string pat;
	cout << "please input text string!";
	cin >> txt;
	cout << "please input pattern string";
	cin >> pat;
	
	
	

	

	cout << stringSearchKmp(pat, txt);
	cin >> pat;


}