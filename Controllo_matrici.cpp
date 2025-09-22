#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double alfa;
	cin>>n;
	vector<int> adj[n];
	double pesi[n][n];
	vector<int> genitore(n,-1);
	bool risultato=true;
	queue<int> q;
	
	
	
	srand(time(0));
	double somma=0;
	double prob_zero= 1/ (double) 2;
	double distribuzione[n];
	double accetta[n][n], iniziale[n][n];



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
	//calcoliamo la matrice con la probabilità di accettazione
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			if(i==j || iniziale[i][j]==0|| iniziale[j][i]==0)
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
	
//stampo la matrice di input	
	

	
	//costrisco le liste di adiacenze
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pesi[i][j]>0){
				adj[i].push_back(j);
			}	
		}
	}
	
	//aggiungo subito alla coda tutti i nodi connessi con il nodo iniziale 0
	for(int x:adj[0]){
		if(pesi[x][0]!=0&&pesi[0][x]!=0){
			q.push(x);
			genitore[x]=0;
		}
	}
	//itero fino a quando non ci sono nodi ancora da considerare
	while(!q.empty()){
		int curr=q.front();
		q.pop();
	
	//controllo	se pesa di più l'arco tra il nodo attuale e il suo genitore
	// o l'arco inverso
		
		if(pesi[curr] [genitore[curr] ] > pesi[genitore [curr] ] [curr]){
	
	// in questo caso moltiplico tutta la riga corrente per il rapporto tra il minore e il maggiore	
			
			alfa=pesi[genitore[curr]][curr]/pesi[curr][genitore[curr]];
			
	//sistemo l'elememento sulla diagonale
			for(int i=0;i<n;i++){
				pesi[curr][i]=pesi[curr][i]*alfa;
			}
			pesi[curr][curr]=1-alfa;
		}
	//altrimenti moltiplico tutta la colonna corrente per il rapporto
	//e sistemo la diagonale	
		else {
			alfa = pesi[curr][genitore[curr]] / pesi[genitore[curr]][curr];		
			for(int i=0;i<n;i++){
				if(i!=curr){
				pesi[i][i]+=pesi[i][curr]*(1.0-alfa);
				pesi[i][curr]*=alfa;
				}
			}
		}
	//aggiungo alla coda tutti i nodi adiacenti al corrente non considerati
		for(int x:adj[curr]){
			if(pesi[x][curr]!=0&&pesi[curr][x]!=0 &&genitore[x]==-1){
				q.push(x);
				genitore[x]=curr;
			}
		}
	}
	//verifico se la matrice finale è simmetrica 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(fabs(pesi[i][j] - pesi[j][i])> pow(10,-10)) {
				risultato=false;
			}
			
		}
	}
	cout<<risultato;
}
