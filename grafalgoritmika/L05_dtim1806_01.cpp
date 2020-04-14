//Demeter Tamas
//dtim1806
//511/2
//lab5 1

#include <iostream> 
#include <fstream>
#include <queue> 
using namespace std;

//melysegi bejaras kevesebb parameterrel(min vagat)
void dfs(int a[50][50], int s, bool latogatott[],int n)
{
	latogatott[s] = true;
	for (int i = 0; i < n; i++)
		if (a[s][i] && !latogatott[i])
			dfs(a, i, latogatott,n);
}

//melysegi bejarassal meghatarozzuk a "szulok" vektorat
bool bfs(int ra[50][50], int s, int d, int szulo[],int n)
{
	//latogatottsag
	bool latogatott[50] = { false };
	
	//varakozasi sorral bejarjuk
	queue <int> q;
	q.push(s);
	latogatott[s] = true;
	szulo[s] = -1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++)
		{
			if (latogatott[v] == false && ra[u][v] > 0)
			{
				q.push(v);
				szulo[v] = u;
				latogatott[v] = true;
			}
			if (latogatott[u] && !latogatott[v] && ra[u][v])
				cout << u << " - " << v << endl;
		}

	}

	//ha a nyelohoz ertunk, vege
	return (latogatott[d] == true);
}

//Ford Fulkerson
int ff(int a[50][50], int s, int t,int n)
{
	int u, v;

	//rezidualis graf letrehozasa
	int ra[50][50];  		  
	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++)
			ra[u][v] = a[u][v];

	int szulo[50];  
	int maxf = 0;  

	//amig el tudunk jutni a forrsabol a nyelobe, szamoljuk a maximalis folyam erteket
	while (bfs(ra, s, t, szulo,n))
	{
		int f = 9999; //aktualis folyam
		for (v = t; v != s; v = szulo[v])
		{
			u = szulo[v];
			f = min(f, ra[u][v]);
		}

		//az eleket megforditjuk minden iteracioban
		for (v = t; v != s; v = szulo[v])
		{
			u = szulo[v];
			ra[u][v] -= f;
			ra[v][u] += f;
		}
		maxf += f;
	}
	//min vagat
	bool latogatott[50] = { false };
	dfs(ra, s, latogatott,n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (latogatott[i] && !latogatott[j] && a[i][j])
				cout << i << " - " << j << endl;
	return maxf;
}

int main()
{
	//az indexekbol kivontam 1-et, mert 0tol indexelek.
	int a[50][50] = { 0 };
	ifstream f;
	f.open("graf.txt");
	int n, s, d, i, j, k;
	f >> n;
	f >> s >> d;
	while (!f.eof()) {
		f >> i >> j >> k;
		a[i - 1][j - 1] = k;
	}
	cout << "min vagat:" << endl;
	cout << "maxfolyam: " << ff(a, s-1, d-1, n);
	f.close();
	return 0;
}

