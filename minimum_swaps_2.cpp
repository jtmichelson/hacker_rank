/* You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. 
You are allowed to swap any two elements. 
You need to find the minimum number of swaps required to sort the array in ascending order. */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> split_string(string);

vector<int> remap(const vector<int>& arg){
    vector<pair<int, int>> valToIndex;
    for (int i = 0; i < arg.size(); ++i){
        valToIndex.emplace_back(make_pair(arg[i], i));
    }
    sort(valToIndex.begin(), valToIndex.end());
    vector<int> res(arg.size());
    for (int i = 0; i < arg.size(); ++i){
        res[valToIndex[i].second] = i+1;
    }
    return res;
}

int minimumSwaps(std::vector<int> arr) {
    vector<int> consecArr = remap(arr);
    int minimumSwaps = 0;
    for(int i = 0; i < consecArr.size(); ++i) {
        if(consecArr[i] == i+1) {
            continue;
        }
        swap(consecArr[i], consecArr[consecArr[i]-1]);
        minimumSwaps++;
        --i;
    }
    return minimumSwaps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
