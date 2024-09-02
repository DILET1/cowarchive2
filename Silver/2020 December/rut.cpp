//time to actually finish this problem after 1.5 years 
/*
Observations: N = 1E3, so N^2 or N^2logN or even N^2logN^2 is possible.
Simulation is pointless, we're basically just seeing where lines intersect.
Parallel cows will never hurt each other, perpendicular cows can and will if they will cross in front of the cow's path (those behind will also never hurt).
The main issue is chronology, how do we know if the cow will even make it to the intersection? Theoretically, if we sort cows in terms of increasing non-mutable coordinate (X for north, Y for south), things should work themselves out.
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> coords;
bool sortNorth(int a, int b){
	return coords[a].first < coords[b].first;
}
bool sortEast(int a, int b){
	return coords[a].second < coords[b].second;
}
int main(){
	int n;
	cin >> n;
	vector<int> north; 
	vector<int> east;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		int x, y;
		cin >> x >> y;
		if(c == 'E'){
			east.push_back(i);
		}
		if(c == 'N'){
			north.push_back(i);
		}
		coords.push_back({x,y});
	}
	sort(north.begin(), north.end(), sortNorth);
	sort(east.begin(), east.end(), sortEast);
	vector<bool> stop(n, false);
	int startE = 0;
	vector<int> ans(n, 0);
	for(int nc : north){
		for(int ec : east){
			if(!stop[nc] && !stop[ec] && coords[nc].first > coords[ec].first && coords[ec].second > coords[nc].second){
				//difference in y greater - N stopped, difference in x greater - E stopped (less distance = arrive first). If same, neither are stopped.
				if(coords[nc].first - coords[ec].first > coords[ec].second - coords[nc].second){
					stop[ec] = true;
					ans[nc]+=ans[ec];
					ans[nc]++;
				}
				if(coords[nc].first - coords[ec].first < coords[ec].second - coords[nc].second){
					stop[nc] = true;
					ans[ec]+=ans[nc];
					ans[ec]++;
				}
			}
		}
	}
	for(int a : ans){
		cout<<a<<endl;
	}
}
