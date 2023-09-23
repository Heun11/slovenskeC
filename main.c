#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void write_to_file(const char* filename, const char* code)
{
	FILE* fp;
	fp = fopen(filename, "w");
	if(NULL==fp){
		printf("file can't be open\n");
		return;
	}

	fprintf(fp,"%s",code);
	fclose(fp);
}

char* translate(const char* filename)
{
	FILE* fp;
	char c;
	int sz;
	char defines[] = "#define zaciatok main\n"
			"#define vypis printf\n"
			"#define vrat return\n"
			"#define cislo int\n"
			"#define pismeno char\n"
			"#define one void\n\n";
	int defines_len = sizeof(defines)/sizeof(char);

	fp = fopen(filename, "r");
	if(NULL==fp){
		printf("file can't be opened\n");
		return NULL;
	}

	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char* code = (char*)malloc((sz+1)*sizeof(char));
	int maxSize = (sz+defines_len+1)*sizeof(char);
	char* codeNew = (char*)malloc(maxSize+1);
	int codeI = 0;
	int codeINew = 0;

	while(c!=EOF){
		c = fgetc(fp);
		code[codeI]=c;
		codeI++;
	}
	code[codeI] = '\0';
	codeI++;
	fclose(fp);

	for(int i=0;i<defines_len-1;i++){
		codeNew[codeINew] = defines[i];
		codeINew++;
	}
	codeNew[codeINew] = '\0';
	
	char* buff = malloc(32*sizeof(char));
	int buffI = 0;

	int startI = 0;
	int konecI = 0;
	int lastI = 0;

	int i = 0;
	while(i<codeI){
		if(code[i]=='#'){
			buffI = 0;
			buff[buffI] = code[i];
			buffI++;
			startI = i;
			i++;

			while(((code[i]>=65 && code[i<=90])
			||(code[i]>=97 && code[i]<=122))){
				buff[buffI] = code[i];
				buffI++;
				i++;
			}
			buff[buffI] = '\0';
			buffI++;
			konecI = i;

			if(maxSize-codeINew<=startI-lastI){
				maxSize+=startI-lastI+1;
				codeNew = realloc(codeNew, maxSize);
			}
			for(int j=lastI;j<startI;j++){
				codeNew[codeINew] = code[j];
				codeINew++;
			}
			if(strcmp(buff, "#zahrn")==0){
				char def[] = "#include";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}
				for(int j=0;j<(sizeof(def)/sizeof(char))-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
			if(strcmp(buff, "#definuj")==0){
				char def[] = "#define";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}


			lastI = konecI;
		}

		i++;
	}

	if(maxSize-codeINew<=codeI-lastI){
		maxSize+=(codeI-lastI)*sizeof(char);
		codeNew = realloc(codeNew, maxSize);
	}

	for(int i=lastI;i<codeI-2;i++){
		codeNew[codeINew] = code[i];
		codeINew++;
	}

	codeNew[codeINew] = '\0';
	return codeNew;
}

int main(int argc, char** argv)
{
	if(argc>1 && argc<3){
		char* c = translate(argv[1]);
		//printf("%s\n", c);
		write_to_file("slovenskyPreklad.c", c);
		system("gcc slovenskyPreklad.c -o main");
	}
	else{
		printf("nedal si kod alebo si ich dal az moc\n");
	}

	return 0;
}
