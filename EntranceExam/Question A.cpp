#include <iostream>
#include <cmath>

int main() {

    int a;
    int b;
    int r;
    int n;

    int c;
    int d;

    std::cin>>a>>b>>r>>n;

    for (int i = 0; i<n; i++)
    {
        std::cin>>c>>d;

        if (r>= sqrt(pow(a-c,2) + pow(b-d,2)))
        {
            std::cout<<"no\n";
        }
        else
        {
            std::cout<<"yes\n";
        }

    }

    return 0;
}