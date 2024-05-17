# Slovenské č
Projekt Translatora z našej (Slovenskej) verzie C do pôvodnej C formy a následne skompilovaný do exe (pochytil ma Štúrovský prejav o VLASTNOM JAZYKU)

## Príklad 1:
    #zahrn<stdio.h>
    #zahrn<stdlib.h>

    #definuj PI 3.14

    cislo zaciatok()
    {
        vypis("Slovencina je super %.2f\n", PI);
        vrat 0;
    }

## Príklad 2:
    #zahrn<stdio.h>
    #zahrn<stdlib.h>

    #definuj PI 3.14

    cislo zaciatok()
    {
        cislo a = 12;
        cislo b = 1;

        pismeno veta[40] = "Slovencina je cool!";
        
        prepinac(a)
        {
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

## Ako ?:

### (linux):
- skompilujte si súbor main.c na slovencina (potrebujete len GCC)
- spustite `./slovencina test.sjl test`
- spustite `./test  `    

### (windows):
- neviem, dako cez MINGW skompilovat main.c

### Cesta Štúra:

    „Naspäť cesta nemožná, napred sa ísť musí.“

### Klúčové slová Slovenského C
    zaciatok              main      začiatok
    vypis                 printf    výpis
    vrat                  return    vráť
    cislo                 int       číslo
    pismeno               char      písmeno
    one                   void      oné
    konstanta             const     konštanta
    desatinne_cislo       float     desatinné číslo
    velke_desatinne_cislo double    veľké desatinné číslo
    velke                 long      veľké
    male                  short     malé
    struktura             struct    štruktúra
    typova_definicia      typedef   typová definícia
    ser_na_to             break     ser na to
    pokracuj              continue  pokračuj
    ak                    if        ak
    alebo                 else if   alebo
    inak                  else      inak
    pre                   for       pre
    pokial                while     pokiaľ
    prepinac              switch    prepínač
    pripad                case      prípad
    klasicky              default   klasicky
    vycet                 enum      výčet
    extrahuj              extern    extrahuj
    chod_na               goto      choď na
    riadkova              inline    riadková
    registruj             register  registruj
    obmedz                restrict  obmedz
    znamienkove           signed    znamienkové
    bezznamienkove        unsigned  bezznamienkové
    velkost_tohto         sizeof    veľkosť tohto
    staticke              static    statické
    zvaz                  union     zväz
    nestala               volatile  nestála

### Predprocesorové direktíva Slovenského C (zatiaľ)
    #zahrn             #include zahrň
    #definuj           #define  definuj
    #ak                #if      ak
    #importuj          #import  importuj
    #alebo             #elif    alebo
    #inak              #else    inak
    #ak_koniec         #endif   ak koniec
    #chyba             #error   chyba
    #ak_definovane     #ifdef   ak definované
    #ak_nie_definovane #ifndef  ak nie definované
    #ciara             #line    čiara
    #oddefinuj         #undef   oddefinuj
    #pouzivam          #using   používam
