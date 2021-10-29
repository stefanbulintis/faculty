#include <iostream>
#include <string>

using namespace std;

class Persoana
{
    string nume, prenume;
    unsigned int varsta;
public:
    Persoana(){}
    Persoana(string nume, string prenume, unsigned int varsta)
    {
        this -> nume = nume;
        this -> prenume = prenume;
        this -> varsta = varsta;
    }

    virtual void afisare()
    {
        cout << "\nNume: " << nume << endl;
        cout << "Prenume: " << prenume << endl;
        cout << "Varsta: " << varsta << endl;
    }

    virtual string getNume()
    {
        return this -> nume;
    }
};

class Angajat : public Persoana
{
    unsigned int salariu, vechime;
public:
    Angajat(){}
    Angajat(string nume, string prenume, unsigned int varsta, unsigned int salariu, unsigned int vechime) : Persoana(nume, prenume, varsta)
    {
        this -> salariu = salariu;
        this -> vechime = vechime;
    }

    virtual void afisare()
    {
        Persoana::afisare();
        cout << "Vechime: " << vechime << endl;
        cout << "Salariu: " << salariu << endl;
    }
};

class Student : public Persoana
{
    string departament, facultate;
    unsigned int an;
public:
    Student(){}
    Student(string nume, string prenume, unsigned int varsta, string departament, string facultate, unsigned int an) : Persoana(nume, prenume, varsta)
    {
        this -> departament = departament;
        this -> facultate = facultate;
        this -> an = an;
    }

    virtual void afisare()
    {
        Persoana::afisare();
        cout << "Facultate: " << facultate << endl;
        cout << "Departament: " << departament << endl;
    }
};

class Profesor : public Angajat
{
    string materie, grad_invatamant;
public:
    Profesor(){}
    Profesor(string nume, string prenume, unsigned int varsta, unsigned int salariu, unsigned int vechime, string materie, string grad_invatamant) : Angajat(nume, prenume, varsta, salariu, vechime)
    {
        this -> materie = materie;
        this -> grad_invatamant = grad_invatamant;
    }

    virtual void afisare()
    {
        Angajat::afisare();
        cout << "Materia predata: " << materie << endl;
        cout << "Gradul de invatamant: " << grad_invatamant << endl << endl;
    }
};

class Inginer : public Angajat
{
    string firma, tip;
public:
    Inginer(){}
    Inginer(string nume, string prenume, unsigned int varsta, unsigned int salariu, unsigned int vechime, string firma, string tip) : Angajat(nume, prenume, varsta, salariu, vechime)
    {
        this -> firma = firma;
        this -> tip = tip;
    }

    virtual void afisare()
    {
        Angajat::afisare();
        cout << "Firma la care lucreaza: " << firma << endl;
        cout << "Tipul de inginer: " << tip << endl << endl;
    }
};

class Licenta : public Student
{
    double nota_bac;
public:
    Licenta(){}
    Licenta(string nume, string prenume, unsigned int varsta, string departament, string facultate, unsigned int an, double nota_bac) : Student(nume, prenume, varsta, departament, facultate, an)
    {
        this -> nota_bac = nota_bac;
    }

    virtual void afisare()
    {
        Student::afisare();
        cout << "Nota de la bacalaureat: " << nota_bac << endl << endl;
    }
};

class Master : public Student
{
    string tema_licenta;
    double nota_licenta;
public:
    Master(){}
    Master(string nume, string prenume, unsigned int varsta, string departament, string facultate, unsigned int an, string tema_licenta, double nota_licenta) : Student(nume, prenume, varsta, departament, facultate, an)
    {
        this -> tema_licenta = tema_licenta;
        this -> nota_licenta = nota_licenta;
    }

    virtual void afisare()
    {
        Student::afisare();
        cout << "Tema licentei a fost: " << tema_licenta << endl;
        cout << "Nota licentei a fost: " << nota_licenta << endl << endl;
    }
};

class Doctorand : public Student
{
    string proiect_master;
    double nota_master;
public:
    Doctorand(){}
    Doctorand(string nume, string prenume, unsigned int varsta, string departament, string facultate, unsigned int an, string proiect_master, double nota_master) : Student(nume, prenume, varsta, departament, facultate, an)
    {
        this -> proiect_master = proiect_master;
        this -> nota_master = nota_master;
    }

    virtual void afisare()
    {
        Student::afisare();
        cout << "Proiectul de la master a fost: " << proiect_master << endl;
        cout << "Nota de la master a fost: " << nota_master << endl << endl;
    }
};

int main()
{
    int opt;

    Profesor lista_profesori[50];
    Inginer lista_ingineri[50];
    Licenta lista_licenta[50];
    Doctorand lista_doctoranzi[50];
    Master lista_masteranzi[50];

    int nr_profesori = 0;
    int nr_ingineri = 0;
    int nr_licenta = 0;
    int nr_doctoranzi = 0;
    int nr_masteranzi = 0;

    string nume_cautat;
    string nume_sters;

    string nume_profesor, prenume_profesor, materie_profesor, grad_invatamant_profesor;
    unsigned int varsta_profesor, salariu_profesor, vechime_profesor;

    string nume_inginer, prenume_inginer, firma_inginer, tip_inginer;
    unsigned int varsta_inginer, salariu_inginer, vechime_inginer;

    string nume_licentiat, prenume_licentiat, departament_licentiat, facultate_licentiat;
    unsigned int varsta_licentiat, an_licentiat;
    double nota_bac_licentiat;

    string nume_masterand, prenume_masterand, departament_masterand, facultate_masterand, tema_licenta_masterand;
    unsigned int an_masterand, varsta_masterand;
    double nota_licenta_masterand;

    string nume_doctorand, prenume_doctorand, departament_doctorand, facultate_doctorand, proiect_master_doctorand;
    unsigned int varsta_doctorand, an_doctorand;
    double nota_master_doctorand;

    cout << "\n##################------------------#############\n\nPress ENTER to continue\n";
    cin.ignore();
    do
    {
        cout << "\n1. Introducere date intr-un vector" << endl;
        cout << "2. Afisare anumita lista" << endl;
        cout << "3. Cautare in anumita lista" << endl;
        cout << "4. Stergere din anumita lista" << endl;
        cout << "0. Iesire" << endl << endl;
        cout << "\nAlegeti optiunea: ";

        cin >> opt;


        switch(opt)
        {
            case 1:
                char lista_aleasa;

                cout << "Lista optiuni:" << endl;
                cout << "a) Profesor" << endl;
                cout << "b) Inginer" << endl;
                cout << "c) Student la licenta" << endl;
                cout << "d) Masterand" << endl;
                cout << "e) Doctorand" << endl;

                do {
                    cout << "\nCe doriti sa adaugati?" << endl;
                    cin >> lista_aleasa;
                }while(lista_aleasa < 'a' || lista_aleasa > 'e');

                switch(lista_aleasa)
                {
                    case 'a':

                        fflush(stdin);
                        cout << "\nIntroduceti numele profesorului: ";
                        getline(cin, nume_profesor);

                        fflush(stdin);
                        cout << "Introduceti prenumele profesorului: ";
                        getline(cin, prenume_profesor);

                        cout << "Introduceti varsta profesorului: ";
                        cin >> varsta_profesor;

                        fflush(stdin);
                        cout << "Introduceti materia predata de profesor: ";
                        getline(cin, materie_profesor);

                        fflush(stdin);
                        cout << "Introduceti gradul de invatamant al profesorului: ";
                        getline(cin, grad_invatamant_profesor);

                        cout << "Introduceti salariul profesorului: ";
                        cin >> salariu_profesor;

                        cout << "Introduceti vechimea profesorului: ";
                        cin >> vechime_profesor;

                        lista_profesori[nr_profesori++] = Profesor(nume_profesor, prenume_profesor, varsta_profesor, salariu_profesor, vechime_profesor, materie_profesor, grad_invatamant_profesor);

                        break;

                    case 'b':

                        fflush(stdin);
                        cout << "\nIntroduceti numele inginerului: ";
                        getline(cin, nume_inginer);

                        fflush(stdin);
                        cout << "Introduceti prenumele inginerului: ";
                        getline(cin, prenume_inginer);

                        cout << "Introduceti varsta inginerului: ";
                        cin >> varsta_inginer;

                        fflush(stdin);
                        cout << "Introduceti tipul de inginer: ";
                        getline(cin, tip_inginer);

                        fflush(stdin);
                        cout << "Introduceti firma la care lucreaza inginerul: ";
                        getline(cin, firma_inginer);

                        cout << "Introduceti salariul inginerului: ";
                        cin >> salariu_inginer;

                        cout << "Introduceti vechimea inginerului: ";
                        cin >> vechime_inginer;

                        lista_ingineri[nr_ingineri++] = Inginer(nume_inginer, prenume_inginer, varsta_inginer, salariu_inginer, vechime_inginer, firma_inginer, tip_inginer);
                        break;

                    case 'c':

                        fflush(stdin);
                        cout << "\nIntroduceti numele studentului de la licenta: ";
                        getline(cin, nume_licentiat);

                        fflush(stdin);
                        cout << "Introduceti prenumele studentului de la licenta: ";
                        getline(cin, prenume_licentiat);

                        cout << "Introduceti varsta studentului de la licenta: ";
                        cin >> varsta_licentiat;

                        fflush(stdin);
                        cout << "Introduceti facultatea la care invata studentul: ";
                        getline(cin, facultate_licentiat);

                        fflush(stdin);
                        cout << "Introduceti departamentul la care e studentul: ";
                        getline(cin, departament_licentiat);

                        cout << "Introduceti anul in care este studentul: ";
                        cin >> an_licentiat;

                        cout << "Introduceti nota pe care a avut-o studentul la examenul de bacalaureat: ";
                        cin >> nota_bac_licentiat;

                        lista_licenta[nr_licenta++] = Licenta(nume_licentiat, prenume_licentiat, varsta_licentiat, departament_licentiat, facultate_licentiat, an_licentiat, nota_bac_licentiat);
                        break;

                    case 'd':

                        fflush(stdin);
                        cout << "\nIntroduceti numele masterandului: ";
                        getline(cin, nume_masterand);

                        fflush(stdin);
                        cout << "Introduceti prenumele masterandului: ";
                        getline(cin, prenume_masterand);

                        cout << "Introduceti varsta masterandului: ";
                        cin >> varsta_masterand;

                        fflush(stdin);
                        cout << "Introduceti facultatea la care invata masterandul: ";
                        getline(cin, facultate_masterand);

                        fflush(stdin);
                        cout << "Introduceti departamentul la care e masterandul: ";
                        getline(cin, departament_masterand);

                        cout << "Introduceti anul in care este masterandul: ";
                        cin >> an_masterand;

                        fflush(stdin);
                        cout << "Introduceti tema pe care a sustinut-o masterandul la lucrarea de licenta: ";
                        getline(cin, tema_licenta_masterand);

                        cout << "Introduceti nota pe care a avut-o masterandul la examenul de licenta: ";
                        cin >> nota_licenta_masterand;

                        lista_masteranzi[nr_masteranzi++] = Master(nume_masterand, prenume_masterand, varsta_masterand, departament_masterand, facultate_masterand, an_masterand, tema_licenta_masterand, nota_licenta_masterand);
                        break;

                    case 'e':

                        fflush(stdin);
                        cout << "\nIntroduceti numele doctorandului: ";
                        getline(cin, nume_doctorand);

                        fflush(stdin);
                        cout << "Introduceti prenumele doctorandului: ";
                        getline(cin, prenume_doctorand);

                        cout << "Introduceti varsta doctorandului: ";
                        cin >> varsta_doctorand;

                        fflush(stdin);
                        cout << "Introduceti facultatea la care invata docotorandul: ";
                        getline(cin, facultate_doctorand);

                        fflush(stdin);
                        cout << "Introduceti departamentul la care e doctorandul: ";
                        getline(cin, departament_doctorand);

                        cout << "Introduceti anul in care este doctorandul: ";
                        cin >> an_doctorand;

                        fflush(stdin);
                        cout << "Introduceti tema pe care a sustinut-o doctorandul la lucrarea de master: ";
                        getline(cin, proiect_master_doctorand);

                        cout << "Introduceti nota pe care a avut-o doctorandul la examenul de master: ";
                        cin >> nota_master_doctorand;

                        lista_doctoranzi[nr_doctoranzi++] = Doctorand(nume_doctorand, prenume_doctorand, varsta_doctorand, departament_doctorand, facultate_doctorand, an_doctorand, proiect_master_doctorand, nota_master_doctorand);
                        break;
                }
                break;

            case 2:
                cout << "Lista optiuni:" << endl;
                cout << "a) Profesor" << endl;
                cout << "b) Inginer" << endl;
                cout << "c) Student la licenta" << endl;
                cout << "d) Masterand" << endl;
                cout << "e) Doctorand" << endl;

                do {
                    cout << "\nCe doriti sa afisati?" << endl;
                    cin >> lista_aleasa;
                }while(lista_aleasa < 'a' || lista_aleasa > 'e');

                switch (lista_aleasa) {
                    case 'a':
                        for(int i=0; i<nr_profesori; i++)
                        {
                            lista_profesori[i].afisare();
                        }
                        break;

                    case 'b':
                        for(int i=0; i<nr_ingineri; i++)
                        {
                            lista_ingineri[i].afisare();
                        }
                        break;

                    case 'c':
                        for(int i=0; i<nr_licenta; i++)
                        {
                            lista_licenta[i].afisare();
                        }
                        break;

                    case 'd':
                        for(int i=0; i<nr_masteranzi; i++)
                        {
                            lista_masteranzi[i].afisare();
                        }
                        break;

                    case 'e':
                        for(int i=0; i<nr_doctoranzi; i++)
                        {
                            lista_doctoranzi[i].afisare();
                        }
                        break;
                }
                break;

            case 3:
                cout << "Lista optiuni:" << endl;
                cout << "a) Profesor" << endl;
                cout << "b) Inginer" << endl;
                cout << "c) Student la licenta" << endl;
                cout << "d) Masterand" << endl;
                cout << "e) Doctorand" << endl;

                do {
                    cout << "\nCe doriti sa cautati?" << endl;
                    cin >> lista_aleasa;
                }while(lista_aleasa < 'a' || lista_aleasa > 'e');

                switch (lista_aleasa) {
                    case 'a':
                        fflush(stdin);
                        cout << "Introduceti numele profesorului pe care il cautati: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_profesori; i++)
                        {
                            if(lista_profesori[i].getNume() == nume_cautat)
                            {
                                lista_profesori[i].afisare();
                            }
                        }
                        break;

                    case 'b':
                        fflush(stdin);
                        cout << "Introduceti numele inginerului pe care il cautati: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_ingineri; i++)
                        {
                            if(lista_ingineri[i].getNume() == nume_cautat)
                            {
                                lista_ingineri[i].afisare();
                            }
                        }
                        break;

                    case 'c':
                        fflush(stdin);
                        cout << "Introduceti numele studentului pe care il cautati: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_licenta; i++)
                        {
                            if(lista_licenta[i].getNume() == nume_cautat)
                            {
                                lista_licenta[i].afisare();
                            }
                        }
                        break;

                    case 'd':
                        fflush(stdin);
                        cout << "Introduceti numele masterandului pe care il cautati: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_masteranzi; i++)
                        {
                            if(lista_masteranzi[i].getNume() == nume_cautat)
                            {
                                lista_masteranzi[i].afisare();
                            }
                        }
                        break;

                    case 'e':
                        fflush(stdin);
                        cout << "Introduceti numele doctorandului pe care il cautati: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_doctoranzi; i++)
                        {
                            if(lista_doctoranzi[i].getNume() == nume_cautat)
                            {
                                lista_doctoranzi[i].afisare();
                            }
                        }
                        break;
                }

                break;

            case 4:
                cout << "Lista optiuni:" << endl;
                cout << "a) Profesor" << endl;
                cout << "b) Inginer" << endl;
                cout << "c) Student la licenta" << endl;
                cout << "d) Masterand" << endl;
                cout << "e) Doctorand" << endl;

                do {
                    cout << "\nCe doriti sa stergeti?" << endl;
                    cin >> lista_aleasa;
                }while(!(lista_aleasa >= 'a' || lista_aleasa <= 'e'));

                switch (lista_aleasa) {
                    case 'a':
                        fflush(stdin);
                        cout << "Introduceti numele profesorului pe care il stergeti: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_profesori; i++)
                        {
                            if(lista_profesori[i].getNume() == nume_cautat)
                            {
                                for(int j=i; j<nr_profesori - 1; j++)
                                {
                                    lista_profesori[j] = lista_profesori[j+1];
                                }
                                nr_profesori--;
                            }
                        }

                        for(int i=0; i<nr_profesori; i++)
                        {
                            lista_profesori[i].afisare();
                        }
                        break;

                    case 'b':
                        fflush(stdin);
                        cout << "Introduceti numele inginerului pe care il stergeti: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_ingineri; i++)
                        {
                            if(lista_ingineri[i].getNume() == nume_cautat)
                            {
                                for(int j=i; j<nr_ingineri - 1; j++)
                                {
                                    lista_ingineri[j] = lista_ingineri[j+1];
                                }
                                nr_ingineri--;
                            }
                        }

                        for(int i=0; i<nr_ingineri; i++)
                        {
                            lista_ingineri[i].afisare();
                        }
                        break;

                    case 'c':
                        fflush(stdin);
                        cout << "Introduceti numele studentului pe care doriti sa  il stergeti: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_licenta; i++)
                        {
                            if(lista_licenta[i].getNume() == nume_cautat)
                            {
                                for(int j=i; j<nr_licenta - 1; j++)
                                {
                                    lista_licenta[j] = lista_licenta[j+1];
                                }
                                nr_licenta--;
                            }
                        }

                        for(int i=0; i<nr_licenta; i++)
                        {
                            lista_licenta[i].afisare();
                        }
                        break;

                    case 'd':
                        fflush(stdin);
                        cout << "Introduceti numele masterandului pe care doriti sa  il stergeti: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_masteranzi; i++)
                        {
                            if(lista_masteranzi[i].getNume() == nume_cautat)
                            {
                                for(int j=i; j<nr_masteranzi - 1; j++)
                                {
                                    lista_masteranzi[j] = lista_masteranzi[j+1];
                                }
                                nr_masteranzi--;
                            }
                        }

                        for(int i=0; i<nr_masteranzi; i++)
                        {
                            lista_masteranzi[i].afisare();
                        }
                        break;

                    case 'e':
                        fflush(stdin);
                        cout << "Introduceti numele doctorandului pe care doriti sa  il stergeti: ";
                        getline(cin, nume_cautat);

                        for(int i=0; i<nr_doctoranzi; i++)
                        {
                            if(lista_doctoranzi[i].getNume() == nume_cautat)
                            {
                                for(int j=i; j<nr_doctoranzi - 1; j++)
                                {
                                    lista_doctoranzi[j] = lista_doctoranzi[j+1];
                                }
                                nr_doctoranzi--;
                            }
                        }

                        for(int i=0; i<nr_doctoranzi; i++)
                        {
                            lista_doctoranzi[i].afisare();
                        }
                        break;
                }
                break;

            case 0:
                exit(0);

            default:
                cout << "Optiunea aleasa de dumneavoastra nu exista!\n";
                break;
        }
    }while(opt!=0);

    return 0;
}
