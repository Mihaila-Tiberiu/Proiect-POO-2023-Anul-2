#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>

using namespace std;

class Furnizor {
private:
	char* numeFurnizor = NULL;
	char CUI[20] = "RO0000000000";

public:
	Furnizor() {
	}

	Furnizor(const char* numeFurnizor)
	{
		if (numeFurnizor != NULL)
		{
			this->numeFurnizor = new char[strlen(numeFurnizor) + 1];
			strcpy(this->numeFurnizor, numeFurnizor);
		}
	}

	Furnizor(const char* numeFurnizor, const char* CUI)
	{
		if (numeFurnizor != NULL)
		{
			this->numeFurnizor = new char[strlen(numeFurnizor) + 1];
			strcpy(this->numeFurnizor, numeFurnizor);
		}
		if (CUI != NULL)
			strcpy(this->CUI, CUI);
	}

	Furnizor(const Furnizor& p)
	{
		if (numeFurnizor != NULL)
		{
			this->numeFurnizor = new char[strlen(p.numeFurnizor) + 1];
			strcpy(this->numeFurnizor, p.numeFurnizor);
		}
		if (CUI != NULL)
			strcpy(this->CUI, CUI);
	}

	Furnizor& operator= (const Furnizor& p)
	{
		if (this != &p) {
			if (numeFurnizor != NULL)
			{
				this->numeFurnizor = new char[strlen(p.numeFurnizor) + 1];
				strcpy(this->numeFurnizor, p.numeFurnizor);
			}
			if (CUI != NULL)
				strcpy(this->CUI, CUI);
		}

		return *this;
	}

	~Furnizor()
	{
		delete[] numeFurnizor;
	}

	friend ostream& operator << (ostream& out, Furnizor& sursa)
	{
		if (sursa.numeFurnizor != NULL)
			out << "Numele furnizorului este: " << sursa.numeFurnizor << endl;
		if (sursa.CUI != NULL)
			out << "Identificatorul furnizorului este: " << sursa.CUI << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Furnizor& sursa)
	{
		cout << "Dati numele furnizorului: " << endl;
		char buffer[255];
		in >> buffer;
		if (sursa.numeFurnizor != NULL) delete[] sursa.numeFurnizor;
		sursa.numeFurnizor = new char[strlen(buffer) + 1];
		strcpy(sursa.numeFurnizor, buffer);

		cout << "Dati identificatorul furnizorului: " << endl;
		in >> sursa.CUI;
		return in;
	}

	void afisare()
	{
		if (this->numeFurnizor != NULL)
			cout << "Numele furnizorului este: " << this->numeFurnizor << endl;
		else cout << "Numele furnizorului nu este definit." << endl;
		if (this->CUI != NULL)
			cout << "Identificatorul furnizorului este: " << this->CUI << endl;
	}

	void modificare()
	{
		cout << "Dati numele furnizorului: " << endl;
		char buffer[255];
		cin >> buffer;
		if (this->numeFurnizor != NULL) delete[] this->numeFurnizor;
		this->numeFurnizor = new char[strlen(buffer) + 1];
		strcpy(this->numeFurnizor, buffer);

		cout << "Dati identificatorul furnizorului: " << endl;
		cin >> this->CUI;
	}

	char& operator[](int index)
	{
		if (index >= 0 && index < 13)
			return this->CUI[index];
	}

	Furnizor operator- (int scazator)
	{
		Furnizor copie = *this;
		if (scazator > 0 && scazator <= strlen(copie.CUI))
			copie.CUI[strlen(copie.CUI) - scazator] = '\0';
	}

	//preincrementare
	Furnizor& operator --()
	{
		if (strlen(this->CUI) > 0)
			this->CUI[strlen(this->CUI) - 1] = '\0';
		return *this;
	}

	//postincrementare
	Furnizor& operator --(int)
	{
		Furnizor copie = *this;
		this->CUI[strlen(this->CUI) - 1] = '\0';
		return copie;
	}

	explicit operator string()
	{
		return string(this->CUI);
	}

	bool operator !()
	{
		if (this->numeFurnizor == NULL)
			return true;
		else
			return false;
	}

	bool operator > (Furnizor f)
	{
		if (strcmp(this->CUI, f.CUI) > 0) return true;
		else return false;
	}

	bool operator == (Furnizor f)
	{
		if (strcmp(this->CUI, f.CUI) == 0) return true;
		else return false;
	}

	const char* getNumeFurnizor()
	{
		if (this->numeFurnizor != NULL)
			return this->numeFurnizor;
		else
			return "NEDEFINIT";
	}

	void setNumeFurnizor(const char* numeNou)
	{
		if (numeNou != NULL)
		{
			if (this->numeFurnizor != NULL) delete[] this->numeFurnizor;
			this->numeFurnizor = new char[strlen(numeNou) + 1];
			strcpy(this->numeFurnizor, numeNou);
		}
	}

	char* getCUIFurnizor()
	{
		return this->CUI;
	}
	void setCUI(const char* CUInou)
	{
		if (CUInou != NULL)
		{
			strcpy(this->CUI, CUInou);
		}
	}
};

class Angajat {
private:
	string nume = "NEDEFINIT";
	static int nrTotalAngajati;

	float* istoricSalarii = NULL;
	int nrSchimbariSalarii = 0;

	char functie[25] = "NEDEFINIT";
public:
	Angajat() { nrTotalAngajati++; }
	Angajat(const char* functie)
	{
		nrTotalAngajati++;
		if (functie != NULL)
			strcpy(this->functie, functie);
	}
	Angajat(string nume, float* istoricSalarii, int nrSchimbariSalarii, const char* functie)
	{
		nrTotalAngajati++;
		this->nume = nume;
		if (istoricSalarii != NULL && nrSchimbariSalarii > 0)
		{
			this->nrSchimbariSalarii = nrSchimbariSalarii;
			this->istoricSalarii = new float[nrSchimbariSalarii];
			for (int i = 0; i < nrSchimbariSalarii; i++)
				this->istoricSalarii[i] = istoricSalarii[i];
		}
		if (functie != NULL)
			strcpy(this->functie, functie);
	}

	Angajat(const Angajat& a)
	{
		nrTotalAngajati++;
		this->nume = a.nume;
		if (a.istoricSalarii != NULL && a.nrSchimbariSalarii > 0)
		{
			this->nrSchimbariSalarii = a.nrSchimbariSalarii;
			this->istoricSalarii = new float[a.nrSchimbariSalarii];
			for (int i = 0; i < a.nrSchimbariSalarii; i++)
				this->istoricSalarii[i] = a.istoricSalarii[i];
		}
		if (functie != NULL)
			strcpy(this->functie, a.functie);
	}

	Angajat& operator= (const Angajat& a)
	{
		if (this != &a) {
			this->nume = a.nume;
			if (a.istoricSalarii != NULL && a.nrSchimbariSalarii > 0)
			{
				this->nrSchimbariSalarii = a.nrSchimbariSalarii;
				this->istoricSalarii = new float[a.nrSchimbariSalarii];
				for (int i = 0; i < a.nrSchimbariSalarii; i++)
					this->istoricSalarii[i] = a.istoricSalarii[i];
			}
			if (functie != NULL)
				strcpy(this->functie, a.functie);
		}
		return *this;
	}

	~Angajat()
	{
		nrTotalAngajati--;
		delete[] this->istoricSalarii;
	}

	friend ostream& operator << (ostream& out, Angajat& sursa)
	{
		if (sursa.istoricSalarii != NULL && sursa.nrSchimbariSalarii > 0)
		{
			out << "Numele angajatului este: " << sursa.nume << endl;
			out << "Angajatul a schimbat salariul de " << sursa.nrSchimbariSalarii << " ori." << endl;
			for (int i = 0; i < sursa.nrSchimbariSalarii; i++)
			{
				out << "Salariul nr " << i + 1 << " al angajatului a fost: " << sursa.istoricSalarii[i] << endl;
			}
		}
		if (sursa.functie != NULL)
			out << "Angajatul are functia de " << sursa.functie;
		return out;
	}

	friend istream& operator >> (istream& in, Angajat& sursa)
	{
		cout << "Dati numele angajatului: "; in >> sursa.nume;
		cout << "Dati numarul de schimbari de salarii: "; in >> sursa.nrSchimbariSalarii;
		if (sursa.nrSchimbariSalarii > 0)
		{
			if (sursa.istoricSalarii != NULL) delete[] sursa.istoricSalarii;
			sursa.istoricSalarii = new float[sursa.nrSchimbariSalarii];
			for (int i = 0; i < sursa.nrSchimbariSalarii; i++)
			{
				cout << "Dati salariul cu numarul " << i + 1 << ": "; in >> sursa.istoricSalarii[i];
			}
		}
		cout << "Dati functia angajatului: "; in >> sursa.functie;
		return in;
	}

	void afisare()
	{
		if (this->istoricSalarii != NULL && this->nrSchimbariSalarii > 0)
		{
			cout << "Numele angajatului este: " << this->nume << endl;
			cout << "Angajatul a schimbat salariul de " << this->nrSchimbariSalarii << " ori." << endl;
			for (int i = 0; i < this->nrSchimbariSalarii; i++)
			{
				cout << "Salariul nr " << i + 1 << " al angajatului a fost: " << this->istoricSalarii[i] << endl;
			}
		}
		if (this->functie != NULL)
			cout << "Angajatul are functia de " << this->functie << endl;
	}

	void modificare()
	{
		cout << "Dati numele angajatului: "; cin >> this->nume;
		cout << "Dati numarul de schimbari de salarii: "; cin >> this->nrSchimbariSalarii;
		if (this->nrSchimbariSalarii > 0)
		{
			if (this->istoricSalarii != NULL) delete[] this->istoricSalarii;
			this->istoricSalarii = new float[this->nrSchimbariSalarii];
			for (int i = 0; i < this->nrSchimbariSalarii; i++)
			{
				cout << "Dati salariul cu numarul " << i + 1 << ": "; cin >> this->istoricSalarii[i];
			}
		}
		cout << "Dati functia angajatului: "; cin >> this->functie;
	}

	float& operator[](int index)
	{
		if (index > 0 && index <= this->nrSchimbariSalarii && this->istoricSalarii != NULL)
			return this->istoricSalarii[index];
	}

	Angajat operator +(float schimbareNoua)
	{
		Angajat copie = *this;
		float* aux = new float[copie.nrSchimbariSalarii + 1];
		if (copie.nrSchimbariSalarii > 0 && copie.istoricSalarii != NULL) {
			for (int i = 0; i < copie.nrSchimbariSalarii; i++)
				aux[i] = copie.istoricSalarii[i];
			delete[] copie.istoricSalarii;
		}
		copie.nrSchimbariSalarii++;
		aux[copie.nrSchimbariSalarii - 1] = schimbareNoua;
		copie.istoricSalarii = aux;
		return copie;
	}

	//preincrementare
	Angajat& operator++()
	{
		float* aux = new float[this->nrSchimbariSalarii + 1];
		if (this->nrSchimbariSalarii > 0 && this->istoricSalarii != NULL) {
			for (int i = 0; i < this->nrSchimbariSalarii; i++)
				aux[i] = this->istoricSalarii[i];
			delete[] this->istoricSalarii;
		}
		this->nrSchimbariSalarii++;
		aux[this->nrSchimbariSalarii - 1] = 0;
		this->istoricSalarii = aux;
	}

	//postincrementare
	Angajat operator ++(int)
	{
		Angajat copie = *this;
		float* aux = new float[this->nrSchimbariSalarii + 1];
		if (this->nrSchimbariSalarii > 0 && this->istoricSalarii != NULL) {
			for (int i = 0; i < this->nrSchimbariSalarii; i++)
				aux[i] = this->istoricSalarii[i];
			delete[] this->istoricSalarii;
		}
		this->nrSchimbariSalarii++;
		aux[this->nrSchimbariSalarii - 1] = 0;
		this->istoricSalarii = aux;
		return copie;
	}

	explicit operator string()
	{
		return string(this->functie);
	}

	bool operator !()
	{
		if (this->istoricSalarii == NULL)
			return true;
		else
			return false;

	}

	bool operator >= (Angajat a)
	{
		if (this->istoricSalarii != NULL && this->nrSchimbariSalarii > 0 &&
			a.istoricSalarii != NULL && a.nrSchimbariSalarii > 0)
			return this->istoricSalarii[this->nrSchimbariSalarii - 1] >=
			a.istoricSalarii[a.nrSchimbariSalarii - 1];
	}

	bool operator == (Angajat a)
	{
		if (this->istoricSalarii != NULL && this->nrSchimbariSalarii > 0 &&
			a.istoricSalarii != NULL && a.nrSchimbariSalarii > 0)
			return this->istoricSalarii[this->nrSchimbariSalarii - 1] ==
			a.istoricSalarii[a.nrSchimbariSalarii - 1];
	}

	string getNumeAngajat()
	{
		return this->nume;
	}

	void setNumeAngajat(string numeNou)
	{
		if (numeNou.length() > 0)
			this->nume = numeNou;
	}

	static int getNrTotalAngajati()
	{
		return nrTotalAngajati;
	}

	int getNrSchimbariSalarii()
	{
		return this->nrSchimbariSalarii;
	}

	float* getIstoricSalarii()
	{
		float IstoricSalariiAux[80];
		for (int i = 0; i < nrSchimbariSalarii; i++)
			IstoricSalariiAux[i] = istoricSalarii[i];
		return IstoricSalariiAux;
	}

	char* getFunctie()
	{
		return this->functie;
	}

	void setFunctie(const char* funcNou)
	{
		if (funcNou != NULL)
		{
			strcpy(this->functie, funcNou);
		}
	}

	void setSalariuCurent(float salariuCurent)
	{
		float* aux = new float[this->nrSchimbariSalarii + 1];
		if (this->nrSchimbariSalarii > 0 && this->nrSchimbariSalarii != NULL) {
			for (int i = 0; i < this->nrSchimbariSalarii; i++)
				aux[i] = this->istoricSalarii[i];
			delete[] this->istoricSalarii;
		}
		this->nrSchimbariSalarii++;
		aux[nrSchimbariSalarii - 1] = salariuCurent;
		this->istoricSalarii = aux;
	}
};
int Angajat::nrTotalAngajati = 0;

class Client {
private:
	static int nrTotalClienti;
	string nume = "NEDEFINIT";


	float* istoricValComenzi = NULL;
	int nrComenzi = 0;

	char adresa[25] = "NEDEFINIT";
public:
	Client()
	{
		nrTotalClienti++;
	}

	Client(string nume, const char* adresa)
	{
		nrTotalClienti++;
		this->nume = nume;
		if (adresa != NULL)
			strcpy(this->adresa, adresa);
	}

	Client(string nume, float* istoricValComenzi, int nrComenzi, const char* adresa)
	{
		nrTotalClienti++;
		this->nume = nume;
		if (istoricValComenzi != NULL && nrComenzi > 0)
		{
			this->nrComenzi = nrComenzi;
			this->istoricValComenzi = new float[nrComenzi];
			for (int i = 0; i < nrComenzi; i++)
				this->istoricValComenzi[i] = istoricValComenzi[i];
		}
		if (adresa != NULL)
			strcpy(this->adresa, adresa);
	}

	Client(const Client& c)
	{
		nrTotalClienti++;
		this->nume = nume;
		if (c.istoricValComenzi != NULL && c.nrComenzi > 0)
		{
			this->nrComenzi = c.nrComenzi;
			this->istoricValComenzi = new float[c.nrComenzi];
			for (int i = 0; i < c.nrComenzi; i++)
				this->istoricValComenzi[i] = c.istoricValComenzi[i];
		}
		if (adresa != NULL)
			strcpy(this->adresa, adresa);
	}

	Client& operator= (const Client& c)
	{
		if (this != &c) {
			this->nume = c.nume;
			if (c.istoricValComenzi != NULL && c.nrComenzi > 0)
			{
				this->nrComenzi = c.nrComenzi;
				this->istoricValComenzi = new float[c.nrComenzi];
				for (int i = 0; i < c.nrComenzi; i++)
					this->istoricValComenzi[i] = c.istoricValComenzi[i];
			}
			if (adresa != NULL)
				strcpy(this->adresa, adresa);
		}
		return *this;
	}

	~Client()
	{
		delete[] this->istoricValComenzi;
	}

	friend ostream& operator<< (ostream& out, Client& sursa)
	{
		if (sursa.istoricValComenzi != NULL && sursa.nrComenzi > 0)
		{
			out << "Numele clientului este: " << sursa.nume << endl;
			out << "Clientul a plasat " << sursa.nrComenzi << " comenzi" << endl;
			for (int i = 0; i < sursa.nrComenzi; i++)
			{
				out << "Valoarea comenzii cu nr " << i + 1 << " a fost: " << sursa.istoricValComenzi[i] << endl;
			}
		}
		if (sursa.adresa != NULL)
			out << "Adresa de livrare a clientului este " << sursa.adresa;
		return out;
	}

	friend istream& operator>> (istream& in, Client& sursa)
	{
		cout << "Dati numele clientului: "; in >> sursa.nume;
		cout << "Dati numarul de comenzi: "; in >> sursa.nrComenzi;
		if (sursa.nrComenzi > 0)
		{
			if (sursa.istoricValComenzi != NULL) delete[] sursa.istoricValComenzi;
			sursa.istoricValComenzi = new float[sursa.nrComenzi];
			for (int i = 0; i < sursa.nrComenzi; i++)
			{
				cout << "Dati valoarea comenzii " << i + 1 << ": "; in >> sursa.istoricValComenzi[i];
			}
		}
		cout << "Dati adresa clientului: "; in >> sursa.adresa;
		return in;
	}

	void afisare() {
		if (this->istoricValComenzi != NULL && this->nrComenzi > 0)
		{
			cout << "Numele clientului este: " << this->nume;
			cout << "Clientul a plasat " << this->nrComenzi << " comenzi" << endl;
			for (int i = 0; i < this->nrComenzi; i++)
			{
				cout << "Valoarea comenzii cu nr " << i + 1 << " a fost: " << this->istoricValComenzi[i] << endl;
			}
		}
		if (this->adresa != NULL)
			cout << "Adresa de livrare a clientului este " << this->adresa;
	}

	void modificare() {
		cout << "Dati numele clientului: "; cin >> this->nume;
		cout << "Dati numarul de comenzi: "; cin >> this->nrComenzi;
		if (this->nrComenzi > 0)
		{
			if (this->istoricValComenzi != NULL) delete[] this->istoricValComenzi;
			this->istoricValComenzi = new float[this->nrComenzi];
			for (int i = 0; i < this->nrComenzi; i++)
			{
				cout << "Dati valoarea comenzii " << i + 1 << ": "; cin >> this->istoricValComenzi[i];
			}
		}
		cout << "Dati adresa clientului: "; cin >> this->adresa;
	}

	float& operator[](int index)
	{
		if (index > 0 && index <= this->nrTotalClienti && this->istoricValComenzi != NULL)
			return this->istoricValComenzi[index];
	}

	Client operator +(float schimbareNoua)
	{
		Client copie = *this;
		float* aux = new float[copie.nrComenzi + 1];
		if (copie.nrComenzi > 0 && copie.nrComenzi != NULL) {
			for (int i = 0; i < copie.nrComenzi; i++)
				aux[i] = copie.istoricValComenzi[i];
			delete[] copie.istoricValComenzi;
		}
		copie.nrComenzi++;
		aux[copie.nrComenzi - 1] = schimbareNoua;
		copie.istoricValComenzi = aux;
		return copie;
	}

	//preincrementare
	Client& operator++()
	{
		float* aux = new float[this->nrComenzi + 1];
		if (this->nrComenzi > 0 && this->istoricValComenzi != NULL) {
			for (int i = 0; i < this->nrComenzi; i++)
				aux[i] = this->istoricValComenzi[i];
			delete[] this->istoricValComenzi;
		}
		this->nrComenzi++;
		aux[this->nrComenzi - 1] = 0;
		this->istoricValComenzi = aux;
	}

	//postincrementare
	Client operator ++(int)
	{
		Client copie = *this;
		float* aux = new float[this->nrComenzi + 1];
		if (this->nrComenzi > 0 && this->istoricValComenzi != NULL) {
			for (int i = 0; i < this->nrComenzi; i++)
				aux[i] = this->istoricValComenzi[i];
			delete[] this->istoricValComenzi;
		}
		this->nrComenzi++;
		aux[this->nrComenzi - 1] = 0;
		this->istoricValComenzi = aux;
		return copie;
	}

	explicit operator string()
	{
		return string(this->adresa);
	}

	bool operator !()
	{
		if (this->istoricValComenzi == NULL)
			return true;
		else
			return false;

	}

	bool operator < (Client a)
	{
		if (this->istoricValComenzi != NULL && this->nrComenzi > 0 &&
			a.istoricValComenzi != NULL && a.nrComenzi > 0)
			return this->istoricValComenzi[this->nrComenzi - 1] <
			a.istoricValComenzi[a.nrComenzi - 1];
	}

	bool operator == (Client a)
	{
		if (this->istoricValComenzi != NULL && this->nrComenzi > 0 &&
			a.istoricValComenzi != NULL && a.nrComenzi > 0)
			return this->istoricValComenzi[this->nrComenzi - 1] ==
			a.istoricValComenzi[a.nrComenzi - 1];
	}

	string getNumeClient()
	{
		return this->nume;
	}

	void setNumeClient(string numeNou)
	{
		if (numeNou.length() > 0)
			this->nume = numeNou;
	}

	static int getNrTotalClienti()
	{
		return nrTotalClienti;
	}

	int getNrComenzi()
	{
		return this->nrComenzi;
	}

	float* getIstoricValComenzi()
	{
		float IstoricAux[80];
		for (int i = 0; i < nrComenzi; i++)
			IstoricAux[i] = this->istoricValComenzi[i];
		return IstoricAux;
	}

	char* getAdresa()
	{
		return this->adresa;
	}

	void setAdresa(const char* adresaNoua)
	{
		if (adresaNoua != NULL)
		{
			strcpy(this->adresa, adresaNoua);
		}
	}

	void setValoareUltimaComanda(float valoareRecenta)
	{
		float* aux = new float[this->nrComenzi + 1];
		if (this->nrComenzi > 0 && this->nrComenzi != NULL) {
			for (int i = 0; i < this->nrComenzi; i++)
				aux[i] = this->istoricValComenzi[i];
			delete[] this->istoricValComenzi;
		}
		this->nrComenzi++;
		aux[nrComenzi - 1] = valoareRecenta;
		this->istoricValComenzi = aux;
	}
};
int Client::nrTotalClienti = 0;

class Magazin {
private:
	Angajat manager;
	float oreDeschidere[7] = { 0,0,0,0,0,0,0 };
	float oreInchidere[7] = { 0,0,0,0,0,0,0 };
	char* adresa = NULL;

	const int idMagazin;

public:
	Magazin(int idMagazin) :idMagazin(idMagazin) {}
	Magazin(Angajat manager, int idMagazin) :idMagazin(idMagazin)
	{
		this->manager = manager;
	}
	Magazin(Angajat manager, float* oreDeschidere, float* oreInchidere, const char* adresa, int idMagazin) :idMagazin(idMagazin)
	{
		this->manager = manager;
		if (oreDeschidere != NULL)
			for (int i = 0; i < 7; i++)
				this->oreDeschidere[i] = oreDeschidere[i];
		if (oreInchidere != NULL)
			for (int i = 0; i < 7; i++)
				this->oreInchidere[i] = oreInchidere[i];
		if (adresa != NULL)
		{
			this->adresa = new char[strlen(adresa) + 1];
			strcpy(this->adresa, adresa);
		}
	}
	Magazin(const Magazin& a) :idMagazin(a.idMagazin)
	{
		this->manager = a.manager;
		if (a.oreDeschidere != NULL)
			for (int i = 0; i < 7; i++)
				this->oreDeschidere[i] = a.oreDeschidere[i];
		if (a.oreInchidere != NULL)
			for (int i = 0; i < 7; i++)
				this->oreInchidere[i] = a.oreInchidere[i];
		if (a.adresa != NULL)
		{
			this->adresa = new char[strlen(a.adresa) + 1];
			strcpy(this->adresa, a.adresa);
		}
	}

	Magazin& operator=(const Magazin& a)
	{
		if (this != &a) {
			this->manager = a.manager;
			if (a.oreDeschidere != NULL)
				for (int i = 0; i < 7; i++)
					this->oreDeschidere[i] = a.oreDeschidere[i];
			if (a.oreInchidere != NULL)
				for (int i = 0; i < 7; i++)
					this->oreInchidere[i] = a.oreInchidere[i];
			if (a.adresa != NULL)
			{
				this->adresa = new char[strlen(a.adresa) + 1];
				strcpy(this->adresa, a.adresa);
			}
		}
		return *this;
	}

	~Magazin()
	{
		delete[] this->adresa;
	}

	friend ostream& operator<< (ostream& out, Magazin& sursa) {
		out << sursa.manager;
		out << "Orele de deschidere sunt: " << endl;
		for (int i = 0; i < 7; i++)
			out << sursa.oreDeschidere[i] << "\t";
		out << "Orele de inchidere sunt: " << endl;
		for (int i = 0; i < 7; i++)
			out << sursa.oreInchidere[i] << "\t";
		if (sursa.adresa != NULL)
			out << "Adresa magazinului este: " << sursa.adresa << endl;
		out << "ID-ul magazinului este: " << sursa.idMagazin << endl;
		return out;
	}

	friend istream& operator>> (istream& in, Magazin& sursa) {
		cout << "Dati managerul magazinului: " << endl;
		in >> sursa.manager;
		cout << "Dati orele de deschidere: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "Ora de deschidere pentru ziua " << i + 1 << endl;
			in >> sursa.oreDeschidere[i];
		}
		cout << "Dati orele de inchidere: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "Ora de inchidere pentru ziua " << i + 1 << endl;
			in >> sursa.oreInchidere[i];
		}
		char buffer[255];
		cout << "Dati adresa magazinului:" << endl;
		in >> buffer;
		if (buffer != NULL)
		{
			if (sursa.adresa != NULL) delete[] sursa.adresa;
			sursa.adresa = new char[strlen(buffer) + 1];
			strcpy(sursa.adresa, buffer);
		}
	}

	void afisare()
	{
		cout << this->manager;
		cout << "Orele de deschidere sunt: " << endl;
		for (int i = 0; i < 7; i++)
			cout << this->oreDeschidere[i] << "\t";
		cout << "Orele de inchidere sunt: " << endl;
		for (int i = 0; i < 7; i++)
			cout << this->oreInchidere[i] << "\t";
		if (this->adresa != NULL)
			cout << "Adresa magazinului este: " << this->adresa << endl;
		cout << "ID-ul magazinului este: " << this->idMagazin << endl;
	}

	void modificare()
	{
		cout << "Dati managerul magazinului: " << endl;
		cin >> this->manager;
		cout << "Dati orele de deschidere: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "Ora de deschidere pentru ziua " << i + 1 << endl;
			cin >> this->oreDeschidere[i];
		}
		cout << "Dati orele de inchidere: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "Ora de inchidere pentru ziua " << i + 1 << endl;
			cin >> this->oreInchidere[i];
		}
		char buffer[255];
		cout << "Dati adresa magazinului:" << endl;
		cin >> buffer;
		if (buffer != NULL)
		{
			if (this->adresa != NULL) delete[] this->adresa;
			this->adresa = new char[strlen(buffer) + 1];
			strcpy(this->adresa, buffer);
		}
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < 7)
			return oreDeschidere[index];
	}

	Magazin operator - (int zi)
	{
		Magazin copie = *this;
		if (zi >= 0 && zi < 7)
			copie.oreDeschidere[zi] = 0;
		return copie;
	}

	//preincrementare
	Magazin& operator++()
	{
		for (int i = 0; i < 7; i++)
			this->oreDeschidere[i] += 1;
		return *this;
	}

	//postincrementare
	Magazin operator++(int)
	{
		Magazin copie = *this;
		for (int i = 0; i < 7; i++)
			this->oreDeschidere[i] += 1;
		return copie;
	}

	explicit operator int() {
		return int(this->oreDeschidere);
	}

	bool operator !()
	{
		if (this->adresa == NULL)
			return true;
		else
			return false;
	}

	bool operator >= (Magazin m)
	{
		int scor = 0;
		for (int i = 0; i < 7; i++)
		{
			if (this->oreDeschidere[i] > m.oreDeschidere[i]) scor++;
		}

		if (scor >= 4) return true;
		else return false;
	}

	bool operator == (Magazin m)
	{
		bool ok = 1;
		for (int i = 0; i < 7; i++)
		{
			if (this->oreDeschidere[i] != m.oreDeschidere[i]) ok = 0;
		}

		if (ok == 1) return true;
		else return false;
	}

	Angajat getManager()
	{
		return this->manager;
	}
	void setManager(Angajat a)
	{
		this->manager = a;
	}

	float* getOreDeschidere()
	{
		return this->oreDeschidere;
	}

	void setOreDeschidere(int ore[7])
	{
		for (int i = 0; i < 7; i++)
			this->oreDeschidere[i] = ore[i];
	}

	float* getOreInchidere()
	{
		return this->oreInchidere;
	}

	void setOreInchidere(int ore[7])
	{
		for (int i = 0; i < 7; i++)
			this->oreInchidere[i] = ore[i];
	}

	const char* getAdresa()
	{
		if (this->adresa != NULL)
			return this->adresa;
		else
			return "NEDEFINIT";
	}

	void setAdresa(const char* adresaNoua)
	{
		if (adresaNoua != NULL)
		{
			if (this->adresa != NULL) delete[] this->adresa;
			this->adresa = new char[strlen(adresaNoua) + 1];
			strcpy(this->adresa, adresaNoua);
		}
	}

	int getIdMagazin()
	{
		return this->idMagazin;
	}

};

class Material {
private:
	char denumireMaterial[25] = "NEDEFINIT";
	float* istoricPretPerKg = NULL;
	int nrSchimbariPreturi = 0;
public:
	Material() {}
	Material(const char* denumireMaterial)
	{
		if (denumireMaterial != NULL)
			strcpy(this->denumireMaterial, denumireMaterial);
	}
	Material(const char* denumireMaterial, float* istoricPretPerKg, int nrSchimbariPreturi)
	{
		if (denumireMaterial != NULL)
			strcpy(this->denumireMaterial, denumireMaterial);
		if (istoricPretPerKg != NULL && nrSchimbariPreturi > 0)
		{
			this->nrSchimbariPreturi = nrSchimbariPreturi;
			this->istoricPretPerKg = new float[nrSchimbariPreturi];
			for (int i = 0; i < nrSchimbariPreturi; i++)
				this->istoricPretPerKg[i] = istoricPretPerKg[i];
		}
	}

	Material(const Material& m)
	{
		if (m.denumireMaterial != NULL)
			strcpy(this->denumireMaterial, m.denumireMaterial);
		if (istoricPretPerKg != NULL && m.nrSchimbariPreturi > 0)
		{
			this->nrSchimbariPreturi = m.nrSchimbariPreturi;
			this->istoricPretPerKg = new float[m.nrSchimbariPreturi];
			for (int i = 0; i < m.nrSchimbariPreturi; i++)
				this->istoricPretPerKg[i] = m.istoricPretPerKg[i];
		}
	}

	Material& operator = (const Material& m)
	{
		if (this != &m) {
			if (m.denumireMaterial != NULL)
				strcpy(this->denumireMaterial, m.denumireMaterial);
			if (istoricPretPerKg != NULL && m.nrSchimbariPreturi > 0)
			{
				this->nrSchimbariPreturi = m.nrSchimbariPreturi;
				this->istoricPretPerKg = new float[m.nrSchimbariPreturi];
				for (int i = 0; i < m.nrSchimbariPreturi; i++)
					this->istoricPretPerKg[i] = m.istoricPretPerKg[i];
			}
		}
		return *this;
	}

	~Material() {
		delete[] this->istoricPretPerKg;
	}

	friend ostream& operator<< (ostream& out, Material& sursa)
	{
		out << "Denumirea materialului este " << sursa.denumireMaterial << endl;
		out << "Nr de schimbari de pret ale materialului este de " << sursa.nrSchimbariPreturi << endl;
		if (sursa.denumireMaterial != NULL && sursa.nrSchimbariPreturi > 0)
			for (int i = 0; i < sursa.nrSchimbariPreturi; i++)
				out << sursa.istoricPretPerKg[i] << "\t";
		return out;
	}

	friend istream& operator>> (istream& in, Material& sursa)
	{
		cout << "Dati denumirea materialului: "; in >> sursa.denumireMaterial;
		cout << "Dati nr de schimbari de pret "; in >> sursa.nrSchimbariPreturi;
		if (sursa.nrSchimbariPreturi > 0)
		{
			if (sursa.istoricPretPerKg != NULL) delete[] sursa.istoricPretPerKg;
			sursa.istoricPretPerKg = new float[sursa.nrSchimbariPreturi];
			for (int i = 0; i < sursa.nrSchimbariPreturi; i++)
			{
				cout << "Dati pretul cu numarul" << i + 1 << endl;
				in >> sursa.istoricPretPerKg[i];
			}
		}
		return in;
	}

	void afisare() {
		cout << "Denumirea materialului este " << this->denumireMaterial << endl;
		cout << "Nr de schimbari de pret ale materialului este de " << this->nrSchimbariPreturi << endl;
		if (this->denumireMaterial != NULL && this->nrSchimbariPreturi > 0)
			for (int i = 0; i < this->nrSchimbariPreturi; i++)
				cout << this->istoricPretPerKg[i] << "\t";
	}

	void modificare()
	{
		cout << "Dati denumirea materialului: "; cin >> this->denumireMaterial;
		cout << "Dati nr de schimbari de pret "; cin >> this->nrSchimbariPreturi;
		if (this->nrSchimbariPreturi > 0)
		{
			if (this->istoricPretPerKg != NULL) delete[] this->istoricPretPerKg;
			this->istoricPretPerKg = new float[this->nrSchimbariPreturi];
			for (int i = 0; i < this->nrSchimbariPreturi; i++)
			{
				cout << "Dati pretul cu numarul" << i + 1 << endl;
				cin >> this->istoricPretPerKg[i];
			}
		}
	}

	float& operator[](int index)
	{
		if (index > 0 && index <= this->nrSchimbariPreturi && this->istoricPretPerKg != NULL)
			return this->istoricPretPerKg[index];
	}

	Material operator +(float schimbareNoua)
	{
		Material copie = *this;
		float* aux = new float[copie.nrSchimbariPreturi + 1];
		if (copie.nrSchimbariPreturi > 0 && copie.nrSchimbariPreturi != NULL) {
			for (int i = 0; i < copie.nrSchimbariPreturi; i++)
				aux[i] = copie.istoricPretPerKg[i];
			delete[] copie.istoricPretPerKg;
		}
		copie.nrSchimbariPreturi++;
		aux[copie.nrSchimbariPreturi - 1] = schimbareNoua;
		copie.istoricPretPerKg = aux;
		return copie;
	}

	//preincrementare
	Material& operator++()
	{
		float* aux = new float[this->nrSchimbariPreturi + 1];
		if (this->nrSchimbariPreturi > 0 && this->istoricPretPerKg != NULL) {
			for (int i = 0; i < this->nrSchimbariPreturi; i++)
				aux[i] = this->istoricPretPerKg[i];
			delete[] this->istoricPretPerKg;
		}
		this->nrSchimbariPreturi++;
		aux[this->nrSchimbariPreturi - 1] = 0;
		this->istoricPretPerKg = aux;
	}

	//postincrementare
	Material operator ++(int)
	{
		Material copie = *this;
		float* aux = new float[this->nrSchimbariPreturi + 1];
		if (this->nrSchimbariPreturi > 0 && this->istoricPretPerKg != NULL) {
			for (int i = 0; i < this->nrSchimbariPreturi; i++)
				aux[i] = this->istoricPretPerKg[i];
			delete[] this->istoricPretPerKg;
		}
		this->nrSchimbariPreturi++;
		aux[this->nrSchimbariPreturi - 1] = 0;
		this->istoricPretPerKg = aux;
		return copie;
	}

	explicit operator string()
	{
		return string(this->denumireMaterial);
	}

	bool operator !()
	{
		if (this->istoricPretPerKg == NULL)
			return true;
		else
			return false;

	}

	bool operator < (Material a)
	{
		if (this->istoricPretPerKg != NULL && this->nrSchimbariPreturi > 0 &&
			a.istoricPretPerKg != NULL && a.nrSchimbariPreturi > 0)
			return this->istoricPretPerKg[this->nrSchimbariPreturi - 1] <
			a.istoricPretPerKg[a.nrSchimbariPreturi - 1];
	}

	bool operator == (Material a)
	{
		if (this->istoricPretPerKg != NULL && this->nrSchimbariPreturi > 0 &&
			a.istoricPretPerKg != NULL && a.nrSchimbariPreturi > 0)
			return this->istoricPretPerKg[this->nrSchimbariPreturi - 1] ==
			a.istoricPretPerKg[a.nrSchimbariPreturi - 1];
	}

	char* getDenumireMaterial()
	{
		return this->denumireMaterial;
	}

	void setDenumireMaterial(const char* denumireNoua)
	{
		if (denumireNoua != NULL)
			strcpy(this->denumireMaterial, denumireNoua);
	}

	int getNrSchimbariPreturi()
	{
		return this->nrSchimbariPreturi;
	}

	float* getIstoricPretPerKg()
	{
		float IstoricAux[80];
		for (int i = 0; i < nrSchimbariPreturi; i++)
			IstoricAux[i] = this->istoricPretPerKg[i];
		return IstoricAux;
	}

	void setPretCurent(float pretCurent)
	{
		float* aux = new float[this->nrSchimbariPreturi + 1];
		if (this->nrSchimbariPreturi > 0 && this->nrSchimbariPreturi != NULL) {
			for (int i = 0; i < this->nrSchimbariPreturi; i++)
				aux[i] = this->istoricPretPerKg[i];
			delete[] this->istoricPretPerKg;
		}
		this->nrSchimbariPreturi++;
		aux[nrSchimbariPreturi - 1] = pretCurent;
		this->istoricPretPerKg = aux;
	}

};

class ModulFacturiFisiereBinare {
private:
	static int nrTotalFacturiEmise;

public:
	static int getNrTotalFacturiEmise()
	{
		return nrTotalFacturiEmise;
	}

	static void saveInvoiceToBin(string numeClient, string seria, float totalFactura)
	{
		fstream fMAIN("FACTURI.txt", ios::app | ios::binary);

		nrTotalFacturiEmise++;

		fMAIN.write((char*)&nrTotalFacturiEmise, sizeof(int));

		int lg1 = numeClient.length() + 1;
		fMAIN.write((char*)&lg1, sizeof(int));
		fMAIN.write(numeClient.data(), lg1 * sizeof(char));

		int lg2 = seria.length() + 1;
		fMAIN.write((char*)&lg2, sizeof(int));
		fMAIN.write(seria.data(), lg2 * sizeof(char));

		fMAIN.write((char*)&totalFactura, sizeof(float));

		fMAIN.close();

	}

	static void readFromTxtToBin(fstream& fAux)
	{

		string numeClient;
		string seria;
		float totalFactura;

		fAux >> numeClient;
		fAux >> seria;
		fAux >> totalFactura;

		saveInvoiceToBin(numeClient, seria, totalFactura);
	}

	static void readFromCSVToBin(const char* numeFisier)
	{
		// delimitatorul = "\n"
		fstream fAux;
		fAux.open(numeFisier);
		if (fAux.fail()) {
			cout << numeFisier << " nu este un fisier valid." << endl;
		}
		else
		{
			while (!fAux.eof())
			{
				readFromTxtToBin(fAux);
				cout << "Factura a fost citita si salvata cu succes." << endl;
			}
		}
		fAux.close();
	}

	static void displayNthInvoiceFromBin(int n)
	{
		if (n > nrTotalFacturiEmise)
			cout << "n este mai mare decat numarul de facturi emise" << endl;
		else
		{
			int nrFacturaOut;
			string numeClientOut;
			string seriaOut;
			float totalFacturaOut;

			fstream fMAIN("FACTURI.txt", ios::in | ios::binary);

			for (int i = 1; i <= n; i++)
			{
				int lg1, lg2;

				fMAIN.read((char*)&nrFacturaOut, sizeof(int));

				fMAIN.read((char*)&lg1, sizeof(int));
				char* buffer = new char[lg1];
				fMAIN.read(buffer, lg1);
				numeClientOut = buffer;
				delete[] buffer;

				fMAIN.read((char*)&lg2, sizeof(int));
				char* buffer2 = new char[lg2];
				fMAIN.read(buffer2, lg2);
				seriaOut = buffer2;
				delete[] buffer2;

				fMAIN.read((char*)&totalFacturaOut, sizeof(float));
			}

			fMAIN.close();

			cout << "Numarul facturii este: " << nrFacturaOut << endl;
			cout << "Numele clientului este: " << numeClientOut << endl;
			cout << "Seria facturii este: " << seriaOut << endl;
			cout << "Totalul de plata al facturii este: " << totalFacturaOut << endl;
		}
	}

	static void readArgsInvoices(int argc, char* argv[])
	{
		if (argc > 1)
		{
			bool ok = true;
			for (int i = 1; i < argc; i++) // argv[0] ia mereu valoarea numelui executabilului, deci acest element este trecut cu vederea
			{
				char aux[5];
				strcpy(aux, argv[i] + strlen(argv[i]) - 4);
				fstream fAux;
				fAux.open(argv[i]);
				if (strcmp(aux, ".txt") != 0 || fAux.fail()) {
					cout << argv[i] << " nu este un fisier txt valid." << endl;
					ok = false;
				}
				else
				{
					readFromTxtToBin(fAux);
					cout << "Factura din fisierul " << argv[i] << " a fost citita si salvata cu succes." << endl;
				}
				fAux.close();
			}

			if (ok != true)
				cout << "Nu toate fisierele citite sunt valide." << endl;
			else
				cout << "Toate fisierele au fost citite cu succes." << endl;
		}
		else
			cout << "Nu au fost primite fisiere txt drept argumente." << endl;
	}

	static void addInvoiceManually()
	{
		fstream fMAIN("FACTURI.txt", ios::app | ios::binary);

		nrTotalFacturiEmise++;
		string numeClient;
		string seria;
		float totalFactura;


		fMAIN.write((char*)&nrTotalFacturiEmise, sizeof(int));

		cout << "Dati numele clientului: "; cin >> numeClient;
		int lg1 = numeClient.length() + 1;
		fMAIN.write((char*)&lg1, sizeof(int));
		fMAIN.write(numeClient.data(), lg1 * sizeof(char));

		cout << "Dati seria facturii: "; cin >> seria;
		int lg2 = seria.length() + 1;
		fMAIN.write((char*)&lg2, sizeof(int));
		fMAIN.write(seria.data(), lg2 * sizeof(char));

		cout << "Dati totalul de plata: "; cin >> totalFactura;
		fMAIN.write((char*)&totalFactura, sizeof(float));

		fMAIN.close();
	}
};
int ModulFacturiFisiereBinare::nrTotalFacturiEmise = 0;

class ModulGenerariRapoarte {

public:
	static void sumaFacturi()
	{
		int nrFacturaOut;
		string numeClientOut;
		string seriaOut;
		float totalFacturaOut;

		float suma = 0;

		fstream fMAIN("FACTURI.txt", ios::in | ios::binary);

		for (int i = 1; i <= ModulFacturiFisiereBinare::getNrTotalFacturiEmise(); i++)
		{
			int lg1, lg2;

			fMAIN.read((char*)&nrFacturaOut, sizeof(int));

			fMAIN.read((char*)&lg1, sizeof(int));
			char* buffer = new char[lg1];
			fMAIN.read(buffer, lg1);
			numeClientOut = buffer;
			delete[] buffer;

			fMAIN.read((char*)&lg2, sizeof(int));
			char* buffer2 = new char[lg2];
			fMAIN.read(buffer2, lg2);
			seriaOut = buffer2;
			delete[] buffer2;

			fMAIN.read((char*)&totalFacturaOut, sizeof(float));
			suma += totalFacturaOut;
		}
		fMAIN.close();

		cout << "Raport generat." << endl;
		cout << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		cout << "Suma tuturor valorilor facturilor este: " << suma << endl;
		fstream f("Raport_1_Suma.txt", ios::out);
		f << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		f << "Suma tuturor valorilor facturilor este: " << suma << endl;
		f.close();
	}

	static void maxFacturi()
	{
		int nrFacturaOut;
		string numeClientOut;
		string seriaOut;
		float totalFacturaOut;

		float max = -1;
		int nrFacturaMax = -1;

		fstream fMAIN("FACTURI.txt", ios::in | ios::binary);

		for (int i = 1; i <= ModulFacturiFisiereBinare::getNrTotalFacturiEmise(); i++)
		{
			int lg1, lg2;

			fMAIN.read((char*)&nrFacturaOut, sizeof(int));

			fMAIN.read((char*)&lg1, sizeof(int));
			char* buffer = new char[lg1];
			fMAIN.read(buffer, lg1);
			numeClientOut = buffer;
			delete[] buffer;

			fMAIN.read((char*)&lg2, sizeof(int));
			char* buffer2 = new char[lg2];
			fMAIN.read(buffer2, lg2);
			seriaOut = buffer2;
			delete[] buffer2;

			fMAIN.read((char*)&totalFacturaOut, sizeof(float));
			if (max < totalFacturaOut)
			{
				max = totalFacturaOut;
				nrFacturaMax = nrFacturaOut;
			}
		}
		fMAIN.close();

		cout << "Raport generat." << endl;
		cout << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		cout << "Valoarea maxima a unei facturi este: " << max << ", cea de a " << nrFacturaMax << "-a factura emisa." << endl;
		fstream f("Raport_2_Max.txt", ios::out);
		f << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		f << "Valoarea maxima a unei facturi este: " << max << ", cea de a " << nrFacturaMax << "-a factura emisa." << endl;
		f.close();
	}

	static void avgFactura()
	{
		int nrFacturaOut;
		string numeClientOut;
		string seriaOut;
		float totalFacturaOut;

		float suma = 0;

		fstream fMAIN("FACTURI.txt", ios::in | ios::binary);

		for (int i = 1; i <= ModulFacturiFisiereBinare::getNrTotalFacturiEmise(); i++)
		{
			int lg1, lg2;

			fMAIN.read((char*)&nrFacturaOut, sizeof(int));

			fMAIN.read((char*)&lg1, sizeof(int));
			char* buffer = new char[lg1];
			fMAIN.read(buffer, lg1);
			numeClientOut = buffer;
			delete[] buffer;

			fMAIN.read((char*)&lg2, sizeof(int));
			char* buffer2 = new char[lg2];
			fMAIN.read(buffer2, lg2);
			seriaOut = buffer2;
			delete[] buffer2;

			fMAIN.read((char*)&totalFacturaOut, sizeof(float));
			suma += totalFacturaOut;
		}
		fMAIN.close();

		cout << "Raport generat." << endl;
		cout << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		cout << "Valoarea medie a unei facturi este: " << suma / ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		fstream f("Raport_3_Avg.txt", ios::out);
		f << "Facturi emise: " << ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		f << "Valoarea medie a unei facturi este: " << suma / ModulFacturiFisiereBinare::getNrTotalFacturiEmise() << endl;
		f.close();
	}

	static void Meniu()
	{
		int optiune = 0;
		cout << "Alegeti raportul pe care doriti sa il generati: " << endl <<
			"Pentru a calcula suma tuturor valorilor facturilor, folositi 1" << endl <<
			"Pentru a calcula cea mai mare valoare a facturilor, folositi 2" << endl <<
			"Pentru a calcula valoarea medie a unei facturi, folositi 3" << endl;
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			sumaFacturi();
			break;
		case 2:
			maxFacturi();
			break;
		case 3:
			avgFactura();
			break;
		default:
			cout << "Optiune invalida." << endl;
		}
	}
};

class ModulGenerariRapMateriale
{
public:
	virtual void setTemperatura(float temperaturaNoua) = 0;
	virtual float getTemperatura() = 0;

	virtual void afisareNrMaterialeTip() {
		cout << "Tipul de material nu a fost definit." << endl;
	}
	virtual void afisareTemperatura() {
		cout << "Tipul de material nu a fost definit." << endl;
	}
};

class MaterialLichid : public Material, public ModulGenerariRapMateriale
{
private:
	static int nrMaterialeLichide;
	float temperaturaSolidificare = 0;

public:
	MaterialLichid() : Material() { nrMaterialeLichide++; }
	~MaterialLichid() { nrMaterialeLichide--; }

	void setTemperatura(float temperaturaNoua)
	{
		this->temperaturaSolidificare = temperaturaNoua;
	}

	float getTemperatura()
	{
		return this->temperaturaSolidificare;
	}

	static int getNrMaterialeTip()
	{
		return nrMaterialeLichide;
	}

	void afisareNrMaterialeTip()
	{
		cout << "Nr total de materiale lichide salvate este: " << MaterialLichid::getNrMaterialeTip() << endl;
	}

	void afisareTemperatura()
	{
		cout << "Temperatura de solidificare a materialului lichid " << this->getDenumireMaterial() << " este " << this->temperaturaSolidificare << " grade Celsius." << endl;
	}
};
int MaterialLichid::nrMaterialeLichide = 0;

class MaterialSolid : public Material, public ModulGenerariRapMateriale
{
private:
	static int nrMaterialeSolide;
	float temperaturaTopire = 0;

public:
	MaterialSolid() : Material() { nrMaterialeSolide++; }
	~MaterialSolid() { nrMaterialeSolide--; }

	void setTemperatura(float temperaturaNoua)
	{
		this->temperaturaTopire = temperaturaNoua;
	}

	float getTemperatura()
	{
		return this->temperaturaTopire;
	}

	static int getNrMaterialeTip()
	{
		return nrMaterialeSolide;
	}

	void afisareNrMaterialeTip()
	{
		cout << "Nr total de materiale solide salvate este: " << MaterialSolid::getNrMaterialeTip() << endl;
	}

	void afisareTemperatura()
	{
		cout << "Temperatura de topire a materialului solid " << this->getDenumireMaterial() << " este " << this->temperaturaTopire << " grade Celsius." << endl;
	}
};
int MaterialSolid::nrMaterialeSolide = 0;

int main(int argc, char* argv[])
{
	/*
	// Faza 1
	Furnizor f1;
	f1.afisare();
	f1.setCUI("1");
	f1.setNumeFurnizor("Furnizor SRL");
	cout << f1.getNumeFurnizor() << endl;
	cout << f1.getCUIFurnizor() << endl;
	f1.modificare();
	cout << f1.getNumeFurnizor() << endl;
	cout << f1.getCUIFurnizor() << endl;
	Angajat a1;
	a1.afisare();
	a1.setSalariuCurent(10);
	a1.setSalariuCurent(20);
	a1.setFunctie("Functie de Test");
	a1.setNumeAngajat("Alexandru");
	cout << a1.getFunctie() << endl;
	cout << a1.getIstoricSalarii()[0] << endl;
	cout << a1.getNrSchimbariSalarii() << endl;
	cout << a1.getNrTotalAngajati() << endl;
	cout << a1.getNumeAngajat() << endl;
	a1.modificare();
	a1.afisare();
	cout << "Testare operatori >> si <<" << endl;
	cin >> a1;
	cout << a1;
	Client c1;
	c1.afisare();
	c1.setValoareUltimaComanda(10);
	c1.setAdresa("Adresa de Test");
	c1.setNumeClient("Vasile");
	cout << c1.getAdresa() << endl;
	cout << c1.getIstoricValComenzi()[0] << endl;
	cout << c1.getNrComenzi() << endl;
	cout << c1.getNrTotalClienti() << endl;
	cout << c1.getNumeClient() << endl;
	c1.modificare();
	cout << "Testare operatori >> si <<" << endl;
	cin >> c1;
	c1.afisare();
	cout << c1;
	Magazin mag1(1);
	mag1.afisare();
	mag1.setAdresa("adresa noua magazin");
	mag1.setManager(a1);
	int ore[7] = { 1,1,1,1,1,1,1 };
	mag1.setOreDeschidere(ore);
	int ore2[7] = { 2,2,2,2,2,2,2 };
	mag1.setOreInchidere(ore2);
	cout << mag1;
	cout << mag1.getAdresa() << endl;
	cout << mag1.getIdMagazin() << endl;
	Material mat1;
	mat1.afisare();
	mat1.setDenumireMaterial("Uraniu");
	mat1.setPretCurent(14.5);
	cout << mat1;
	cout << mat1.getDenumireMaterial() << endl;
	mat1.setPretCurent(12.3);
	cout << mat1.getIstoricPretPerKg()[1] << endl;
	cout << mat1.getNrSchimbariPreturi();

	// Faza 2
	ModulFacturiFisiereBinare::readArgsInvoices(argc, argv);
	ModulFacturiFisiereBinare::displayNthInvoiceFromBin(1);
	ModulFacturiFisiereBinare::addInvoiceManually(); //Client_3 , AC , 3.3
	ModulFacturiFisiereBinare::displayNthInvoiceFromBin(3);
	ModulFacturiFisiereBinare::readFromCSVToBin("CSV.csv");
	ModulFacturiFisiereBinare::displayNthInvoiceFromBin(5);
	ModulFacturiFisiereBinare::displayNthInvoiceFromBin(4);
	ModulGenerariRapoarte::sumaFacturi();
	ModulGenerariRapoarte::maxFacturi();
	ModulGenerariRapoarte::avgFactura();
	ModulGenerariRapoarte::Meniu(); // 1
	ModulGenerariRapoarte::Meniu(); // 2
	ModulGenerariRapoarte::Meniu(); // 3
	ModulGenerariRapoarte::Meniu(); // 0

	// Toate datele despre facturi sunt stocate intr-un fisier binar numit "FACTURI.txt"

	// fisiere text => salvare individuala a continutului fisierului (o factura pe fisier text) in fisierul binar cu datele despre facturi
	// fisiere CSV => salvare multipla a continutului fisierului (mai multe facturi in fisier) in fisierul binar cu datele despre facturi

	// Numele clientilor trebuie sa fie un sir de caractere care nu contine spatii
	// Seria clientilor trebuie sa fie un sir de caractere care nu contine spatii
	// Valoarea facturii trebuie sa fie un numar real pozitiv
	*/

	// Faza 3
	MaterialLichid apa;
	apa.setDenumireMaterial("Apa");
	apa.setTemperatura(0);
	cout << "Temperatura: " << apa.getTemperatura() << endl;
	apa.afisareNrMaterialeTip();
	apa.afisareTemperatura();

	MaterialSolid fier;
	fier.setDenumireMaterial("Fier");
	fier.setTemperatura(1538);
	cout << "Temperatura: " << fier.getTemperatura() << endl;
	fier.afisareNrMaterialeTip();
	fier.afisareTemperatura();

	MaterialSolid aluminiu;
	aluminiu.setDenumireMaterial("Aluminiu");
	aluminiu.setTemperatura(660.3);
	cout << "Temperatura: " << aluminiu.getTemperatura() << endl;
	aluminiu.afisareNrMaterialeTip();
	aluminiu.afisareTemperatura();

	MaterialLichid mercur;
	mercur.setDenumireMaterial("Mercur");
	mercur.setTemperatura(-38.83);
	cout << "Temperatura: " << mercur.getTemperatura() << endl;
	mercur.afisareNrMaterialeTip();
	mercur.afisareTemperatura();

	Material generic;
	generic.setDenumireMaterial("Generic");

	cout << "Denumirile materialelor create: " << endl;
	Material* vctMat[] = { &apa, &fier, &aluminiu, &mercur, &generic };
	for (int i = 0; i < 5; i++)
	{
		cout << vctMat[i]->getDenumireMaterial() << " ";
	}
	cout << endl << "Temperaturile specifice proprietatilor materialelor create: " << endl;
	ModulGenerariRapMateriale* vctGenerariRapoarteMat[] = { &apa, &fier, &aluminiu, &mercur };
	for (int i = 0; i < 4; i++)
	{
		cout << vctGenerariRapoarteMat[i]->getTemperatura() << " ";
	}

	cout << endl << "_____STL_____" << endl;
	cout << "Vector de temperaturi: " << endl;
	vector<float> vTemperaturi;
	vTemperaturi.push_back(apa.getTemperatura());
	vTemperaturi.push_back(fier.getTemperatura());
	vTemperaturi.push_back(aluminiu.getTemperatura());
	vTemperaturi.push_back(mercur.getTemperatura());

	vector<float>::iterator it1;
	for (it1 = vTemperaturi.begin(); it1 != vTemperaturi.end(); it1++)
		cout << *it1 << " ";
	cout << endl;

	cout << "Lista de temperaturi: " << endl;
	list<float> lTemperaturi;
	lTemperaturi.push_back(apa.getTemperatura());
	lTemperaturi.push_back(fier.getTemperatura());
	lTemperaturi.push_front(aluminiu.getTemperatura());
	lTemperaturi.push_front(mercur.getTemperatura());

	list<float>::reverse_iterator it2;
	for (it2 = lTemperaturi.rbegin(); it2 != lTemperaturi.rend(); it2++)
		cout << *it2 << " ";
	cout << endl;

	cout << "Set de temperaturi: " << endl;
	set<float> sTemperaturi;
	sTemperaturi.insert(apa.getTemperatura());
	sTemperaturi.insert(fier.getTemperatura());
	sTemperaturi.insert(aluminiu.getTemperatura());
	sTemperaturi.insert(mercur.getTemperatura());

	set<float>::iterator it3;
	for (it3 = sTemperaturi.begin(); it3 != sTemperaturi.end(); it3++)
		cout << *it3 << " ";
	cout << endl;

	cout << "Cautare temperatura 0 grade Celsius in set: " << endl;
	it3 = sTemperaturi.find(0);
	if (it3 != sTemperaturi.end())
		cout << "Temperatura a fost gasita. " << endl;
	else
		cout << "Temperatura NU a fost gasita. " << endl;

	cout << "Map de temperaturi: " << endl;
	map<char*, float> mTemperaturi;
	mTemperaturi[apa.getDenumireMaterial()] = apa.getTemperatura();
	mTemperaturi[fier.getDenumireMaterial()] = fier.getTemperatura();
	mTemperaturi[aluminiu.getDenumireMaterial()] = aluminiu.getTemperatura();
	mTemperaturi[mercur.getDenumireMaterial()] = mercur.getTemperatura();

	map<char*, float>::iterator it4;
	for (it4 = mTemperaturi.begin(); it4 != mTemperaturi.end(); it4++)
		cout << it4->first << ": " << it4->second << endl;

	return 0;
}