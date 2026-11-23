#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    string string;
    cin >> string;

    // 

    
    int smallest_excite = 0;
    int largest_excite = 0;

    int cur_length = 0;

    int i = 0;

    int end_F = 0;

    // checking the start F?
    int a = 0;
    while (a < N && string[a] == 'F'){
        end_F++;
        a++;
    }
    

    if (a == N) {
        cout << N << endl;
        for (int i = 0; i < N; i++) {
            cout << i << endl;
        }
        return 0;
    }

    for (int j = 1; j < N; j++) {
        if (string[j] != 'F' && string[j] == string[j - 1]) {
            smallest_excite++;
            largest_excite++;
        }
    }
    
    i = a;
    char first_char;

    
    while (i<N){
        
        if (string[i] == 'F'){
            first_char = string[i-1];
            while (i < N && string[i] == 'F') {
                cur_length++;
                i++;
            }
            if (i == N) {
                end_F += cur_length;
                break;
            }
            else{
                if (string[i] != first_char){
                    largest_excite += cur_length;
                    smallest_excite += cur_length % 2;
                }else{
                    largest_excite += cur_length+1;
                    smallest_excite += (cur_length+1) % 2;
                }
                
                
            }
            
        }
        cur_length = 0;
        i++;
        
    }

    if (end_F>0){
        cout << largest_excite+end_F-smallest_excite+1 << endl;
        for (int i = smallest_excite;i<=largest_excite+end_F;i++){
            cout << i << endl;
        }
    }else{
        cout <<(largest_excite-smallest_excite)/2+1 << endl;
        for (int i = smallest_excite; i <= largest_excite; i += 2){
            cout << i << endl;
        }
    }

}