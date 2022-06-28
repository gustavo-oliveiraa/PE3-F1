//Nome: Gabriel Oliveira Santos / Matrícula: UC21100452
//Nome: Gustavo Maxwel de Sousa Oliveira / Matrícula: UC21101257

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 450

struct Piloto{
	int idPiloto; 
	int idade;
	char nome[200], pais[45], sexo;
};

struct Piloto piloto;

 struct Circuito{
 	float tamanho;
 	double menorTempo, tempo;
	int codigo;
	char nome[200], pais[50];//esqueci do país
	//pedir o id do piloto e verificar se existe com a struct Piloto.
};

struct Circuito circuito;

struct Data{
	int dia, mes, ano;
};

struct Data data;

struct MelhorVolta{
	struct Piloto piloto;
	struct Circuito circuito;
	struct Data data;
	char equipePiloto;
	double melhorVolta;
};

void le_valida_idPiloto(struct MelhorVolta f1[], int index);
void le_valida_idadePiloto(struct MelhorVolta f1[], int index);
void le_valida_nomePiloto(struct MelhorVolta f1[], int index);
void le_valida_sexoPiloto(struct MelhorVolta f1[], int index);
void le_valida_paisPilotoP(struct MelhorVolta f1[], int index);
void le_valida_tamCircuito(struct MelhorVolta f1[], int index);
void le_valida_codigoCircuito(struct MelhorVolta f1[], int index);
void le_valida_nomeCircuito(struct MelhorVolta f1[], int index);
void le_valida_paisCircuito(struct MelhorVolta f1[], int index);
void le_valida_menorTempoCircuito(struct MelhorVolta f1[], int index, int cont1);

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct MelhorVolta F1[MAX];
	
	int opcao=0,opcao2=0, cont=0, cont2=0, cont3=0;
	int codigoC;
	
	do{
	
		system("cls");
		
		printf("Cadastrar(Pilotos, Circuitos e Voltas)(0)\n");
		printf("Consulta simples sobre todos (Pilotos, Circuitos e Voltas)(1)\n");
		printf("Pesquisar pilotos nome(2)\n");
		printf("Pesquisar um circuito e os dados relacionados ao mesmo(3)\n");
		printf("Pesquisar por tempo de volta(0.00.000)(4)\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				do{
					system("cls");
					printf("Digite 1 para cadastrar um piloto\n");
					printf("Digite 2 para cadastrar um circuito\n");
					printf("Digite 3 para registrar uma melhor volta\n");
					printf("Digite 4 para sair\n");
					scanf("%d", &opcao2);
					switch(opcao2){
						case 1:
							le_valida_idPiloto(&F1, cont);
							
							le_valida_idadePiloto(&F1, cont);
							
							le_valida_nomePiloto(&F1, cont);
							
							le_valida_paisPilotoP(&F1, cont);
							
							le_valida_sexoPiloto(&F1, cont);
				
							cont++;
							getch("");
						break;
					
						case 2:
							le_valida_codigoCircuito(&F1, cont2);
							
							le_valida_nomeCircuito(&F1, cont2);
							
							le_valida_paisCircuito(&F1, cont2);
							
							le_valida_tamCircuito(&F1, cont2);

							le_valida_menorTempoCircuito(&F1, cont2, cont);
							
							cont2++;
							getch("");
						break;
						
						case 3:
							
							cont3++;
						break;
						
						case 4:
						
						break;
					}
				}while(opcao2!=4);
			break;
			
			case 1:
				
			break;
			
			case 2:
				
			break;
			
			case 3:
				
			break;
			
			case 4:
				
			break;
			
			case 5:
				
			break;
		}
	}while(opcao!=5);
	
	return 0;
}

void le_valida_idPiloto(struct MelhorVolta f1[], int index){
	
	int unId=0;
	
	do{
		printf("Identificação do piloto: ");
		scanf("%d", &f1[index].piloto.idPiloto);
		
		for(unId; unId<index; unId++){
			if(f1[index].piloto.idPiloto == f1[unId].piloto.idPiloto){
				do{
					printf("Esse número já está em uso!\n");
					printf("Identificação do piloto: ");
					scanf("%d", &f1[index].piloto.idPiloto);
				}while(f1[index].piloto.idPiloto == f1[unId].piloto.idPiloto);	
			}
		}
		
		//printf("%d\n", f1[0].piloto.idPiloto);
		//printf("%d", f1[1].piloto.idPiloto);
		
	}while(f1[index].piloto.idPiloto<100 || f1[index].piloto.idPiloto>500);
}

void le_valida_idadePiloto(struct MelhorVolta f1[], int index){
	
	do{
		printf("Idade do piloto:");
		scanf("%d",&f1[index].piloto.idade);
		if(f1[index].piloto.idade<18){
			printf("Vai pra F2!(>18)\n");
		}else if(f1[index].piloto.idade>65){
					printf("\nAposenta!(<65)\n");
				}
	}while(f1[index].piloto.idade <18 || f1[index].piloto.idade>65);
}

void le_valida_nomePiloto(struct MelhorVolta f1[], int index){
		
	int tam, espaco, j=0;
	
	do{
		fflush(stdin);
		printf("Nome do piloto:");
		scanf("%[^\n]s",&f1[index].piloto.nome);
		fflush(stdin);
		
		tam=strlen(f1[index].piloto.nome);
		
		for(j; j<tam;j++){
				f1[index].piloto.nome[j] = tolower(f1[index].piloto.nome[j]);
			}
			
			f1[index].piloto.nome[0] = toupper(f1[index].piloto.nome[0]);
		for(j=0; j<tam; j++){
			if(f1[index].piloto.nome[j]==' '){
				espaco = j; 
				f1[index].piloto.nome[espaco+1] = toupper(f1[index].piloto.nome[espaco+1]);
			}
		}
		if(tam<1 || tam>200){
			printf("O nome não pode ser nulo\n");
		}
	}while(tam<1 || tam>200);
}

void le_valida_paisPilotoP(struct MelhorVolta f1[], int index){
	
	int tam, espaco, j=0, valido=0, r;
	char arqPaises[200][50];
	
	do{
		FILE *arq;
		
		arq = fopen("Paises.txt", "r");
		
		if(arq == NULL){
			printf("Erro ao abrir o arquivo!");
		}else{
				fflush(stdin);
				printf("País piloto:");
				scanf("%[^\n]s",&f1[index].piloto.pais);
				
				tam=strlen(f1[index].piloto.pais);
				
				for(j; j<tam;j++){
					f1[index].piloto.pais[j] = tolower(f1[index].piloto.pais[j]);
				}
					
				f1[index].piloto.pais[0] = toupper(f1[index].piloto.pais[0]);
				for(j=0; j<tam; j++){
					if(f1[index].piloto.pais[j]==' '){
						espaco = j; 
						f1[index].piloto.pais[espaco+1] = toupper(f1[index].piloto.pais[espaco+1]);
					}
				}
				
				valido=0;
				
				while(fscanf(arq,"%s",arqPaises)!=EOF){
					if(strcmp(arqPaises, f1[index].piloto.pais)==0){
						valido=1;
						printf("País Aceito!\n\n");
						break;
					}	
				}
		
				if(valido==0){
					printf("País Inexistente!\n");
				}
		}
		fclose(arq);
	}while(tam<1 || tam>45 || valido==0);
}


void le_valida_sexoPiloto(struct MelhorVolta f1[], int index){
	
	do{
		fflush(stdin);
		printf("Sexo(M/F):");
		scanf("%c",&f1[index].piloto.sexo);
		fflush(stdin);
		
		f1[index].piloto.sexo = toupper(f1[index].piloto.sexo);
		
		if(f1[index].piloto.sexo!='M' && f1[index].piloto.sexo!='F'){
			printf("(M/F)!\n");
		}
	}while(f1[index].piloto.sexo!='M' && f1[index].piloto.sexo!='F');
}

void le_valida_codigoCircuito(struct MelhorVolta f1[], int index){
	
		f1[index].circuito.codigo=index+1;//o codigo vai ser 
		printf("Codigo do circuito:%d",f1[index].circuito.codigo);	
}

void le_valida_nomeCircuito(struct MelhorVolta f1[], int index){
	
	int tam=0;
	
	do{
		fflush(stdin);
		printf("\nNome do circuito:");
		scanf("%[^\n]s",&f1[index].circuito.nome);
		
		tam=strlen(f1[index].circuito.nome);
		
		if(tam>200){
			printf("Muito grande!(<200)\n");
		}else if(tam<1){
					printf("O nome não pode ser nulo!(>5)\n");
				}
	}while(tam>200|| tam<1);
}

void le_valida_tamCircuito(struct MelhorVolta f1[], int index){
	
	do{
		fflush(stdin);
		printf("\nTamanho do circuito(Km):");
		scanf("%f",&f1[index].circuito.tamanho);
		if(f1[index].circuito.tamanho>10){
			printf("Muito grande!(<10)\n");
		}else if(f1[index].circuito.tamanho<5){
					printf("\nMuito pequeno!(>5)\n");
				}
	}while(f1[index].circuito.tamanho <5 || f1[index].circuito.tamanho>10);
}

void le_valida_paisCircuito(struct MelhorVolta f1[], int index){
	
	int tam, espaco, j=0, valido=0;
	char arqPaises[200][50];
	
	do{
		FILE *arq;
		
		arq = fopen("PaisesCircuito.txt", "r");
		
		if(arq == NULL){
			printf("Erro ao abrir o arquivo!");
		}else{
				printf("\nPaises aceitos:\n");
				while(fscanf(arq,"%s",arqPaises)!=EOF){
					printf("%s\n", arqPaises);
				
				}
				fflush(stdin);
				printf("\nPaís do circuito:");
				scanf("%[^\n]s",&f1[index].circuito.pais);
				
				tam=strlen(f1[index].circuito.pais);
				
				for(j; j<tam;j++){
					f1[index].circuito.pais[j] = tolower(f1[index].circuito.pais[j]);
				}
					
				f1[index].circuito.pais[0] = toupper(f1[index].circuito.pais[0]);
				for(j=0; j<tam; j++){
					if(f1[index].circuito.pais[j]==' '){
						espaco = j; 
						f1[index].circuito.pais[espaco+1] = toupper(f1[index].circuito.pais[espaco+1]);
					}
				}
				
				valido=0;
				
				while(fscanf(arq,"%s",arqPaises)!=EOF){
					if(strcmp(arqPaises, f1[index].circuito.pais)==0){
						valido=1;
						printf("País Aceito!\n\n");
						break;
					}	
				}
		
				if(valido==0){
					printf("País Inexistente!\n");
				}
				

				
		}
		fclose(arq);
	}while(tam<1 || tam>45 || valido==0);
}

void le_valida_menorTempoCircuito(struct MelhorVolta f1[], int index, int cont1){
	
	int f=0, auxId=0, a=0;
	double menorT=0;
	do{
		printf("\nMelhor volta do circuito(0.00.000):");
		scanf("%lf",&f1[index].circuito.tempo);
		fflush(stdin);
		printf("\n%lf", f1[index].circuito.tempo);
		printf("\nIdentificação do piloto:");
		scanf("%d",&auxId);
		
		for(f; f<cont1; f++){
			if(auxId == f1[f].piloto.idPiloto){
				printf("\nPiloto:%s", f1[f].piloto.nome);
				a=1;
			}
		}
		
		if(a==0){
			printf("\nId inexistente!");
		}
		
		f=0;
		
		for(f; f<index; f++){
			if(f==0){
				menorT=f1[index].circuito.tempo;
			}else if(f1[index].circuito.tempo<menorT){
					menorT=f1[index].circuito.tempo;
				}
		}
		
		f1[index].circuito.menorTempo=menorT;
		printf("\n%.5lf", f1[index].circuito.menorTempo);
		
	}while(f1[index].circuito.tempo <1 || f1[index].circuito.tempo>10);
}











