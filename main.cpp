#include "SparceMatrix.h"

int main() {
    //////General checker/////
    SparceMatrix<int, -1> sm;
    assert(sm.size() == 0);
    Element a = sm[0][0];
    assert(sm.size() == 0);
    sm[100][100] = 314;
    assert(sm.size() == 1);
    ////////Secondary checker///
    int N = 10;
    SparceMatrix <int, 0> m;
    for (auto i = 0; i < N; i++) {
        m[i][i] = i;
        m[i][N - i] = N - i;
    }
    for (auto i = 1; i < N; i++) {
        for (auto j = 1; j < N; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "All size matrix = " << m.size() << std::endl;
    return 0;
}

