#include <stdio.h>
#include <vector>
using namespace std;

/*  Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

    ar1[] = {1, 5, 10, 20, 40, 80}
    ar2[] = {6, 7, 20, 80, 100}
    Output: 20, 80 */

void catchUpTarget(const vector<int> &arr, int &start, int target) {
	while(start < arr.size() && arr[start] < target) ++start;
}

vector<int> getCommon(vector<vector<int> > &arrays) {
	int N = arrays.size();
	vector<int>	result;
	if(N < 2) return result;

	vector<int>	startPosArr(N, 0);
	int target = 0, targetCnt = 0;

	while(true) {
		for(int i = 0; i < N; ++i)
			if(startPosArr[i] >= arrays[i].size()) return result;

		target = arrays[0][startPosArr[0]];  targetCnt = 1;

		for(int i = 1; i < N; ++i) {
			catchUpTarget(arrays[i], startPosArr[i], target);
			if(startPosArr[i] < arrays[i].size() && target == arrays[i][startPosArr[i]])
				++targetCnt;
		}

		if(targetCnt == N) result.push_back(target);
		catchUpTarget(arrays[0], startPosArr[0], target + 1);
	}
	return result;
}

int main() {
	int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);

    vector<vector<int> > arrays;
	vector<int>	v1(ar1, ar1 + n1);
	vector<int>	v2(ar2, ar2 + n2);

	arrays.push_back(v1);
	arrays.push_back(v2);

	vector<int> result = getCommon(arrays);

	for(int i = 0; i < result.size(); ++i) printf("%d ", result[i]);
	printf("\n");
	return 0;
}
