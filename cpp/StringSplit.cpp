/// @file
/// @brief Demonstrate ways to split string

#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

// use boost::split if you can

std::vector<std::string> SplitWithStringStream(std::string text)
{
    std::stringstream ss(text);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> words(begin, end);
    return words;
}

/// @brief Run the tests
void StringSplit()
{
    std::string testText = "The quick brown fox";
    auto words1 = SplitWithStringStream(testText);
    std::cout << "SplitWithStringStream: ";
    std::copy(words1.begin(), words1.end(), std::ostream_iterator<std::string>(std::cout, "|"));
    std::cout << std::endl;
}
