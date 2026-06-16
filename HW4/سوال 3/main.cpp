#include <iostream>
using namespace std ;
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);





long long int partition(long long int arr[], long long int start, long long int end)
{

    long long int pivot = arr[start];

    long long int count = 0;
    for (long long int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    long long int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    long long int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(long long int arr[], long long int start, long long int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    long long int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}


//تابع های کوییک سرت

int main() {
    IoFast;
    long long int n = 0, t, p, q, j, sum;
    long long int counter = -1, c = 1;

    cin >> n >> t;
    long long int answer[n], answer_1[n];
    long long int arr[n], list[n];

    for (long long int i = 0; i < n; i++) {
        cin >> p;
        arr[i] = p;
        list[i] = p;
    }


    quickSort(arr, 0, n - 1);


    long long int tekrari[n][2];
    for (long long int z = 0; z < n; z++) {
        tekrari[z][0] = 0;
        tekrari[z][1] = 0;
    }
    for (long long int i = 0; i < n; i++) {
        if (arr[i] != tekrari[counter][0]) {
            counter += 1;
            tekrari[counter][0] = arr[i];
            c = 1;
            tekrari[counter][1] = c;
        } else {
            c += 1;
            tekrari[counter][1] = c;

        }
    }

    answer[0] = (counter + 1);
    sum = (counter + 1);
    for (long long int k = 0; k < n; k++) {
        long long int max, min, middle;
        max = (counter);
        min = -1;
        while ((max - min) != 1) {
            middle = ((min + max) / 2);
            if (list[k] >= tekrari[middle][0]) {
                min = middle;
            }
            if (list[k] < tekrari[middle][0]) {
                max = middle;
            }

        }

        if (list[k] == tekrari[min][0]) {
            tekrari[min][1] -= 1;
            if (tekrari[min][1] == 0) {
                sum -= 1;
                answer[k+1 ] = sum + 1;

            }
            else {
                answer[k+1 ] = sum;
            }
        }
        else if  (list[k] == tekrari[counter][0]) {
            tekrari[counter][1] -= 1;
            if (tekrari[counter][1] == 0) {
                sum -= 1;
                answer[k+1] = (sum + 1);

            }
            else {
                answer[k+1 ] = sum;
            }
        }
    }

    for (long long int i = 0; i < t; i++) {
        cin >> q;
        cout<<answer[q]<<endl;
    }
}