#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100000
#define DIVIDER '|'

int main()
{
    int pal[LIMIT] = {0};
    char characters[LIMIT];

    string str;
    while (cin >> str) {
        int N = str.size();
        memset(characters, DIVIDER, sizeof(characters));

        int doubleN = (N << 1) + 1;

        for (int i = 0; i < N; i++) {
            characters[2 * i + 1] = str[i];
        }

        int center = 0, right = 0;
        int maximum = 0;
        int maximumCenter = 0;

        for (int i = 0; i < doubleN; ++i) {
            int mirror = (center << 1) - i;

            if (i < right) {
                pal[i] = min(right - i, pal[mirror]);
            }

            while (
                i - pal[i] - 1 >= 0 &&
                i + pal[i] + 1 < doubleN &&
                characters[i - pal[i] - 1] == characters[i + pal[i] + 1]
            ) ++pal[i];

            if (i + pal[i] > right) {
                center = i;
                right = i + pal[i];
            }

            if (pal[i] > maximum) {
                maximum = pal[i];
                maximumCenter = i;
            }
        }

        int s = 0;
        int st = maximumCenter - maximum;
        int dr = maximumCenter + maximum;
        for (int i = st; i < dr; ++i) {
            if (characters[i] != DIVIDER) ++s;
        }

        cout << s << endl;
    }

    return 0;
}
