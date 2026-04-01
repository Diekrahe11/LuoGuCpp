#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	int boyCNT = 0;
	int girlCNT = 0;
	for(int i = 0; i < str.length(); ++i){
		if(str[i] != '.'){
			switch(str[i]){
				case 'b':{
					boyCNT++;
					break;
				}
				case 'o':{
					if(i - 1 >= 0){
						if(str[i - 1] == 'b'){
							continue;
						}
						boyCNT++;
					}
					break;
				}
				case 'y':{
					if(i - 1 >= 0){
						if(str[i - 1] == 'o'){
							continue;
						}
						boyCNT++;
					}
					break;
				}
				case 'g':{
					girlCNT++;
					break;
				}
				case 'i':{
					if(i - 1 >= 0){
						if(str[i - 1] == 'g'){
							continue;
						}
						girlCNT++;
					}
					break;
				}
				case 'r':{
					if(i - 1 >= 0){
						if(str[i - 1] == 'i'){
							continue;
						}
						girlCNT++;
					}
					break;
				}
				case 'l':{
					if(i - 1 >= 0){
						if(str[i - 1] == 'r'){
							continue;
						}
						girlCNT++;
					}
					break;
				}
			}
		}
		else {
			continue;
		}
	}
	
	cout << boyCNT << endl;
	cout << girlCNT << endl;
	
	return 0;
}
