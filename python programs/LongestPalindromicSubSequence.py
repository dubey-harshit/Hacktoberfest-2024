"""
Question:
Given a string, find the length of its Longest Palindromic Subsequence (LPS).
A subsequence is a sequence that can be derived from another sequence by deleting
some or no elements without changing the order of the remaining elements.

Example:
Input: "BBABCBCAB"
Output: 7
Explanation: The longest palindromic subsequence is "BABCBAB".

Implement a solution using dynamic programming with the following requirements:
1. Time Complexity: O(n^2), where n is the length of the input string
2. Space Complexity: O(n^2)
"""

def longest_palindromic_subsequence(s):
    """
    Find the length of the Longest Palindromic Subsequence in the given string.

    Args:
    s (str): The input string

    Returns:
    int: The length of the longest palindromic subsequence

    Time Complexity: O(n^2), where n is the length of the input string
    Space Complexity: O(n^2)
    """
    n = len(s)
    
    # Initialize the dp table
    dp = [[0 for _ in range(n)] for _ in range(n)]
    
    # Every single character is a palindrome of length 1
    for i in range(n):
        dp[i][i] = 1
    
    # Fill the dp table
    for cl in range(2, n + 1):  # cl is the chain length
        for i in range(n - cl + 1):
            j = i + cl - 1
            if s[i] == s[j] and cl == 2:
                dp[i][j] = 2
            elif s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    
    # Return the length of LPS
    return dp[0][n-1]

def print_longest_palindromic_subsequence(s):
    """
    Print the Longest Palindromic Subsequence in the given string.

    Args:
    s (str): The input string

    Returns:
    str: The longest palindromic subsequence

    Time Complexity: O(n^2), where n is the length of the input string
    Space Complexity: O(n^2)
    """
    n = len(s)
    dp = [[0 for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = 1
    
    for cl in range(2, n + 1):
        for i in range(n - cl + 1):
            j = i + cl - 1
            if s[i] == s[j] and cl == 2:
                dp[i][j] = 2
            elif s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    
    # Reconstruct the LPS
    lps = [""] * dp[0][n-1]
    i, j, start, end = 0, n - 1, 0, dp[0][n-1] - 1
    
    while i <= j:
        if i == j:
            lps[start] = s[i]
        elif s[i] == s[j]:
            lps[start] = lps[end] = s[i]
            start += 1
            end -= 1
        elif dp[i][j] == dp[i+1][j]:
            i += 1
        else:
            j -= 1
        if dp[i][j] <= 2:
            break
        i += 1
        j -= 1
    
    return "".join(lps)

# Example usage
if __name__ == "__main__":
    test_string = "BBABCBCAB"
    lps_length = longest_palindromic_subsequence(test_string)
    lps = print_longest_palindromic_subsequence(test_string)
    
    print(f"Input string: {test_string}")
    print(f"Length of Longest Palindromic Subsequence: {lps_length}")
    print(f"Longest Palindromic Subsequence: {lps}")