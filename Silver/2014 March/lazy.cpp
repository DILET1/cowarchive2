#include <bits/stdc++.h>
using namespace std;
//tactic: calculate each space's number in O(N) time, with N^2 spaces. Gives us N^3 which with N < 400 will pass.
int main(){
	int n, k;
	ifstream in("lazy.in");
	ofstream out("lazy.out");
//	cin >> n >> k;
	in >> n>> k;
	vector<vector<int>> grid(n, vector<int>(n+1, 0));
	for(int i = 0; i < n; i++){ //each row gets a prefix sum
		int a;
//		cin >> a;
		in >> a;
		grid[i][1] = a;
		for(int j = 2; j <=n; j++){
//			cin >> a;
			in >> a;
			grid[i][j] = a + grid[i][j-1];
		}
	}
	int ans = -2E9;
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n+1; j++){
			int ca = 0;
			for(int r = max(i-k, 0); r < min(i+k+1, n); r++){ //highest row we can go to - the top row or k rows above the selected cell, lowest bottom or k rows below.
				int left = max(j-k+abs(i - r), 1); //depending on how many steps we used to get to the row, we have k - that number of steps left to use.
				int right = min(j+k-abs(i - r), n);
//				cout<<left<<" "<<right<<'\n';
				ca+=(grid[r][right] - grid[r][left-1]); //prefix sum things
			}
//			cout<<ca<<'\n';
			ans = max(ans, ca);			
		}
	}
//	cout<<ans<<'\n';
	out<<ans<<'\n';
	//kinda good to be back, ngl
}
