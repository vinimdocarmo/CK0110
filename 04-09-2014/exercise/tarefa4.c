#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda {
	char name[100];
	int id; // Matrícula
	int ddd;
	int phone;
 	char type;	
 	int empty; //0 se a posição estiver ocupada, 1 se ela estiver vazia
} typedef TipoAgenda;

void print_menu();
void print_contact(TipoAgenda agenda);
char chose_menu_option();

void list_names();
void search_phone_by_name(char name[]);
void remove_contact(char name[]);
void insert_contact(TipoAgenda agenda);

#define MAXNOME 100
#define MAXREGISTROS 1000

TipoAgenda agenda[MAXREGISTROS];
int number_of_contacts;

int main(int argn, char *argc[]) {
	
	int i = 0;
	char option, name[MAXNOME];
	FILE *file = fopen(argc[1], "r");
	TipoAgenda insertable_agenda;

	if(argc[1] != NULL) {
		while(!feof(file)) {
			fscanf(file, "%s\n",    agenda[i].name);
			fscanf(file, "%d\n",   &agenda[i].id);
			fscanf(file, "%d\n",   &agenda[i].ddd);
			fscanf(file, "%d\n",   &agenda[i].phone);
			fscanf(file, "%c\n",   &agenda[i].type);
			agenda[i].empty = 0;
			i++;
			number_of_contacts++;
		}

		fclose(file);
	}

	while(1) {
		print_menu();
		
		option = chose_menu_option();

		switch(option) {
			case 'B':
			case 'b':				
				printf("\n\t[+] Digite o nome do contato: ");
				scanf(" %s", name);

				search_phone_by_name(name);
				break;
			case 'I':
			case 'i':
				printf("\n\t[+] Digite o nome do contato: \t");
				scanf(" %s", insertable_agenda.name);
				printf("\n\t[+] Digite a matrícula do contato: \t");
				scanf(" %d", &insertable_agenda.id);
				printf("\n\t[+] Digite o DDD do contato: \t");
				scanf(" %d", &insertable_agenda.ddd);
				printf("\n\t[+] Digite o telefone do contato: \t");
				scanf(" %d", &insertable_agenda.phone);
				printf("\n\t[+] Digite o tipo do telefone: \t");
				scanf(" %c", &insertable_agenda.type);
				insertable_agenda.empty = 0;

				insert_contact(insertable_agenda);
				break;
			case 'A':
			case 'a':	
				printf("\n\t[+] Digite o nome do contato: ");
				scanf(" %s", name);

				remove_contact(name);
				break;
			case 'L':
			case 'l':
				list_names();
				break;
			case 'S':
			case 's':
				puts("\n\tBye!");
				return EXIT_SUCCESS;
			default:
				puts("\n\t[+] Opção incorreta! Tente novamente.");
		}
	}

	return EXIT_SUCCESS;
}

void print_menu() {
	puts("\n\t############## MENU ##############");
	puts("\t# \t\t\t\t #");
	puts("\t# B) Buscar telefone pelo nome\t #");
	puts("\t# I) Inserir novo registro\t #");
	puts("\t# A) Apagar registro pelo nome\t #");
	puts("\t# L) Listar nomes na agenda\t #");
	puts("\t# S) Sair\t\t\t #");
	puts("\t# \t\t\t\t #");
	puts("\t##################################");
	printf("\n\t[+] Esconha uma das opções acima: ");
}

void print_contact(TipoAgenda agenda) {
	printf("\n\t_____________________________\n");
	printf("\n\t Nome: %s\n", agenda.name);
	printf("\n\t Matrícula: %d\n", agenda.id);
	printf("\n\t DDD: %d\n", agenda.ddd);
	printf("\n\t Telefone: %d\n", agenda.phone);
	printf("\n\t Tipo: %c\n", agenda.type);
}

char chose_menu_option() {
	char option;

	scanf(" %s", &option);

	return option;
}

void list_names() {
	int i;
	
	if(number_of_contacts == 0) {
		printf("\n\t[+] Lista vazia.\n");
		return;
	}

	for(i = 0; i < number_of_contacts; i++) {
		if(agenda[i].empty == 0)
			print_contact(agenda[i]);
	}
}

void search_phone_by_name(char name[]) {
	int i;
	char *phone_type;

	for(i = 0; i < number_of_contacts; i++) {
		if(strcmp(agenda[i].name, name) == 0) {
			if(agenda[i].type == 'C')
				phone_type = "Celular";
			else if(agenda[i].type == 'F')
				phone_type = "Fixo";
			
			printf("\n\t_____________________________\n");
			printf("\n\t%s (%d)%d (%s)\n", agenda[i].name, agenda[i].ddd, agenda[i].phone, phone_type);
			return;
		}
	}
	printf("\n\t[+] Contato não encontrado.\n");
}

void remove_contact(char name[]) {
	int i;

	for (i = 0; i < number_of_contacts; ++i) {
		if(strcmp(agenda[i].name, name) == 0) {
			strcpy(agenda[i].name, "");
			agenda[i].id = 0;
			agenda[i].ddd = 0;
			agenda[i].phone = 0;
			agenda[i].type = ' ';
			agenda[i].empty = 1;

			printf("\n\t[+] Contato removido.\n");
			return;
		}	
	}
	printf("\n\t[+] Contato não encontrado.\n");
}

void insert_contact(TipoAgenda insertable_agenda) {
	int i, pos = 0;

	for(i = 0; i < number_of_contacts; ++i) {
		if(agenda[i].empty == 1) {
			pos = i;
			break;
		}
		pos = number_of_contacts;
	}

	strcpy(agenda[pos].name, insertable_agenda.name);
	agenda[pos].id    = insertable_agenda.id;
	agenda[pos].ddd   = insertable_agenda.ddd;
	agenda[pos].phone = insertable_agenda.phone;
	agenda[pos].type  = toupper(insertable_agenda.type);
	agenda[pos].empty = insertable_agenda.empty;

	if(pos == number_of_contacts)
		number_of_contacts++;

	printf("\n\t[+] Contato inserido com sucesso.\n");
}