//Demeter Tamas
//511/2
//dtim1806
//P1

//A tesztelo program sikeresen lefutott 
//Minden teszt helyes volt

void reverse(int n, int* x);
void swap(int& a, int& b);
class NagyEgesz {
	int* szam;
	int hossz;
	int e;

public:
	NagyEgesz();
	NagyEgesz(int elojel, int n, const int* szamjegyek);
	NagyEgesz(const NagyEgesz& x);
	~NagyEgesz();
	NagyEgesz operator=(const NagyEgesz& x);
	bool operator==(const NagyEgesz& x);
	NagyEgesz osszead(const NagyEgesz& x);
	NagyEgesz kivon(const NagyEgesz& x);
	NagyEgesz szoroz(const NagyEgesz& x);
	NagyEgesz oszt(const NagyEgesz& x);
	void kiir() const;

	class NullavalValoOsztas {

	};

};
