#include<bits/stdc++.h>
using namespace std;
int main(){

	//dichiarazioni iniziali e input
	
	int n;
	srand(time(0));
	double somma=0;
	double prob_zero= 1/ (double) 2;
	cout<<"Inserisci numero di stati: ";
	cin>>n;
	cout<<endl;
	double distribuzione[n];
	double pesi[n][n], accetta[n][n], iniziale[n][n];
	
	//generiamo una distribuzione all'equilibrio randomica
	for(int i=0;i<n;i++)
	{
		distribuzione[i]=rand()%100;
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
			if( rand()%100 / (double) 100 < prob_zero&&i!=((j-1+n)%n) && i!=((j+1)%n) ){
				iniziale[i][j]=0;
			}
			else {
			iniziale[i][j]=rand()%100;
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
			
			if(i==j || iniziale[i][j]==0|| iniziale[j][i]==0)
				accetta[i][j]=0;
			else {
				accetta[i][j]= min((double) 1, ( distribuzione[j]*iniziale[j][i]/( distribuzione[i] * iniziale[i][j] ) ) );
			}
		}
	}
	
	//moltiplichiamo elemento per elemento le due matrice e normalizziamo 
	//gli elementi sulla diagonale per ottenere una matrice reversibile
	
	for(int i=0;i<n;i++){
		somma=0;
		for(int j=0;j<n;j++)
		{
			pesi[i][j]=iniziale[i][j]*accetta[i][j];
			somma+=pesi[i][j];
			
		}
		pesi[i][i]-=somma-1;
	}
	
	//stampiamo i risultati finali
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			cout<<pesi[i][j]<<" ";
		}
		cout<<endl;
	}
}



