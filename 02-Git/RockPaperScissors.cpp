#include <iostream>
#include <random>
#include <map>


void UserInputPrompt()
{
    std::cout << "Please choose:" << std::endl \
        << "rock (r) - paper (p) - scissors (s) or (q) for quit:" \
        << std::endl;
}

void UserIncorrectInputPrompt()
{
    std::cout << std::endl << std::endl \
        << "Your input is incorrect. Try again, please:" \
        << std::endl << std::endl;
}

char GetUserInput()
{
    char rock_paper_scissors_symbol{ 'q' };
    std::cin >> rock_paper_scissors_symbol;

    return rock_paper_scissors_symbol;
}

enum class UserChoice { rock = 0, paper, scissors, quit = 10, other };

UserChoice CheckUserInput(char user_input)
{
    switch (user_input)
    {
    case 'r':
        return UserChoice::rock;
        break;
    case 'p':
        return UserChoice::paper;
        break;
    case 's':
        return UserChoice::scissors;
        break;
    case 'q':
        return UserChoice::quit;
        break;
    default:
        return UserChoice::other;
        break;
    }
}

UserChoice GetRandomChoice()
{
    std::random_device random_device;

    // Choose a random mean between 0 and 2
    // Actually, it means UserChoice::rock, UserChoice::paper and UserChoice::scissors
    std::default_random_engine default_random_engine(random_device());
    std::uniform_int_distribution<int> uniform_int_distribution(0, 2);

    int random_choice{ uniform_int_distribution(default_random_engine) };

        switch (random_choice)
        {
        case 0:
            return UserChoice::rock;
            break;
        case 1:
            return UserChoice::paper;
            break;
        case 2:
            return UserChoice::scissors;
            break;
        default:
            return UserChoice::rock; //Actually must throwing an appropriate exception
            break;
        }
}

std::string GameResult(UserChoice user_choice, UserChoice random_choice)
{
    typedef std::pair<UserChoice, UserChoice> GameResultPair;
    typedef std::string GameResultExplanation;
    typedef std::map<GameResultPair, GameResultExplanation> GameResults;

    const GameResults game_results{
        {std::make_pair(UserChoice::rock, UserChoice::rock), \
        std::string{ "All players have formed the same shapes. So, it's a draw!"} },
        {std::make_pair(UserChoice::paper, UserChoice::paper), \
        std::string{ "All players have formed the same shapes. So, it's a draw!" } },
        {std::make_pair(UserChoice::scissors, UserChoice::scissors), \
        std::string{ "All players have formed the same shapes. So, it's a draw!" } },

        {std::make_pair(UserChoice::rock, UserChoice::paper), \
        std::string{ "Sorry, but you've lost. Because paper beats rock."} },
        {std::make_pair(UserChoice::rock, UserChoice::scissors), \
        std::string{ "Congratulation! You've won. Because rock beats scissors."} },

        {std::make_pair(UserChoice::paper, UserChoice::rock), \
        std::string{ "Congratulation! You've won. Because paper beats rock."} },
        {std::make_pair(UserChoice::paper, UserChoice::scissors), \
        std::string{ "Sorry, but you've lost. Because scissors beats paper."} },

        {std::make_pair(UserChoice::scissors, UserChoice::rock), \
        std::string{ "Sorry, but you've lost. Because rock beats scissors."} },
        {std::make_pair(UserChoice::scissors, UserChoice::paper), \
        std::string{ "Congratulation! You've won. Because scissors beats paper."} }
    };

    GameResultPair game_result_pair{std::make_pair(user_choice, random_choice)};

    auto game_result{ game_results.find(game_result_pair) };

    if (game_result != game_results.end())
    {
        return game_result->second;
    }
    else
    {
        return std::string("Unknown error!");
    }
}

void RockPaperScissorsGame(UserChoice user_choice)
{
    std::cout << GameResult(user_choice, GetRandomChoice()) \
        << std::endl << std::endl;
}

void RockPaperScissorsGameMainCycle()
{
    for (bool is_it_continuing{ true }; is_it_continuing;)
    {
        UserInputPrompt();

        UserChoice user_choice{ CheckUserInput(GetUserInput()) };

        switch(user_choice)
        {
        case UserChoice::rock:
            RockPaperScissorsGame(user_choice);
            break;
        case UserChoice::paper:
            RockPaperScissorsGame(user_choice);
            break;
        case UserChoice::scissors:
            RockPaperScissorsGame(user_choice);
            break;
        case UserChoice::quit:
            is_it_continuing = false;
            break;
        default:
            UserIncorrectInputPrompt();
            break;
        }
    }
}

int main()
{
    RockPaperScissorsGameMainCycle();
}