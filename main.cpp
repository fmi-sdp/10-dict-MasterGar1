#include "unordered_map"
#include "string"
#include "vector"
#include "iostream"
using namespace std;

template <typename T, typename P>
void print_map(unordered_map<T, P> dict) {
     cout << "contents:\n";
     for (auto& p : dict)
          cout << ' ' << p.first << " => " << p.second << '\n';
}

template <typename T>
void print_vec(vector<T> vec) {
     cout << "[ ";
     size_t size = vec.size();
     for(size_t i = 0; i < size; i++) {
          cout << vec[i];
          if(i < size - 1) {
               cout << " , ";
          }
     }
     cout<<" ]";
}

template <typename T, typename P>
void print_map(unordered_map<T, vector<P>> dict) {
     cout << "contents:\n";
     for (auto& p : dict) {
          cout << ' ' << p.first << " => ";
          print_vec(p.second);
          cout << endl;
     }
}


unordered_map<string, int> word_frequency(vector<string> words) {
     unordered_map<string, int> holder;
     for(const string& word : words) {
          if(holder.count(word) == 0) {
               holder.insert({word, 1});
          } else {
               holder[word] += 1;
          }
     }
     print_map(holder);
     return holder;
}
typedef pair<string, string> tupstr;
unordered_map<string, vector<string>> group_by_category(vector<tupstr> objects) {
     unordered_map<string, vector<string>> holder;
     for(const tupstr& obj : objects) {
          if(holder.count(obj.second) == 0) {
               vector<string> vec = {obj.first};
               holder.insert({obj.second, vec});
          } else {
               holder[obj.second].push_back(obj.first);
          }
     }

     print_map(holder);
     return holder;
}

typedef unordered_map<char, char> charmap;
string replace_given(string text, charmap dict) {
     for(char& c : text) {
          if(dict.count(c) == 1) {
               c = dict[c];
          }
     }
     cout<<text;
     return text;
}
typedef  pair<int, int> pint;
typedef vector<pint> numvec;
numvec find_summed(vector<int> vec, int sum) {
     size_t size = vec.size();
     numvec found;
     for(size_t i = 0; i < size - 1; i++) {
          for(size_t j = i + 1; j < size; j++) {
               if(vec[i] + vec[j] == sum) {
                    found.emplace_back(i, j);
               }
          }
     }
     cout << "[ ";
     for(size_t i = 0; i < found.size(); i++) {
          cout << "( " << found[i].first << " , " << found[i].second << " )";
          if(i < found.size() - 1) {
               cout << " , ";
          }
     }
     cout<<" ]";
     return found;
}

void find_symmetric(numvec vec) {
     unordered_map<pint, bool> map();
     for(pint el : vec) {
          if(map.count(el) == 0) {
               map.insert({el, false});
          } else if(map.count(pint(el.second, el.first))) {

          }
     }
}

int main() {
     // Task 1
     // word_frequency({"apple", "banana", "apple", "orange", "banana", "apple"});
     // Task 2
     // vector<tupstr> vec =     {tupstr("apple", "fruit"),
     //                          tupstr("carrot", "vegetable"),
     //                          tupstr("banana", "fruit"),
     //                          tupstr("broccoli", "vegetable")};
     // group_by_category(vec);
     // Task 3
     // charmap dict;
     // dict.insert({'h', 'H'});
     // dict.insert({'e', '3'});
     // dict.insert({'o', '0'});
     // replace_given("hello world",dict);
     // Task 4
     // find_summed({8, 7, 2, 5, 3, 1}, 10);
     return 0;
}