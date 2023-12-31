#ifndef VECTORCONSTITERATOR_H
#define VECTORCONSTITERATOR_H

#include <iterator>

namespace Plotypus
{
    template<typename T>
    class ArrayConstIterable
    {
        public:
            class ConstIterator
            {
                public:
                    using iterator_category = std::contiguous_iterator_tag;
                    using iterator_concept  = std::contiguous_iterator_tag;
                    using difference_type   = ptrdiff_t;
                    using value_type        = const std::remove_cv_t<T>;
                    using pointer           = std::shared_ptr<const T>;
                    using reference         = const T&;
                    using element_type      = const T;
                    using native_iter_type  = typename std::vector<std::shared_ptr<T>>::const_iterator;

                private:
                    native_iter_type nIter;

                public:
                    // user needs
                    ConstIterator(native_iter_type nIter);

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

                    // std::random_access_iterator<I>
                    //     std::totally_ordered<I>
                    std::weak_ordering operator<=>(const ConstIterator& it) const;

                    //     std::sized_sentinel_for<I, I>
                    difference_type operator-(const ConstIterator& it) const;

                    //     std::iter_difference<I> operators
                    ConstIterator& operator+= (difference_type diff);
                    ConstIterator& operator-= (difference_type diff);
                    ConstIterator  operator+ (difference_type diff) const;
                    ConstIterator  operator- (difference_type diff) const;
                    friend ConstIterator operator+(difference_type diff, const ConstIterator& it);
                    friend ConstIterator operator-(difference_type diff, const ConstIterator& it);
                    reference operator[](difference_type diff) const;

                    // std::contiguous_iterator<I>
                    pointer operator->() const;
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
            static_assert(std::totally_ordered<ConstIterator>);
            static_assert(std::sized_sentinel_for<ConstIterator, ConstIterator>);
            static_assert(std::random_access_iterator<ConstIterator>);
            static_assert(std::is_lvalue_reference_v<std::iter_reference_t<ConstIterator>>);
            static_assert(std::same_as<std::iter_value_t<ConstIterator>,
                          std::remove_cvref_t<std::iter_reference_t<ConstIterator>>>);
            // static_assert(std::contiguous_iterator<ConstIterator>);


        public:
            ArrayConstIterable() = default;

            virtual ConstIterator cbegin() const = 0;
            virtual ConstIterator cend() const = 0;

            virtual ConstIterator begin() const = 0;
            virtual ConstIterator end() const = 0;
    };
}

#include "arrayconstiterable.txx"

#endif // VECTORCONSTITERATOR_H
