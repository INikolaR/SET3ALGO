#include <bits/stdc++.h>

using namespace std;

/// @brief Realization of insertion sort.
/// @param a array
/// @param start start index
/// @param end end index
void insertion_sort(vector<int>& a, int start, int end) {
    size_t n = end - start;
    int key, j;
    for (int i = start + 1; i < start + n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= start && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

/// @brief Realization of merge sort.
/// @param a array
/// @param start start index
/// @param end end index
void merge_sort(vector<int>& a, int start, int end) {
    if (start + 1 == end) {
        return;
    }
    int middle = (start + end) / 2;
    merge_sort(a, start, middle);
    merge_sort(a, middle, end);
    vector<int> c(end - start);
    merge(a.begin() + start, a.begin() + middle, a.begin() + middle, a.begin() + end, c.begin());
    copy(c.begin(), c.end(), a.begin() + start);
}

/// @brief Realization of hybrid (merge + insertion) sort. Uses merge sort if end - start > limit, else - insertion sort.
/// @param a array
/// @param start start index
/// @param end end index
/// @param limit the maximum number of elements to do insertion sort
void hybrid_sort(vector<int>& a, int start, int end, int limit) {
    if (end - start <= limit) {
        insertion_sort(a, start, end);
        return;
    }
    if (start + 1 == end) {
        return;
    }
    int middle = (start + end) / 2;
    merge_sort(a, start, middle);
    merge_sort(a, middle, end);
    vector<int> c(end - start);
    merge(a.begin() + start, a.begin() + middle, a.begin() + middle, a.begin() + end, c.begin());
    copy(c.begin(), c.end(), a.begin() + start);
}

void generate_data(vector<int>& random_data, vector<int>& reversed_data, vector<int>& almost_sorted_data) {
    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    std::uniform_int_distribution<> dis(0, 3000);
    std::uniform_int_distribution<> dis2(0, 4000);
    random_data = vector<int>(4000);
    reversed_data = vector<int>(4000);
    almost_sorted_data = vector<int>(4000);
    for (int i = 0; i < 4000; ++i) {
        random_data[i] = dis(engine);
    }
    copy(random_data.begin(), random_data.end(), reversed_data.begin());
    sort(reversed_data.begin(), reversed_data.end());
    copy(reversed_data.begin(), reversed_data.end(), almost_sorted_data.begin());
    reverse(reversed_data.begin(), reversed_data.end());
    for (int i = 0; i < 100; ++i) {
        int first = dis2(engine);
        int second = dis2(engine);
        swap(almost_sorted_data[first], almost_sorted_data[second]);
    }
}

long long measure_merge(vector<int>::iterator start, int size) {
    long long microsec = 0;
    for (int j = 0; j < 10000; ++j) {
        vector<int> c(size);
        copy(start, start + size, c.begin());
        auto start = std::chrono::high_resolution_clock::now();
        merge_sort(c, 0, c.size());
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
    fout.open("generated_arrays.txt", std::ofstream::out);
    vector<int> random_data;
    vector<int> reversed_data;
    vector<int> almost_sorted_data;
    generate_data(random_data, reversed_data, almost_sorted_data);
    for (int i = 0; i < random_data.size(); ++i) {
        fout << random_data[i] << " ";
    }
    fout << endl;
    for (int i = 0; i < reversed_data.size(); ++i) {
        fout << reversed_data[i] << " ";
    }
    fout << endl;
    for (int i = 0; i < almost_sorted_data.size(); ++i) {
        fout << almost_sorted_data[i] << " ";
    }
    fout << endl;
    fout.close();
    fout.open("generated_data_merge.txt", std::ofstream::out);
    for (int i = 500; i <= 4000; i += 100) {
        fout << i << " ";
    }
    fout << endl;
    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_merge(random_data.begin(), i) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_merge(reversed_data.begin(), i) << " ";
    }
    fout << endl;

    for (int i = 500; i <= 4000; i += 100) {
        fout << measure_merge(almost_sorted_data.begin(), i) << " ";
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