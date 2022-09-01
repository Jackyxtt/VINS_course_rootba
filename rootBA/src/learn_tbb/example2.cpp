//
// Created by yxt on 2022/8/31.
//

#include <iostream>
#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>
#include <vector>

using namespace std;
using namespace tbb;

int main()
{
    vector<int> vec;
    for(int i=0; i<100; i++)
        vec.push_back(i);

    int result = parallel_reduce(blocked_range<vector<int>::iterator>(vec.begin(), vec.end()),
                                 0,[](const blocked_range<vector<int>::iterator>& r, int init)->int{

                for(auto a = r.begin(); a!=r.end(); a++)
                    init+=*a;
                return init;
            },

                                 [](int x, int y)->int{
                                     return x+y;
                                 }
    );
    cout<<"result:"<<result<<endl;
    return 0;

}