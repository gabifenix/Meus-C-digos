#include <iostream>

using namespace std;

typedef struct{
	string nome;
	string cpf;
	string opcao_curso;
	int numero_inscricao;
	bool inscricao_efetivada;
	bool aprovado;
	string alunos_aprovados [40];
} INSCRICAO;

typedef struct {
	INSCRICAO *top;
	int size;
} INSCRICAO_REALIZADA;

INSCRICAO_REALIZADA * inicializar() {
	INSCRICAO_REALIZADA * s = new INSCRICAO_REALIZADA;
	s->size = 0;
	s->top = NULL; 		
}

void push(INSCRICAO_REALIZADA *s, int value) {
	INSCRICAO_REALIZADA *np;
	np = new INSCRICAO_REALIZADA;
	if (np == NULL) {
		cout << "Não há alunos inscritos";
	}
	
	np->size = value;
}

int pop(INSCRICAO_REALIZADA *s) {
	int temp;
	INSCRICAO *np;
	
	if (s->top = NULL) {
		cout << "Não há alunos inscritos";
	}
	
	np = s->top;
	delete np;
	
	return temp;
}

void destruir_pilha(INSCRICAO_REALIZADA *s) {
	while (s->top != NULL) {
		pop(s);
	}
	pop(s);
	delete s;
}

void imprime_pilha(INSCRICAO_REALIZADA *s) {
	INSCRICAO* temp;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
	cout << s->size << endl;
	while(temp!=NULL){
		cout << temp->nome << endl;
	}
	cout << endl;
}

int main() {
	INSCRICAO dados_do_aluno;
	INSCRICAO_REALIZADA confirmacao;
	
	INSCRICAO_REALIZADA *minha_pilha = inicializar();
	imprime_pilha(minha_pilha);
	cout << "Nome: \n";
	cin >> dados_do_aluno.nome;
	cout << "CPF: \n";
	cin >> dados_do_aluno.cpf;
	cout << "Curso \n";
	cin >> dados_do_aluno.opcao_curso;
	cout << "Número da inscrição \n";
	cin >> dados_do_aluno.numero_inscricao;
	
	cout << "\n";
	
	cout << "Inscrição realizada com sucesso!";
	
	return 0;
}
