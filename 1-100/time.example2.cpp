void findPairs(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) { // Dhyan dein, yahan j < 5 hai, N nahi.
      std::cout << arr[i] << " and " << j << std::endl;
    }
  }
}

// O(N) Time as it was actually O(5N) but as N tends towards infinity 5 doesnt
// make any sense O(1) Space
