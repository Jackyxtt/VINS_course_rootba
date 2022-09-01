#include <iostream>
#include <vector>
#include <tbb/tbb.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_for.h>

using namespace std;
using namespace tbb;

typedef vector<int>::iterator IntVecIt;

struct body
{
    void operator()(const blocked_range<IntVecIt>&r)const
    {
        for(auto i = r.begin(); i!=r.end(); i++)

            cout<<*i<<' ';
    }
};

int main()
{
    vector<int> vec;
    for(int i=0; i<10; i++)
        vec.push_back(i);

    parallel_for(blocked_range< IntVecIt>(vec.begin(), vec.end())
            , body());
    return 0;
}