#!/bin/bash

# Number of iterations
ITERATIONS=100

# Initialize total operations counter
total_ops=0

# Loop for the specified number of iterations
for ((i = 1; i <= ITERATIONS; i++))
do
    # Generate 500 unique random numbers
    numbers=($(shuf -i 0-2147483647 -n 500))

    # Convert the numbers to a space-separated string
    numbers_str=$(IFS=' '; echo "${numbers[*]}")

    # Call push_swap and count the number of operations
    ops=$(./push_swap.out $numbers_str | wc -l)

    # Add the number of operations to the total
    total_ops=$((total_ops + ops))

    # Print the current iteration and number of operations
    echo "Iteration $i: $ops operations"
done

# Calculate the average number of operations
average_ops=$(echo "scale=2; $total_ops / $ITERATIONS" | bc)

# Print the result
echo "Average number of operations over $ITERATIONS iterations: $average_ops"
