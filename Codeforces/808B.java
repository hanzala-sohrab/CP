
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Read the number of days (n) and the length of a week (k)
            int n = scanner.nextInt();
            int k = scanner.nextInt();

            // Initialize an array to store sleep times for each day
            int[] sleepTimes = new int[n];

            // Variable to store the total sum of sleep times over all weeks
            long totalSum;

            // Read the sleep times for each day
            for (int i = 0; i < n; i++) { // O(n)
                sleepTimes[i] = scanner.nextInt();
            }

            // Calculate the sum of sleep times for the first 'k' days
            long sum = 0;
            for (int i = 0; i < k; i++) { // O(k)
                sum += sleepTimes[i];
            }

            // Initialize totalSum with the sum of the first 'k' days
            totalSum = sum;

            // Initialize two pointers for the sliding window
            int p1 = 0, p2 = k;

            // Slide the window across the array to calculate the sum for each week
            while (p2 < n) { // O(n-k)
                // Subtract the element going out of the window
                sum -= sleepTimes[p1];
                // Add the new element coming into the window
                sum += sleepTimes[p2];
                // Add the current window sum to totalSum
                totalSum += sum;
                // Move the window forward
                p1++;
                p2++;
            }

            // Output the average sleep time over all weeks with a precision of 6 decimal places
            System.out.printf("%.6f\n", 1.0 * totalSum / (n - k + 1));
        }
    }
}
