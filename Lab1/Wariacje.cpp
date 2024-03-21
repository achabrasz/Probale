//#include <iostream>
//#include <vector>
//using namespace std;
//
//void wariacje(vector<int> v, int n) {
//	if (n == 0) {
//		for (int i = 0; i < v.size(); i++) {
//			cout << v[i] << " ";
//		}
//		cout << endl;
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			swap(v[i], v[n-1]);
//			wariacje(v, n-1);
//			swap(v[i], v[n-1]);
//		}
//	}
//}
//
//int main() {
//	int m;
//	cin >> m;
//	vector<int> v(m);
//	for (int i = 0; i < m; i++) {
//		v[i] = i+1;
//	}
//	wariacje(v, m);
//}