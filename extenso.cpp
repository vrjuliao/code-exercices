#include<iostream>
#include<vector>
#include<string>
std::vector<std::string> units = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eigth",
    "nine"
};

std::vector<std::string> first_ten = {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fiveteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

std::vector<std::string> tens = {
    "",
    "",
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

std::string write(int number){
    std::string word= "";
    int hundred = number / 100;
    if(hundred > 0)
        word += units[hundred] + " hundred";
    
    int rest_of_division = (number % 100);
    int ten_division = rest_of_division / 10;
    int rest_of_ten_division = rest_of_division % 10;
    
    if(ten_division == 1) {
        if (word != "")
            word += " ";
        word += first_ten[rest_of_ten_division];
    } else {
        if(ten_division > 1) {
            if (word != "")
                word += " ";
            word += tens[ten_division];
        }
        if(rest_of_ten_division > 0) {
            if (word != "")
                word += " ";
            word += units[rest_of_ten_division];
        }
    }
    return word;
}

int main() {
    int number;
    std::cin >> number;

    int rest_of_division;
    
    std::string aux, word = "";
    rest_of_division = number % 1000;
    
    word = write(rest_of_division);

    number = number / 1000;
    rest_of_division = number % 1000;
    aux = write(rest_of_division);
    if (aux != ""){
        word = aux + " thousand " + word;
    }
    number = number / 1000;
    rest_of_division = number % 1000;
    aux = write(rest_of_division);
    if (aux != ""){
        word = aux + " milions " + word;
    }
    std::cout << word << std::endl;
}