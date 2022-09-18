//Numbertoword.cpp
In this program we use c language and make convertor number to word
#include <stdio.h>
#include <string>

std::string ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirtenn", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
std::string powerOfTens[] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
std::string multipleOfTens[] = { "", " thousand", " million", " billion", " trillion", " quadrillion", " quintillion" };

std::string hundredsToWords(int num) {
    if (num > 999) return ""; // if num is geater than 999 its not a hundred
    if (num < 20) return ones[num]; // if num is less than 20 it has a value in ones array
    int v_ones = num % 10; // getting right last digit (ones); 99<9>
    int v_tens = (num % 100) / 10; // getting middle value (tens); 9<9>9
    int v_hundreds = (num % 1000) / 100; // getting first value (hundreds); <9>99
    std::string val = "";

    if (v_hundreds > 0) {
        val = " " + ones[v_hundreds] + " hundred";
    }

    if (v_tens > 0) {
        val += " " + powerOfTens[v_tens];
    }

    if (v_ones > 0) {
        val += (v_tens > 0 ? "-" : " ") + ones[v_ones];
    }

    return val;
}

std::string convertToWords(long long num, int pot = 0) {
    std::string val = "";

    val = hundredsToWords(num % 1000); // Converting the last three digit into words
    if (num % 1000 > 0) val += multipleOfTens[pot]; // Adding postfix if needed
    num /= 1000; // deleting the last three digits
    if (num > 0) {
        val = convertToWords(num, ++pot) + val; // converting remaining value and add above value
    }

    return val;
}

int main()
{
    long long amt = 0L;
    printf("Enter the amount\n");
    scanf("%lld", &amt);

    printf("amount (%lld) is words: %s", amt, convertToWords(amt).c_str());
}
