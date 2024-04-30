#ifndef _meualoc
#define _meualoc
#define BESTFIT 0
#define FIRSTFIT 1
#define NEXTFIT 2
#define MAGICVAR 20299
#define CEIL 65531


//TAMANHO MÁXIMO DE ALOCACAO: 65535 (maior unsigned short)

using namespace std;

class Node{
	public:
		char* addr;
		int tamanho;

		Node(char* addre, int tam){
				addr = addre;
				tamanho = tam;
		}

};

class Data{
	public:
	int id;
	char* pont;

	Data(int id, char* pont){
		id = id;
		pont = pont;
	}
};

class meualoc{

	public:
		list<Node> listaLivres;
		int tamanhoMemoria;
		int politicaMem;
		list<Node>::iterator posLista;
		char* memoria; //char* pois eh byte a byte
		//tamanhoMemoria vai definir o tamanho da memória que o alocador vai utilizar
		//politicaMem define como escolher o bloco de onde saira a memória
		meualoc(int tamanhoMemoria,int politicaMem);

		char *getMemoriaPointer();
		int getMemoriaTam();

		void setMeuAloc(int tamanho,int politica);

		void initListaDeVazia();

		void insertListaDeVazias(Node* tmp);

		void fillMemory();

		void coalesce();

		//Pega um pedaco da variavel memoria e aloca, retornando o ponteiro para o comeco dessa regiao e atualizando a lista de livres.
		char *aloca(unsigned short int tamanho);

		//Verifica se a posicao dada pelo ponteiro esta alocada
		char* verifica(char* ponteiro,int posicao);

		
		
		//Libera o espaco ocupado na posicao, de forma analoga ao free. Ou seja, liberar toda a memoria alocada para este ponteiro na funcao aloca.
		int libera(char* ponteiro);

		//Imprime o numero de elementos na lista de vazios, o maior e a media de tamanhos dos blocos vazios
		void imprimeDados();

		~meualoc();

		int tamListaVazios();

		int tamLivres();

		int mediaTamBlocos();
};

void string_to_vet_char(string source, char data[],int tam);



#endif
