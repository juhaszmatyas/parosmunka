#include <iostream>
#include <vector>
#include <set>

using namespace std;


bool possible(vector<vector<int>> preferences, vector<int> choices, int index)
{
    set<int> dupl;
    for (int i = 0; i < index; i++)
        dupl.insert(preferences[i][choices[i]]);
    return dupl.size() == index;
}

int calc_satisfaction(vector<int> choices)
{
    int sum = 0;
    for (auto& e : choices)
        sum += e;
    return sum;
}

int main()
{
    int N;
    cin >> N;
    vector<int> choices(N, -1), result(N);
    vector<vector<int>> preferences(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> preferences[i][j];

    int i = 0;
    int best_satisfaction = INT_MAX;
    while (i >= 0)
    {
        if (i >= N)
        {
            int satisfaction = calc_satisfaction(choices);
            if (satisfaction < best_satisfaction)
            {
                best_satisfaction = satisfaction;
                for (int j = 0; j < N; j++)
                    result[j] = preferences[j][choices[j]];
            }

            i--;
        }

        do {
            choices[i]++;
        } while (choices[i] < N && !possible(preferences, choices, i));

        if (choices[i] < N)
        {
            i++;
        }
        else
        {
            choices[i] = -1;
            i--;
            if (i < 0) break;
        }
    }

    std::cout << best_satisfaction << "\n";
    for (auto& e : result)
        std::cout << e << " ";
    std::cout << "\n";
}