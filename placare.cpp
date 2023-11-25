#include <fstream>
using namespace std;
int main()
{
    ifstream citeste("placare.in");
    ofstream scrie("placare.out");
    int n; citeste >> n;
    int m; citeste >> m;
    int a[n][m], i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (j < m)
        {
            while (a[i][j] > 0 && j < m)
            {
                j++;
            }
            if (j < m)
            {
                int cod; citeste >> cod;
                if (cod < 0)
                {
                    for (int linie = i; linie < n; linie++)
                    {
                        a[linie][j] = cod*(-1);
                    }
                    j++;
                }
                else
                {
                    for (int coloana = j;
                         coloana < (j + cod); coloana++)
                    {
                        a[i][coloana] = cod;
                    }
                    j += cod;
                }
            }
        }
    }
    citeste.close();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scrie << a[i][j] << ' ';
        }
        scrie << endl;
    }
    scrie.close();
    return 0;
}
