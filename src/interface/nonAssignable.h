#ifndef NONASSIGNABLE_H
#define NONASSIGNABLE_H

namespace Plotypus
{
    struct NonAssignable
    {
        NonAssignable() = default;
        NonAssignable(const NonAssignable&) = delete;
        NonAssignable& operator=(const NonAssignable&) = delete;
    };
}

#endif // NONASSIGNABLE_H
