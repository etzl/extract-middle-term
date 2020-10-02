#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

template<typename... T>
void print(T... args)
{
    (std::cout << ... << args) << '\n';
}

forward_list<int> extract_pairs(const int product, const int adds)
{
    forward_list<int> numbers;

    if (product>0) { // both factors are positive or both negative
        vector<int> ignores;

        for (int i=1; i<=product; ++i) {
            if (product%i == 0) {
                {
                    // don't repeat from the list
                    bool has_i =
                        find(ignores.begin(), ignores.end(), i)!=ignores.end();
                    if (has_i)
                        continue;
                }

                int factor = product / i;
                // we will probably test factor too so we must ignore it
                ignores.push_back(factor);

                bool b = (factor + i == adds);

                if (b) {
                    numbers = {factor, i};
                    break;
                }
                // opposite sign of both numbers could adds too!
                else if ((-factor-i) == adds) {
                    numbers = {-factor, -i};
                    break;
                }
            }
        }
    }
    else if (product<0) { // one of factors are positive and one is negative
        int local_product = -product;

        for (int i =1; i<=local_product; ++i) {
            if (local_product%i==0) {
                // we can't ignore because -3+5!=-5+3
                int factor = -(local_product / i);
                bool b = (factor + i == adds);

                if (b) {
                    numbers = {factor, i};
                    break;
                }
            }
        }
    }


    return numbers;
}

void input(int& product, int& adds)
{
    cout << "xy=";
    cin >> product;
    cout << "x+y=";
    cin >> adds;
}

int main()
{
    int product, adds;
    input(product, adds);
    forward_list<int> numbers = extract_pairs(product, adds);

    if (numbers.empty()) {
        print("couldn't find any!");
        return 1;
    }

    for (const auto& n: numbers)
        print(n);
    return 0;
}
