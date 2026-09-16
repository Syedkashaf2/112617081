void weirdPrint(int arr[], int N) {
  // Part 1
  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }

  // Part 2
  for (int j = 0; j < N; j++) {
    std::cout << arr[j] * 2 << " ";
  }
}

// O(N) Time, O(1) Space as timr was actually O(2N) but as n tends towards
// infinity the constants make negligible change
