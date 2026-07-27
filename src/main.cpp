/*
    Rock Paper Scissors
    -------------------
    A console-based Rock Paper Scissors game written in C++.

    Features:
    - User input validation
    - Best-of-N style matches
    - Score tracking
    - Replay option
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <thread>
#include <chrono>

char player_choice();
char computer_choice();
void show_choices(char choice, char computer);
void round_winner(char player, char computer);
void point_calculator(char player, char computer, short& computer_point, short& user_point);
void show_round_stats(short player_rounds_won, short computer_rounds_won, short round_amout);
void show_match_winner(short user_rounds_won, short computer_rounds_won);
void int_input_validator(short& number_variable);
bool continuation_permission();
int close_game();

int main() {
    // Seed the random number generator once when the program starts.
    srand(time(nullptr));
    
    /*
       Allow the player to play multiple matches.
       Play rounds until either the player or the computer reaches
       the required number of points.
    */ 
    do {
        short round_amount{};
        short user_point_counter{};
        short computer_point_counter{};
        std::cout << "Enter the number of points needed to win: ";
        int_input_validator(round_amount);
        
        char player;
        do {
            player = player_choice();
            if (player == 'e') {
                return close_game();
            }

            char computer = computer_choice();
            show_choices(player, computer);
            round_winner(player, computer);
            point_calculator(player, computer, computer_point_counter, user_point_counter);
            show_round_stats(user_point_counter, computer_point_counter, round_amount);

        } while (user_point_counter != round_amount && computer_point_counter != round_amount);  
        
        show_match_winner(user_point_counter, computer_point_counter);

        std::cout << "******************************************************************************\n";

    } while (continuation_permission());

    return close_game();
} 

char player_choice() {
    std::cout << "******************************************************************************\n" 
              << "Please select between (Rock, Paper, Scissors, Exit / R, P, S, E): ";

    std::string choice;
    // Keep asking until the player enters a valid choice.
    while (true) {
        // Recover from an input stream failure before asking again.
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input.\n" 
                      << "Select between (r for rock, p for paper, s for scissors, e for exit): ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        /*
            Convert the entire input to lowercase so the comparison
            becomes case-insensitive.
        */
        for (char& c : choice){
            c = std::tolower(static_cast<unsigned char>(c));
        }
        
        // Reject anything that isn't one of the accepted commands.
        if (choice != "r" &&
            choice != "rock" &&
            choice != "p" &&
            choice != "paper" &&
            choice != "s" &&
            choice != "scissors" &&
            choice != "scissor" &&
            choice != "e" &&
            choice != "exit") {
            std::cout << "Invalid input.\n" 
                      << "Select between(r for rock, p for paper, s for scissors, e for exit): ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        /*
            Reject inputs containing extra characters such as
            "rock hello" or "r 123"
        */
        if (std::cin.peek() != '\n') {
            std::cout << "Invalid input.\n" 
                      << "Select between(r for rock, p for paper, s for scissors, e for exit): ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;   
        }
        
        break;
        
    }
    /*
        Convert the validated string into the character used
        throughout the rest of the program.
    */
    if (choice == "exit" || choice == "e"){
        return 'e';
    }
    if (choice == "rock" || choice == "r"){
        return 'r';
    }
    if (choice == "paper" || choice == "p"){
        return 'p';
    }
    if (choice == "scissors" || choice == "scissor" || choice == "s"){
        return 's';
    }

    /*     
        This should never happen, but guarantees the function
        always returns a value.
    */ 
    return '\0';
}

char computer_choice() {
    // Generate a random number representing Rock, Paper or Scissors.
    int computer{rand() % 3};
    switch (computer) {
        case 0:
            return 'r';
        case 1:
            return 'p';
        case 2:
            return 's';
        /*     
            This should never happen, but guarantees the function
            always returns a value.
        */ 
        default:
            return '\0';
    
    
    }
}

void show_choices(char choice, char computer) {
    switch (choice) {
        case 'r': 
            std::cout << "You chose rock.\n";
            break;
        case 'p':
            std::cout << "You chose paper.\n";
            break;
        case 's':
            std::cout << "You chose scissors.\n";
            break;
        default:
            std::cout << "Something went wrong.\n";
            break;
    }

    switch (computer) {
        case 'r': 
            std::cout << "Computer chose rock.\n";
            break;
        case 'p':
            std::cout << "Computer chose paper.\n";
            break;
        case 's':
            std::cout << "Computer chose scissors.\n";
            break;
        default:
            std::cout << "Something went wrong.\n";
            break;
    }
}

void round_winner(char player, char computer) {
    if (player == 'r') {
        switch (computer) {
            case 'r':
                std::cout << "It's a tie.\n";
                break;
            case 'p':
                std::cout << "You lost the round.\n";
                break;
            case 's':
                std::cout << "You won the round.\n";
                break;
        }
    }
    else if (player == 'p') {
        switch (computer) {
            case 'p':
                std::cout << "It's a tie.\n";
                break;
            case 's':
                std::cout << "You lost the round.\n";
                break;
            case 'r':
                std::cout << "You won the round.\n";
                break;
        }
    }
    else {
        switch (computer) {
            case 's':
                std::cout << "It's a tie.\n";
                break;
            case 'r':
                std::cout << "You lost the round.\n";
                break;
            case 'p':
                std::cout << "You won the round.\n";
                break;
        }
        
    }
}

void point_calculator(char player, char computer, short& computer_point, short& user_point) {
    // Award a point to the winner of the current round.
    if (player == 'r') {
        switch (computer) {
            case 'r':
                break;
            case 'p':
                computer_point++;
                break;
            case 's':
                user_point++;
                break;
            default:
                std::cout << "Unexpected computer choice.\n";
        }
    }
    else if (player == 'p') {
        switch (computer) {
            case 'p':
                break;
            case 's':
                computer_point++;
                break;
            case 'r':
                user_point++;
                break;
            default:
                std::cout << "Unexpected computer choice.\n";
        }
    }
    else {
        switch (computer) {
            case 's':
                break;
            case 'r':
                computer_point++;
                break;
            case 'p':
                user_point++;
                break;
        }
        
    }
}

void show_round_stats(short player_rounds_won, short computer_rounds_won, short round_amount) {
    std::cout << "\tPLAYER " << player_rounds_won << "            " << computer_rounds_won << " COMPUTER\n" 
              << "\t\t First to " << round_amount << '\n';
}

void show_match_winner(short user_rounds_won, short computer_rounds_won) {
    if (user_rounds_won > computer_rounds_won) {
        std::cout << "YOU HAVE WON THE MATCH\n" 
                  << "CONGRATULATIONS\n";
    }
    else {
        std::cout << "You've lost the match. :(\n" 
                  << "You will get it next time.\n";
    }
}

void int_input_validator(short& number_variable) { 
    // Keep asking until the user enters a valid positive number.
    while (true) {
        // Reject non-numeric input.
        if (!(std::cin >> number_variable)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input, please enter a short valid numeric value: ";
            continue;
        }
        // Only positive numbers are accepted.
        if (number_variable < 1) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input, please enter a short valid numeric value: ";
            continue;
        }
        // Reject extra characters such as "5abc" or "5 hello".
        if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input, please enter a short valid numeric value: ";
            continue;
        }

        break;
    }
}

bool continuation_permission() {
    std::string entered_value;
    // Keep asking until the user enters a valid response.
    while (true) {
        std::cout << "Do you wish to continue playing(y/n): ";

        // Recover from an input stream failure before asking again.
        if (!(std::cin >> entered_value)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Something went wrong, Please enter a valid input.\n";
            continue;
        }
        
        // Reject inputs containing extra characters such as
        if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Something went wrong, Please enter a valid input.\n";
            continue;
        }

        /*
            Convert the input to lowercase so comparisons
            are case-insensitive.
        */
        for (char& c : entered_value) {
            c = std::tolower(static_cast<unsigned char>(c));
        }

        // Only accept yes/no responses.
        if (entered_value != "yes" &&
            entered_value != "no" &&
            entered_value != "y" &&
            entered_value != "n") {
            std::cout << "Something went wrong, Please enter a valid input.\n";
            continue;
        }
        break;
    }
    if (entered_value == "yes" ||
        entered_value == "y") {
        return true;
    }
    
    return false;
}

int close_game() {
    std::cout << "Closing the game.\n"
              << "Thank you for playing.\n"
              << "******************************************************************************\n";
    
    // Enables the player to read the closing text before executing the exit.
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
