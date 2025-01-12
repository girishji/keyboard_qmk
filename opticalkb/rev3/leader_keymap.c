#include "leader.h"

// Rule of thumb: Vowels are avoided in map lhs, unless vowel refers to template
// parameter (ex. vector<int> is vi).


void leader_fi(void) {
    SEND_STRING("for (int i = 0; i < (int); i++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 20; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_fj(void) {
    SEND_STRING("for (int j = 0; j < (int); j++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 20; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_fk(void) {
    SEND_STRING("for (int k = 0; k < (int); k++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 20; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_fa(void) {
    SEND_STRING("for (auto&  : ) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 11; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_ft(void) {
    SEND_STRING("for (auto it = .begin(); it != .end(); it++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 15; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_fm(void) {
    SEND_STRING("// map | views::values, map | views::keys\n");
    SEND_STRING("for (const auto& [key, val] : ) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 30; i++) SEND_STRING(SS_TAP(X_RIGHT));
}

void leader_fe(void) {
    SEND_STRING("ranges::for_each(, [](int& n) {});"); // for_each_n(iter, n, UnaryFn) applies to first n elements
    for (int i = 0; i < 17; i++) SEND_STRING(SS_TAP(X_LEFT));
}

void leader_pr(void) {
    // SEND_STRING("ranges::for_each(, [](const int& n) {cout << n;});cout<<endl;");
    SEND_STRING("for (const auto& t : ) { cout << t << \" \"; }; cout << endl;");
    for (int i = 0; i < 38; i++) SEND_STRING(SS_TAP(X_LEFT));
}

void leader_p2(void) {
    SEND_STRING("ranges::copy(, ostream_iterator<int>(cout, \" \"));cout<<endl;");
    for (int i = 0; i < 47; i++) SEND_STRING(SS_TAP(X_LEFT));
}

void leader_be(void) {
    SEND_STRING(".begin(), .end()");
    for (int i = 0; i < 16; i++) SEND_STRING(SS_TAP(X_LEFT));
}

void leader_vi(void) {
    SEND_STRING("vector<int> ");
}

void leader_vv(void) {
    SEND_STRING("vector<vector<int>> ");
}

void leader_vs(void) {
    SEND_STRING("vector<string> ");
}

void leader_pi(void) {
    SEND_STRING("pair<int,int> ");
}

void leader_rg(void) {
    SEND_STRING("ranges::");
}

void leader_rv(void) {
    SEND_STRING("views::");
}

void leader_fn(void) {
    SEND_STRING("function<int(int)> fac = [&fac](int n) {");
}

void leader_cscln(void) {
    // send_string_with_delay("cout <<  << endl;", 10);
    SEND_STRING("cout <<  << endl;");
    for (int i = 0; i < 9; i++) SEND_STRING(SS_TAP(X_LEFT));
}

void leader_i(void) {
    const char *str =
    "using namespace string_view_literals;\n"
    "using i64 = int64_t;\n"
    "namespace rg = ranges;\n"
    "namespace rv = ranges::views;\n"
    "#define F first\n"
    "#define S second\n"
    "#define PB push_back\n"
    ;
    SEND_STRING(str);
}

void leader_mi(void) {
    SEND_STRING("numeric_limits<int>::max()");
}

void leader_ltlt(void) {
    const char *str =
    "template<typename Os, typename V>\n"
    "Os& operator<<(Os& os, const V& v) {\n"
    "    // for (os << \"{ \"; const auto& e : v) os << e << ' '; return os << \"}\";\n"
    "    // os << '(' << v.first << \", \" << v.second << ')'; return os;\n"
    "    bool o{};\n"
    "    for (os << \"{ \"; const auto& e : v) os << (o ? \", \" : (o = 1, \" \")) << e;\n"
    "    return os << \" }\n\";\n"
    "}\n"
    "struct Order {\n"
    "    int order_id{};\n"
    "    friend std::ostream& operator<<(std::ostream& os, const Order& ord) {\n"
    "        return os << '{' << ord.order_id << '}';\n"
    "    }\n"
    "};\n"
    "template<class T>\n"
    "std::ostream& operator<<(std::ostream& os, std::initializer_list<T> const& list) {\n"
    "    for (os << \"{ \"; auto const& e : list) os << e << ' '; return os << \"}\";\n"
    "}\n"
    ;
    // SEND_STRING("ostream& operator<<(ostream& os, const pair<int, int>& p) {\n");
    // SEND_STRING("os << '(' << p.first << \", \" << p.second << ')'; return os;\n}\n");
    SEND_STRING(str);
}

void leader_op(void) {
    const char* str =
    "optional<vector<int>> functionWithOptionalVector() {\n"
    "    if (some_condition) {\n"
    "        return vector<int>{1, 2, 3};\n"
    "    }\n"
    "    return nullopt; \n"
    "}\n"
    "if (maybeInt1) { // Checking if a value exists\n"
    "    cout << \"Has value: \" << *maybeInt1 << endl; \n"
    "}\n"
    "int value = maybeInt1.value(); // Throws if no value\n"
    "int safeValue = maybeInt1.value_or(0); // Safe access with default\n"
    ;
    SEND_STRING(str);
}

void leader_tp(void) {
    const char *str =
    "tuple<int, string, double> myTuple = {42, \"World\", 2.718};\n"
    "auto myTuple = make_tuple(42, \"World\", 2.718);\n"
    "auto [a, b, c] = myTuple;\n"
    "cout << get<0>(myTuple) << endl; // 42\n"
    ;
    SEND_STRING(str);
}

// Algorithms

void leader_a1(void) {
    const char *str =
        "// ast set_intersection set_union set_difference includes\n"
        "// ahp make_heap push_heap pop_heap is_heap sort_heap\n"
        "// amm max min max_element min_element clamp\n"
        "// amr merge\n"
        "// ait advance next prev distance (iterator operations)\n"
        "// apr is_permutation next_permutation\n"
        "// acv conversions for string char int\n"
        "// abt bitset\n"
        "// ams freopen getline swap_modify\n"
        "// apw zip pairwise iota cartesian_product\n"
        "// am2 increasing_strictly increasing decreasing_strictly decreasing\n"
        "//     iterate_over_unique_keys_in_sorted_range iterate_over_identical_keys_in_sorted_range\n"
        "// arg regex\n"
        "// arr reverse rotate shift_left shift_right\n"
        "// ass shuffle random_shuffle sample\n"
        "// aan all_of any_of none_of\n"
        ;
    SEND_STRING(str);
}

void leader_a2(void) {
    const char *str =
        "// acn ranges::contains ranges::contains_subrange\n"
        "// afn find find_if find_if_not find_last find_last_if find_last_if_not (see af2)\n"
        "// af2 find_end find_first_of adjacent_find\n"
        "// act count count_if\n"
        "// aeq equal\n"
        "// asc search search_n ranges::starts_with ranges::ends_with\n"
        "// afl ranges::fold_left ranges::fold_left_first ranges::fold_right ranges::fold_right_last\n"
        "// acp copy copy_if copy_n copy_backward move move_backward\n"
        "// asw swap swap_ranges iter_swap\n"
        "// atr transform\n"
        "// arp replace replace_if\n"
        "// afg fill generate\n"
        "// arm remove remove_if remove_copy remove_copy_if\n"
        "// auc unique unique_copy\n"
        "// apt is_partitioned partition stable_partition partition_point\n"
        "// asr sort stable_sort partial_sort (see as2)\n"
        "// as2 is_sorted is_sorted_until nth_element\n"
        "// abs lower_bound upper_bound equal_range binary_search (see ab2)\n"
        "// ab2 notes on comparison function for sorting, binary_search, and partitioning\n"
        ;
    SEND_STRING(str);
}

void leader_ascln(void) {
    leader_a1();
    leader_a2();
}

void leader_acv(void) { // Conversions
    const char* str =
    "'0' + 5\n"
    "ch - '0'\n"
    "bitset<32> binary(num); // num is int\n"
    "string str = to_string(num); // num is int\n"
    "stoi(str)\n"
    "stoull(str)\n"
    "while (auto ch : str) OR vector<char>(s.begin(), s.end())\n"
    "char to string; s += ch; string(1, ch); s.push_back(ch);\n"
    "conv_bin_string_number; string binaryString = \"1101\"; // Binary string\n"
    "int number = stoi(binaryString, nullptr, 2); // Convert to integer with base 2\n"
    ;
    SEND_STRING(str);
}

void leader_ast(void) {
    const char *str =
    "// OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2,\n"
    "//                     OutputIt d_first, Compare comp );\n"
    "//  bool cmp(const Type1& a, const Type2& b); // returns true if the first argument is less than the second.\n"
    "vector<int> res; set_intersection(vec1sortd.begin(), vec1sortd.end(), vec2sortd.begin(), vec2sortd.end(), back_inserter(res)); use ranges::\n"
    "vector<int> res; set_union(vec1sortd.begin(), vec1sortd.end(), vec2sortd.begin(), vec2sortd.end(), back_inserter(res)); use ranges::\n"
    "vector<int> res; set_difference(vec1sortd.begin(), vec1sortd.end(), vec2sortd.begin(), vec2sortd.end(), back_inserter(res)); use ranges::\n"
    "// bool includes( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp );\n"
    "//  bool cmp(const Type1& a, const Type2& b); // returns true if the first argument is less than the second.\n"
    "// Returns true if the sorted range [first2, last2) is a subsequence of the sorted range [first1, last1)\n"
    "//     Does not care about contiguous (see ex.)\n"
    "//     bool cmp(const Type1& a, const Type2& b); // returns true if the first argument is less than the second.\n"
    "const auto\n"
    "    b = {'a', 'c'},\n"
    "    c = {'a', 'a', 'b'},\n"
    "    f = {'A', 'B', 'C'},\n"
    "    z = {'a', 'b', 'c', 'f', 'h', 'x'};\n"
    "std::ranges::includes(z, b) // true, even though a and c are not contiguous\n"
    "std::ranges::includes(z, c) // false\n"
    "auto ignore_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };\n"
    "std::ranges::includes(z, f, ignore_case) // true\n"
    ;
    SEND_STRING(str);
}

void leader_amr(void) {
    const char* str =
    "// OutputIt merge( InputIt1 first1, InputIt1 last1,\n"
    "//             InputIt2 first2, InputIt2 last2,\n"
    "//             OutputIt d_first, Compare comp );\n"
    "// first1, last1 	- 	the first range of elements to merge\n"
    "// first2, last2 	- 	the second range of elements to merge\n"
    "// d_first 	- 	the beginning of the destination range \n"
    "//     bool cmp(const Type1& a, const Type2& b); // returns true if the first argument is less than the second.\n"
    "vector<int> res; merge(vec1sortd.begin(), vec1sortd.end(), vec2sortd.begin(), vec2sortd.end(), back_inserter(res));\n"
    ;
    SEND_STRING(str);
}

void leader_asr(void) {  // sort
    const char *str =
    "// void sort( RandomIt first, RandomIt last, Compare comp );\n"
    "//   bool cmp(const Type1& a, const Type2& b);\n"
    "//   returns true if the first argument is less than (i.e. is ordered before) the second.\n"
    "// void stable_sort( RandomIt first, RandomIt last, Compare comp );\n"
    "//   The order of equivalent elements is guaranteed to be preserved.\n"
    "// void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp );\n"
    "//   (sorts the first N elements of a range)\n"
    "//   Rearranges elements such that the range [first, middle) contains the\n"
    "//   sorted (middle − first) smallest elements\n"
    "sort(s.begin(), s.end(), greater<int>());\n"
    "struct {\n"
    "    bool operator()(int a, int b) const { return a < b; }\n"
    "} customLess;\n"
    "sort(s.begin(), s.end(), customLess);\n"
    "sort(s.begin(), s.end(), [](int a, int b) { return a > b; });\n"
    "int data[] = {3, 1, 4, 1, 5};\n"
    "assert(not std::is_sorted(std::begin(data), std::end(data), std::greater<>{}));\n"
    "int *const sorted_end = std::is_sorted_until(data, data + 3);\n"
    "sorted_size = std::distance(data, sorted_end);\n"
    "// Sort using projection, pair.first\n"
    "ranges::sort(v, {}, &pair<int, int>::first);\n"
    "ranges::sort(v, ranges::less{}, &pair<int, int>::first);\n"
    "sort_descending_projection; ranges::sort(v, ranges::greater{}, &pair<int, int>::first);\n"
    ;
    SEND_STRING(str);
}

void leader_as2(void) { // more sort
    const char *str =
    "// bool is_sorted( ForwardIt first, ForwardIt last, Compare comp );\n"
    "assert(std::is_sorted(v.cbegin(), v.cend()) && \"yes, sorted\");\n"
    "// ForwardIt is_sorted_until( ForwardIt first, ForwardIt last, Compare comp );\n"
    "// constexpr I ranges::is_sorted_until( I first, S last, Comp comp = {}, Proj proj = {} );\n"
    "//   finds the largest sorted subrange \n"
    "const auto sorted_end = std::ranges::is_sorted_until(nums);\n"
    "sorted_size = std::ranges::distance(nums.begin(), sorted_end);\n"
    "//\n"
    "// void nth_element( RandomIt first, RandomIt nth, RandomIt last, Compare comp );\n"
    "//   nth_element rearranges elements in [first, last) such that after the\n"
    "//   rearrangement the element pointed at by nth is changed to whatever element\n"
    "//   would occur in that position if [first, last) were sorted.\n"
    "// Find median\n"
    "std::vector<int> v{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};\n"
    "auto m = v.begin() + v.size() / 2;\n"
    "std::nth_element(v.begin(), m, v.end());\n"
    "std::cout << \"The median is \" << v[v.size() / 2] << '\n';\n"
    "//   median is 6\n"
    "//   v = {3, 2, 3, 4, 5, 6, 10, 7, 9, 6};\n"
    "// Second largest element (Note: comp function changed)\n"
    "std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater{});\n"
    "std::cout << \"The second largest element is \" << v[1] << '\n';\n"
    "std::cout << \"The largest element is \" << v[0] << '\n';\n"
    ;
    SEND_STRING(str);
}

void leader_ahp(void) { // heap
    const char *str =
    "vector<int> v{3, 2, 4, 1, 5, 9};\n"
    "make_heap(v.begin(), v.end()); // max heap\n"
    "pop_heap(v.begin(), v.end());  // sends the top element to last position\n"
    "auto top = v.back(); // get the top element (that was pushed to the back by pop_heap\n"
    "v.pop_back();  // remove the top element\n"
    "v.push_back(6);\n"
    "push_heap(v.begin(), v.end()); // reconsititute the heap to include '6'\n"
    "if (!is_heap(v.begin(), v.end()))\n"
    "sort_heap(v.begin(), v.end()); // heap property is lost\n"
    "auto heap_end = std::is_heap_until(v.begin(), v.end()); // iterator to last element which is still heap\n"
    "  // Examines the range [first, last) and finds the largest range beginning at first which is a heap.\n"
    "// min heap\n"
    "make_heap(v1.begin(), v1.end(), greater<>{});\n"
    "pop_heap(v1.begin(), v1.end(), greater<>{});  // see above\n"
    "push_heap(v1.begin(), v1.end(), greater<>{});  // see above\n";
    SEND_STRING(str);
}

void leader_amm(void) { // min max
    const char *str =
    "auto it = ranges::max_element(R, [](const auto& a, const auto& b) {}, &pair<x, y>::first);\n"
    "min_element(v.begin(), v.end())\n"
    "auto m = min({\"foo\", \"bar\", \"hello\"}, [](const string_view s1, const string_view s2) {\n"
    "                          return s1.size() < s2.size(); });\n"
    "max({010, 10, 0X10, 0B10})\n"
    "// ranges::min( const T& a, const T& b, Comp comp = {}, Proj proj = {} );\n"
    "ranges::min({\"foo\"sv, \"bar\"sv, \"hello\"sv}, {}, &string_view::size)\n"
    "ranges::min(1, 9999)\n"
    "ranges::min('a', 'b')\n"
    "// clamp: If the value of v is within [lo, hi], returns v; otherwise returns the nearest boundary.\n"
    "const T& clamp( const T& v, const T& lo, const T& hi, Compare comp );\n"
    "clamp(-129, INT8_MIN, INT8_MAX)  returns -128 (INT8_MIN=-128, INT8_MAX=127)\n"
    "clamp(128, INT8_MIN, INT8_MAX)  returns 127 (INT8_MIN=-128, INT8_MAX=127)\n"
    ;
    SEND_STRING(str);
}

void leader_ait(void) { // iterator
    const char *str =
    "// Increments given iterator it by n elements. If n is negative, the iterator is decremented. Returns nothing.\n"
    "    auto vi = v.begin();\n"
    "    advance(vi, 2);\n"
    "    advance(vi, -1);\n"
    "// Return the nth successor (or -nth predecessor if n is negative) of iterator it.\n"
    "    auto it = v.begin();\n"
    "    auto nx = next(it, 2);\n"
    "    nx = next(it, -2);\n"
    "// Return the nth predecessor (or -nth successor if n is negative) of iterator it.\n"
    "    auto pv = prev(it, 2);\n"
    "static_assert(distance(il.begin(), il.end()) == 3);\n"
    "static_assert(distance(il.end(), il.begin()) == -3);\n";
    SEND_STRING(str);
}

void leader_apr(void) { // permutation
    const char *str =
    "// bool next_permutation( BidirIt first, BidirIt last, Compare comp );\n"
    "//   bool cmp(const Type1& a, const Type2& b); // returns true if the first argument is less than the second.\n"
    "do {\n"
    "    cout << s << endl;\n"
    "} while (next_permutation(s.begin(), s.end()));\n"
    "string s = \"aba\"; produces: aba baa aab\n"
    "array a{'a', 'b', 'c'}; produces { a b c } { a c b } { b a c } { b c a } { c a b } { c b a }\n"
    "// bool is_permutation( ForwardIt1 first1, ForwardIt1 last1,\n"
    "//                  ForwardIt2 first2, ForwardIt2 last2,\n"
    "//                  BinaryPredicate pred );\n"
    "//      bool pred(const Type1 &a, const Type2 &b); // return true if the elements should be treated as equal.\n"
    "static constexpr auto v1 = {1, 2, 3, 4, 5};\n"
    "static constexpr auto v2 = {3, 5, 4, 1, 2};\n"
    "if (is_permutation(v1.begin(), v1.end(), v2.begin()))\n"
    ;
    SEND_STRING(str);
}

void leader_abt(void) { // bitset
    const char *str =
    "bitset<8> bits(42);  // Binary: 00101010\n"
    "if (bits.test(0)) cout << \"Bit 0 is 1\" << endl;\n"
    "cout << \"Number of 1 bits: \" << bits.count() << endl;\n"
    "cout << \"First set bit index: \" << bits._Find_first() << endl;\n"
    "// use << >> & | bit operations just like an int\n"
    "for (size_t i = 0; i < bits.size(); ++i) {}\n"
    "for (bool bit : bits) {}\n"
    ;
    SEND_STRING(str);
}

void leader_ams(void) { // miscellaneous
    const char *str =
    "freopen(\"file\", \"r\", stdin);<cr>for (string line; getline(cin, line); ) {}\n"
    "// Re-read input from a input stream. Easier to do it with istringstream, but\n"
    "// trickier with cin/stdin since you're dealing with actual input streams. Use\n"
    "// freopen() to convert cin to a line and open istringstream in this case.\n"
    "iss.clear(); iss.seekg(0);\n"
    "// Swap and modify;\n"
    "swap(i, j), j = -j\n"
    "tie(i, j) = tuple{j, -i};\n"
    ;
    SEND_STRING(str);
}

void leader_apw(void) {
    const char *str =
    "// pairwise;\n"
    "pairwise = views::zip(numbers, numbers | views::drop(1));\n"
    "// iota\n"
    "Fills the range [first, last) with sequentially increasing values, starting\n"
    "with value and repetitively evaluating ++value.\n"
    "std::list<int> list(8);\n"
    "std::ranges::iota(list, 0); // Fill the list with ascending values: 0, 1, 2, ..., 7\n"
    "// cartesian product\n"
    "for (auto [i, j] : views::cartesian_product(views::iota(0, m), views::iota(0, n))) {}\n"
    "const auto x = std::array{'A', 'B'};\n"
    "const auto y = std::vector{1, 2, 3};\n"
    "const auto z = std::list<std::string>{\"α\", \"β\", \"γ\", \"δ\"};\n"
    "for (int i{1}; auto const& tuple : std::views::cartesian_product(x, y, z))\n"
    "    print(tuple, i++);\n"
    ;
    SEND_STRING(str);
}

void leader_am2(void) { // miscellaneous
    const char *str =
    "increasing_strictly; ranges::adjacent_find(vec, greater_equal<int>()) == vec.end()\n"
    "increasing; ranges::adjacent_find(vec, greater<int>()) == vec.end()\n"
    "decreasing_strictly; ranges::adjacent_find(vec, less_equal<int>()) == vec.end()\n"
    "decreasing; ranges::adjacent_find(vec, less<int>()) == vec.end()\n"
    "// Iterate over unique keys (elements) in a sorted range\n"
    "for (auto it = p.begin(); it != p.end();\n"
    "    it = ranges::upper_bound(it, p.end(), it->first, {}, &plot_loc_t::first)) {}\n"
    "for (auto it = data.begin(); it != data.end();\n"
    "    it = ranges::upper_bound(it, data.end(), *it)) {}\n"
    "I upper_bound( I first, S last, const T& value,\n"
    "                   Comp comp = {}, Proj proj = {} );\n"
    "// Returns an iterator pointing to the first element in the range [first, last)\n"
    "    that is greater than value, or last if no such element is found.\n"
    "// Iterate over subrange of identical keys in a sorted range\n"
    "for (const auto& el : ranges::equal_range(p, it->first, {}, &plot_loc_t::first)) {}\n"
    "for (auto& el : ranges::equal_range(data, key)) {}\n"
    "ranges::subrange<I> equal_range( I first, S last, const T& value,\n"
    "                       Comp comp = {}, Proj proj = {} );\n"
    "Returns a view containing all elements equivalent to value in the range [first, last).\n"
    ;
    SEND_STRING(str);
}

void leader_arg(void) { // regex
    const char *str =
    "smatch matches;\n"
    "regex pat {R\"(\\w{2}\\s∗\\d{5}(−\\d{4})?)\"};\n"
    "if (regex_search(line, matches, pat)) {\n"
    "cout << lineno << \": \" << matches[0] << '\n'; // the complete match\n"
    "if (1 < matches.size() && matches[1].matched) // if there is a sub-pattern\n"
    "int x = stoi(matches[1].str());\n"
    "regex2; regex pat {R\"(\\s+(\\w+))\"};<c-r>=abbr#Eatchar()<cr>\n"
    "regex_iterator; for (sregex_iterator p(str.begin(), str.end(), pat); p!=sregex_iterator(); ++p) cout << (∗p)[0] << '\n';\n"
    "regex_array; vector<regex> pat{regex(R\"(Button A: X\\+(\\d+), Y\\+(\\d+))\"), regex(R\"(Button B: X\\+(\\d+), Y\\+(\\d+))\")};\n"
    ;
    SEND_STRING(str);
}


void leader_acn(void) { // contains
    const char *str =
    "// ranges::contains ranges::contains_subrange searches if a specific element or a range is in another range\n"
    "// see 'includes' also under set operations.\n"
    "bool contains( I first, S last, const T& value, Proj proj = {} );\n"
    "bool contains_subrange( R1&& r1, R2&& r2, Pred pred = {}, Proj1 proj1 = {}, Proj2 proj2 = {} );\n"
    "constexpr auto haystack = std::array{3, 1, 4, 1, 5};\n"
    "constexpr auto needle = std::array{1, 4, 1};\n"
    "ranges::contains(haystack, 4) // true\n"
    "ranges::contains_subrange(haystack, needle) // true\n"
    ;
    SEND_STRING(str);
}

void leader_afn(void) { // find
    const char *str =
    "// find searches for an element equal to value (using operator==).\n"
    "if (ranges::find(v, 5) != v.end()) cout << \"v contains: 5\" << '\n';\n"
    "// find_if searches for an element for which predicate p returns true.\n"
    "auto indices = views::cartesian_product(views::iota(0, 4), views::iota(0, 5));\n"
    "auto it = ranges::find_if(indices, [&](const auto& idx) { // use 'auto', not pair<int,int>\n"
    "    auto [i, j] = idx;\n"
    "    return matrix[i][j] == target;\n"
    "});\n"
    "if (it != indices.end()) cout << *it;\n"
    "// find_if_not searches for an element for which predicate q returns false. see find_if_ranges.\n"
    "//\n"
    "// ranges::find_last, ranges::find_last_if, ranges::find_last_if_not\n"
    "// Returns the last element in the range [first, last) that satisfies specific criteria:\n"
    "ranges::subrange<I> find_last( I first, S last, const T& value, Proj proj = {} );\n"
    "ranges::subrange<I> find_last_if( I first, S last, Pred pred, Proj proj = {} );\n"
    "constexpr static auto v = {1, 2, 3, 1, 2, 3, 1, 2};\n"
    "constexpr auto i2 = ranges::find_last(v, 3);\n"
    "static_assert(ranges::distance(v.begin(), i2.begin()) == 5);\n"
    "auto abs = [](int x) { return x < 0 ? -x : x; };\n"
    "auto pred = [](int x) { return x == 3; };\n"
    "constexpr auto i2 = ranges::find_last_if(v, pred, abs);\n"
    "static_assert(ranges::distance(v.begin(), i2.begin()) == 5);\n"
    ;
    SEND_STRING(str);
}

void leader_af2(void) { // find
    const char *str =
    "// find_end: Searches for the last occurrence of the sequence [s_first, s_last) in the range [first, last). \n"
    "//   Return: Iterator to the beginning of last occurrence of the sequence [s_first, s_last) in range [first, last).\n"
    "// ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p );\n"
    "//   bool pred(const Type1 &a, const Type2 &b); // returns true if the elements should be treated as equal.\n"
    "// find_first_of: Searches the range [first, last) for any of the elements in\n"
    "//   the range [s_first, s_last).\n"
    "// returns Iterator to the first element in the range [first, last) that is\n"
    "//   equal to an element from the range [s_first, s_last). Else, 'last' is returned.\n"
    "// InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last, BinaryPred p );\n"
    "//   bool pred(const Type1 &a, const Type2 &b); // returns true if the elements should be treated as equal.\n"
    "// adjacent_find: Searches the range [first, last) for two consecutive equal elements. \n"
    "//   Return: An iterator to the first of the first pair of identical elements. If\n"
    "//   no such elements are found, last is returned. \n"
    "ForwardIt adjacent_find( ForwardIt first, ForwardIt last, BinaryPred p );\n"
    "  bool pred(const Type1 &a, const Type2 &b); // returns true if the elements should be treated as equal.\n"
    "std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};\n"
    "auto i1 = std::adjacent_find(v1.begin(), v1.end());\n"
    "if (i1 == v1.end()) // No matching adjacent elements\n"
    "else // *i1 = 40\n"
    "auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());\n"
    "if (i2 == v1.end()) // The entire vector is sorted in ascending order\n"
    "else // The last element in the non-decreasing subsequence, *i2 = 41\n"
    ;
    SEND_STRING(str);
}

void leader_aan(void) {
    const char *str =
    "all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; }))\n"
    "any_of(v.cbegin(), v.cend(), DivisibleBy(7)))\n"
    "struct DivisibleBy {\n"
    "    const int d;\n"
    "    DivisibleBy(int n) : d(n) {}\n"
    "    bool operator()(int n) const { return n % d == 0; }\n"
    "};\n"
    "none_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; }));\n"
    ;
    SEND_STRING(str);
}

void leader_act(void) { // count
    const char *str =
    "//count, counf_if: Returns the number of elements in the range [first, last) satisfying specific criteria.\n"
    "count( InputIt first, InputIt last, const T& value );\n"
    "ranges::count( R&& r, const T& value, Proj proj = {} );\n"
    "count_if( InputIt first, InputIt last, UnaryPred p );\n"
    "ranges::count_if( R&& r, Pred pred, Proj proj = {} );\n"
    "const int num_items = std::count(v.cbegin(), v.cend(), target); // v is vector<int>, target=3\n"
    "int count_div4 = std::count_if(v.begin(), v.end(), [](int i) { return i % 4 == 0; });\n"
    ;
    SEND_STRING(str);
}

void leader_aeq(void) { // equal
    const char *str =
    "// equal: Checks whether [first1, last1) and a range starting from first2 are equal\n"
    "// Returns bool\n"
    "bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPred p );\n"
    "  bool pred(const Type1 &a, const Type2 &b); // true if the elements should be treated as equal.\n"
    "constexpr bool is_palindrome(const std::string_view& s) {\n"
    "    return std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());\n"
    "}\n"
    ;
    SEND_STRING(str);
}

void leader_asc(void) {  // search
    const char *str =
    "// search: Searches for the first occurrence of the sequence of elements\n"
    "// [s_first, s_last) in the range [first, last).\n"
    "// return: Iterator to the beginning of first occurrence of the sequence, else 'last' is returned.\n"
    "ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p );\n"
    "  bool pred(const Type1 &a, const Type2 &b); // true if the elements should be treated as equal.\n"
    "bool contains(const auto& cont, std::string_view s) {\n"
    "    // str.find() (or str.contains(), since C++23) can be used as well\n"
    "    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();\n"
    "}\n"
    "const auto str{\"why waste time learning, when ignorance is instantaneous?\"sv};\n"
    "assert(contains(str, \"learning\"));\n"
    "assert(not contains(str, \"lemming\"));\n"
    "// search_n: Searches the range [first, last) for the first sequence of count\n"
    "// identical elements, each equal to the given value\n"
    "ForwardIt search_n( ForwardIt first, ForwardIt last,\n"
    "                    Size count, const T& value, BinaryPred p );\n"
    "// ranges::starts_with Checks whether the second range matches the prefix of the first range.\n"
    "bool starts_with( R1&& r1, R2&& r2, Pred pred = {}, Proj1 proj1 = {}, Proj2 proj2 = {} );\n"
    "static_assert(std::ranges::starts_with(\"const_cast\", \"const\"sv));\n"
    "// ranges::ends_with Checks whether the second range matches the suffix of the first range.\n"
    "bool ends_with( R1&& r1, R2&& r2, Pred pred = {}, Proj1 proj1 = {}, Proj2 proj2 = {} );\n"
    "std::ranges::ends_with(\"dynamic_cast\", \"cast\") // true\n"
    ;
    SEND_STRING(str);
}

void leader_afl(void) { // fold
    const char *str =
    "ranges::fold_left -> returns the result of evaluation of the chain expression:\n"
    "ranges::fold_left_first -> *first is used internally as an initial element.\n"
    "return f(f(f(f(init, x1), x2), ...), xn), where x1, x2, ..., xn are elements of the range.\n"
    "ranges::fold_right -> return f(x1, f(x2, ...f(xn, init))), where x1, x2, ..., xn are elements of the range.\n"
    "ranges::fold_right_last -> use *last as initial value\n"
    "auto fold_left( R&& r, T init, F f );\n"
    "int mul = ranges::fold_left(v, 1, std::multiplies<int>()); // v is vector<int>\n"
    "std::string str = ranges::fold_left(v, \"A\",\n"
    "        [](std::string s, int x) { return s + ':' + std::to_string(x); });\n"
    "std::vector<std::string> vs{\"A\", \"B\", \"C\", \"D\"};\n"
    "auto r2 = ranges::fold_right(vs, \"!\"s, std::plus<>()); // ABCD!\n"
    ;
    SEND_STRING(str);
}

void leader_acp(void) { // copy
    const char *str =
    "// OutputIt copy( InputIt first, InputIt last, OutputIt d_first );\n"
    "// OutputIt copy_if( InputIt first, InputIt last, OutputIt d_first, UnaryPred pred );\n"
    "std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));\n"
    "std::copy(from_vector.begin(), from_vector.end(), std::ostream_iterator<int>(std::cout, " "));\n"
    "std::copy_if(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector),\n"
    "                 [](int x) { return x % 3 == 0; });\n"
    "std::copy_if(from_vector.begin(), from_vector.end(), std::ostream_iterator<int>(std::cout, " "),\n"
    "                 [](int x) { return x % 2 != 0; });\n"
    "// OutputIt copy_n( InputIt first, Size count, OutputIt result );\n"
    "//   Copies exactly count values\n"
    "std::copy_n(in.begin(), 4, std::back_inserter(out));\n"
    "std::vector<int> v_out(v_in.size());\n"
    "std::copy_n(v_in.cbegin(), 100, v_out.begin());\n"
    "// BidirIt2 copy_backward( BidirIt1 first, BidirIt1 last, BidirIt2 d_last );\n"
    "// Copies the elements from the range [first, last) to another range ending at\n"
    "// d_last. The elements are copied in reverse order (the last element is copied\n"
    "// first), but their relative order is preserved.\n"
    "std::copy_backward(source.begin(), source.end(), destination.end());\n"
    "// move and move_backward are similar to copy and copy_backward\n"
    ;
    SEND_STRING(str);
}

void leader_asw(void) { // swap
    const char *str =
    "// void swap( T& a, T& b );\n"
    "int a = 5, b = 3;\n"
    "std::swap(a, b);\n"
    "A p {6}, q {9}; // 'struct A' with 'friend void swap(A& lhs, A& rhs) {}'\n"
    "swap(p, q);\n"
    "// ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2 );\n"
    "// ranges::swap_ranges( R1&& r1, R2&& r2 );\n"
    "std::swap_ranges(from.begin(), v.begin() + 3, to.begin());\n"
    "// iter_swap -> Swaps the values of the elements the given iterators are pointing to.\n"
    "// void iter_swap( ForwardIt1 a, ForwardIt2 b );\n"
    "template<class ForwardIt>\n"
    "void selection_sort(ForwardIt begin, ForwardIt end) {\n"
    "    for (ForwardIt it = begin; it != end; ++it)\n"
    "        std::iter_swap(it, std::min_element(it, end));\n"
    "}\n"
    ;
    SEND_STRING(str);
}

void leader_atr(void) { // transform
    const char *str =
    "// unary_op vs binary_op\n"
    "// OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, UnaryOp unary_op );\n"
    "//   unary_op applied from first1 and result stored in d_first (could be equal to first1) onwards\n"
    "// OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOp binary_op );\n"
    "//   same except binary_op is applied to pairs of elements from two ranges: starting first1 and first2\n"
    "// also ranges::transform views::transform\n"
    "char to_uppercase(unsigned char c) { return std::toupper(c); }\n"
    "std::string hello(\"hello\");\n"
    "std::transform(hello.cbegin(), hello.cend(), hello.begin(), to_uppercase); // unary\n"
    "std::vector<unsigned> ordinals = {1,2,3,4};\n"
    "std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),\n"
    "                   ordinals.begin(), std::plus<>{}); // binary op, get {2,4,6,8}\n"
    ;
    SEND_STRING(str);
}

void leader_arp(void) { // replace
    const char *str =
    "// void replace( ForwardIt first, ForwardIt last, const T& old_value, const T& new_value );\n"
    "// void replace_if( ForwardIt first, ForwardIt last, UnaryPred p, const T& new_value );\n"
    "//   Replaces all elements in the range [first, last) with new_value if they satisfy specific criteria.\n"
    "std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};\n"
    "// Replace all occurrences of 8 with 88.\n"
    "std::replace(s.begin(), s.end(), 8, 88);\n"
    "// Replace all values less than 5 with 55.\n"
    "std::replace_if(s.begin(), s.end(), [](int x) { return x < 5; }, 55);\n"
    ;
    SEND_STRING(str);
}

void leader_afg(void) {
    const char *str =
    "// void fill( ForwardIt first, ForwardIt last, const T& value );\n"
    "//   Assigns the given value to all elements in the range [first, last).\n"
    "std::fill(v.begin(), v.end(), 8); // set all of the elements to 8\n"
    "// OutputIt fill_n( OutputIt first, Size count, const T& value );\n"
    "//   Same except assign to count elements.\n"
    "\n"
    "// void generate( ForwardIt first, ForwardIt last, Generator g );\n"
    "//   Assigns each element in range [first, last) a value generated by the given\n"
    "//   function object g.\n"
    "// Initialize with default values 0,1,2,3,4 from a lambda function\n"
    "// Equivalent to std::iota(v.begin(), v.end(), 0);\n"
    "std::generate(v.begin(), v.end(), [n = 0] () mutable { return n++; });\n"
    "std::generate(back_inserter(v), [n = 0] () mutable { return n++; });\n"
    "//   mutable: lambda-declarator that removes const qualification from parameters captured by copy\n"
    "// OutputIt generate_n( OutputIt first, Size count, Generator g );\n"
    "//   Similar to fill_n\n"
    "// Random number generator\n"
    "template<int min, int max>\n"
    "int rand_int() {\n"
    "    static std::uniform_int_distribution dist(min, max);\n"
    "    static std::mt19937 gen(std::random_device{}());\n"
    "    return dist(gen);\n"
    "}\n"
    "std::vector<int> v;\n"
    "std::generate_n(std::back_inserter(v), 20, rand_int< -9, +9>);\n"
    ;
    SEND_STRING(str);
}

void leader_arm(void) {
    const char *str =
    "// ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );\n"
    "// ForwardIt remove_if( ForwardIt first, ForwardIt last, UnaryPred p );\n"
    "//   Removes all elements satisfying specific criteria from the range [first,\n"
    "//   last) and returns a past-the-end iterator for the new end of the range. \n"
    "std::string str1{\"Text with some   spaces\"};\n"
    "auto noSpaceEnd = std::remove(str1.begin(), str1.end(), ' '); // spaces not removed yet\n"
    "// Note, the original string is still not shrunk.\n"
    "str1.erase(noSpaceEnd, str1.end()); // now the spaces are removed physically\n"
    "// Use UnaryPred:\n"
    "std::string str2 = \"Text\\n with\\tsome  whitespaces\\n\\n\";\n"
    "str2.erase(std::remove_if(str2.begin(), str2.end(),\n"
    "              [](unsigned char x) { return std::isspace(x); }), str2.end());\n"
    "\n"
    "// OutputIt remove_copy( InputIt first, InputIt last, OutputIt d_first, const T& value );\n"
    "// ForwardIt2 remove_copy( ExecutionPolicy&& policy, ForwardIt1 first, ForwardIt1 last,\n"
    "//                        ForwardIt2 d_first, const T& value );\n"
    "//   Copies elements from the range [first, last), to another range beginning\n"
    "//   at d_first, omitting the elements which satisfy specific criteria.\n"
    "// Erase the hash characters '#' on the fly.\n"
    "std::string str = \"#Return #Value #Optimization\";\n"
    "std::remove_copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout), '#');\n"
    ;
    SEND_STRING(str);
}

void leader_auc(void) {
    const char *str =
    "\n"
    "// ForwardIt unique( ForwardIt first, ForwardIt last, BinaryPred p );\n"
    "//   Range has to be sorted since it removed only adjacent equal elements.\n"
    "std::vector<int> v{1, 2, 1, 1, 3, 3, 3, 4, 5, 4};\n"
    "// remove consecutive (adjacent) duplicates\n"
    "auto last = std::unique(v.begin(), v.end());\n"
    "// v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate\n"
    "v.erase(last, v.end());\n"
    "\n"
    "// OutputIt unique_copy( InputIt first, InputIt last, OutputIt d_first, BinaryPred p );\n"
    "//   Copies the elements from the range [first, last), to another range\n"
    "//   beginning at d_first in such a way that there are no consecutive equal\n"
    "//   elements.\n"
    "//   bool pred(const Type1 &a, const Type2 &b); // returns true if the elements should be treated as equal\n"
    "std::string s2;\n"
    "std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),\n"
    "             [](char c1, char c2) { return c1 == 'm' && 'm' == c2; });\n"
    ;
    SEND_STRING(str);
}

void leader_arr(void) {
    const char *str =
    "// void reverse( BidirIt first, BidirIt last ); // Reverse the order of elements\n"
    "std::reverse(v.begin(), v.end());\n"
    "int a[] = {4, 5, 6, 7};\n"
    "std::reverse(std::begin(a), std::end(a));\n"
    "//\n"
    "// ForwardIt rotate( ForwardIt first, ForwardIt middle, ForwardIt last );\n"
    "//   Performs a left rotation on a range\n"
    "// simple rotation to the left, 0 1 2 -> 1 2 0\n"
    "std::rotate(v.begin(), v.begin() + 1, v.end());\n"
    "// simple rotation to the right\n"
    "std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());\n"
    "//\n"
    "// ForwardIt shift_left( ForwardIt first, ForwardIt last, difference_type n );\n"
    "// ForwardIt shift_right( ForwardIt first, ForwardIt last, difference_type n );\n"
    "//   Shifts the elements in the range [first, last) by n positions. \n"
    "std::vector<int>         b{1, 2, 3, 4, 5, 6, 7};\n"
    "std::shift_left(begin(b), end(b), 3); // 1 2 3 4 5 6 7  ->  4 5 6 7 5 6 7\n"
    ;
    SEND_STRING(str);
}

void leader_ass(void) {
    const char *str =
    "// void shuffle( RandomIt first, RandomIt last, URBG&& g );\n"
    "// void random_shuffle( RandomIt first, RandomIt last, RandomFunc& r );\n"
    "//   r 	- 	function object returning a randomly chosen value\n"
    "//   g 	- 	generator object returning a randomly chosen value\n"
    "//   Reorders the elements in the given range [first, last)\n"
    "std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};\n"
    "std::random_device rd;\n"
    "std::mt19937 g(rd());\n"
    "std::shuffle(v.begin(), v.end(), g);\n"
    "//\n"
    "// SampleIterator sample( PopulationIt first, PopulationIt last, SampleIt out, Distance n, URBG&& g );\n"
    "//   Selects n elements from the sequence [first, last) (without replacement)\n"
    "//   such that each possible sample has equal probability of appearance, and\n"
    "//   writes those selected elements into the output iterator out.\n"
    "std::string in {\"ABCDEFGHIJK\"}, out;\n"
    "std::sample(in.begin(), in.end(), std::back_inserter(out), 4,\n"
    "                std::mt19937 {std::random_device{}()});\n"
    ;
    SEND_STRING(str);
}

void leader_apt(void) {
    const char *str =
    "// bool is_partitioned( InputIt first, InputIt last, UnaryPred p );\n"
    "// ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPred p );\n"
    "//   p 	- 	unary predicate which returns true for the elements\n"
    "//   expected to be found in the beginning of the range.\n"
    "// BidirIt stable_partition( BidirIt first, BidirIt last, UnaryPred p );\n"
    "//   Relative order of the elements is preserved.\n"
    "std::array<int, 9> v {1, 2, 3, 4, 5, 6, 7, 8, 9};\n"
    "auto is_even = [](int i) { return i % 2 == 0; };\n"
    "std::cout << std::is_partitioned(v.begin(), v.end(), is_even) << ' ';\n"
    "auto it = std::partition(v.begin(), v.end(), is_even);\n"
    "// Partitioned vector:\n"
    "std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));\n"
    "//\n"
    "// ForwardIt partition_point( ForwardIt first, ForwardIt last, UnaryPred p );\n"
    "//   Examines the partitioned range [first, last) and locates the end of the\n"
    "//   first partition, that is, the first element that does not satisfy p or\n"
    "//   last if all elements satisfy p. \n"
    "const auto pp = std::partition_point(v.cbegin(), v.cend(), is_even);\n"
    ;
    SEND_STRING(str);
}

void leader_abs(void) { // binary search
    const char *str =
    "// ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );\n"
    "//   Returns first element in the range [first, last) which is not ordered (ex. less than) before value.\n"
    "// ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );\n"
    "//    Returns first element in the partitioned range [first, last) which is ordered after value.\n"
    "//   bool pred(const Type1 &a, const Type2 &b);\n"
    "//     returns true if the first argument is ordered before the second.\n"
    "const std::vector<int> data{1, 2, 4, 5, 5, 6};\n"
    "auto lower = std::lower_bound(data.begin(), data.end(), 3); // *lower=4 (not <3)\n"
    "auto lower = std::lower_bound(data.begin(), data.end(), 2); // *lower=2 (not <2)\n"
    "auto lower = std::lower_bound(data.begin(), data.end(), 7); // *lower=data.end()\n"
    "//\n"
    "std::vector data{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};\n"
    "//                                 ^^^^^^^^^^\n"
    "auto lower = ranges::lower_bound(data, 4);\n"
    "auto upper = ranges::upper_bound(data, 4);\n"
    "// lower points to first 4, upper to last 4\n"
    "//\n"
    "// std::pair<ForwardIt, ForwardIt> equal_range( ForwardIt first, ForwardIt last,\n"
    "//                   const T& value, Compare comp );\n"
    "// constexpr ranges::subrange<I> equal_range( I first, S last, const T& value,\n"
    "//                   Comp comp = {}, Proj proj = {} );\n"
    "//   Returns a range containing all elements equivalent to value\n"
    "auto a = ranges::equal_range(data, 4);\n"
    "for (const auto& e : a) cout << e << ' '; // 4 4 4 4\n"
    "auto p = equal_range(data.begin(), data.end(), 4);\n"
    "for (auto it = p.first; it != p.second; ++it) std::cout << *it << ' '; // 4 4 4 4\n"
    "//\n"
    "// bool binary_search( ForwardIt first, ForwardIt last, const T& value, Compare comp );\n"
    "// constexpr bool ranges::binary_search( R&& r, const T& value, Comp comp = {}, Proj proj = {} );\n"
    "//   Checks if an element equivalent to value appears within the range\n"
    "if (std::binary_search(sortedvecofint.begin(), sortedvecofint.end(), 3)) {}\n"
    ;
    SEND_STRING(str);
}

void leader_ab2(void) {
    const char *str =
    "// Comparator difference between non-ranges and ranges\n"
    "// Non-ranges:\n"
    "struct S {\n"
    "    int number;\n"
    "    char name;\n"
    "    // note: name is ignored by this comparison operator\n"
    "    bool operator<(const S& s) const { return number < s.number; }\n"
    "};\n"
    "struct Comp { // mixed comparison\n"
    "    bool operator()(const S& s, int i) const { return s.number < i; }\n"
    "    bool operator()(int i, const S& s) const { return i < s.number; }\n"
    "};\n"
    "// note: not ordered, only partitioned w.r.t. S defined below\n"
    "const std::vector<S> vec{{1, 'A'}, {2, 'B'}, {2, 'C'},\n"
    "                             {2, 'D'}, {4, 'G'}, {3, 'F'}};\n"
    "const S value{2, '?'};\n"
    "// Compare using S::operator<():\n"
    "const auto p = std::equal_range(vec.begin(), vec.end(), value);\n"
    "for (auto it = p.first; it != p.second; ++it)\n"
    "    std::cout << it->name << ' '; // B C D\n"
    "// Using heterogeneous comparison:\n"
    "const auto p2 = std::equal_range(vec.begin(), vec.end(), 2, Comp{}); // B C D\n"
    "//\n"
    "// ranges::\n"
    "struct S {\n"
    "    int number {};\n"
    "    char name {};\n"
    "    // note: name is ignored by these comparison operators\n"
    "    friend bool operator== (const S s1, const S s2) { return s1.number == s2.number; }\n"
    "    friend auto operator<=>(const S s1, const S s2) { return s1.number <=> s2.number; }\n"
    "    friend std::ostream& operator<<(std::ostream& os, S o) {\n"
    "        return os << '{' << o.number << \", '\" << o.name << \"'}\";\n"
    "    }\n"
    "};\n"
    "auto a = ranges::equal_range(vec, value);\n"
    "for (const auto& e : a)\n"
    "    std::cout << e << ' ';  // {2, 'B'} {2, 'C'} {2, 'D'}\n"
    "auto c = ranges::equal_range(vec, 'D', ranges::less {}, &S::name);\n"
    "for (const auto& e : c)\n"
    "    std::cout << e << ' ';  // {2, 'D'} {4, 'D'}\n"
    ;
    SEND_STRING(str);
}

// Documentation

void leader_dscln(void) {
    const char *str =
        "// dtm template\n"
        "// dfo function_object\n"
        "// dvc vector\n"
        "// dv0 vector/container: concat join_into_a_string slice erase_remove iterate_remove\n"
        "// dst string\n"
        "// ds0 string split_string\n"
        "// dls list\n"
        "// ddq deque\n"
        "// dts set\n"
        "// dmp map\n"
        ;
    SEND_STRING(str);
}

void leader_dtm(void) { // Templates
    const char *str =
    "template<typename T>\n"
    "class Less_than {\n"
    "const T val; // value to compare against\n"
    "// template of specific type\n"
    "template<int N>\n"
    "auto blink = [](int foo) -> u64 {\n"
    "    for (auto _ : flux::ints(0, N)) {}\n"
    "};\n"
    "auto const part1 = blink<25>;\n"
    "template<class T>\n"
    "std::ostream& operator<<(std::ostream& os, std::initializer_list<T> const& list) {\n"
    "    for (os << \"{ \"; auto const& elem : list) os << elem << ' '; return os << \"}\";\n"
    "}\n"
    ;
    SEND_STRING(str);
}


void leader_dfo(void) { // function object
    const char *str =
    "// std::not_fn\n"
    "//     creates a function object that negates the result of the callable object passed to it.\n"
    "// std::plus -> function object implementing x + y\n"
    "//     template< class T = void >\n"
    "//     struct plus;\n"
    "//        -> Effectively calls operator+ on two instances of type T.\n"
    "// std::plus<void>\n"
    "//     -> function object implementing x + y deducing parameter and return types\n"
    "//     template<>\n"
    "//     class minus<void>;\n"
    "// std::minus std::minus<void>\n"
    "// std::multiplies std::multiplies<void>\n"
    "// std::divides std::divides<void>\n"
    "// std::modulus std::modulus<void>  -> x % y\n"
    "// std::negate std::negate<void> -> -x\n"
    "// --- Comparisons\n"
    "// std::equal_to std::equal_to<void> -> x == y\n"
    "// std::not_equal_to std::not_equal_to<void>\n"
    "// std::greater std::greater<void>\n"
    "// std::less std::less<void>\n"
    "// std::greater_equal std::greater_equal<void>\n"
    "// std::less_equal std::less_equal<void>\n"
    "// --- Logical operations\n"
    "// std::logical_and std::logical_and<void> -> x && y\n"
    "// std::logical_or std::logical_or<void>\n"
    "// std::logical_not std::logical_not<void> -> !x\n"
    "// --- Bitwise operations\n"
    "// std::bit_and std::bit_and<void> -> x & y\n"
    "// std::bit_or std::bit_or<void>\n"
    "// std::bit_xor std::bit_xor<void>\n"
    "// std::bit_not std::bit_not<void>\n"
    "// --- Constrained comparison function objects\n"
    "// ranges::equal_to ranges::not_equal_to -> x != y\n"
    "// ranges::less ranges::greater\n"
    "// ranges::less_equal ranges::greater_equal\n"
    "// ranges::compare_three_way x <=> y\n"
    ;
    SEND_STRING(str);
}

void leader_dvc(void) { // vector
    const char *str =
    "// vector::vector         Capacity\n"
    "// vector::~vector        vector::empty\n"
    "// vector::operator=      vector::size\n"
    "// vector::assign         vector::max_size\n"
    "// vector::assign_range   vector::reserve\n"
    "// vector::get_allocator  vector::capacity\n"
    "//                        vector::shrink_to_fit\n"
    "// Element access\n"
    "// vector::operator[]     Modifiers\n"
    "// vector::at             vector::clear\n"
    "// vector::data           vector::erase\n"
    "// vector::front          vector::insert\n"
    "// vector::back           vector::insert_range\n"
    "//                        vector::append_range\n"
    "// Iterators              vector::emplace\n"
    "// vector::begin          vector::emplace_back\n"
    "// vector::cbegin         vector::push_back\n"
    "// vector::end            vector::pop_back\n"
    "// vector::cend           vector::resize\n"
    "// vector::rbegin         vector::swap\n"
    "// vector::crbegin\n"
    "// vector::rend           Non-member functions\n"
    "// vector::crend          operator==\n"
    "//                        operator<=>\n"
    "//                        swap(std::vector)\n"
    "//                        erase(std::vector)\n"
    "//                        erase_if(std::vector)\n"
    ;
    SEND_STRING(str);
}

void leader_dv0(void) { // vector
    const char *str =
    "// concat\n"
    "vec1.insert(vec1.end(), vec2.begin(), vec2.end());\n"
    "copy(vec.begin(),vec.end(),back_inserter(res)); // append to res\n"
    "unique_copy(vec.begin(),vec.end(),back_inserter(res)); // append to res unique elements\n"
    "// join vector into a string\n"
    "ostringstream oss; for (const auto& n : vec) { oss << n << ','; };\n"
    "string s = oss.str(); oss.pop_back();\n"
    "stringstream oss; ranges::copy(numbers, ostream_iterator<int>(oss, ','));\n"
    "string s = oss.str(); oss.pop_back();\n"
    "// slice vector\n"
    "iabbr <buffer> slice_vec; vector<int>(vec.begin() + i, vec.begin() + j)\n"
    "//  Iterate and remove elements from container/vector\n"
    "//  Directly modifying a container (like removing elements) while iterating over\n"
    "//  it with a range-based for loop or a standard iterator can lead to undefined\n"
    "//  behavior.\n"
    "//  The preferred way to safely remove elements from a vector while iterating is\n"
    "//  to use the erase-remove idiom or work with iterators explicitly.\n"
    "// Explanation\n"
    "//  remove_if:\n"
    "//    Moves all elements that do not satisfy the condition to the beginning of the\n"
    "//      vector and returns an iterator to the new logical end.\n"
    "//    Does not actually shrink the vector, leaving garbage elements at the end.\n"
    "//  erase:\n"
    "//    Removes the garbage elements, shrinking the vector.\n"
    "vector<string> words = {\"apple\", \"banana\"};\n"
    "words.erase(remove_if(words.begin(), words.end(), [](const string& word) { return word.size() > 5; }), words.end());\n"
    "for (auto it = words.begin(); it != words.end(); ) {\n"
    "    if (it->size() > 5) {\n"
    "        it = words.erase(it); // Erase returns the next valid iterator\n"
    "    } else ++it; // Move to the next element\n"
    "}\n"
    ;
    SEND_STRING(str);
}

void leader_dv1(void) { // vector
    const char *str =
    "// constructor\n"
    "std::vector<std::string> words1{\"the\", \"frogurt\", \"is\", \"also\", \"cursed\"}; // initializer list syntax\n"
    "std::vector<std::string> words2(words1.begin(), words1.end());\n"
    "std::vector<std::string> words3(words1);\n"
    "std::vector<std::string> words4(5, \"Mo\"); // words4 is {\"Mo\", \"Mo\", \"Mo\", \"Mo\", \"Mo\"}\n"
    "\n"
    "// vector& operator=( const vector& other );\n"
    "// vector& operator=( std::initializer_list<value_type> ilist );\n"
    "//\n"
    "// void assign( size_type count, const T&value );\n"
    "// void assign(InputIt first, InputIt last );\n"
    "// void assign( std::initializer_list<T> ilist );\n"
    "// void assign_range( R&& rg );\n"
    "vec_of_chars.assign(5, 'a');\n"
    "vec_of_chars.assign(another.begin(), another.end());\n"
    "vec_of_chars.assign({'C', '+', '+', '1', '1'});\n"
    "vec_of_chars.assign_range(another);\n"
    ;
    SEND_STRING(str);
}

void leader_dv5(void) { // vector
    const char *str =
    "// iterator insert( const_iterator pos, T&& value );\n"
    "//   Inserts a copy of value before pos.\n"
    "// iterator insert( const_iterator pos, size_type count, const T& value );\n"
    "//   Inserts count copies of the value before pos.\n"
    "// iterator insert( const_iterator pos, InputIt first, InputIt last );\n"
    "//   Inserts elements from range [first, last) before pos.\n"
    "// iterator insert( const_iterator pos, std::initializer_list<T> ilist );\n"
    "// iterator insert_range( const_iterator pos, R&& rg );\n"
    "// iterator emplace( const_iterator pos, Args&&... args );\n"
    "//\n"
    "// iterator erase( iterator pos );\n"
    "//   Removes the element at pos.\n"
    "// iterator erase( iterator first, iterator last );\n"
    "//\n"
    "// void append_range( R&& rg );\n"
    "//   Inserts copies of elements from the range rg before end()\n"
    "//\n"
    "// void swap( vector& other );\n"
    ;
    SEND_STRING(str);
}

void leader_dv6(void) { // vector
    const char *str =
    "// Non-member functions\n"
    "// std::vector<T, Alloc>::size_type erase( std::vector<T, Alloc>& c, const U& value );\n"
    "std::erase(vec_of_chars, '3');  // erases all occurances of '3'\n"
    "// std::vector<T, Alloc>::size_type erase_if( std::vector<T, Alloc>& c, Pred pred );\n"
    "auto erased = std::erase_if(vec_of_chars, [](char x) { return (x - '0') % 2 == 0; });\n"
    "// returns number of elements erased\n"
    ;
    SEND_STRING(str);
}

void leader_dst(void) { // string
    const char *str =
    "// Member functions    Modifiers                   Constants\n"
    "// ::basic_string      ::clear                     basic_string::npos\n"
    "// ::~basic_string     ::insert                    >---<\n"
    "// ::operator=         ::insert_range              Non-member functions\n"
    "// ::assign            ::erase                     operator+\n"
    "// ::assign_range      ::push_back                 swap(std::basic_string)\n"
    "// ::get_allocator     ::pop_back                  erase(std::basic_string)\n"
    "//                     ::append                    erase_if(std::basic_string)\n"
    "// Element access      ::append_range\n"
    "// ::at                                            I/O\n"
    "// ::operator[]        ::operator+=                operator<<\n"
    "// ::front             ::replace                   operator>>\n"
    "// ::back              ::replace_with_range        getline\n"
    "// ::data              ::copy\n"
    "// ::c_str             ::resize                    Comparison\n"
    "// ::operator          ::resize_and_overwrite      operator<=>\n"
    "//  basic_string_view  ::swap\n"
    "//                                                 Numeric conversions\n"
    "// Iterators           Capacity                    stoi\n"
    "// ::begin             ::empty                     stol\n"
    "// ::cbegin            ::size, length              stoll\n"
    "// ::end               ::max_size                  stoul\n"
    "// ::cend              ::reserve                   stoull\n"
    "// ::rbegin            ::capacity                  stof\n"
    "// ::crbegin           ::shrink_to_fit             stod\n"
    "// ::rend                                          stold\n"
    "// ::crend             Operations                  to_string\n"
    "//                     ::compare                   to_wstring\n"
    "// Search              ::starts_with\n"
    "// ::find              ::ends_with                 Literals\n"
    "// ::rfind             ::contains                  operator""s\n"
    "// ::find_first_of     ::substr\n"
    "// ::find_first_not_of                             Helper classes\n"
    "// ::find_last_of                                  hash<std::basic_string>\n"
    "// ::find_last_not_of\n"
    ;
    SEND_STRING(str);
}

void leader_ds0(void) { // string, more
    const char *str =
    "// string split 1;\n"
    "constexpr auto delim{\"^_^\"sv};\n"
    "for (const auto word : views::split(words, delim)) {\n"
    "    string s(string_view{word});\n"
    "    cout << quoted(string_view(word)) << ' ';\n"
    "    if (isdigit(string_view(word).front()))\n"
    "        prog.push_back(stoi(string_view(word).data()));\n"
    "}\n"
    "string split 2;\n"
    "istringstream iss(line);\n"
    "string fr;\n"
    "getline(iss, fr, '-');  // delim has to be char (not string)\n"
    "while(getline(iss, fr, '-')) { }\n"
    ;
    SEND_STRING(str);
}

void leader_ds1(void) { // string
    const char *str =
    "// constructor\n"
    "std::string s2(4, '='); // string(size_type count, CharT ch);\n"
    "char mutable_c_str[] = \"another C-style string\";\n"
    "std::string s4(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);\n"
    "std::string s6(\"C-style string\", 7); // string(CharT const* s, size_type count);\n"
    "             // count -> size of the resulting string\n"
    "std::string s7(\"C-style string\");\n"
    "std::string s15(other15, 8); // string(const string& other, size_type pos);\n"
    "std::string s17(other17, 0, other17.length() - 1);\n"
    "    // string(const string& other, size_type pos, size_type count)\n"
    "std::string s19({'C', '-', 's', 't', 'y', 'l', 'e'});\n"
    "// operator=\n"
    "std::list<int> x{1, 2, 3}, y, z;\n"
    "y = x; // ok: list& operator=( list&& other );\n"
    "const auto w = {4, 5, 6, 7}; // not vector, but initializer_list\n"
    "z = w; // ok: list& operator=( std::initializer_list<value_type> ilist );\n"
    "//\n"
    "// basic_string& assign( const basic_string& str );\n"
    "// basic_string& assign( size_type count, CharT ch );\n"
    "// basic_string& assign( const CharT* s, size_type count );\n"
    "// basic_string& assign( const CharT* s );\n"
    "// basic_string& assign( const basic_string& str, size_type pos, size_type count = npos);\n"
    "// basic_string& assign( InputIt first, InputIt last );\n"
    "// basic_string& assign( std::initializer_list<CharT> ilist );\n"
    "// basic_string& assign_range( R&& rg );  // rg can be: const auto x = {'a', 'b'};\n"
    ;
    SEND_STRING(str);
}

void leader_ds4(void) { // string
    const char *str =
    "// size_type find( const basic_string& str, size_type pos = 0 ) const;\n"
    "// size_type find( const CharT* s, size_type pos, size_type count ) const;\n"
    "//         count 	length of substring to search for\n"
    "// size_type find( const CharT* s, size_type pos = 0 ) const;\n"
    "// size_type find( CharT ch, size_type pos = 0 ) const;\n"
    "// size_type find( const StringViewLike& t, size_type pos = 0 ) const;\n"
    "//\n"
    "// size_type rfind( const basic_string& str, size_type pos = npos ) const;\n"
    "// size_type rfind( const CharT* s, size_type pos, size_type count ) const;\n"
    "//         count 	length of substring to search for\n"
    "// size_type rfind( const CharT* s, size_type pos = npos ) const;\n"
    "// size_type rfind( CharT ch, size_type pos = npos ) const;\n"
    "// size_type rfind( const StringViewLike& t, size_type pos = npos ) const;\n"
    "//\n"
    "// Finds the first character equal to one of the characters in the given\n"
    "// character sequence. If none of the characters in the given character\n"
    "// sequence is present in the range, npos will be returned.\n"
    "// size_type find_first_of( const basic_string& str, size_type pos = 0 ) const;\n"
    "// size_type find_first_of( const CharT* s, size_type pos, size_type count ) const;\n"
    "//         count 	length of substring to search for\n"
    "// size_type find_first_of( const CharT* s, size_type pos = 0 ) const;\n"
    "// size_type find_first_of( CharT ch, size_type pos = 0 ) const;\n"
    "// size_type find_first_of( const StringViewLike& t, size_type pos = 0 ) const;\n"
    "//\n"
    "// Finds the first character equal to none of the characters in the given character sequence.\n"
    "// find_first_not_of: similar to above\n"
    "//\n"
    "// Finds the last character equal to one of characters in the given character sequence.\n"
    "// find_last_of: similar to above\n"
    "//\n"
    "// Finds the last character equal to none of the characters in the given character sequence.\n"
    "// find_last_not_of: similar to above\n"
    ;
    SEND_STRING(str);
}

void leader_ds5(void) { // string
    const char *str =
    "// string\n"
    "// basic_string& insert( size_type index, size_type count, CharT ch );\n"
    "// basic_string& insert( size_type index, const CharT* s );\n"
    "// basic_string& insert( size_type index, const CharT* s, size_type count );\n"
    "// basic_string& insert( size_type index, const basic_string& str );\n"
    "// basic_string& insert( size_type index, const basic_string& str, size_type s_index, size_type count=npos );\n"
    "//   s_index is position of first char in str (string to insert)\n"
    "// iterator insert( iterator pos, CharT ch );\n"
    "// iterator insert( const_iterator pos, size_type count, CharT ch );\n"
    "// void insert( iterator pos, InputIt first, InputIt last );\n"
    "// iterator insert( const_iterator pos, std::initializer_list<CharT> ilist );\n"
    "// basic_string& insert( size_type index, const StringViewLike& t );\n"
    "// basic_string& insert( size_type index, const StringViewLike& t, size_type t_index, size_type count = npos );\n"
    "// iterator insert_range( const_iterator pos, R&& rg ); // rg can be: const auto x = {'a', 'b'};\n"
    "// erase\n"
    "// basic_string& erase( size_type index = 0, size_type count = npos ); // count can be > string.length\n"
    "// iterator erase( const_iterator position );\n"
    "// iterator erase( const_iterator first, const_iterator last );\n"
    "// append\n"
    "// basic_string& append( size_type count, CharT ch );\n"
    "// basic_string& append( const CharT* s, size_type count );\n"
    "// basic_string& append( const CharT* s );\n"
    "// basic_string& append( const SV& t );\n"
    "// basic_string& append( const basic_string& str );\n"
    "// basic_string& append( const basic_string& str, size_type pos, size_type count = npos );\n"
    "// basic_string& append( InputIt first, InputIt last );\n"
    "// basic_string& append( std::initializer_list<CharT> ilist );\n"
    "// std::basic_string& append_range( R&& rg ); // rg can be: const auto x = {'a', 'b'};\n"
    ;
    SEND_STRING(str);
}

void leader_ds6(void) { // string
    const char *str =
    "// operator+=\n"
    "// str += \"This\";\n"
    "// str += 'a';\n"
    "// str += {' ', 's', 't', 'r', 'i', 'n', 'g', '.'};\n"
    "// replace\n"
    "// basic_string& replace( size_type pos, size_type count, const basic_string& str );\n"
    "// basic_string& replace( const_iterator first, const_iterator last,\n"
    "//                        const basic_string& str );\n"
    "// basic_string& replace( size_type pos, size_type count, const basic_string& str,\n"
    "//                        size_type pos2, size_type count2 = npos );\n"
    "// basic_string& replace( size_type pos, size_type count,\n"
    "//                        const CharT* cstr, size_type count2 );\n"
    "// basic_string& replace( const_iterator first, const_iterator last,\n"
    "//                        const CharT* cstr, size_type count2 );\n"
    "// basic_string& replace( size_type pos, size_type count, const CharT* cstr );\n"
    "// basic_string& replace( const_iterator first, const_iterator last, const CharT* cstr );\n"
    "// basic_string& replace( size_type pos, size_type count, size_type count2, CharT ch );\n"
    "// basic_string& replace( const_iterator first, const_iterator last, size_type count2, CharT ch );\n"
    "// basic_string& replace( const_iterator first, const_iterator last, InputIt first2, InputIt last2 );\n"
    "// basic_string& replace( const_iterator first, const_iterator last, std::initializer_list<CharT> ilist );\n"
    "// basic_string& replace( size_type pos, size_type count, const StringViewLike& t );\n"
    "// basic_string& replace( const_iterator first, const_iterator last, const StringViewLike& t );\n"
    "// basic_string& replace( size_type pos, size_type count, const StringViewLike& t,\n"
    "//                        size_type pos2, size_type count2 = npos );\n"
    "// std::basic_string& replace_with_range( const_iterator first, const_iterator last, R&& rg );\n"
    "// swap\n"
    "// void swap( std::basic_string& lhs, std::basic_string& rhs );\n"
    "// swap(str1, str2);\n"
    ;
    SEND_STRING(str);
}

void leader_ds8(void) { // non-member funcs
    const char *str =
    "// c++20 has no < > == etc., only <=>\n"
    "// auto operator<=>( const std::basic_string& lhs, const std::basic_string& rhs )\n"
    "// The <=> operator returns:\n"
    "//    A value less than 0 if the left-hand side is less than the right-hand side.\n"
    "//    A value equal to 0 if the left-hand side is equal to the right-hand side.\n"
    "//    A value greater than 0 if the left-hand side is greater than the right-hand side.\n"
    "//\n"
    "// compare: returns <0, 0, >0.\n"
    "// int compare( const basic_string& str ) const;\n"
    "// int compare( size_type pos1, size_type count1, const basic_string& str ) const;\n"
    "// int compare( size_type pos1, size_type count1, const basic_string& str,\n"
    "//              size_type pos2, size_type count2 = npos ) const;\n"
    "// int compare( const CharT* s ) const;\n"
    "// int compare( size_type pos1, size_type count1, const CharT* s ) const;\n"
    "// int compare( size_type pos1, size_type count1, const CharT* s, size_type count2 ) const;\n"
    "// int compare( const StringViewLike& t ) const;\n"
    "// int compare( size_type pos1, size_type count1, const StringViewLike& t ) const;\n"
    "// int compare( size_type pos1, size_type count1, const StringViewLike& t,\n"
    "//              size_type pos2, size_type count2 = npos) const;\n"
    "//    count1 	- 	number of characters of this string to compare\n"
    "//    pos1 	- 	position of the first character in this string to compare\n"
    "//    count2 	- 	number of characters of the given string to compare\n"
    "//    pos2 	- 	position of the first character of the given string to compare \n"
    "//\n"
    "auto result = batman.compare(\"Superman\");\n"
    "// bool starts_with( std::basic_string_view sv ) const noexcept;\n"
    "// bool starts_with( CharT ch ) const noexcept;\n"
    "// bool starts_with( const CharT* s ) const;\n"
    "//\n"
    "// bool ends_with( std::basic_string_view sv ) const noexcept;\n"
    "// bool ends_with( CharT ch ) const noexcept;\n"
    "// bool ends_with( const CharT* s ) const;\n"
    "//\n"
    "// contains: Checks if the string contains the given substring.\n"
    "// bool contains( std::basic_string_view sv ) const noexcept;\n"
    "// bool contains( CharT ch ) const noexcept;\n"
    "// bool contains( const CharT* s ) const;\n"
    "//\n"
    "// basic_string substr( size_type pos = 0, size_type count = npos ) const;\n"
    "//   Returns a substring [pos, pos + count). If the requested substring extends\n"
    "//   past the end of the string, the returned substring is [pos, size()).\n"
    "//     count 	- 	length of the substring\n"
    "\n"
    ;
    SEND_STRING(str);
}

void leader_ds9(void) { // string
    const char *str =
    "// static const size_type npos = -1;\n"
    "// This is a special value equal to the maximum value representable by the type size_type. \n"
    "// Although the definition uses -1, size_type is an unsigned integer type, and the value of npos is the largest positive value it can hold.\n"
    "// std::string s = \"test\";\n"
    "// if (s.find('a') == s.npos)\n"
    "//     std::cout << \"no 'a' in 'test'\";\n"
    "//\n"
    "// size_type erase( std::basic_string& c, const U& value );\n"
    "// size_type erase( std::basic_string& c, Pred pred );\n"
    "std::erase(word, 'l'); // all instances of 'l' erased\n"
    "auto erased = std::erase_if(word, [](char x) { return x == 'a' or x == 'r' or x == 't'; });\n"
    "//  returns number of characters erased\n"
    ;
    SEND_STRING(str);
}

void leader_dls(void) {  // list
    const char *str =
    "// Doubly linked list\n"
    "list::list          Modifiers\n"
    "list::~list         list::clear\n"
    "list::operator=     list::insert\n"
    "list::assign        list::insert_range\n"
    "list::assign_range  list::emplace\n"
    "list::get_allocator list::erase\n"
    "                    list::push_front\n"
    "Element access      list::emplace_front\n"
    "list::front         list::prepend_range\n"
    "list::back          list::pop_front\n"
    "                    list::push_back\n"
    "Iterators           list::emplace_back\n"
    "list::begin         list::append_range\n"
    "list::cbegin        list::pop_back\n"
    "list::end           list::resize\n"
    "list::cend          list::swap\n"
    "list::rbegin\n"
    "list::crbegin       Capacity\n"
    "list::rend          list::size\n"
    "list::crend         list::empty\n"
    "                    list::max_size\n"
    "Operations\n"
    "list::merge         Non-member functions\n"
    "list::splice        operator==\n"
    "list::remove        operator<=>\n"
    "list::remove_if     swap(std::list)\n"
    "list::reverse       erase(std::list)\n"
    "list::unique        erase_if(std::list)\n"
    "list::sort\n"
    ;
    SEND_STRING(str);
}

void leader_dl1(void) { // string
    const char *str =
    "// constructor\n"
    "std::list<std::string> words1{\"the\", \"frogurt\", \"is\", \"also\", \"cursed\"}; //initializer list syntax:\n"
    "std::list<std::string> words2(words1.begin(), words1.end());\n"
    "std::list<std::string> words3(words1);\n"
    "std::list<std::string> words4(5, \"Mo\"); // words4 is {\"Mo\", \"Mo\", \"Mo\", \"Mo\", \"Mo\"}\n"
    "//\n"
    "// list& operator=( const list& other );\n"
    "// list& operator=( std::initializer_list<value_type> ilist );\n"
    "//\n"
    "// void assign( size_type count, const T& value ); // lst.assign(5, 'a'); // a a a a a\n"
    "// void assign( InputIt first, InputIt last );\n"
    "// void assign( std::initializer_list<T> ilist );\n"
    "// void assign_range( R&& rg );\n"
    ;
    SEND_STRING(str);
}

void leader_dl4(void) { // string
    const char *str =
    "// merge: Both lists should be SORTED.\n"
    "// void merge( list&& other );\n"
    "// void merge( list& other, Compare comp );\n"
    "list1.sort(), list2.sort();\n"
    "list1.merge(list2); // result is sorted also, return none\n"
    "//\n"
    "// splice: Transfers elements from one list to another. No elements are copied\n"
    "// or moved, only the internal pointers of the list nodes are re-pointed (unlike insert())\n"
    "// void splice( const_iterator pos, list& other );\n"
    "// void splice( const_iterator pos, list&& other );\n"
    "// void splice( const_iterator pos, list& other, const_iterator it );\n"
    "// void splice( const_iterator pos, list& other, const_iterator first, const_iterator last);\n"
    "std::list<int> list1{1, 2, 3, 4, 5};\n"
    "std::list<int> list2{10, 20, 30, 40, 50};\n"
    "auto it = list1.begin(); std::advance(it, 2);\n"
    "list1.splice(it, list2);\n"
    "// list2 is empty, list1: 1 2 10 20 30 40 50 3 4 5, 'it' points to 3 after splicing\n"
    "list2.splice(list2.begin(), list1, it, list1.end());\n"
    "// list1: 1 2 10 20 30 40 50 list2: 3 4 5\n"
    "//\n"
    "// size_type remove( const T& value );\n"
    "// size_type remove_if( UnaryPredicate p );\n"
    "auto count = l.remove_if([](int n){ return n > 10; }); // count is number of elements removed\n"
    "//\n"
    "// void reverse();\n"
    "//\n"
    "// unique: Removes all consecutive duplicate elements from the container (sort the list)\n"
    "// size_type unique();\n"
    "// size_type unique( BinaryPredicate p );\n"
    "//    bool pred(const Type1 &a, const Type2 &b); // returns true if the elements are equal.\n"
    "//\n"
    "// void sort();\n"
    "// void sort( Compare comp );\n"
    "//   bool cmp(const Type1& a, const Type2& b); // true if first argument is less than the second\n"
    "list.sort(std::greater<int>());\n"
    ;
    SEND_STRING(str);
}

void leader_dl5(void) { // string
    const char *str =
    "// Insert before pos\n"
    "// iterator insert( const_iterator pos, const T& value );\n"
    "// iterator insert( const_iterator pos, size_type count, const T& value );\n"
    "// iterator insert( const_iterator pos, InputIt first, InputIt last );\n"
    "// iterator insert( const_iterator pos, std::initializer_list<T> ilist );\n"
    "// iterator insert_range( const_iterator pos, R&& rg );\n"
    "//\n"
    "// iterator erase( const_iterator pos );\n"
    "// iterator erase( const_iterator first, const_iterator last );\n"
    "//\n"
    "// void append_range( R&& rg );  // no append()\n"
    "// void prepend_range( R&& rg );\n"
    ;
    SEND_STRING(str);
}

void leader_dl7(void) { // string
    const char *str =
    "// void swap( std::list<T, Alloc>& lhs, std::list<T, Alloc>& rhs );\n"
    "// size_type erase( std::list<T, Alloc>& c, const U& value );\n"
    "// size_type erase( std::list<T, Alloc>& c, Pred pred );\n"
    "std::erase(cnt, '3');\n"
    "auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; }); //  returns number of characters erased\n"
    ;
    SEND_STRING(str);
}

void leader_ddq(void) { // deque
    const char *str =
    "// std::deque (double-ended queue) for insertion and deletion at both its\n"
    "// beginning and its end. As opposed to std::vector, the elements of a deque\n"
    "// are not stored contiguously.\n"
    "//\n"
    "// deque::deque\n"
    "// deque::~deque           Capacity\n"
    "// deque::operator=        deque::empty\n"
    "// deque::assign           deque::size\n"
    "// deque::assign_range     deque::max_size\n"
    "// deque::get_allocator    deque::shrink_to_fit\n"
    "\n"
    "// Element access          Modifiers\n"
    "// deque::at               deque::clear\n"
    "// deque::operator[]       deque::insert\n"
    "// deque::front            deque::insert_range\n"
    "// deque::back             deque::emplace\n"
    "//                         deque::erase\n"
    "// Iterators               deque::push_front\n"
    "// deque::begin            deque::emplace_front\n"
    "// deque::cbegin           deque::prepend_range\n"
    "// deque::end              deque::pop_front\n"
    "// deque::cend             deque::push_back\n"
    "// deque::rbegin           deque::emplace_back\n"
    "// deque::crbegin          deque::append_range\n"
    "// deque::rend             deque::pop_back\n"
    "// deque::crend            deque::resize\n"
    "//                         deque::swap\n"
    "// Non-member functions\n"
    "// operator==\n"
    "// operator<=>\n"
    "// swap(std::deque)\n"
    "// erase(std::deque)\n"
    "// erase_if(std::deque)\n"
    ;
    SEND_STRING(str);
}

void leader_dd1(void) { // deque
    const char *str =
    "// constructor\n"
    "std::deque<std::string> words1{\"the\", \"frogurt\", \"is\", \"also\", \"cursed\"};\n"
    "std::deque<std::string> words2(words1.begin(), words1.end());\n"
    "std::deque<std::string> words3(words1);\n"
    "std::deque<std::string> words4(5, \"Mo\"); // words4 is {\"Mo\", \"Mo\", \"Mo\", \"Mo\", \"Mo\"}\n"
    "\n"
    "// deque& operator=( deque&& other )\n"
    "// deque& operator=( std::initializer_list<value_type> ilist );\n"
    "//\n"
    "// void assign( size_type count, const T& value );\n"
    "// void assign( InputIt first, InputIt last );\n"
    "// void assign( std::initializer_list<T> ilist );\n"
    "//\n"
    "// void assign_range( R&& rg );\n"
    "const auto source = std::list{2, 7, 1};\n"
    "auto destination = std::deque{3, 1, 4};\n"
    "destination.assign_range(source);\n"
    ;
    SEND_STRING(str);
}

void leader_dd4(void) { // deque
    const char *str =
    "// void swap( std::deque<T, Alloc>& lhs, std::deque<T, Alloc>& rhs );\n"
    "//\n"
    "// size_type erase( std::deque& c, const U& value );\n"
    "// size_type erase_if( std::deque<T, Alloc>& c, Pred pred );\n"
    "auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });\n"
    ;
    SEND_STRING(str);
}

void leader_dd6(void) { // deque
    const char *str =
    "// iterator insert( const_iterator pos, const T& value );\n"
    "// iterator insert( const_iterator pos, size_type count, const T& value );\n"
    "// iterator insert( const_iterator pos, InputIt first, InputIt last );\n"
    "int arr[] = {501, 502, 503};\n"
    "c1.insert(c1.begin(), arr, arr + std::size(arr));\n"
    "// iterator insert( const_iterator pos, std::initializer_list<T> ilist );\n"
    "c1.insert(c1.end(), {601, 602, 603});\n"
    "// iterator insert_range( const_iterator pos, R&& rg );\n"
    "//\n"
    "// iterator erase( const_iterator pos );\n"
    "// iterator erase( iterator first, iterator last );\n"
    "// iterator erase( const_iterator first, const_iterator last );\n"
    "//\n"
    "// void append_range( R&& rg );\n"
    "// void prepend_range( R&& rg );\n"
    "//\n"
    "// void swap( deque& other );\n"
    ;
    SEND_STRING(str);
}

void leader_dts(void) { // set
    const char *str =
    "// set -> ordered using a sorting function. Search, removal, and insertion\n"
    "//   operations have logarithmic complexity (uses Reb-black trees).\n"
    "// unordered_set -> hash set where buckets are used to store using a hash\n"
    "//   function (constant time insertion, deletion, lookup)\n"
    "// multiset -> Like set except multiple keys with equivalent values are allowed.\n"
    "// set::set            Modifiers\n"
    "// set::~set           set::clear\n"
    "// set::operator=      set::erase\n"
    "// set::get_allocator  set::swap\n"
    "//                     set::extract\n"
    "// Iterators           set::merge\n"
    "// set::begin          set::insert\n"
    "// set::cbegin         set::insert_range\n"
    "// set::end            set::emplace\n"
    "// set::cend           set::emplace_hint\n"
    "// set::rbegin\n"
    "// set::crbegin        Lookup\n"
    "// set::rend           set::count\n"
    "// set::crend          set::find\n"
    "//                     set::contains\n"
    "// Capacity            set::equal_range\n"
    "// set::size           set::lower_bound\n"
    "// set::max_size       set::upper_bound\n"
    "// set::empty\n"
    "//                     Non-member functions\n"
    "// Observers           operator==\n"
    "// set::key_comp       operator<=>\n"
    "// set::value_comp     std::swap(std::set)\n"
    "//                     erase_if(std::set)\n"
    ;
    SEND_STRING(str);
}

void leader_dt1(void) { // set
    const char *str =
    "// constructor\n"
    "// Use custom comparison\n"
    "struct Point { double x, y; };\n"
    "struct PointCmp {\n"
    "    bool operator()(const Point& lhs, const Point& rhs) const {\n"
    "        return std::hypot(lhs.x, lhs.y) < std::hypot(rhs.x, rhs.y);\n"
    "    }\n"
    "};\n"
    "std::set<Point, PointCmp> f = {{2, 5}, {3, 4}, {1, 1}};\n"
    "// (1) Default constructor\n"
    "std::set<std::string> a;\n"
    "// (4) Range constructor\n"
    "std::set<std::string> b(a.find(\"dog\"), a.end());\n"
    "// (6) Copy constructor\n"
    "std::set<std::string> c(a);\n"
    "// (8) Move constructor\n"
    "std::set<std::string> d(std::move(a));\n"
    "// (10) Initializer list constructor\n"
    "std::set<std::string> e{\"one\", \"two\", \"three\", \"five\", \"eight\"};\n"
    "\n"
    "// set& operator=( set&& other );\n"
    "// set& operator=( std::initializer_list<value_type> ilist );\n"
    ;
    SEND_STRING(str);
}

void leader_dt5(void) { // set
    const char *str =
    "// iterator erase( iterator pos );\n"
    "// iterator erase( iterator first, iterator last );\n"
    "//     Iterator following the last removed element.\n"
    "// size_type erase( const Key& key );\n"
    "//     Number of elements removed (0 or 1).\n"
    "// Erase all odd numbers:\n"
    "    for (auto it = c.begin(); it != c.end();) {\n"
    "        if (*it % 2 != 0)\n"
    "            it = c.erase(it);\n"
    "        else\n"
    "            ++it;\n"
    "    }\n"
    "//\n"
    "// void swap( set& other );\n"
    "//\n"
    "// extract(): Unlinks the node that contains the element, without copying or\n"
    "// moving the element. This is likely useless for me.\n"
    "//\n"
    "// void merge( std::set& source );\n"
    "// void merge( std::multiset& source );\n"
    "//   No elements are copied or moved, only the internal pointers of the\n"
    "//   container nodes are repointed. source set is merged into *this.\n"
    "//\n"
    "// std::pair<iterator, bool> insert( value_type&& value );\n"
    "//   Return: A pair consisting of an iterator to the inserted element (or to the\n"
    "//   element that prevented the insertion) and a bool value set to true if and\n"
    "//   only if the insertion took place.\n"
    "// iterator insert( iterator pos, const value_type& value );\n"
    "//   An iterator to the inserted element, or to the element that prevented the insertion.\n"
    "// void insert( InputIt first, InputIt last );\n"
    "// void insert( std::initializer_list<value_type> ilist );\n"
    "// void insert_range( R&& rg );\n"
    ;
    SEND_STRING(str);
}

void leader_dt6(void) { // set
    const char *str =
    "// size_type count( const Key& key ) const;\n"
    "//   Returns 0 or 1 depending on whether is key is present or not.\n"
    "//\n"
    "// iterator find( const Key& key );\n"
    "//    An iterator to the requested element. If no such element is found, past-the-end (see end()).\n"
    "//\n"
    "// bool contains( const Key& key ) const;\n"
    "//\n"
    "// iterator lower_bound( const Key& key );\n"
    "//   Returns an iterator pointing to the first element that is not less than\n"
    "//   (i.e. greater or equal to) key.\n"
    "// iterator upper_bound( const Key& key );\n"
    "//   Returns an iterator pointing to the first element that is greater than key.\n"
    "// Both will return the same iterator since keys are unique\n"
    "//\n"
    "// template< class K >\n"
    "// std::pair<iterator, iterator> equal_range( const K& x );\n"
    "//   x -> alternative value that can be compared to Key\n"
    "//   Returns a range containing all elements with the given key in the\n"
    "//   container. The first iterator is the same as in lower_bound(), and\n"
    "//   the second same as upper_bound().\n"
    "struct Name {\n"
    "    std::string forename, surname;\n"
    "    friend auto operator<(const Name& lhs, const Name& rhs) {\n"
    "        return std::tie(lhs.surname, lhs.forename) < std::tie(rhs.surname, rhs.forename);\n"
    "    }\n"
    "};\n"
    "std::set<Name, std::less<>> names {\n"
    "    {\"Homer\", \"Simpson\"},\n"
    "    {\"Marge\", \"Simpson\"},\n"
    "    {\"Ned\", \"Flanders\"},\n"
    "};\n"
    "struct SurnameCompare { // Note: has mixed comparison\n"
    "    std::string_view surname;\n"
    "    friend bool operator<(const Name& lhs, const SurnameCompare& rhs) {\n"
    "        return lhs.surname < rhs.surname;\n"
    "    }\n"
    "    friend bool operator<(const SurnameCompare& lhs, const Name& rhs) {\n"
    "        return lhs.surname < rhs.surname;\n"
    "    }\n"
    "};\n"
    "auto [begin, end] = names.equal_range(SurnameCompare{\"Simpson\"});\n"
    "// Will have 'Homer Simpson and 'Marge Simpson'\n"
    ;
    SEND_STRING(str);
}

void leader_dt7(void) { // set
    const char *str =
    "// void swap( std::set& lhs, std::set& rhs );\n"
    "//\n"
    "// size_type erase_if( std::set& c, Pred pred );\n"
    "//   Returns the number of erased elements.\n"
    ;
    SEND_STRING(str);
}

void leader_dmp(void) { // map
    const char *str =
    "// map -> ordered using a sorting function. Search, removal, and insertion\n"
    "//   operations have logarithmic complexity (uses Reb-black trees).\n"
    "// unordered_map -> hash map where buckets are used to store using a hash\n"
    "//   function (constant time insertion, deletion, lookup)\n"
    "// multimap -> Like map except multiple keys with equivalent values are allowed.\n"
    "// map::map              Modifiers\n"
    "// map::~map             map::clear\n"
    "// map::operator=        map::insert\n"
    "// map::get_allocator    map::erase\n"
    "//                       map::swap\n"
    "// Element access        map::extract\n"
    "// map::at               map::merge\n"
    "// map::operator[]       map::insert_range\n"
    "//                       map::insert_or_assign\n"
    "// Iterators             map::emplace\n"
    "// map::begin            map::emplace_hint\n"
    "// map::cbegin           map::try_emplace\n"
    "// map::end\n"
    "// map::cend             Lookup\n"
    "// map::rbegin           map::count\n"
    "// map::crbegin          map::find\n"
    "// map::rend             map::contains\n"
    "// map::crend            map::equal_range\n"
    "//                       map::lower_bound\n"
    "// Capacity              map::upper_bound\n"
    "// map::size\n"
    "// map::max_size         Non-member functions\n"
    "// map::empty            operator==\n"
    "//                       operator<=>\n"
    "// Observers             std::swap(std::map)\n"
    "// map::key_comp         erase_if(std::map)\n"
    "// map::value_comp\n"
    ;
    SEND_STRING(str);
}

void leader_dm1(void) { // map
    const char *str =
    "// Constructor\n"
    "// Range constructor\n"
    "    std::map<std::string, int> iter(map1.find(\"anything\"), map1.end());\n"
    "// Copy constructor\n"
    "    std::map<std::string, int> copied(map1);\n"
    "// Move constructor\n"
    "    std::map<std::string, int> moved{std::move(map1)};\n"
    "// Initializer list constructor\n"
    "    const std::map<std::string, int> init\n"
    "    {\n"
    "        {\"this\", 100},\n"
    "        {\"const\", 100}\n"
    "    };\n"
    "// Use a comparison struct\n"
    "    std::map<Point, double, PointCmp> mag =\n"
    "    {\n"
    "        {{5, -12}, 13},\n"
    "        {{-8, -15}, 17}\n"
    "    };\n"
    "// You could also use a lambda that is not dependent on local variables, like this:\n"
    "    auto cmpLambda = [](const Point& lhs, const Point& rhs){ return lhs.y < rhs.y; };\n"
    "    std::map<Point, double, decltype(cmpLambda)> magy(cmpLambda);\n"
    "//\n"
    "// map& operator=( map&& other );\n"
    "// map& operator=( std::initializer_list<value_type> ilist );\n"
    ;
    SEND_STRING(str);
}

void leader_dm2(void) { // map
    const char *str =
    "// T& at( const Key& key );\n"
    "//    Returns a reference to the mapped value of the element with specified\n"
    "//    key. If no such element exists, an exception of type std::out_of_range is\n"
    "//    thrown.\n"
    "//\n"
    "// T& operator[]( const Key& key );\n"
    "//    Initializes value if not present\n"
    "    word_map[\"that\"]; // just inserts the pair {\"that\", 0}\n"
    "// count the number of occurrences of each word\n"
    "// (the first call to operator[] initialized the counter with zero)\n"
    "    std::map<std::string, int>  word_map;\n"
    "    for (const auto& w : {\"this\", \"sentence\", \"is\", \"a\", \"hoax\"})\n"
    "        ++word_map[w];\n"
    ;
    SEND_STRING(str);
}

void leader_dm6(void) { // map
    const char *str =
    "// std::pair<iterator, bool> insert( const value_type& value );\n"
    "//    A pair consisting of an iterator to the inserted element and a bool value\n"
    "//    set to true if and only if the insertion took place.\n"
    "auto [it_hinata, success] = heights.insert({\"Hinata\"s, 162.8});\n"
    "// void insert( InputIt first, InputIt last );\n"
    "// void insert( std::initializer_list<value_type> ilist );\n"
    "// void insert_range( R&& rg ); // rg is range of pair<key, val>\n"
    "auto container = std::map{std::pair{1, 11}, {3, 33}, {2, 22}, {4, 44}};\n"
    "const auto rg = {std::pair{-1, -11}, {3, -33}, {-2, -22}};\n"
    "container.insert_range(rg);\n"
    "//\n"
    "// insert_or_assign -> if key exists replace the value, else insert new pair.\n"
    "//   might as well use map[key] = val\n"
    "// std::pair<iterator, bool> insert_or_assign( const Key& k, M&& obj );\n"
    "std::map<std::string, std::string> myMap;\n"
    "print_result(myMap.insert_or_assign(\"c\", \"cherry\"));\n"
    "print_result(myMap.insert_or_assign(\"c\", \"clementine\"));\n"
    "//  now map['c'] has 'clementine'\n"
    "//\n"
    "// iterator erase( const_iterator pos );  // returns iterator pointing to element after erased\n"
    "// iterator erase( iterator first, iterator last );\n"
    "// size_type erase( const Key& key ); // number of elements erased (0 or 1)\n"
    "//   erase all odd numbers from c\n"
    "    std::map<int, std::string> c = { {1, \"one\"}, {2, \"two\"}, {3, \"three\"} };\n"
    "    for (auto it = c.begin(); it != c.end();) {\n"
    "        if (it->first % 2 != 0)\n"
    "            it = c.erase(it);\n"
    "        else\n"
    "            ++it;\n"
    "    }\n"
    "//\n"
    "// void swap( map& other );\n"
    "//\n"
    "// extract -> Unlinks the node that contains the element pointed to by position\n"
    "// and returns a node handle that owns it. No elements are copied or moved,\n"
    "// node_type extract( const_iterator position );\n"
    "// node_type extract( const Key& k );\n"
    "//   Extract node handle and change key\n"
    "std::map<int, char> cont{{1, 'a'}, {2, 'b'}, {3, 'c'}};\n"
    "auto nh = cont.extract(1);\n"
    "nh.key() = 4;\n"
    "//   Insert node handle back\n"
    "cont.insert(std::move(nh));\n"
    "//\n"
    "// void merge( std::map& source );\n"
    "map1.merge(map2);\n"
    ;
    SEND_STRING(str);
}

void leader_dm7(void) {
    const char *str =
    "// size_type count( const Key& key ) const; // Returns 0 or 1\n"
    "//\n"
    "// iterator find( const Key& key );\n"
    "//   An iterator to the requested element. If it does not exist then end().\n"
    "if (auto search = map.find(key); search != map.end()) // found\n"
    "//\n"
    "// bool contains( const Key& key ) const;\n"
    "//\n"
    "// iterator lower_bound( const Key& key );\n"
    "//   Returns an iterator pointing to the first element that is not less than\n"
    "//   (i.e. greater or equal to) key.\n"
    "// iterator upper_bound( const Key& key );\n"
    "//   Returns an iterator pointing to the first element that is greater than key.\n"
    "// Both will return the same iterator since keys are unique\n"
    "//\n"
    "// template< class K >\n"
    "// std::pair<iterator, iterator> equal_range( const K& x );\n"
    "//   x -> alternative value that can be compared to Key\n"
    "//   Returns a range containing all elements with the given key in the\n"
    "//   container. The first iterator is the same as in lower_bound(), and\n"
    "//   the second same as upper_bound(). (see set::equal_range)\n"
    ;
    SEND_STRING(str);
}

void leader_dm8(void) {
    const char *str =
    "// void swap( std::map& lhs, std::map& rhs );\n"
    "//\n"
    "// size_type erase_if( std::map& c, Pred pred );\n"
    "auto count = std::erase_if(data, [](const auto& item)\n"
    ;
    SEND_STRING(str);
}

// Undo
// void leader_dscln(void) {
//     SEND_STRING(SS_TAP(X_ESC) "`xv`yd");
//     SEND_STRING(":delm x y" SS_TAP(X_ENT));
// }

// Set marks so that block can be deleted later
// void wrap(void (*func)(void)) {
//     if (func != NULL) {
//         SEND_STRING(SS_TAP(X_ESC) "mxi");
//         func();
//         SEND_STRING(SS_TAP(X_ESC) "myi");
//     }
// }

void keyboard_pre_init_user(void) {
    leader_map_key_sequence(leader_fi, 2, KC_F, KC_I);
    leader_map_key_sequence(leader_fj, 2, KC_F, KC_J);
    leader_map_key_sequence(leader_fk, 2, KC_F, KC_K);
    leader_map_key_sequence(leader_fa, 2, KC_F, KC_A);
    leader_map_key_sequence(leader_ft, 2, KC_F, KC_T);
    leader_map_key_sequence(leader_fe, 2, KC_F, KC_E);
    leader_map_key_sequence(leader_fm, 2, KC_F, KC_M);
    leader_map_key_sequence(leader_pr, 2, KC_P, KC_R);
    leader_map_key_sequence(leader_p2, 2, KC_P, KC_2);
    leader_map_key_sequence(leader_be, 2, KC_B, KC_E);
    leader_map_key_sequence(leader_i, 1, KC_I);
    leader_map_key_sequence(leader_vi, 2, KC_V, KC_I);
    leader_map_key_sequence(leader_vv, 2, KC_V, KC_V);
    leader_map_key_sequence(leader_vs, 2, KC_V, KC_S);
    leader_map_key_sequence(leader_pi, 2, KC_P, KC_I);
    leader_map_key_sequence(leader_mi, 2, KC_M, KC_I);
    leader_map_key_sequence(leader_ltlt, 2, KC_LT, KC_LT); // KC_LT is '<'
    leader_map_key_sequence(leader_fn, 2, KC_F, KC_N);
    leader_map_key_sequence(leader_rg, 2, KC_R, KC_G);
    leader_map_key_sequence(leader_rv, 2, KC_R, KC_V);
    leader_map_key_sequence(leader_cscln, 2, KC_C, KC_SCLN);
    leader_map_key_sequence(leader_op, 2, KC_O, KC_P);
    leader_map_key_sequence(leader_tp, 2, KC_T, KC_P);
    // Algorithms
    leader_map_key_sequence(leader_ascln, 2, KC_A, KC_SCLN);
    leader_map_key_sequence(leader_a1,  2, KC_A, KC_1);
    leader_map_key_sequence(leader_a2,  2, KC_A, KC_2);
    leader_map_key_sequence(leader_acv, 3, KC_C, KC_C, KC_V);
    leader_map_key_sequence(leader_acn, 3, KC_C, KC_C, KC_N);
    leader_map_key_sequence(leader_ast, 3, KC_A, KC_S, KC_T);
    leader_map_key_sequence(leader_ahp, 3, KC_A, KC_H, KC_P);
    leader_map_key_sequence(leader_asr, 3, KC_A, KC_S, KC_R);
    leader_map_key_sequence(leader_as2, 3, KC_A, KC_S, KC_2);
    leader_map_key_sequence(leader_amm, 3, KC_A, KC_M, KC_M);
    leader_map_key_sequence(leader_amr, 3, KC_A, KC_M, KC_R);
    leader_map_key_sequence(leader_ait, 3, KC_A, KC_I, KC_T);
    leader_map_key_sequence(leader_apr, 3, KC_A, KC_P, KC_R);
    leader_map_key_sequence(leader_abt, 3, KC_A, KC_B, KC_T);
    leader_map_key_sequence(leader_ams, 3, KC_A, KC_M, KC_S);
    leader_map_key_sequence(leader_apw, 3, KC_A, KC_P, KC_W);
    leader_map_key_sequence(leader_am2, 3, KC_A, KC_M, KC_2);
    leader_map_key_sequence(leader_arg, 3, KC_A, KC_R, KC_G);
    leader_map_key_sequence(leader_act, 3, KC_A, KC_C, KC_T);
    leader_map_key_sequence(leader_afn, 3, KC_A, KC_F, KC_N);
    leader_map_key_sequence(leader_af2, 3, KC_A, KC_F, KC_2);
    leader_map_key_sequence(leader_aan, 3, KC_A, KC_A, KC_N);
    leader_map_key_sequence(leader_aeq, 3, KC_A, KC_E, KC_Q);
    leader_map_key_sequence(leader_asc, 3, KC_A, KC_S, KC_C);
    leader_map_key_sequence(leader_afl, 3, KC_A, KC_F, KC_L);
    leader_map_key_sequence(leader_acp, 3, KC_A, KC_C, KC_P);
    leader_map_key_sequence(leader_asw, 3, KC_A, KC_S, KC_W);
    leader_map_key_sequence(leader_atr, 3, KC_A, KC_T, KC_R);
    leader_map_key_sequence(leader_arp, 3, KC_A, KC_R, KC_P);
    leader_map_key_sequence(leader_aan, 3, KC_A, KC_A, KC_N);
    leader_map_key_sequence(leader_afg, 3, KC_A, KC_F, KC_G);
    leader_map_key_sequence(leader_arm, 3, KC_A, KC_R, KC_M);
    leader_map_key_sequence(leader_auc, 3, KC_A, KC_U, KC_C);
    leader_map_key_sequence(leader_arr, 3, KC_A, KC_R, KC_R);
    leader_map_key_sequence(leader_ass, 3, KC_A, KC_S, KC_S);
    leader_map_key_sequence(leader_apt, 3, KC_A, KC_P, KC_T);
    leader_map_key_sequence(leader_abs, 3, KC_A, KC_B, KC_S);
    leader_map_key_sequence(leader_ab2, 3, KC_A, KC_B, KC_2);
    // Documentation
    leader_map_key_sequence(leader_dscln, 2, KC_D, KC_SCLN);
    leader_map_key_sequence(leader_dtm, 3, KC_D, KC_T, KC_M);
    leader_map_key_sequence(leader_dfo, 3, KC_D, KC_F, KC_O);
    leader_map_key_sequence(leader_dvc, 3, KC_D, KC_V, KC_C);
    leader_map_key_sequence(leader_dv0, 3, KC_D, KC_V, KC_0);
    leader_map_key_sequence(leader_dv1, 3, KC_D, KC_V, KC_1);
    leader_map_key_sequence(leader_dv5, 3, KC_D, KC_V, KC_5);
    leader_map_key_sequence(leader_dv6, 3, KC_D, KC_S, KC_6);
    leader_map_key_sequence(leader_dst, 3, KC_D, KC_S, KC_T);
    leader_map_key_sequence(leader_ds0, 3, KC_D, KC_S, KC_0);
    leader_map_key_sequence(leader_ds1, 3, KC_D, KC_S, KC_1);
    leader_map_key_sequence(leader_ds4, 3, KC_D, KC_S, KC_4);
    leader_map_key_sequence(leader_ds5, 3, KC_D, KC_S, KC_5);
    leader_map_key_sequence(leader_ds6, 3, KC_D, KC_S, KC_6);
    leader_map_key_sequence(leader_ds8, 3, KC_D, KC_S, KC_8);
    leader_map_key_sequence(leader_ds9, 3, KC_D, KC_S, KC_9);
    leader_map_key_sequence(leader_dls, 3, KC_D, KC_L, KC_S);
    leader_map_key_sequence(leader_dl1, 3, KC_D, KC_L, KC_1);
    leader_map_key_sequence(leader_dl4, 3, KC_D, KC_L, KC_4);
    leader_map_key_sequence(leader_dl5, 3, KC_D, KC_L, KC_5);
    leader_map_key_sequence(leader_dl7, 3, KC_D, KC_L, KC_7);
    leader_map_key_sequence(leader_ddq, 3, KC_D, KC_D, KC_Q);
    leader_map_key_sequence(leader_dd1, 3, KC_D, KC_D, KC_1);
    leader_map_key_sequence(leader_dd4, 3, KC_D, KC_D, KC_4);
    leader_map_key_sequence(leader_dd6, 3, KC_D, KC_D, KC_6);
    leader_map_key_sequence(leader_dts, 3, KC_D, KC_T, KC_S);
    leader_map_key_sequence(leader_dt1, 3, KC_D, KC_T, KC_1);
    leader_map_key_sequence(leader_dt5, 3, KC_D, KC_T, KC_5);
    leader_map_key_sequence(leader_dt6, 3, KC_D, KC_T, KC_6);
    leader_map_key_sequence(leader_dt7, 3, KC_D, KC_T, KC_7);
    leader_map_key_sequence(leader_dmp, 3, KC_D, KC_M, KC_P);
    leader_map_key_sequence(leader_dm1, 3, KC_D, KC_M, KC_1);
    leader_map_key_sequence(leader_dm2, 3, KC_D, KC_M, KC_2);
    leader_map_key_sequence(leader_dm6, 3, KC_D, KC_M, KC_6);
    leader_map_key_sequence(leader_dm7, 3, KC_D, KC_M, KC_7);
    leader_map_key_sequence(leader_dm8, 3, KC_D, KC_M, KC_8);
}
