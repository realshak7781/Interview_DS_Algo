#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FAST_IO;
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        
        int bad = -1, margin = 1e9, need = 0;
        bool reject = false;

        for (int i = 0; i < N; i++) {
            cin >> B[i];
            if (A[i] < B[i]) {
                if (bad != -1) reject = true;
                bad = i;
                need = B[i] - A[i];
            } else {
                margin = min(margin, A[i] - B[i]);
            }
        }

        if (reject) {
            cout << "NO\n";
        } else {
            cout << ((margin >= need) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
