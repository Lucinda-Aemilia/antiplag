#include "Preprocess.h"

/// Simply Remove spaces and taps and etc.
void SimplePreprocess::work(std::string& str)
{
    std::string newStr;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 33 && str[i] <= 126)
            newStr += str[i];
    }
    str = newStr;
}
