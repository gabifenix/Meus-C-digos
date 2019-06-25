/*
 * Brincando com listas dinâmicas
 *
 * Um pequeno mimo para vocês, queridos alunos, avançarem nesta difícil jornada.
 *
 * 
 * Monitor: André Ré
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 24/05/2019
 */
 #include <iostream>
 #include <stdlib.h>
 #include <locale.h>
 #include <fstream>

using namespace std;

typedef struct {
    string nome;
    int idade;
    int curso;
    int cpf;
}ELEMENTO;

 typedef struct NO{
 	ELEMENTO aluno;
 	struct NO* proximo;
 }*LISTA;



 LISTA inicializar(LISTA lista_de_candidados){
 	// lista_de_candidados = (LISTA) malloc( sizeof(NO) );
  lista_de_candidados = new NO;
 	lista_de_candidados->proximo = NULL;
 	return lista_de_candidados;
 }

 LISTA cadastrar_candidato(LISTA lista_de_candidados){
     ELEMENTO novo_candidato;
     cout << "Digite o nome do vestibulando " << endl;
     cin >> novo_candidato.nome;
     cout << "Digite a idade do vestibulando " << endl;
     cin >> novo_candidato.idade;
     cout << "Digite o CPF do vestibulando " << endl;
     cin >> novo_candidato.cpf;
     LISTA aux = new NO;
  	 aux->aluno = novo_candidato;
  	 aux->proximo  = lista_de_candidados;
     lista_de_candidados = aux;
     return lista_de_candidados;
 }

 void mostrar_inscritos(LISTA lista_de_candidados){
    LISTA no = lista_de_candidados;
 	while(no != NULL){
        if (no->proximo != NULL) {
            cout <<"CANDIDATO: " << no->aluno.nome << "\n ";
        }

 		no = no->proximo;
 	}
 	cout << endl;
 }

 int numero_de_inscritos(LISTA lista_de_candidados){
     LISTA lista_local = lista_de_candidados;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->proximo;
        cont++;
 	}
 	return (cont - 1);
 }

 void destruir(LISTA lista_de_candidados){
    if(lista_de_candidados->proximo != NULL ) {
        LISTA noProximo = lista_de_candidados;
        while(noProximo->proximo != NULL){
            cout << "| " << noProximo->aluno.nome;
            cout << " - " << noProximo->aluno.idade << endl;
            lista_de_candidados = noProximo->proximo;
            noProximo->proximo = NULL;
            delete noProximo;
            noProximo = lista_de_candidados;
     	}
      delete lista_de_candidados;
    }
 }

 int buscarFila(LISTA lista_de_candidados, string candidato){
     LISTA noProximo = lista_de_candidados;
     int cont = numero_de_inscritos(lista_de_candidados);
     while(noProximo != NULL){
         if (candidato == noProximo->aluno.nome) {
             return cont;
         }
         cont--;
         noProximo = noProximo->proximo;
     }
     return cont;
 }

 int main(){
 	 setlocale(LC_ALL, "Portuguese");
 	 system("color A");
     LISTA lista_de_candidados;
     char escolha = 'x';
     ELEMENTO candidado;
     lista_de_candidados = inicializar(lista_de_candidados);
     do {
           cout << "\n********************************\n";
           cout << "Digite uma letra\n\n";
           cout << "i \t Cadastrar candidato\n";
           cout << "a \t Validar inscricao\n";
           cout << "e \t Encontrar candidato \n";
           cout << "p \t Listar Candidatos \n";
           cout << "q \t Encerrar .\n\n\n";
           cin >> escolha;
           if(escolha == 'i' || escolha == 'I'){
               lista_de_candidados = cadastrar_candidato(lista_de_candidados);
               cout << "Escolha o curso desejado \n";
               cin >> escolha;
               if(escolha == '1'){
               	cout << "Sistemas para Internet \n";
			   }
			   if(escolha == '2'){
			   	cout << "Gest�o Empresarial \n";
			   }
			   cout << "A inscri��o j� foi paga? \n";
			   cin >> escolha;
			   if(escolha == 's' || escolha == 'S'){
			   cout << "Inscri��o realizada com sucesso!!!";
			   }
			   if(escolha == 'n' || escolha == 'N'){
			   	cout << "Seu pagamento da inscri��o do vestibular ainda est� pendente.";
			   }
           }
           if(escolha == 'a' || escolha == 'A'){
              cout << "Lamento, funcionalidade não implementada" << endl;
           }
           if(escolha == 'e' || escolha == 'E'){
               string candidato_procurado;
               cout << " Digite o nome do cliente procurado : " << endl;
               cin >> candidato_procurado;
               cout << "O candidato "<< candidato_procurado ;
               cout << " encontra-se na posicao "<< buscarFila(lista_de_candidados, candidato_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == 'p' || escolha == 'P'){
               cout << "Candidatos inscritos: " << numero_de_inscritos(lista_de_candidados) << endl;
               mostrar_inscritos(lista_de_candidados);
           }
       } while( escolha != 'q');

     	destruir(lista_de_candidados);
     	
     	string line;
  	 	ifstream inscricoes ("inscricoes.txt");
  	 	ifstream candidatos ("candidatos.txt");
  	 	ifstream aprovados ("aprovados.txt");
  	 	
  	 	cout << "\nInscri��es \n\n";
  	 	
       	if (inscricoes.is_open())
  		{
    		while ( getline (inscricoes,line) )
    	{
     	 cout << line << '\n';
    	}
   		 inscricoes.close();
		}
		
		cout << "\nCandidatos \n\n";
		
		if (candidatos.is_open())
  		{
    		while ( getline (candidatos,line) )
    	{
     	 cout << line << '\n';
    	}
   		 candidatos.close();
		}
		
		cout << "\nAprovados \n\n";
		
		if (aprovados.is_open())
  		{
    		while ( getline (aprovados,line) )
    	{
     	 cout << line << '\n';
    	}
   		 aprovados.close();
		}

  		else cout << "Unable to open file";
    	return 0; 
 }
