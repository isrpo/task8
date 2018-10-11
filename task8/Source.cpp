#include <vector>
#include <fstream>
#include <iostream>
#include <set>
#include <cmath>

typedef int NUM;

void factorization(std::vector<NUM> & res, NUM num, NUM generalNum)
{
	if (num % 2 == 1) {
		NUM s = (NUM)std::sqrt(num);
		bool flag = false;
		while (s < num) {
			NUM y = (NUM)std::sqrt(s*s - num);
			if (num == (s*s - y*y) && (s - y != 1)) {
				factorization(res, s - y, generalNum);
				factorization(res, s + y, generalNum);
				flag = true;
				break;
			}
			s++;
		}
		if (!flag && num != 1) {
			res.emplace_back(num);
		}
	}
	else {
		res.emplace_back(2);
		factorization(res, num / 2, generalNum);
	}
	return;
}

int main() {
	std::vector<NUM> res1;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	int n;
	in >> n;

	for (size_t i = 0; i < n; i++) {
		std::set<NUM> res;
		NUM number;
		in >> number;
		std::vector<NUM> oneNum;
		factorization(oneNum, number, number);
		size_t size = oneNum.size();
		for (size_t j = 0; j < size; j++) {
			for (size_t k = j + 1; k < size; k++) {
				res.insert(oneNum[j] * oneNum[k]);
			}
		}
		res1.emplace_back(res.size());
	}

	for (auto i : res1) {
		out << i << " ";
	}
}