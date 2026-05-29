#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main()
{
	const int NUM_FLOATS = 10000;
	// Create two input vectors with 10,000 floats
	std::vector<float> inputA;
	std::vector<float> inputB;

	// Create several destination vector of 10,000 floats 
	std::vector<float> destSeq(NUM_FLOATS);
	std::vector<float> destPar(NUM_FLOATS);
	std::vector<float> destParUnseq(NUM_FLOATS);

	for (int i = 0; i < NUM_FLOATS; i++)
	{
		inputA.emplace_back(static_cast<float>(i));
		inputB.emplace_back(static_cast<float>(i*2));
	}
	
	// Old way (same as std::execution::seq)
	std::transform(
		inputA.begin(), inputA.end(), // Begin/end of 1st input range
		inputB.begin(), // Begin of 2nd input range
		destSeq.begin(), // Begin of destination range
		[](float x, float y) { return x * y; } // Lambda
	);

	// Parallel execution policy
	std::transform(
		std::execution::par, // Parallel execution policy
		inputA.begin(), inputA.end(), // Begin/end of 1st input range
		inputB.begin(), // Begin of 2nd input range
		destPar.begin(), // Begin of destination range
		[](float x, float y) { return x * y; } // Lambda
	);

	// Parallel unsequenced execution policy
	std::transform(
		std::execution::par_unseq, // Parallel/unsequenced policy
		inputA.begin(), inputA.end(), // Begin/end of 1st input range
		inputB.begin(), // Begin of 2nd input range
		destParUnseq.begin(), // Begin of destination range
		[](float x, float y) { return x * y; } // Lambda
	);

	// Verify all the results are the same
	int numDifferences = 0;
	for (int i = 0; i < NUM_FLOATS; i++)
	{
		if (destSeq[i] != destPar[i] || destPar[i] != destParUnseq[i])
		{
			numDifferences++;
		}
	}

	if (numDifferences > 0)
	{
		std::cerr << "Unexpected differences!" << std::endl;
	}
	return 0;
}
