#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>

using namespace std;

int majVote(vector<int> &vec)
{

	if (vec.size() == 0) {
		return -1;
	}

	int maj = vec[0];
	int cnt = 1;
	for (int i=1; i<vec.size(); i++) {
		if (maj == vec[i]) {
			cnt++;
		} else {
			cnt--;
			if (cnt == 0) {
				maj = vec[i];
				cnt++;
			}
		}
	}

	cnt = 0;
	for (int i=0; i<vec.size(); i++) {
		if (maj == vec[i]) {
			cnt++;
		}
	}

	if (cnt > vec.size()/2) {
		return maj;
	} else {
		return -1;
	}
}

int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);

	cout << "Majority element present is " << majVote(vec) << endl;
    return 0;
}
