#include <iostream>
#include <ctime>

void WelcomeMessage() {
    std::cout << "This game is called Triple X and you need to"
    << " guess 3 numbers according to ours tips." << std::endl;
    std::cout << "________________________________________________________________________________________________" << std::endl;
}

void QuestionMessage(int product, int sum) {
    std::cout << "The sum of the 3 numbers is: " << sum << std::endl;
    std::cout << "The product of the 3 numbers is: " << product << std::endl;
}

bool Game(int actual_level) {
    int number_a, number_b, number_c, sum, product;
    int guess_a, guess_b, guess_c, guess_sum, guess_product;

    number_a = rand() % actual_level + 1;
    number_b = rand() % actual_level + 1;
    number_c = rand() % actual_level + 1;
    sum = number_a + number_b + number_c;
    product = number_a * number_b * number_c;

    QuestionMessage(product, sum);

    std::cin >> guess_a >> guess_b >> guess_c;

    guess_sum = guess_a + guess_b + guess_c;
    guess_product = guess_a * guess_b * guess_c;

    if(guess_sum == sum && guess_product == product)
        return true;
    
    else
        return false;

}

int main() {
    int actual_level = 2, max_level = 5, tries = 3;
    
    srand(time(NULL));
    WelcomeMessage();

    while(actual_level < max_level && tries > 0) {
        
        if(Game(actual_level))
            actual_level++;
        
        else {
            tries--;        
            std::cout << "Wrong answer! You have " << tries << " more tries." << std::endl;
        }
    }

    if(tries == 0)
        std::cout << "WRONG! WRONG! WRONG! YOU LOST!" << std::endl;
    else
        std::cout << "Congratulations, kid. Your challenge is complete and done." << std::endl;
}