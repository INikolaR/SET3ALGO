#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>& a, int start, int end, int i) {
    // n isthe size of the heapifying part of the array: only firts n elements will be heapifyed.
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < end && a[l] > a[largest]) {
		largest = l;
    }
	if (r < end && a[r] > a[largest]) {
		largest = r;
    }
    // cout << largest << endl;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, start, end, largest);
	}
}

void buildHeap(vector<int>& a, int start, int end) {
    for (int i = (end - start) / 2 - 1 + start; i >= start; i--) {
		heapify(a, start, end, i);
    }
}

void heapSort(vector<int>& a, int start, int end) {
    buildHeap(a, start, end);
	for (int i = end - 1; i >= start; i--) {
		swap(a[0], a[i]);
		heapify(a, start, i, start);
	}
}

int partition(vector<int>& a, int start, int end) {
    int pivot = a[start];
    int left = start + 1;
    int right = end - 1;
    while (true) {
        while (a[left] < pivot && left < end) {
            ++left;
        }
        while (a[right] >= pivot && right >= left) {
            --right;
        }
        if (right < left) {
            break;
        }
        swap(a[left], a[right]);
    }
    swap(a[start], a[right]);
    return right;
}
 
void quickSort(vector<int>& a, int start, int end) {
    if (start >= end - 1) {
        return;
    }
    int pivot = partition(a, start, end);
    quickSort(a, start, pivot);
    quickSort(a, pivot + 1, end);
}

/// @brief Realization of hybrid (merge + insertion) sort. Uses merge sort if end - start > limit, else - insertion sort.
/// @param a array
/// @param start start index
/// @param end end index
/// @param limit the maximum number of elements to do insertion sort
void hybrid_sort(vector<int>& a, int start, int end, int limit) {
    if (end - start <= limit) {
        heapSort(a, start, end);
    }
    if (start >= end - 1) {
        return;
    }
    int pivot = partition(a, start, end);
    quickSort(a, start, pivot);
    quickSort(a, pivot, end);
}

void get_data_from_N2(vector<int>& random_data, vector<int>& reversed_data, vector<int>& almost_sorted_data) {
    random_data = vector<int>(4000);
    reversed_data = vector<int>(4000);
    almost_sorted_data = vector<int>(4000);
    ifstream fin;
    fin.open("./../N2/generated_arrays.txt", std::ifstream::in);
    for (int i = 0; i < 4000; ++i) {
        fin >> random_data[i];
    }
    for (int i = 0; i < 4000; ++i) {
        fin >> reversed_data[i];
    }
    for (int i = 0; i < 4000; ++i) {
        fin >> almost_sorted_data[i];
    }
}

long long measure_quick(vector<int>::iterator start, int size) {
    long long microsec = 0;
    for (int j = 0; j < 10000; ++j) {
        vector<int> c(size);
        copy(start, start + size, c.begin());
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(c, 0, c.size());
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        microsec += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    }
    return microsec  / 10000;
}

long long measure_hybrid(vector<int>::iterator start, int size, int limit) {
    long long microsec = 0;
    for (int j = 0; j < 10000; ++j) {
        vector<int> c(size);
        copy(start, start + size, c.begin());
        auto start = std::chrono::high_resolution_clock::now();
        hybrid_sort(c, 0, c.size(), limit);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        microsec += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    }
    return microsec  / 10000;
}

int main() {
    ofstream fout;
    fout.open("generated_data_quick.txt", std::ofstream::out);
    vector<int> random_data;
    vector<int> reversed_data;
    vector<int> almost_sorted_data;
    get_data_from_N2(random_data, reversed_data, almost_sorted_data);
    for (int i = 500; i <= 4000; i += 100) {
        fout << i << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_quick(random_data.begin(), i) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_quick(reversed_data.begin(), i) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_quick(almost_sorted_data.begin(), i) << " ";
    }
    fout << endl;
    fout.close();

    fout.open("generated_data_hybrid.txt", std::ofstream::out);
    for (int i = 500; i <= 4000; i += 100) {
        fout << i << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(random_data.begin(), i, 5) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(random_data.begin(), i, 10) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(random_data.begin(), i, 20) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(random_data.begin(), i, 50) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(reversed_data.begin(), i, 5) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(reversed_data.begin(), i, 10) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(reversed_data.begin(), i, 20) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(reversed_data.begin(), i, 50) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(almost_sorted_data.begin(), i, 5) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(almost_sorted_data.begin(), i, 10) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(almost_sorted_data.begin(), i, 20) << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_hybrid(almost_sorted_data.begin(), i, 50) << " ";
    }
    fout << endl;


    fout.close();

    return 0;
}