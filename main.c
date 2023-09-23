#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char defines[] = "#define zaciatok main\n#define cislo int\n#define one void";

char* translate(const char* filename)
{
	FILE* fp;
	char c;
	int sz;

	fp = fopen(filename, "r");
	if(NULL==fp){
		printf("file can't be opened\n");
		return NULL;
	}

	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	char* code = malloc((sz+1)*sizeof(char));
	char* codeNew = malloc((sz+1)*sizeof(char));
	int codeI = 0;
	int codeINew = 0;

	while(c!=EOF){
		c = fgetc(fp);
		code[codeI]=c;
		codeI++;
	}
	code[codeI] = '\0';
	codeI++;

	// code je cely kod, teraz potrebujem dostat list tokenov
	
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

			for(int j=lastI;j<startI;j++){
				codeNew[codeINew] = code[j];
				codeINew++;
			}
			if(strcmp(buff, "#zahrn")==0){
				char def[] = "#include";
				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
			if(strcmp(buff, "#definuj")==0){
				char def[] = "#define";
				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}


			lastI = konecI;
		}

		i++;
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
		printf("%s", c);
	}
	else{
		printf("nedal si kod alebo si ich dal az moc\n");
	}

	return 0;
}
