#include "RandomPoke.h"

// Constructor for the RandomPoke class (default constructor)
RandomPoke::RandomPoke() {}

// Parameterized constructor for the RandomPoke class, taking a filename as
// input This constructor initializes the filename member variable and calls the
// loadNamesFromFile function.
RandomPoke::RandomPoke(string filename) : filename(filename) {
  loadNamesFromFile();
}

// Member function to retrieve a random name from the 'names' vector.
// If the 'names' vector is empty, it returns "No names available."
string RandomPoke::getRandomName() {
  // Check if the 'names' vector is empty
  if (names.empty()) {
    return "No names available";
  }

  // Initialize a random number generator
  random_device rd;
  mt19937 gen(rd());

  // Create a uniform distribution for generating random indices within the
  // 'names' vector
  uniform_int_distribution<int> distribution(0, names.size() - 1);

  // Generate a random index using the random number generator
  int randomIndex = distribution(gen);

  // Return the random name corresponding to the random index
  return names[randomIndex];
}
