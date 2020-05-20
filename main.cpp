#include <iostream>
#include <fstream>
#include <list>
#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include<vector>
#include<typeinfo>

using namespace std;

class Animal
{
protected:
    int greutate,nr_dinti;
    string nume;
public:
    Animal()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
    }
    Animal(const Animal &obj)
    {
        greutate = obj.greutate;
        nume = obj.nume;
        nr_dinti = obj.nr_dinti;
    }
    virtual ~Animal()=default;
    virtual void afisare ( )
    {
        cout << "Numele animalului este " << (this->nume) <<"." << endl<< "Greutatea animalului este  " ;
        cout << (this->greutate) << "." << endl << "Animalul are " << (this->nr_dinti) << " dinti. " << endl;
    }
    Animal& operator=(const Animal& ob)
    {
        this->nume = ob.nume;
        this->greutate = ob.greutate;
        this->nr_dinti = ob.nr_dinti;
        return *this;
    }
    friend istream &operator>>(istream &, Animal &);
    friend ostream &operator<<(ostream &, Animal &);
};
istream &operator >>(istream & in, Animal & obj)
{
    cout << "Introduceti:" << endl ;
    cout << "Numele animalului: ";
    in >> obj.nume;
    cout << "Greutatea animalului: ";
    in >> obj.greutate;
    cout << "Numarul de dinti: " ;
    in >> obj.nr_dinti;
    return in;
}
ostream &operator<<(ostream &out,Animal &obj)
{
    obj.afisare();
    return out;
}

class Nevertebrate:public Animal
{
public:
    Nevertebrate()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
    }
    Nevertebrate( const Nevertebrate &obj ): Animal(obj)
    {
    }
    friend istream&operator>>(istream&, Nevertebrate&);
    friend ostream&operator<<(ostream&, Nevertebrate&);
    virtual ~Nevertebrate()=default;
    virtual void afisare ()
    {
        Animal::afisare();
        cout << "Animalul este nevertebrat." << endl;
    }
};

ostream &operator<<(ostream &out,Nevertebrate &obj)
{
    obj.afisare();
    return out;
}

class Vertebrate:public Animal
{
protected:
    int nr_picioare;
public:
    Vertebrate()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
        nr_picioare = 0 ;
    }
    Vertebrate( const Vertebrate &obj ): Animal(obj)
    {
        nr_picioare = obj.nr_picioare;
    }
    friend istream&operator>>(istream&, Vertebrate&);
    friend ostream&operator<<(ostream&, Vertebrate&);
    virtual ~Vertebrate()=default;
    virtual void afisare ( )
    {
        Animal::afisare();
        cout << "Animalul are "<< nr_picioare <<" picioare." << endl;
        cout << "Animalul este vertebrat. "<< endl;
    }

};
istream &operator >>(istream & in, Vertebrate & obj)
{
    in >> dynamic_cast<Animal&>(obj);
    cout << "Numarul de picioare: " ;
    in >> obj.nr_picioare;
    return in;
}
ostream &operator<<(ostream &out, Vertebrate &obj)
{
    obj.afisare();
    return out;
}

class Pesti:public Vertebrate
{
private:
    bool tip; ///0-nerapitor, 1-rapitor
    int lungime;
public:
    Pesti()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
        nr_picioare = 0;
        lungime = 0;
        tip = -1;
    }
    Pesti& operator=(const Pesti& ob)
    {
        Animal::operator=(ob);
        this->tip = tip;
        this->lungime = lungime;
        return *this;
    }
    int Get_Lungime()
    {
        return lungime;
    }
    Pesti( const Pesti &obj ): Vertebrate(obj)
    {
        lungime = obj.lungime;
        tip = obj.tip;
    }
    double getLungime()
    {
        return lungime;
    }
    bool getTip()
    {
        return tip;
    }

    friend istream&operator>>(istream&, Pesti&);
    friend ostream&operator<<(ostream&, Pesti&);
    virtual ~Pesti()=default;
    virtual void afisare ()
    {
        Vertebrate::afisare();
        cout << "Animalul are " << (this->lungime) << " metri. " << endl;
        if(tip==0)
            cout << "Nu este peste rapitor." << endl;
        if(tip ==1)
            cout << "Este peste rapitor. " << endl;
    }
};
istream &operator >>(istream & in, Pesti & obj)
{
    in >> dynamic_cast<Vertebrate&>(obj);
    cout << "Lungimea animalului: ";
    in >> obj.lungime;
    cout << "Tipul animalului:(1-rapitor,0- nu e rapitor): ";
    in >> obj.tip;
    return in;
}
ostream &operator<<(ostream &out, Pesti &obj)
{
    obj.afisare();
    return out;
}

class Pasari: public Vertebrate
{
private:
    bool tip_zbor;///0-nu zboara, 1-zboara
public:
    Pasari()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
        nr_picioare = 0;
        tip_zbor = -1;
    }
    Pasari( const Pasari &obj ): Vertebrate(obj)
    {
        tip_zbor = obj.tip_zbor;
    }
    friend istream&operator>>(istream&, Pasari&);
    friend ostream&operator<<(ostream&, Pasari&);
    virtual ~Pasari()=default;
    Pasari& operator=(const Pasari& ob)
    {
        Animal::operator=(ob);
        this->tip_zbor = tip_zbor;
        return *this;
    }
    virtual void afisare ()
    {
        Vertebrate::afisare();
        cout << "Animalul ";
        if( tip_zbor==0)
            cout << "nu ";
        cout << "zboara. ";
        cout << endl;
    }
};
istream &operator >>(istream & in, Pasari & obj)
{
    in >> dynamic_cast<Vertebrate&>(obj);
    cout << "Tipul zborului (1-zboara,0-nu zboara): ";
    in >> obj.tip_zbor;
    return in;
}
ostream &operator<<(ostream &out, Pasari &obj)
{
    obj.afisare();
    return out;
}

class Mamifere: public Vertebrate
{
private:
    bool tip_mamifer;///0-face oua, 1-naste pui vii
public:
    Mamifere()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
        nr_picioare = 0;
        tip_mamifer = -1;
    }
    Mamifere( const Mamifere &obj ): Vertebrate(obj)
    {
        tip_mamifer = obj.tip_mamifer;
    }
    Mamifere& operator=(const Mamifere& ob)
    {
        Animal::operator=(ob);
        this->tip_mamifer = tip_mamifer;
        return *this;
    }
    friend istream&operator>>(istream&, Mamifere&);
    friend ostream&operator<<(ostream&, Mamifere&);
    virtual ~Mamifere()=default;
    virtual void afisare ()
    {
        Vertebrate::afisare();
        cout << "Animalul ";
        if( tip_mamifer==0)
            cout<<"fac oua. ";
        else
            cout << "naste pui vii. ";
        cout << endl;
    }

};
istream &operator >>(istream & in, Mamifere & obj)
{
    in >> dynamic_cast<Vertebrate&>(obj);
    cout << "Tipul mamiferului (1-naste pui vii,0-face oua): " ;
    in >> obj.tip_mamifer;
    return in;
}
ostream &operator<<(ostream &out, Mamifere &obj)
{
    obj.afisare();
    return out;
}
class Reptile: public Vertebrate
{
    string culoare;
public:
    Reptile()
    {
        greutate = 0;
        nr_dinti = 0;
        nume = "";
        nr_picioare = 0;
        culoare = "";
    }
    Reptile( const Reptile &obj ): Vertebrate(obj)
    {
        culoare = obj.culoare;
    }
    Reptile& operator=(const Reptile& ob)
    {
        Animal::operator=(ob);
        this->culoare = culoare;
        return *this;
    }
    friend istream&operator>>(istream&, Reptile&);
    friend ostream&operator<<(ostream&, Reptile&);
    virtual ~Reptile()=default;
    virtual void afisare ()
    {
        Vertebrate::afisare();
        cout<< "Animalul este " << this->culoare <<"." << endl;
    }
};
istream &operator >>(istream & in, Reptile & obj)
{
    in >> dynamic_cast<Vertebrate&>(obj);
    cout << "Culoarea animalului: " ;
    in >> obj.culoare;
    return in;
}
ostream &operator<<(ostream &out, Reptile &obj)
{
    obj.afisare();
    return out;
}

class Exceptia: public exception
{
private:
    const char* what_arg;
public:
    Exceptia(const char* what_arg) throw()
    {
        this->what_arg = what_arg;
    };
    ~Exceptia() throw() {};
    const char* what() const throw()
    {
        return this->what_arg;
    }
};

void afisare_meniu()
{
    cout << "MENIU" << endl;
    cout << "1.Introduceti animale in lista." << endl;
    cout << "2.Afisati animalele din lista." << endl;
    cout << "3.Introduceti animale in Atlasul Zoologic." << endl;
    cout << "4.Afisati numarul animalelor din Atlasul Zoologic." << endl;
    cout << "5.Afisati animalele din Atlasul Zoologic." << endl;
    cout << "6.EXIT" << endl;
}

template <typename T>
class AtlasZoologic
{
private:
    T* regn;
    int cnt;
public:
    static int nr_animale;
    AtlasZoologic()
    {
        regn = new T[100];
    }
    AtlasZoologic(int cnt,T*regn)
    {
        regn = new T[100];
        this->cnt = cnt;
        for(int i=0; i<cnt; i++)
            this->regn[i] = regn[i];
    }
    AtlasZoologic(const  AtlasZoologic &other)
    {
        cnt = other.cnt;
        regn = new T[100];
        for(int i=0; i<cnt; i++)
            regn[i] = other.regn[i];
    }
    ~AtlasZoologic()
    {
        delete []regn;
    }
    virtual void Afis()
    {
        cout << "Animalele sunt:" << endl;
        for(int i=0; i<cnt; i++)
            cout << regn[i] << endl;
    }
    friend istream& operator>>(istream&, AtlasZoologic<T>&);
    friend ostream& operator<<(ostream&, AtlasZoologic<T>&);

};

istream& operator>>(istream& in, AtlasZoologic<Mamifere>& ob)
{

    cout << "Introduceti numarul de mamifere: ";
    in >> ob.cnt;
    AtlasZoologic <Mamifere>::nr_animale += ob.cnt;
    cout << "Introduceti mamiferele:" << endl;
    for(int i=0; i<ob.cnt; i++)
    {
        cin >> ob.regn[i];
    }
    return in;
}

istream& operator>>(istream& in, AtlasZoologic<Pasari>& ob)
{
    cout << "Introduceti numarul de pasari:";
    in >> ob.cnt;
    AtlasZoologic<Pasari>::nr_animale += ob.cnt;
    cout << "Introduceti pasarile:"<< endl;
    for(int i=0; i<ob.cnt; i++)
        cin >> ob.regn[i];
    return in;
}

istream& operator>>(istream& in, AtlasZoologic<Reptile>& ob)
{
    cout << "Introduceti numarul de reptile: ";
    in >> ob.cnt;
    AtlasZoologic<Reptile>::nr_animale += ob.cnt;
    cout << "Introduceti reptilele:" << endl;
    for(int i=0; i<ob.cnt; i++)
        cin >> ob.regn[i];
    return in;
}
ostream& operator<<(ostream& out, AtlasZoologic<Mamifere>&ob)
{
    for(int i=0; i<ob.cnt; i++)
        cout<<ob.regn[i];
    return out;
}
ostream& operator<<(ostream& out, AtlasZoologic<Pasari>&ob)
{
    for(int i=0; i<ob.cnt; i++)
        cout<<ob.regn[i];
    return out;
}
ostream& operator<<(ostream& out, AtlasZoologic<Reptile>&ob)
{
    for(int i=0; i<ob.cnt; i++)
        cout<<ob.regn[i];
    return out;
}

template <>
class AtlasZoologic <Pesti>
{
private:
    Pesti* regn;
    int cnt;
public:
    static int nr_animale;
    AtlasZoologic()
    {
        regn = new Pesti[100];
    }
    AtlasZoologic(int nr,Pesti*regn)
    {
        regn = new Pesti[100];
        this->cnt = cnt;
        for(int i=0; i<cnt; i++)
            this->regn[i] = regn[i];
    }
    AtlasZoologic(const  AtlasZoologic &other)
    {
        cnt = other.cnt;
        regn = new Pesti[100];
        for(int i=0; i<cnt; i++)
            regn[i] = other.regn[i];
    }
    ~AtlasZoologic()
    {
        delete []regn;
    }

    void pestiRapitori()
    {
        int  numar = 0;
        for(int i=0; i<cnt; i++)
            if(regn[i].getTip() == 1 && regn[i].getLungime() > 1)
                numar++;
        cout<< numar << " pesti sunt rapitori cu o lungimea mai mare de un metru " << endl;
    }
    friend istream& operator>>(istream&, AtlasZoologic<Pesti>&);
    friend ostream& operator<<(ostream&, AtlasZoologic<Pesti>&);
};

istream& operator>>(istream& in, AtlasZoologic<Pesti>& ob)
{
    cout << "Introduceti numarul de pesti:";
    in >> ob.cnt;
    AtlasZoologic<Pesti>::nr_animale += ob.cnt;
    cout << "Introduceti pestii:" << endl;
    for(int i=0; i<ob.cnt; i++)
        cin >> ob.regn[i];
    return in;
}
ostream& operator<<(ostream& out, AtlasZoologic<Pesti>&ob)
{
    for(int i=0; i<ob.cnt; i++)
        cout << ob.regn[i];
    return out;
}

template<typename T>
int AtlasZoologic<T>::nr_animale=0;
int AtlasZoologic<Pesti>::nr_animale=0;
int n,tip,operatie;

int main()
{

    list<Animal*>animale;
    list<AtlasZoologic<Pesti>*>pesti;
    list<AtlasZoologic<Mamifere>*>mamifere;
    list<AtlasZoologic<Reptile>*>reptile;
    list<AtlasZoologic<Pasari>*>pasari;
    int OK=1;/// presupunem ca n am apelat butonul exit
    while(OK==1)
    {
        afisare_meniu();
        cin >> operatie;
        if(operatie == 1)
        {
            cout << "Numar animale: ";
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cout << "Introduceti tipul animalului:(1-mamifer, 2-pasare, 3-peste, 4-reptila): ";
                cin >> tip;
                if(tip == 1)
                {
                    Mamifere *temp;
                    temp = new Mamifere;
                    cin>>*temp;
                    animale.push_back(temp);
                }
                if(tip == 2)
                {
                    Pasari *temp = new Pasari;
                    cin >> *temp;
                    animale.push_back(temp);
                }
                if(tip == 3)
                {
                    Pesti *temp = new Pesti;
                    cin >> *temp;
                    animale.push_back(temp);
                }
                if(tip == 4)
                {
                    Reptile *temp = new Reptile;
                    cin >> *temp;
                    animale.push_back(temp);
                }
            }
        }
        else if(operatie == 2)
        {
            list<Animal*>::iterator i;
            if(animale.size() == 0)
            {
                try
                {
                    throw(Exceptia("Nu avem animale in lista."));
                }
                catch (exception& e)
                {
                    cout << e.what() << endl;
                }
            }
            for(i = animale.begin(); i != animale.end(); i++)
            {
                if(typeid(**i)==typeid(Mamifere))
                {
                    Mamifere *temp = dynamic_cast<Mamifere*>(*i);
                    cout << *temp << endl;
                }
                if(typeid(**i)==typeid(Pasari))
                {
                    Pasari *temp = dynamic_cast<Pasari*>(*i);
                    cout << *temp << endl;
                }
                if(typeid(**i)==typeid(Pesti))
                {
                    Pesti *temp = dynamic_cast<Pesti*>(*i);
                    cout << *temp << endl;
                }
                if(typeid(**i)==typeid(Reptile))
                {
                    Reptile *temp = dynamic_cast<Reptile*>(*i);
                    cout << *temp << endl;
                }
            }
        }
        else if(operatie == 3)
        {
            cout << "Numarul de adaugari in Atlasul Zoologic: ";
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cout << "Introduceti tipul animalului(1-mamifer, 2-pasare, 3-peste, 4-reptila): ";
                cin >> tip;
                if(tip == 1)
                {
                    AtlasZoologic<Mamifere>* temp = new  AtlasZoologic<Mamifere>;
                    cin >> *temp;
                    mamifere.push_back(temp);
                }
                if(tip == 2)
                {
                    AtlasZoologic<Pasari>* temp = new  AtlasZoologic<Pasari>;
                    cin >> *temp;
                    pasari.push_back(temp);
                }
                if(tip == 3)
                {
                    AtlasZoologic<Pesti>* temp = new  AtlasZoologic<Pesti>;
                    cin >> *temp;
                    pesti.push_back(temp);
                }
                if(tip == 4)
                {
                    AtlasZoologic<Reptile>* temp = new  AtlasZoologic<Reptile>;
                    cin >> *temp;
                    reptile.push_back(temp);
                }
            }
        }
         else if(operatie == 4)
        {
            cout << "Numarul mamiferelor: " << AtlasZoologic<Mamifere>::nr_animale << endl;
            cout << "Numarul pasarilor este: " << AtlasZoologic<Pasari>::nr_animale << endl;
            cout << "Numarul pestilor este: " << AtlasZoologic<Pesti>::nr_animale << endl;
            cout << "Numarul reptilelor este : " << AtlasZoologic<Reptile>::nr_animale << endl;
        }
        else if(operatie == 5)
        {
            if(mamifere.size())
            {
                cout << "Lista de animale din regnul Mamifer:" << endl;
                list<AtlasZoologic<Mamifere>*>::iterator m;
                for(m = mamifere.begin(); m != mamifere.end(); m++)
                    cout << **m;
            }
            else
                cout << "Nu avem mamifere in atlas." << endl;
            if(pasari.size())
            {
                cout << "Lista de animale din regnul Pasari:" << endl;
                list<AtlasZoologic<Pasari>*>::iterator pa;
                for(pa = pasari.begin(); pa != pasari.end(); pa++)
                    cout << **pa;
            }
            else
                cout << "Nu avem pasari in atlas." << endl;
            if(pesti.size())
            {
                cout << "Lista de animale din regnul Pesti:" << endl;
                list<AtlasZoologic<Pesti>*>::iterator pe;
                for(pe = pesti.begin(); pe != pesti.end(); pe++)
                {
                    cout<<**pe;
                    (**pe).pestiRapitori();
                }
            }
            else
                cout<<"Nu avem pesti in atlas." << endl;
            if(reptile.size() != 0)
            {
                cout << "Lista de animale din regnul Reptila:" << endl;
                list<AtlasZoologic<Reptile>*>::iterator r;
                for(r = reptile.begin(); r != reptile.end(); r++)
                    cout<<**r;
            }
            else
                cout<<"Nu avem reptile in atlas." << endl;
        }
        else if(operatie == 6)
                OK=0;
    }

    return 0;
}
