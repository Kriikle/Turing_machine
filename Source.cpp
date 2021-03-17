#include <string>
#include <iostream>

#include <fstream>

using namespace std;


int run_state(char& sumbol, string rule[100], int ar_size_f1, int state, int& count, string& rule_record) {
	string LR = "LR";
	for (int i = 0; i < ar_size_f1; i++) {
		if (sumbol == rule[i][2] and state == rule[i][1] - 48) {
			sumbol = rule[i][7];
			if (rule[i][8] == LR[0]) {
				count--;
			}
			else if (rule[i][8] == LR[1]) {
				count++;
			}
			rule_record = rule[i];
			return rule[i][6] - 48;
		}
	}

	return -1;
}



bool chek_alfabet(string line, string alfabet) {
	bool flg;
	for (int i = 0; i < line.size(); i++) {
		flg = 1;
		for (int j = 0; j < alfabet.size(); j++) {
			if (line[i] == alfabet[j]) {
				flg = 0;
				break;
			}
		}
		if (flg == 1) {
			return 1;
		}
	}
	return 0;
}


bool check_rule(string rule) {
	string LR = "LR";
	if (rule[8] == LR[0] or rule[8] == LR[1]) {
		return 0;
	}
	return 1;
}

int main() {
	string line = "_11*111________________________________________________";
	string alfabet = "1*_";
	int state = 1;
	int r_num;
	string rule_record = "3223424235";
	char line_alt = 24;
	string rule[100];




	//Открытие фалов
	ifstream in("in.txt");
	string s;
	int count = 0;
	while (in.peek() != EOF) {
		getline(in, s);
		count++;
	}
	in.close();

	ifstream fin("in.txt"); // открыли файл для чтения
	getline(fin, line);
	getline(fin, alfabet);
	for (int i = 0; i < count; i++) {
		getline(fin, rule[i]);

	}
	fin.close();//Конец обработки фалов на вход

	ofstream fout("out.txt");//Открытие выходного файла

	if (chek_alfabet(line, alfabet) == 1) {
		cout << "Not alfabet sumbol" << endl;
		return 0;
	}
	for (int i = 0; i < line.size();) {

		state = run_state(line[i], rule, count, state, i, rule_record);
		fout << rule_record << endl;
		fout << line << " " << state << " " << endl;
		for (int j = 0; j < i; j++) {
			fout << " ";
		}
		fout << line_alt << endl;
		if (state == -1) {
			cout << "No rules for this sumbol" << endl;
			break;
		}
		else if (state == 0) {
			cout << "Comleted" << endl;
			break;
		}

	}
	fout.close(); // закрываем файл
	return 0;
}











