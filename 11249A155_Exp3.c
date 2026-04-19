#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void print(char s[], int b) {
    printf("\n%s\nTotal bins used: %d\n", s, b);
}

/* -------- FIRST FIT -------- */
void firstFit(int w[], int n, int cap) {
    int bin[MAX], bins = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bins; j++)
            if (bin[j] >= w[i]) {
                bin[j] -= w[i];
                break;
            }

        if (j == bins)
            bin[bins++] = cap - w[i];
    }

    print("First Fit:", bins);
}

/* -------- SORT DESCENDING -------- */
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

/* -------- FIRST FIT DECREASING -------- */
void firstFitDec(int w[], int n, int cap) {
    int t[MAX], bin[MAX], bins = 0;

    for (int i = 0; i < n; i++)
        t[i] = w[i];

    qsort(t, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bins; j++)
            if (bin[j] >= t[i]) {
                bin[j] -= t[i];
                break;
            }

        if (j == bins)
            bin[bins++] = cap - t[i];
    }

    print("First Fit Decreasing:", bins);
}

/* -------- BEST FIT -------- */
void bestFit(int w[], int n, int cap) {
    int bin[MAX], bins = 0;

    for (int i = 0; i < n; i++) {
        int best = -1, min = cap + 1;

        for (int j = 0; j < bins; j++)
            if (bin[j] >= w[i] && bin[j] - w[i] < min) {
                best = j;
                min = bin[j] - w[i];
            }

        if (best != -1)
            bin[best] -= w[i];
        else
            bin[bins++] = cap - w[i];
    }

    print("Best Fit:", bins);
}

/* -------- MAIN -------- */
int main() {
    int n, cap, w[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &cap);

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    firstFit(w, n, cap);
    firstFitDec(w, n, cap);
    bestFit(w, n, cap);

    return 0;
}
