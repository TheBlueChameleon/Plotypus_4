#ifndef FIFOITERABLE_H
#define FIFOITERABLE_H

#include<list>
#include <utility>

namespace Plotypus
{
    template <typename T>
    struct FiFoIterable
    {
            class Iterator
            {
                public:
                    using iterator_category    = std::bidirectional_iterator_tag;
                    using iterator_concept     = std::bidirectional_iterator_tag;
                    using difference_type      = ptrdiff_t;
                    using value_type           = std::remove_cv_t<T>;
                    using pointer              = T*;
                    using reference            = T&;
                    using element_type         = T;
                    using native_iterator_type = typename std::list<T*>::iterator;

                private:
                    native_iterator_type iter;

                public:
                    // user needs
                    Iterator(const native_iterator_type& iter);

                    // std::weakly_incrementable<I>
                    Iterator() = default;
                    Iterator& operator++();     // prefix inc
                    Iterator operator++(int);   // postfix inc

                    // std::input_or_output_iterator<I>
                    reference operator*();

                    // std::indirectly_readable<I>
                    friend reference operator*(const Iterator& it);

                    // std::input_iterator<I>
                    // No actions were needed here!

                    // std::forward_iterator<I>
                    // In C++20, 'operator==' implies 'operator!='
                    bool operator==(const Iterator& it) const;

                    // std::bidirectional_iterator<I>
                    Iterator& operator--();
                    Iterator operator--(int);
            };

            // === STATIC ASSERTS ===
            // - to verify correct Iterator implementation!
            static_assert(std::weakly_incrementable<Iterator>);
            static_assert(std::input_or_output_iterator<Iterator>);
            static_assert(std::indirectly_readable<Iterator>);
            static_assert(std::input_iterator<Iterator>);
            static_assert(std::incrementable<Iterator>);
            static_assert(std::forward_iterator<Iterator>);
            static_assert(std::bidirectional_iterator<Iterator>);

            FiFoIterable() = default;

            virtual Iterator begin() = 0;
            virtual Iterator end() = 0;
    };
}

#include "fifoiterable.txx"

#endif // FIFOITERABLE_H
