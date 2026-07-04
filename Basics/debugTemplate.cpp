//1. Save as template.cpp in same folder
// USE Them in Main.cpp

// #ifndef ONLINE_JUDGE
// #include "template.cpp"
// #else
// #define dbg(...)
// #define debug(...)
// #define debugArr(...)
// #endif

//Call dbg(arrayname)

#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE

template<typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template<typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template<typename F, typename S>
ostream& operator<<(ostream& os, const map<F, S>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << it->first << " : " << it->second;
    }
    return os << "}";
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& v) {
    os << "{";
    bool first = true;
    for (auto &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x.first << " : " << x.second;
    }
    return os << "}";
}

template<typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& v) {
    os << "{";
    bool first = true;
    for (auto &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

inline void faltu() {
    cerr << '\n';
}

template<typename T>
void faltu(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cerr << arr[i] << ' ';
    cerr << '\n';
}

template<typename T, typename... Args>
void faltu(T arg, Args... args) {
    cerr << arg;
    if (sizeof...(args)) cerr << " | ";
    faltu(args...);
}

#define dbg(...) do {                     \
    cerr << "[" << __LINE__ << "] ";      \
    cerr << #__VA_ARGS__ << " = ";        \
    faltu(__VA_ARGS__);                   \
} while (0)

#else

#define dbg(...)

#endif

#endif
