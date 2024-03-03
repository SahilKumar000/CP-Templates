vector<int> kmp(string s) {
    int n = s.length();
    vector<int> kmp(n,0);
    for (int i = 1; i < n; i++) {
        int prev_index = kmp[i-1];
        while (prev_index > 0 && s[i] != s[j])
            prev_index = kmp[j-1];
        kmp[i] = prev_index + (s[i]==s[prev_index])?1:0;
     }
    return kmp;
}
