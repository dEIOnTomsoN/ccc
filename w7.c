#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLongestSubstring(char *s) {
    int n = strlen(s);
    int charIndex[256]; // To store the most recent index of each character
    int maxLength = 0;
    int start = 0; // Starting index of the current substring
    int end = 0;   // Ending index of the current substring
    int currentLength = 0;

    // Initialize charIndex array with -1
    for (int i = 0; i < 256; i++) {
        charIndex[i] = -1;
    }

    int currentStart = 0; // Starting index of the longest substring

    for (end = 0; end < n; end++) {
        // If the character is already seen, update the start index
        if (charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }

        // Update the index of the current character
        charIndex[s[end]] = end;

        // Calculate the current length of the substring
        currentLength = end - start + 1;

        // Update maxLength and currentStart if needed
        if (currentLength > maxLength) {
            maxLength = currentLength;
            currentStart = start;
        }
    }

    // Print the longest substring
    printf("Longest substring without repeating characters: ");
    for (int i = currentStart; i < currentStart + maxLength; i++) {
        printf("%c", s[i]);
    }

    // Print the length of the longest substring
    printf("\nLength of the longest substring: %d\n", maxLength);
}

int main() {
    char s[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", s);

    findLongestSubstring(s);

    return 0;
}
