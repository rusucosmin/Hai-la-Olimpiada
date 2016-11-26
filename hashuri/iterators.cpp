#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


//    for(auto it : v)
//        cout << it << ' ';

    for(auto it = v.begin(); it != v.end(); ++ it)
        if(*it == 2) {
            v.erase(it);
            break;
        }

    for(int i = 0; i < v.size(); ++ i)
        if(v[i] == 6)
            v.erase(v.begin() + i);

    for(int i = 0; i < v.size(); ++ i) {
        if(v[i] == 9) {
            swap(v[i], v[v.size() - 1]);
            v.pop_back();
        }
    }

}
