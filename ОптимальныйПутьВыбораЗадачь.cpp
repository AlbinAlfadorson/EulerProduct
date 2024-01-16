#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

struct problem {
    int startTime, solvingTime, endTime, score, index;
};

bool sort_problems_by_endtime(problem a, problem b) {
    return a.endTime < b.endTime;
}

tuple<int, vector<int>> maxScore(vector<problem> problems) {
    sort(problems.begin(), problems.end(), sort_problems_by_endtime); // сортируем задачи по времени окончания их решения

    vector<int> links(problems.size());
    vector<long> problems_optimal(problems.size()); // создаем динамический массив, хранящий оптимальные решения,
                                                    // где problems_optimal[i] - это максимальное кол-во баллов, которое возможно получить,
                                                    // используюя только первые i задач
    problems_optimal[0] = 0; 

    int j = 0;  // j хранит индекс последней задачи, которая заканчивается не позже чем начинается задача i
    problems[j].endTime = 0;

    for (size_t i = 1; i < problems_optimal.size(); i ++) {
        if (i == 1) {
            j = 0;
        }
        else {
            for (; j < i; j ++) {
                if (problems[j].endTime > problems[i].startTime) {
                    break;
                }
            }

            j --;
        } // вычисляем j методом двойных указателей
                                                // выясняем что лучше: решать или не решать
        problems_optimal[i] = max(problems_optimal[i - 1], problems_optimal[j] + problems[i].score); 

        if (problems_optimal[i - 1] > problems_optimal[j] + problems[i].score) { // создаем ссылку
            links[i] = -1;
        }
        else {
            links[i] = j;
        }
    }

    vector<int> moves;
    for (int i = problems_optimal.size() - 1; i != 0;) { // восстанавливаем решение (т. е. извлекаем ход решения задач)
        if (links[i] == -1) {
            i --;
        }
        else {
            moves.push_back(problems[i].index);
            i = links[i];
        }
    }

    return make_tuple(problems_optimal[problems_optimal.size() - 1], moves); // возвращаем оптимальное кол-во очков и массив с ходом решения
}


int main() {
    int k;

    cin >> k;
    vector<problem> problems(k + 1); // создаем динамический массив с задачами, причём нумеровать будем с единицы, чтобы не запутаться

    for (int i = 1; i <= k; i ++) {
        cin >> problems[i].startTime >> problems[i].solvingTime >> problems[i].score;

        problems[i].endTime = problems[i].startTime + problems[i].solvingTime; // высчитываем время конца решения задачи

        problems[i].index = i; // так как дальше массив с задачами будет отсортирован, нам необходимо запомнить начальные положения задач
    }

    cout << get<0>(maxScore(problems)) << endl;

    vector<int> moves = get<1>(maxScore(problems));

    cout << moves.size() << endl;

    for (int i = moves.size() - 1; i >= 0; i --) {
        cout << moves[i] << " ";
    }

    system("pause");
    return 0;
}
