#include <iostream>
#include <vector>
using namespace std;

int judge(int a, int b){
	//0£ºa win
	//1£ºb win
	if(a == 0){
		switch(b){
			case 0:
				return 3;
			case 1:
				return 1;
			case 2:
				return 0;
			case 3:
				return 0;
			case 4:
				return 1;
		}
	}else if(a == 1){
		switch(b){
			case 0:
				return 0;
			case 1:
				return 3;
			case 2:
				return 1;
			case 3:
				return 0;
			case 4:
				return 1;
		}
	}else if(a == 2){
		switch(b){
			case 0:
				return 1;
			case 1:
				return 0;
			case 2:
				return 3;
			case 3:
				return 1;
			case 4:
				return 0;
		}
	}else if(a == 3){
		switch(b){
			case 0:
				return 1;
			case 1:
				return 1;
			case 2:
				return 0;
			case 3:
				return 3;
			case 4:
				return 0;
		}
	}else if(a == 4){
		switch(b){
			case 0:
				return 0;
			case 1:
				return 0;
			case 2:
				return 1;
			case 3:
				return 1;
			case 4:
				return 3;
		}
	}
}

int main() {
	int n, na, nb;
	cin >> n >> na >> nb;
	vector<int> listA(na), listB(nb);
	
	for(int i = 0; i < na; ++i){
		cin >> listA[i];
	}
	for(int i = 0; i < nb; ++i){
		cin >> listB[i];
	}
	
	int scoreA = 0, scoreB = 0;
	int indexA = 0, indexB = 0;
	int sizeA = listA.size(), sizeB = listB.size();
	for(int i = 0; i < n; ++i){
		int res = judge(listA[indexA], listB[indexB]);
		
		if(res == 0){
			scoreA++;
		}else if(res == 1){
			scoreB++;
		}
		
		indexA++;
		indexB++;
		if(indexA > sizeA) indexA = 0;
		if(indexB > sizeB) indexB = 0;
	}
	
	cout << scoreA << " " << scoreB << endl;
	return 0;
}
