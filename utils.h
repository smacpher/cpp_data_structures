#ifndef UTILS_H
#define UTILS_H

using namespace std;

/* TestUtils class prototype. */
class Utils {
    public:
        int rand_int_between(int l_bound, int u_bound);
};

/* TestUtils class definition. */
int Utils::rand_int_between(int l_bound, int u_bound) {
    return rand() % (u_bound - l_bound + 1) + l_bound;
}

#endif /* UTILS_H */

