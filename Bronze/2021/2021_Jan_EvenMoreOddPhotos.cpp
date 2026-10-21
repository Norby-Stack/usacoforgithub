#include <bits/stdc++.h>
using namespace std;

/*
my plan is to count the amount of even and odd numbers because thats the only thing we need
i will split it into 3 main cases

1. even = odd
if there are same amount of even and odd, we can just return the total amount because they will all work

2. if odd > even
there are 3 cases here
    1. if (o-e) % 3 = 0
    we can just make 2 odds into 1 even and that is just
    subracting 2 to odd and adding 1 to even until they are the same 
    this is because the difference is changed by 3 every time while the total amount decreases by 1
    then we can just return o + e

    2. if (o-e) % 3 = 2
    then we keep doing the operation we will eventually get odd + 2 = even
    then we can just add 2 evens together and then it will work since even is only 1 greater than odd
    we can just add odd and even

    3. if (o-e) % 3 = 1
    then we keep doing the operation we will eventually get odd + 1 = even
    we can just do the same logic for the with the mod =2 and just add odd and even

3. if even > odd
we can just keep combinging evens so that even is only 1 greater than odd
and print it



*/


int main() 
{

// taking input
int N;
cin >> N;

int cur_cow;

int evens = 0;
int odds = 0;

for (int i = 0;i<N;i++) {
    cin >> cur_cow;
    if (cur_cow % 2 == 0) 
    evens++;
    else
    odds++;
}

// main variables

if (odds == evens) {
    cout << N;
} else if (odds > evens) {

    if ((odds-evens) % 3 == 0) {
        cout << N - (odds-evens) / 3;
    } else if ((odds-evens) % 3 == 1) {
        cout << N - (odds-evens) / 3 - 2;
    } else {
        cout << N - (odds-evens) / 3 - 1;
    }

} else
cout << 2*odds+1;






}