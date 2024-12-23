#include "leader.h"

// Rule of thumb: Vowels are avoided in map lhs, unless vowel refers to template
// parameter (ex. vector<int> is vi).

void leader_fi(void) {
    SEND_STRING("for(int i = 0; i < ; i++) {\n}" SS_TAP(X_UP));
    for (int i = 0; i < 18; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fj(void) {
    SEND_STRING("for(int j = 0; j < ; j++) {\n}" SS_TAP(X_UP));
    for (int i = 0; i < 18; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fa(void) {
    SEND_STRING("for(auto& x : ) {\n}" SS_TAP(X_UP));
    for (int i = 0; i < 13; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_ft(void) {
    SEND_STRING("for(auto it=.begin(); it!=.end(); it++) {\n}" SS_TAP(X_UP));
    for (int i = 0; i < 11; i++) SEND_STRING(SS_TAP(X_RIGHT));
}
void leader_fe(void) {
    SEND_STRING("ranges::for_each(, [](int& n) {});");
    for (int i = 0; i < 17; i++) SEND_STRING(SS_TAP(X_LEFT));
}
void leader_pr(void) {
    SEND_STRING("ranges::for_each(, [](const int& n) {cout << n;});cout<<endl;");
    for (int i = 0; i < 45; i++) SEND_STRING(SS_TAP(X_LEFT));
}
void leader_pp(void) {
    SEND_STRING("ranges::copy(, ostream_iterator<int>(cout, \" \"));cout<<endl;");
    for (int i = 0; i < 47; i++) SEND_STRING(SS_TAP(X_LEFT));
}
void leader_be(void) {
    SEND_STRING("a.begin(), a.end()");
}
void leader_mx(void) {
    SEND_STRING("ranges::max_element(");
}
void leader_ds(void) {
    SEND_STRING("ranges::distance(");
}
void leader_ll(void) {
    SEND_STRING("signed long long ");
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
void leader_fr(void) {
    SEND_STRING("first");
}
void leader_sc(void) {
    SEND_STRING("second");
}
void leader_pb(void) {
    SEND_STRING("push_back(");
}
void leader_i(void) {
    SEND_STRING("typedef signed long long ll;\n");
    SEND_STRING("typedef vector<int> vi;\n");
    SEND_STRING("typedef vector<vector<int>> vii;\n");
    SEND_STRING("typedef pair<int,int> pi;\n");
    SEND_STRING("typedef vector<string> vs;\n");
    SEND_STRING("#define F first\n");
    SEND_STRING("#define S second\n");
    SEND_STRING("#define PB push_back\n");
}

void keyboard_pre_init_user(void) {
    leader_map_key_sequence(leader_fi, 2, KC_F, KC_I);
    leader_map_key_sequence(leader_fj, 2, KC_F, KC_J);
    leader_map_key_sequence(leader_fa, 2, KC_F, KC_A);
    leader_map_key_sequence(leader_ft, 2, KC_F, KC_T);
    leader_map_key_sequence(leader_fe, 2, KC_F, KC_E);
    leader_map_key_sequence(leader_pr, 2, KC_P, KC_R);
    leader_map_key_sequence(leader_pp, 2, KC_P, KC_P);
    leader_map_key_sequence(leader_be, 2, KC_B, KC_E);
    leader_map_key_sequence(leader_mx, 2, KC_M, KC_X);
    leader_map_key_sequence(leader_ds, 2, KC_D, KC_S);
    leader_map_key_sequence(leader_i, 1, KC_I);
    leader_map_key_sequence(leader_ll, 2, KC_L, KC_L);
    leader_map_key_sequence(leader_vi, 2, KC_V, KC_I);
    leader_map_key_sequence(leader_vv, 2, KC_V, KC_V);
    leader_map_key_sequence(leader_vs, 2, KC_V, KC_S);
    leader_map_key_sequence(leader_pi, 2, KC_P, KC_I);
    leader_map_key_sequence(leader_fr, 2, KC_F, KC_R);
    leader_map_key_sequence(leader_sc, 2, KC_S, KC_C);
    leader_map_key_sequence(leader_pb, 2, KC_P, KC_B);
}
