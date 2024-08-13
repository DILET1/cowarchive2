#include <bits/stdc++.h>
using namespace std;
//tactic: group points by common y-coordinate, and then seperately by common x-coordinate. Go through each y-coordinate, and for each pointt, check how many points have its x-coordinate. Get total length of all possible bases (difference in x for commmon y) and heights (difference in y for common x). Multiply and have fun. 
int MOD = 1e9+7;
int main(){
	long long ans = 0;
	vector<vector<int>> byY(20001, vector<int>(0));
	vector<vector<int>> byX(20001, vector<int>(0));
	ifstream in("triangles.in");
	ofstream out("triangles.out");
	int n;
	in >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		in >> x >> y;
		x+=1e4;y+=1e4; //shifting coordinates right 1e4 units so everything is nonnegative
		byY[y].push_back(x);
		byX[x].push_back(y);
	}
	for(int i = 0; i < 20001; i++){
		sort(byY[i].begin(), byY[i].end()); //not necessary, but whatever
		sort(byX[i].begin(), byX[i].end()); //ditto
	}
	for(int i = 0; i < 20001; i++){
		if(byY[i].size() > 1){ //we can at least make one side
			for(int j = 0; j < byY[i].size(); j++){
				int cx = byY[i][j];
				if(byX[cx].size() > 1){ //if there is a point with the same x-coordinate (meaning a vertical side does exist) we can then abuse the distributive rule (yay, elementary school math)
					//get sum of y-sides
					long long yNet = 0; //these can gettt big
					for(int x = 0; x < byX[cx].size(); x++){
						yNet+=abs(i - byX[cx][x]);
					}
					//get sum of x-sides
					long long sideNet = 0;
					for(int down = j-1; down >= 0; down--){
						sideNet+=(cx - byY[i][down]);
					}
					for(int up = j+1; up < byY[i].size(); up++){
						sideNet+=(byY[i][up] - cx);
					}
					long long stageAns = yNet * sideNet;
					stageAns%=(MOD);
					ans+=stageAns;
					ans%=(MOD);
				}
			}
		}
	}
	out<<ans<<'\n';
}
