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
			"#define one void\n"
			"#define konstanta const\n"
			"#define desatinne_cislo float\n"
			"#define velke_desatinne_cislo double\n"
			"#define velke long\n"
			"#define male short\n"
			"#define struktura struct\n"
			"#define typova_definicia typedef\n"
			"#define ser_na_to break\n"
			"#define pokracuj continue\n"
			"#define ak if\n"
			"#define alebo else if\n"
			"#define inak else\n"
			"#define pismeno char\n"
			"#define pre for\n"
			"#define pokial while\n"
			"#define prepinac switch\n"
			"#define pripad case\n"
			"#define klasicky default\n"
			"#define vycet enum\n"
			"#define extrahuj extern\n"
			"#define chod_na goto\n"
			"#define riadkova inline\n"
			"#define chod_na goto\n"
			"#define registruj register\n"
			"#define obmedz restrict\n"
			"#define znamienkove signed\n"
			"#define bezznamienkove unsigned\n"
			"#define velkost_tohto sizeof\n"
			"#define staticke static\n"
			"#define zvaz union\n"
			"#define nestala volatile\n"
			"\n";
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
      if(strcmp(buff, "#importuj")==0){
				char def[] = "#import";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}
				for(int j=0;j<(sizeof(def)/sizeof(char))-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#ak")==0){
				char def[] = "#if";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#alebo")==0){
				char def[] = "#elif";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#inak")==0){
				char def[] = "#else";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#ak_koniec")==0){
				char def[] = "#endif";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#chyba")==0){
				char def[] = "#error";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#ak_definovane")==0){
				char def[] = "#ifdef";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#ak_nie_definovane")==0){
				char def[] = "#ifndef";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#ciara")==0){
				char def[] = "#line";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#oddefinuj")==0){
				char def[] = "#undef";
				if(maxSize-codeINew<=sizeof(def)/sizeof(char)){
					maxSize+=sizeof(def)/sizeof(char)+1;
					codeNew = realloc(codeNew, maxSize);
				}

				for(int j=0;j<sizeof(def)-1;j++){
					codeNew[codeINew] = def[j];
					codeINew++;
				}
			}
      if(strcmp(buff, "#pouzivam")==0){
				char def[] = "#using";
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
	if(argc>1 && argc<4){
		char* c = translate(argv[1]);
		char* com = malloc(sizeof(char)*(sizeof(argv[2])/sizeof(char)+48));
		write_to_file("slovenskyPreklad.c", c);
		sprintf(com, "gcc slovenskyPreklad.c -o %s", argv[2]);
		system(com);
		free(com);
		free(c);
	}
	else{
		printf("nedal si parametre alebo si ich dal az moc\nTreba dat \"./slovencina nazov.sjl nazov\"\n");
	}

	return 0;
}
