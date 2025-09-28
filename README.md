# Reversibilità delle catene di Markov
In questa repository sono presenti:
- 2 codici per la generazione delle matrici di catene (reversibili e no)
- l'implementazione dell'algoritmo con le matrici
- l'implementazione dell'algoritmo con gli spanning tree
- 3 codici che permettono il testing dei 3 algoritmi visti

I due codici che generano le matrici prendono in input solo la dimensione voluta della matrice da creare e stampano la matrice generata.

I codici che implementano i due algoritmi chiedono in input la dimensione della matrice e la matrice che si vuole verificare.
In output stampano entrambi un valore booleano: vero se la catena è reversibile e falso altrimenti.

## Testing

Per il testing dei codici, abbiamo prima implementato un codice che verifica la correttezza dell'algoritmo di Metropolis-Hastings, verificando se le matrici che genera sono reversibili
utilizzando le equazioni dettagliate del bilancio. Il codice di testing prende in input la dimensione di matrice e verifica se la matrice generata è effetivamente reversibile,
dando la possibilità all'utente con la risposta con un valore booleano (1 per il sì, 0 per il no) di vedere la matrice creata.
Per il testing dei due algoritmi di verifica, viene chiesto in input la dimensione della matrice e se ci vuole testare il codice con una matrice reversibile o meno.
Viene controllata la correttezza del codice confrontando il motodo di generazione utilizzato (Metropolis-Hastings o no) con il risultato finale. Se i valori coincidono, significa che il codice si è comportato correttamente.
Durante la computazione, sarà possibile anche stampare certi risultati intermedi come la matrice iniziale generata.
