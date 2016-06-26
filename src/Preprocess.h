#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <string>

class Preprocess
{
public:
    Preprocess() {}

    virtual void work(std::string& str) = 0;

    virtual ~Preprocess() {};
};

class SimplePreprocess : public Preprocess
{
public:
    SimplePreprocess() {}

    void work(std::string& str);

    virtual ~SimplePreprocess() {}
};

#endif // PREPROCESS_H
