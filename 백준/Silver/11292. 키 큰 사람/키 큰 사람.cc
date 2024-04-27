#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<string> answer;
vector<pair<string, double>> student;

void print() {

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}

bool cmp(pair<string, double> x, pair<string, double> y) {
	
	if (x.second > y.second) {
		return true;
	}
	return false;
}

int main(void) {

	while (1) {
		cin >> n;
		
		if (n == 0) {
			print();
			return 0;
		}
		student.clear();
		student.resize(n);
		for (int i = 0; i < n; i++) {
			string name;
			double grade;
			cin >> name >> grade;
			student[i].first = name;
			student[i].second = grade;
		}
		for (int i = 0; i < n; i++) {
			sort(student.begin(), student.end(), cmp);
		}
		
		double score = student[0].second;
		//cout << score;
		string names = "";
		for (int i = 0; i < n; i++) {
			if (student[i].second == score) {
				names = names + student[i].first + " ";
			}
		}
		answer.push_back(names);
	}
	return 0;

}