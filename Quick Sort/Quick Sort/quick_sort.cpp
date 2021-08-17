#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<char> *items, int l, int r) {
	int i = l - 1;
	char x = items->at(r);
	for (int j = l; j < r; j++) {
		if (items->at(j) < x)
		{
			i++;
			swap(items->at(i), items->at(j));
		}
	}
	i++;
	swap(items->at(i), items->at(r));
	return i;
}
void qs(vector<char> *items, int l, int r) {
	if (l >= r)  //base case
		return;
	int p = partition(items, l, r);
	qs(items, l, p - 1);
	qs(items, p + 1, r);
}
int main() {
	vector<char> t_1 = { 'f','s','r','e','h','e','s','c','b','a','f' };
	qs(&t_1, 0, 10);
	for (int i = 0; i < t_1.size(); i++) {
		cout << t_1[i] << " ";
	}
}