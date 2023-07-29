#ifndef FIFOCONSTITERABLE_H
#define FIFOCONSTITERABLE_H

#include<list>
#include <utility>

namespace Plotypus
{
    template <typename T>
    struct FiFoConstIterable
    {
            class ConstIterator
            {
                public:
                    using iterator_category    = std::bidirectional_iterator_tag;
                    using iterator_concept     = std::bidirectional_iterator_tag;
                    using difference_type      = typename std::iterator<iterator_category, T>::difference_type;
                    using value_type           = std::remove_cv_t<T>;
                    using pointer              = T*;
                    using reference            = T&;
                    using element_type         = T;
                    using native_iterator_type = typename std::list<T*>::const_iterator;

                private:
                    native_iterator_type iter;

                public:
                    // user needs
                    ConstIterator(const native_iterator_type& iter);

                    // std::weakly_incrementable<I>
                    ConstIterator() = default;
                    ConstIterator& operator++();     // prefix inc
                    ConstIterator operator++(int);   // postfix inc

                    // std::input_or_output_iterator<I>
                    reference operator*();

                    // std::indirectly_readable<I>
                    friend reference operator*(const ConstIterator& it);

                    // std::input_iterator<I>
                    // No actions were needed here!

                    // std::forward_iterator<I>
                    // In C++20, 'operator==' implies 'operator!='
                    bool operator==(const ConstIterator& it) const;

                    // std::bidirectional_iterator<I>
                    ConstIterator& operator--();
                    ConstIterator operator--(int);
            };

            // === STATIC ASSERTS ===
            // - to verify correct Iterator implementation!
            static_assert(std::weakly_incrementable<ConstIterator>);
            static_assert(std::input_or_output_iterator<ConstIterator>);
            static_assert(std::indirectly_readable<ConstIterator>);
            static_assert(std::input_iterator<ConstIterator>);
            static_assert(std::incrementable<ConstIterator>);
            static_assert(std::forward_iterator<ConstIterator>);
            static_assert(std::bidirectional_iterator<ConstIterator>);

            FiFoConstIterable() = default;

            virtual ConstIterator cbegin() const = 0;
            virtual ConstIterator cend() const = 0;

            virtual ConstIterator begin() const = 0;
            virtual ConstIterator end() const = 0;
    };
}

#include "fifoconstiterable.txx"

#endif // FIFOCONSTITERABLE_H
