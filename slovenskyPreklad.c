#define zaciatok main
#define vypis printf
#define vrat return
#define cislo int
#define pismeno char
#define one void
#define konstanta const
#define desatinne_cislo float
#define velke_desatinne_cislo double
#define velke long
#define male short
#define struktura struct
#define typova_definicia typedef
#define ser_na_to break
#define pokracuj continue
#define ak if
#define alebo else if
#define inak else
#define pismeno char
#define pre for
#define pokial while
#define prepinac switch
#define pripad case
#define klasicky default
#define vycet enum
#define extrahuj extern
#define chod_na goto
#define riadkova inline
#define chod_na goto
#define registruj register
#define obmedz restrict
#define znamienkove signed
#define bezznamienkove unsigned
#define velkost_tohto sizeof
#define staticke static
#define zvaz union
#define nestala volatile

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

cislo zaciatok()
{
	cislo a = 12;
	cislo b = 1;

  pismeno veta[40] = "Slovencina je cool!";
  
  prepinac(a){
    pripad 1:
      vypis("a je 1\n");
      ser_na_to;
    pripad 2:
      vypis("a je 2\n");
      ser_na_to;
    klasicky:
      vypis("neviem co je a\n");
      ser_na_to;
  }

	ak(a>b){
		vypis("a je vacsie ako b\n");
	}
	alebo(b<a){
		vypis("b je vacsie ako b\n");
	}
	inak{
		vypis("b je rovne a\n");
	}

	vypis("%s %.2f\n", veta, PI);
	vrat 0;
}
