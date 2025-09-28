#include<bits/stdc++.h>
using namespace std;
int main()  {
    //dichiarazioni iniziali e input
	int n;
	cout<<"Inserisci numero di stati: ";
    cin>>n;
    cout<<endl;
    double pesi [n][n];
    vector<int> adj[n];
    vector<bool> visited(n,false);
    vector<double> backwards(n,0);
    vector<double> forwards(n,0);
    queue<int> q; 
    srand(time(0));
    bool reversibile,risultato;
	double somma=0;
	double prob_zero= 1/ (double) 2;
	double distribuzione[n];
	double accetta[n][n], iniziale[n][n];
    
	cout<<"La matrice testata deve essere reversibile? ";
	cin>>reversibile;
	cout<<endl;
	
if(reversibile){
	//generiamo una distribuzione all'equilibrio da rispettare
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
	

		//moltiplichiamo elemento per elemento le due matrici e normalizziamo 
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
}
else{	
	//generiamo una matrice casuale non reversibile
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
}
bool scelta;
cout<<"Vuole vedere la matrice iniziale? ";
	cin>>scelta;
	cout<<endl;
	if(scelta){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pesi[i][j]<<" ";
		}
		cout<<endl;
	}
}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pesi[i][j]>0){
				adj[i].push_back(j);
			}	
		}
	}

    visited[0] = true;
    q.push(0);
    
    while (!q.empty()) {
        
        int curr = q.front(); 
        q.pop();

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                if(curr==0){
                	forwards[x]=pesi[0][x];
					backwards[x]=pesi[x][0];				
				}
				else {
					forwards[x]=forwards[curr]*pesi[curr][x];
					backwards[x]=pesi[x][curr]*backwards[curr];				
				}
                q.push(x);
            }
        }
}

    
    risultato=true;
    
    for(int i=1;i<n;i++){
    	if(visited[i]=false){
    		risultato=false;
		}
 		for(int x : adj[i]){
 			if(fabs(forwards[i]*pesi[i][x]*backwards[x]-forwards[x]*pesi[x][i]*backwards[i])>pow(10,-10)){
 				risultato=false;
			 }
 			
		 }   	
	}
	
	cout<<risultato<<" ";
    if(risultato==reversibile){
    	cout<<"corretto";
	}
	else cout<<"sbagliato";
    
    
    return 0;
}
