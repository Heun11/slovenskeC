# Slovenské C
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

## Ako ?:

### (linux/mac):
- stiahnite si súbor `slovencina`
- spustite `./slovencina test.sjl`
- spustite `./main`    

### (windows):
- neviem, dako cez MINGW skompilovat main.c

### Cesta Štúra:

    „Naspäť cesta nemožná, napred sa ísť musí.“