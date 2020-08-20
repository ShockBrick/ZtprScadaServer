#include "aaaaa.h"

class aaaaaData : public QSharedData
{
public:

};

aaaaa::aaaaa() : data(new aaaaaData)
{

}

aaaaa::aaaaa(const aaaaa &rhs) : data(rhs.data)
{

}

aaaaa &aaaaa::operator=(const aaaaa &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

aaaaa::~aaaaa()
{

}
