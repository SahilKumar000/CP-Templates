vector<int> kmp(string s) {
    int n = s.length();
    vector<int> kmp(n,0);
    for (int i = 1; i < n; i++) {
        int j = kmp[i-1];
        while (j > 0 && s[i] != s[j])
            j = kmp[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
