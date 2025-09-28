#include<bits/stdc++.h>
using namespace std;
int main(){
	//Dichiarazioni iniziali e input
	int n;
	srand(time(0));
	double somma=0;
	double prob_zero= 1/ (double) 2;
	cout<<"Inserisci il numero di stati: ";
	cin>>n;
	cout<<endl;
	double distribuzione[n];
	double pesi[n][n], accetta[n][n], iniziale[n][n];
	
	//generaimo una distribuzione all'equilibrio randomica
	for(int i=0;i<n;i++)
	{
		distribuzione[i]=rand()%100+1;
		somma+=distribuzione[i];
	}
		for(int i=0;i<n;i++)
	{
		distribuzione[i]/=double(somma);
	}
	//generiamo la matrice randomica iniziale

	for(int i=0;i<n;i++){
	somma=0;		
		for(int j=0;j<n;j++){
			if( rand()%100 / (double) 100 < prob_zero&&i!=((j-1)%n) && i!=((j+1)%n) ){
				iniziale[i][j]=0;
			}
			else {
			iniziale[i][j]=rand()%100+1;
		somma+=iniziale[i][j];
	}
		}
		for(int j=0;j<n;j++){
			iniziale[i][j]/=somma;
		}
	}
	
	//calcoliamo la matrice con le probabilità di accettazione
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			if(i==j || pesi[i][j]==0|| pesi[j][i]==0)
				accetta[i][j]=0;
			else {
				accetta[i][j]= min((double) 1, ( distribuzione[j]*iniziale[j][i]/( distribuzione[i] * iniziale[i][j] ) ) );
			}
		}
	}
	
	//moltiplichiamo elemento per elemnto le due matrice e normalizziamo 
	//gli elementi sulla diagonale
	
	for(int i=0;i<n;i++){
		somma=0;
		for(int j=0;j<n;j++)
		{
			pesi[i][j]=iniziale[i][j]*accetta[i][j];
			somma+=pesi[i][j];
			
		}
		pesi[i][i]-=somma-1;
	}
	bool corretto=true;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			cout<<pesi[i][j]<<" ";
			if(fabs(distribuzione[i]*pesi[i][j]-distribuzione[j]*pesi[j][i])>pow(10,10)){
				corretto=false;
			}
		}
		cout<<endl;
	}
	cout<<corretto;
}


