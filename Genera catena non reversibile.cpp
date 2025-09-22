#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	srand(time(0));
	double somma=0;
	double prob_zero= 1/ (double) 2;
	cin>>n;
	double pesi[n][n];

	for(int i=0;i<n;i++){
	somma=0;		
		for(int j=0;j<n;j++){
			if( rand()%100 / (double) 100 < prob_zero ){
				pesi[i][j]=0;
			}
			else {
			pesi[i][j]=rand()%100;
		somma+=pesi[i][j];
	}		
		}
		for(int j=0;j<n;j++){
			pesi[i][j]/=somma;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pesi[i][j]<<" ";
		}
		cout<<endl;
	}
}
