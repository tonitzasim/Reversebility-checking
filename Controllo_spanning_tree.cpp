#include<bits/stdc++.h>
using namespace std;
int main()  {
    
	//dichiarazioni iniziali e input
	
	int n;
    cin>>n;
    double pesi [n][n];
    vector<int> adj[n];
    vector<bool> visited(n,false);
    vector<double> backwards(n,0);
    vector<double> forwards(n,0);
    queue<int> q; 

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pesi[i][j];
		}
	}
	//costruiamo le liste di adiacenza
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pesi[i][j]>0){
				adj[i].push_back(j);
			}	
		}
	}
//facciamo una bfs per calcolare i vettori di forwards e backwards
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

    //controlliamo la condizione di Kolmogorov sui cicli fondamntali
    
	bool reversibile=true;
    
    for(int i=1;i<n;i++){
    	if(visited[i]=false){
    		reversibile=false;
		}
 		for(int x : adj[i]){
 			if(fabs(forwards[i]*pesi[i][x]*backwards[x]-forwards[x]*pesi[x][i]*backwards[i])>pow(10,-10)){
 				reversibile=false;
			 }
 			
		 }   	
	}
	
	cout<<reversibile;
	
    return 0;
}

