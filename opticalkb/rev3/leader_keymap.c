#include "leader.h"

// Rule of thumb: Vowels are avoided in map lhs, unless vowel refers to template
// parameter (ex. vector<int> is vi).

void leader_fi(void) {
    SEND_STRING("for (int i = 0; i < (int); i++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 21; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fj(void) {
    SEND_STRING("for (int j = 0; j < (int); j++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 21; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fk(void) {
    SEND_STRING("for (int k = 0; k < (int); k++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 21; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fa(void) {
    SEND_STRING("for (auto& x : ) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 11; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_ft(void) {
    SEND_STRING("for (auto it = .begin(); it != .end(); it++) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 11; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fm(void) {
    SEND_STRING("for (const auto& [key, val] : ) {\n" SS_TAP(X_UP));
    for (int i = 0; i < 26; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fe(void) {
    SEND_STRING("ranges::for_each(, [](int& n) {});");
    for (int i = 0; i < 17; i++) SEND_STRING(SS_TAP(X_LEFT));
}
void leader_pr(void) {
    // SEND_STRING("ranges::for_each(, [](const int& n) {cout << n;});cout<<endl;");
    SEND_STRING("for (const auto& t : ) { cout << t << " "; }; cout << endl;");
    for (int i = 0; i < 38; i++) SEND_STRING(SS_TAP(X_LEFT));
}
// void leader_pp(void) {
//     SEND_STRING("ranges::copy(, ostream_iterator<int>(cout, \" \"));cout<<endl;");
//     for (int i = 0; i < 47; i++) SEND_STRING(SS_TAP(X_LEFT));
// }
void leader_be(void) {
    SEND_STRING(".begin(), .end()");
}
void leader_mx(void) {
    SEND_STRING("auto it = ranges::max_element(R, [](const auto& a, const auto& b) {}, &pair<x, y>::first);");
}
// void leader_ds(void) {
//     SEND_STRING("ranges::distance(");
// }
// void leader_ll(void) {
//     SEND_STRING("signed long long ");
// }
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
void leader_i(void) {
    SEND_STRING("using namespace string_view_literals;\n");
    SEND_STRING("using i64 = int64_t;\n");
    SEND_STRING("namespace rg = ranges;\n");
    SEND_STRING("namespace rv = ranges::views;\n");
    SEND_STRING("#define F first\n");
    SEND_STRING("#define S second\n");
    SEND_STRING("#define PB push_back\n");
}
void leader_mi(void) {
    SEND_STRING("numeric_limits<int>::max();");
}
void leader_leftleft(void) {
    SEND_STRING("ostream& operator<<(ostream& os, const pair<int, int>& p) {\n");
    SEND_STRING("os << '(' << p.first << \", \" << p.second << ')'; return os;\n}\n");
}
// Conversions
void leader_cic(void) {
    SEND_STRING("'0' + 5");
}
void leader_cci(void) {
    SEND_STRING("ch - '0'");
}
void leader_cib(void) {
    SEND_STRING("bitset<32> binary(num); // num is int");
}
void leader_cis(void) {
    SEND_STRING("string str = to_string(num); // num is int");
}
void leader_csi(void) {
    SEND_STRING("stoi(str)");
}
void leader_csu(void) {
    SEND_STRING("stoull(str)");
}
void leader_csc(void) {
    SEND_STRING("while (auto ch : str) OR vector<char>(s.begin(), s.end())");
}
void leader_ccs(void) {
    SEND_STRING("s += ch; string(1, ch); s.push_back(ch);");
}
void leader_fn(void) {
    SEND_STRING("function<int(int)> fac = [&fac](int n) {");
}
void keyboard_pre_init_user(void) {
    leader_map_key_sequence(leader_fi, 2, KC_F, KC_I);
    leader_map_key_sequence(leader_fj, 2, KC_F, KC_J);
    leader_map_key_sequence(leader_fk, 2, KC_F, KC_K);
    leader_map_key_sequence(leader_fa, 2, KC_F, KC_A);
    leader_map_key_sequence(leader_ft, 2, KC_F, KC_T);
    leader_map_key_sequence(leader_fe, 2, KC_F, KC_E);
    leader_map_key_sequence(leader_fm, 2, KC_F, KC_M);
    leader_map_key_sequence(leader_pr, 2, KC_P, KC_R);
    // leader_map_key_sequence(leader_pp, 2, KC_P, KC_P);
    leader_map_key_sequence(leader_be, 2, KC_B, KC_E);
    leader_map_key_sequence(leader_mx, 2, KC_M, KC_X);
    // leader_map_key_sequence(leader_ds, 2, KC_D, KC_S);
    leader_map_key_sequence(leader_i, 1, KC_I);
    // leader_map_key_sequence(leader_ll, 2, KC_L, KC_L);
    leader_map_key_sequence(leader_vi, 2, KC_V, KC_I);
    leader_map_key_sequence(leader_vv, 2, KC_V, KC_V);
    leader_map_key_sequence(leader_vs, 2, KC_V, KC_S);
    leader_map_key_sequence(leader_pi, 2, KC_P, KC_I);
    leader_map_key_sequence(leader_mi, 2, KC_M, KC_I);
    leader_map_key_sequence(leader_leftleft, 2, KC_LEFT, KC_LEFT);
    leader_map_key_sequence(leader_cic, 3, KC_C, KC_I, KC_C);
    leader_map_key_sequence(leader_cci, 3, KC_C, KC_C, KC_I);
    leader_map_key_sequence(leader_cib, 3, KC_C, KC_I, KC_B);
    leader_map_key_sequence(leader_cis, 3, KC_C, KC_I, KC_S);
    leader_map_key_sequence(leader_csi, 3, KC_C, KC_S, KC_I);
    leader_map_key_sequence(leader_csu, 3, KC_C, KC_S, KC_U);
    leader_map_key_sequence(leader_csc, 3, KC_C, KC_S, KC_C);
    leader_map_key_sequence(leader_ccs, 3, KC_C, KC_C, KC_S);
    leader_map_key_sequence(leader_fn, 2, KC_F, KC_N);
    leader_map_key_sequence(leader_rg, 2, KC_R, KC_G);
    leader_map_key_sequence(leader_rv, 2, KC_R, KC_V);
}
