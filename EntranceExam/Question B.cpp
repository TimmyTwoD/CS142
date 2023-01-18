#include <iostream>
#include <map>

int main() {
    
    int n;
    int m;

    std::cin>>n;

    std::map<int, int> frog;

    for (int i = 0; i < n; i++)
    {
        std::cin>>m;
        frog[m]++;
    }

    for(auto iterator = frog.begin(); iterator != frog.end(); iterator++)
    {
        std::cout<<iterator->first<<" "<<iterator->second<<"\n";
    }

    return 0;
}