#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define blue "\x1b[34m"
#define yel "\x1b[33m"
#define cyan "\x1b[36m"
#define cls   "\x1b[0m"
#define white "\x1b[37m"
#define magenta "\x1b[95m"
#define gren "\x1b[92m"
#define  arquivo "db.k"

int main(int argc, char const *argv[])
{
	/*variaveis*/

	char aux[20]; int opt=0;char l[1];
	FILE *PA;
	PA = fopen(arquivo,"rb+");if(PA == NULL){fopen(arquivo,"wb+");}

	/*funções*/

	void create(){strcat(argv[2],".k");PA = fopen(argv[2],"wb+");}

	void open(){printf("\nkey:%s",argv[2]);strcat(argv[2],".k");PA = fopen(argv[2],"rb+");rewind(PA);
	printf("\tvalues: ");
	while(!feof(PA)){fread(&l,sizeof(char)*1,1,PA);printf("%s",l);}printf("\n");}

	/*void query(){strcat(argv[2],".k");PA = fopen(argv[2],"rb+");rewind(PA);
	int q=0,n;
	n = strlen(argv[3]);
	for(int y = 0; y < n; y++){
	while(!feof(PA)){
		fread(&l,sizeof(char)*1,1,PA);
		if(strcmp(l,argv[3][0])==0){char aux[n];fread(&aux[n-1],sizeof(aux),1,PA)
		if(strcmp(aux,))}
	}
}
}*/

	void write(){
	int y = atoi(argv[3]);
	/*int b = atoi(argv[4]);*/
	strcat(argv[2],".k");PA = fopen(argv[2],"wb+");rewind(PA);
	for(int i = 5; i < y+5; i++){
		int w = strlen(argv[i]);
		char aux[w];
		strcpy(aux,argv[i]);
		strcat(aux,"|");
		fwrite(&aux,sizeof(aux)+2,1,PA);
		/*printf("\n\t%s",argv[i]);*/
	}
}

void add(){
int y = atoi(argv[3]);
/*int b = atoi(argv[4]);*/
strcat(argv[2],".k");PA = fopen(argv[2],"ab+");fseek(PA,0,SEEK_END);
for(int i = 5; i < y+5; i++){
	int w = strlen(argv[i]);
	char aux[w];
	strcpy(aux,argv[i]);
	strcat(aux,"|");
	fwrite(&aux,sizeof(aux)+2,1,PA);
	/*printf("\n\t%s",argv[i]);*/
}
}


	void help(){printf(magenta "\n\t:________________:Cdict:_______________:\n" cls);
	printf(cyan "\n\tSumary: " cls);printf(cyan"\n\t01:"cls);printf(white"[./cdict -c name]for create key."cls);
		printf(cyan"\n\t02:"cls);printf(white"[./cdict -r name]for read key.");
		printf(cyan"\n\t03:"cls);printf(white"[./cdict -a name]for append values in key.");
		printf(cyan"\n\t04:"cls);printf(white"[./cdict -w name i j values]\n\t"cls);printf(yel"*note: [i/j] reference of matrix index.\n"cls);
		printf(cyan "\n\t_________________________________________" cls);
		printf(gren"\n\t https://github.com/Kaiofprates " cls);
		printf(cyan"\n\t________dev_Kaio_F_prates__5-18__________\n\n" cls);

	}

	/*menu*/

if(strcmp(argv[1],"-c")==0){opt=1;}
if(strcmp(argv[1],"-r")==0){opt=2;}
if(strcmp(argv[1],"--h")==0){opt=3;}
if(strcmp(argv[1],"-w")==0){opt=4;}
if(strcmp(argv[1],"-a")==0){opt=5;}

switch(opt){

	case 1:
	create();
	break;

	case 2:
	open();
	break;

	case 3:
	help();

	case 4:
	write();
	break;
	case 5:
	add();
	break;

}
fclose(PA);
	return 0;
}
