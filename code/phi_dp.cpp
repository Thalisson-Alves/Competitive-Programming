const int MAX_N = 1e5;
vector<int> phi(MAX_N+1);
void phi_dp() {
  for (int i = 1; i <= MAX_N; i++) {
    phi[i] += i;
    for (int j = i+i; j <= MAX_N; j+=i) {
      phi[j] -= phi[i];
    }
  }
}
