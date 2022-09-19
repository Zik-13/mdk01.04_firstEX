#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void first()
{
    double a;
    double b;
    double c;
    double x;
    cout << "Enter a value a: ";
    cin >> a;
    cout << "Enter a value b: ";
    cin >> b;
    cout << "Enter a value c: ";
    cin >> c;
    if ((b * b - 4 * a * c) >= 0) //Если дискриминант больше или равен 0
    {
        x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "The first root is equal to " << x << endl;
        x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "The second root is equal to " << x << endl;
    }
    else
    {
        cout << "The discriminant is less than 0, the roots are insubstantial." << endl;
    }
    cout << " " << endl;
}

void second() {
    int n, i, j, k;
    double d, s;
    cout << "Poryadok: " << endl;
    cin >> n;
    double** a = new double* [n];
    for (i = 0; i <= n; i++)
        a[i] = new double[n];
    double** a1 = new double* [n];
    for (i = 0; i <= n; i++)
        a1[i] = new double[n];
    double* b = new double[n];
    double* x = new double[n];

    cout << "Vvedite koefficienty i svobodnye chleny " << endl;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[ " << i << "," << j << "]= ";
            cin >> a[i][j];
            a1[i][j] = a[i][j];
        }
        cout << "b,[ " << i << "]= ";
        cin >> b[i];
    }
    for (k = 1; k <= n; k++) // прямой ход
    {
        for (j = k + 1; j <= n; j++)
        {
            d = a[j][k] / a[k][k]; // формула (1)
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
            }
            b[j] = b[j] - d * b[k]; // формула (3)
        }
    }

    for (k = n; k >= 1; k--) // обратный ход
    {
        d = 0;
        for (j = k + 1; j <= n; j++)
        {
            s = a[k][j] * x[j]; // формула (4)
            d = d + s; // формула (4)
        }
        x[k] = (b[k] - d) / a[k][k]; // формула (4)
    }
    cout << "Korni sistemy: " << endl;

    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "]=" << x[i] << " " << endl;
    }
        
    cout << " " << endl;
}

void third() {
    int k;
    cout << "Vvedite cishlo: ";
    cin >> k;
    long int x, d;
    x = k;
    for (d = 1; d < x; d++)
    {
        k = k * (x - d);
        cout << "x[" << d << "]=" << k << endl;
    }
    cout << " " << endl;
}

int main()
{   
    int x;
    float y = true;
    while (y) {

        try
        {
            cout << "Enter number task: ";
            cin >> x;
            switch (x)
            {
            case 1:
                first();
                break;
            case 2:
                second();
                break;
            case 3:
                third();
                break;

            default:
                cout << "I don't know what this number, repeat. ";
                break;
            }
        }
        catch (const std::exception&)
        {
            cout << "I don't know what this number, repeat. ";
        }
    }

    return 0; 
}