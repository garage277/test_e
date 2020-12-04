#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <functional>

using namespace std;

struct microbe_life_t{
    size_t life_hours{0};
    int16_t first_child{-1};
    int16_t second_child{-1};
};

struct generation_t{
    size_t sum{0};
    size_t n{0};
};

using pop_cont_t = std::map<uint16_t, microbe_life_t>; //контейнер с кучей микробов
using gen_cont_t = std::vector<generation_t>; //контейнер с данными по поколениям

void f(pop_cont_t &populations, gen_cont_t &generations, uint16_t number, size_t depth)
{
    //получаем бактерию
    auto ml = populations.at(number);

    //depth - глубина рекурсии = поколение
    if( generations.size() < depth+1 ) //новое поколение
        generations.push_back({ml.life_hours,1});
    else //плюсуем в уже существующее поколение
    {
        generations[depth].sum += ml.life_hours;
        ++generations[depth].n;
    }

    if( ml.first_child != -1 ) //есть потомок #1 ?
        f( populations, generations, ml.first_child, depth+1 );
    if( ml.second_child != -1 ) //есть потомок #2 ?
        f( populations, generations, ml.second_child, depth+1 );

    return;
}

int main()
{
    cin.exceptions(std::ios::failbit);
    size_t len{0};
    cin >> len;

    if( len < 1 || len > 1000 )
        throw std::invalid_argument("количесво бактерий должно быть [1,1000]");


    //в populations храним инфу о всех бактериях
    pop_cont_t populations;
    for(size_t i=0; i<len; ++i)
    {
        uint16_t number{0};
        microbe_life_t ml;

        cin >> number >> ml.life_hours >> ml.first_child >> ml.second_child;

        populations.insert_or_assign(number, ml);
    }

    //в generations подсчитываем среднее время жизни. индекс - номер поколения
    gen_cont_t generations;


    //начинаем с первой бактерии
    f(populations, generations,1,0);

    cout << fixed << setprecision(2);
    for( size_t i=0; i<generations.size(); ++i )
    {
        if( i!=0 )
            cout << " ";
        auto x = generations[i];
        float tmp(x.sum);
        cout << tmp/x.n;
    }

    cout << endl;

    return 0;
}
