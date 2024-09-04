#include <bits/stdc++.h>
using namespace std;
int main(){
	int l, n, f, c;
	ifstream in("reststops.in");
	ofstream out("reststops.out");
	in >> l >> n >> f >> c;
	vector<pair<int,int>> stops;
	for(int i = 0; i < n; i++){
		int a, b;
		in >> a >> b;
		stops.push_back({a,b});
	}
	sort(stops.begin(), stops.end());
	vector<pair<int,int>>::iterator ptr = stops.end();
	ptr--;
	int max = stops[stops.size() - 1].second;
	vector<int> indices;
	indices.push_back(stops.size() -1);
	int ctr = stops.size() - 1;
	while(ptr!=stops.begin()){
		ctr--;
		ptr--;
		if((*ptr).second > max){
			max = (*ptr).second;
			indices.push_back(ctr);
		}
	}
	int curLoc = 0;
	long long ans = 0;
	long long dr = f - c;
	for(int c = indices.size() -1; c >= 0; c--){
		long long time = stops[indices[c]].first - curLoc;
		time*=dr;
		ans+=(time * stops[indices[c]].second);
		curLoc = stops[indices[c]].first;
	}
	out<<ans<<'\n';
}
