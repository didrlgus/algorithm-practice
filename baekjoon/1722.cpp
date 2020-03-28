// 1722. 순열의 순서
#include <iostream>
#include <vector>

using namespace std;

bool check[21];
long long fac[21];

int main()
{

    int N;
    cin >> N;

    int cmd;
    cin >> cmd;

    fac[0] = 1;

    for (int i = 1; i < 21; i++)
    {
        fac[i] = i * fac[i - 1];
    }

    if (cmd == 1)
    {

        long long k;
        cin >> k;

        vector<int> vec(N);

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[j])
                {
                    continue;
                }
                if (k > fac[N - i - 1])
                {
                    k -= fac[N - i - 1];
                }
                else
                {
                    vec[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << vec[i] << " ";
        }
    }
    else
    {
        vector<int> vec(N);
        for (int i = 0; i < N; i++)
        {
            cin >> vec[i];
        }

        long long result = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < vec[i]; j++)
            {
                if (check[j])
                {
                    continue;
                }
                result += fac[N - 1 - i];
            }
            check[vec[i]] = true;
        }

        cout << result + 1;
    }
    return 0;
}