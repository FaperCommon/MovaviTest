#include <iostream>
#include <vector>
#include <set>



int main()
{
    const int size = 1000000;

    std::vector<int> vec(size);
    for(int i = 0;i < size;i++)
         vec.push_back(rand()%10000);

    std::set<int> s( vec.begin(), vec.end() );
    vec.assign( s.begin(), s.end() );

    return 0;
}


