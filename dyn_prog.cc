
#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

std::vector<int> compute_min(const std::vector<int>& coin_values, const int& target_val) {
	std::map<int, std::vector<int>> valueToVec;

	std::vector<int> min_values(target_val + 1);
	for (auto&& x : min_values) {
		x = INT_MAX;
		vector<int> temp;
		valueToVec[x] = temp;
	}
	min_values[0] = 0;

	for (int i = 1; i < (target_val + 1); ++i) {
		vector<int> previous;
		for (int j = 0; j < coin_values.size(); ++j) {
			if ((coin_values[j] <= i) && 
				(min_values[i-coin_values[j]] + 1) < min_values[i]) {
				min_values[i] = min_values[i - coin_values[j]] + 1;

				previous = valueToVec[i - coin_values[j]];
				previous.push_back(coin_values[j]);
			}
		}
		valueToVec[i] = previous;
	}

	cout << min_values[target_val] << endl;
	return valueToVec[target_val];
}

int main() {
	int num_coin_values;
	cout << "Enter number of coin values" << endl;
	cin >> num_coin_values;

	vector<int> coin_values(num_coin_values);

	cout << "Enter the coin values: ";
	for (auto&& curr_value : coin_values)
		cin >> curr_value;

	cout << "Enter desired value: ";
	int desired_value;
	cin >> desired_value;

	vector<int> change = compute_min(coin_values, desired_value);

	for (auto&& coins : change) {
		cout << coins << endl;
	}

	return 0;
}
