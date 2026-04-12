#include <iostream>
#include <vector>
using namespace std;

struct Locate{
	int row;
	int col;
	int face = 0;
};

Locate human, cow, beginHuman, beginCow;
vector<vector<char>> map(10, vector<char>(10));

void insert(){
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			cin >> map[i][j];
			if(map[i][j] == 'F') human.row = i, human.col = j;
			if(map[i][j] == 'C') cow.row = i, cow.col = j;
		}
	}
	
	beginHuman.row = human.row, beginHuman.col = human.col;
	beginCow.row = cow.row, beginCow.col = cow.col;
}

bool Meet(){
	if(human.row == cow.row && human.col == cow.col){
		return true;
	}
	return false;
}

bool GetBack(){
	if(human.row == beginHuman.row && human.col == beginHuman.col && human.face == beginHuman.face
		&& cow.row == beginCow.row && cow.col == beginCow.col && cow.face == beginCow.face){
		return true;
	}
	return false;
}

void HumanUpMove(){
	if(human.row == 0){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	if(map[human.row - 1][human.col] == '*'){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	human.row--;
}

void CowUpMove(){
	if(cow.row == 0){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	if(map[cow.row - 1][cow.col] == '*'){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	cow.row--;
}

void HumanRightMove(){
	if(human.col == 9){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	if(map[human.row][human.col + 1] == '*'){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	human.col++;
}

void CowRightMove(){
	if(cow.col == 9){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	if(map[cow.row][cow.col + 1] == '*'){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	cow.col++;
}


void HumanDownMove(){
	if(human.row == 9){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	if(map[human.row + 1][human.col] == '*'){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	human.row++;
}

void CowDownMove(){
	if(cow.row == 9){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	if(map[cow.row + 1][cow.col] == '*'){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	cow.row++;
}

void HumanLeftMove(){
	if(human.col == 0){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	if(map[human.row][human.col - 1] == '*'){
		human.face = (human.face + 1) % 4;
		return;
	}
	
	human.col--;
}

void CowLeftMove(){
	if(cow.col == 0){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	if(map[cow.row][cow.col - 1] == '*'){
		cow.face = (cow.face + 1) % 4;
		return;
	}
	
	cow.col--;
}

int main() {
	insert();
	
	int count = 0;
	while(count <= 160000){
		if(cow.face == 0){
			CowUpMove();
		}else if(cow.face == 1){
			CowRightMove();
		}else if(cow.face == 2){
			CowDownMove();
		}else{
			CowLeftMove();
		}
		
		if(human.face == 0){
			HumanUpMove();
		}else if(human.face == 1){
			HumanRightMove();
		}else if(human.face == 2){
			HumanDownMove();
		}else {
			HumanLeftMove();
		}
		
		count++;
		if(Meet()){
			cout << count << endl;
			return 0;
		}
		
		if(GetBack()){
			cout << 0 << endl;
			return 0;
		}
	}
	
	cout << 0 << endl;
	return 0;
}
