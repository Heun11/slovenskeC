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
#define kratke short
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

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

cislo zaciatok()
{
	cislo a = 12;
	cislo b = 1;

	ak(a>b){
		vypis("a je vacsie ako b\n");
	}
	alebo(b<a){
		vypis("b je vacsie ako b\n");
	}
	inak{
		vypis("b je rovne a\n");
	}

	vypis("Slovencina je super %.2f\n", PI);
	vrat 0;
}
