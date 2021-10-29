#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functie pentru a verifica daca vectorul e sortat
int verificare_vector_sortat(double vector[], int lungime)
{
    for(int i=0; i<lungime-1; i++)
    {
        for(int j=i+1; j<lungime; j++)
        {
            //daca nu este sortat
            if(vector[i] > vector[j])
            {
                return 0;
            }
        }
    }

    //daca nu a intrat niciodata pe return 0 inseamna ca este sortat
    return 1;
}


int cautare_binara(double vector[], double stanga, double dreapta, double nr_cautat, double epsilon)
{
    int nr_pasi = 0;
    while(dreapta >= stanga)
    {
        //creste numarul de pasi la fiecare reluare in while
        nr_pasi++;

        //luam indicele de mijloc pentru verificare binara
        int mid = (stanga + dreapta) / 2;

        //daca este in interval
        if(vector[mid] >= nr_cautat - epsilon && vector[mid] <= nr_cautat + epsilon)
        {
            return nr_pasi;
        }

        //daca numarul cautat este mai mare decat media, se schimba limita inferioara a intervalului
        if(vector[mid] < nr_cautat)
        {
            stanga = mid + 1;
        }
        else //daca numarul cautat este mai mic decat media, se schimba limita superioara a intervalului
        {
            dreapta = mid - 1;
        }
    }

    //la fel ca la cautarea liniara
    return 0;
}

int cautare_liniara(double vector[], int lungime, double nr_cautat, double epsilon)
{
    int nr_pasi = 0;
    for(int i=0; i<lungime; i++)
    {
        nr_pasi++;
        if(vector[i] >= nr_cautat - epsilon && vector[i] <= nr_cautat + epsilon)
        {
            return nr_pasi;
        }
    }

    //nu intra niciodata aici pentru ca ultimul numar din fisier mereu o sa corespunds conditiei
    return 0;
}

int main() {
    FILE *input, *output;
    double vector_numere[50];
    unsigned int nr_numere;
    double epsilon;

    //verificam daca fisierul a fost creat
    if((input = fopen("INPUT.DAT", "rt"))==NULL)
    {
        printf("Fisierul nu exista");
        exit(1);
    }

    //verificam daca pe prima linie avem numar intreg pozitiv
    fscanf(input, "%d", &nr_numere);
    if(nr_numere < 0)
    {
        printf("Pe prima linie a fisierului trebuie sa fie numar intreg fara semn");
        exit(1);
    }

    //incarcam cele n numere intr-un vector pentru a fi mai usor de cautat
    for(int i=0; i<nr_numere; i++)
    {
        fscanf(input, "%lf", &vector_numere[i]);
    }

    //citire epsilon
    fscanf(input, "%lf", &epsilon);

    //inchidem fisierul deoarece nu mai avem nevoie de el
    fclose(input);

    //deschidem output.dat cu scopul de a scrie in el
    output = fopen("OUTPUT.DAT", "wt");

    //daca vectorul este sortat
    if(verificare_vector_sortat(vector_numere, nr_numere) == 1)
    {
        int nr_pasi = cautare_binara(vector_numere, 0, nr_numere - 1, vector_numere[nr_numere-1], epsilon);
        fprintf(output, "Metoda folosita este cautarea binara si numarul de pasi este: %d", nr_pasi);
    }
    else
    {
        int nr_pasi = cautare_liniara(vector_numere, nr_numere, vector_numere[nr_numere-1], epsilon);
        fprintf(output, "Metoda folosita este cautarea liniara si numarul de pasi este: %d", nr_pasi);
    }

    //inchidem fisierul de output
    fclose(output);

    printf("Verifica fisierul OUTPUT.DAT");

    return 0;
}
