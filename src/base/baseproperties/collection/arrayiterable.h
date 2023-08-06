#ifndef VECTORLIKE_H
#define VECTORLIKE_H

#include <iterator>

namespace Plotypus
{
    template<typename T>
    struct ArrayIterable
    {
            class Iterator
            {
                public:
                    using iterator_category = std::contiguous_iterator_tag;
                    using iterator_concept  = std::contiguous_iterator_tag;
                    using difference_type   = ptrdiff_t;
                    using value_type        = std::remove_cv_t<T>;
                    using pointer           = std::shared_ptr<T>;
                    using reference         = T&;
                    using element_type      = T;
                    using native_iter_type  = typename std::vector<std::shared_ptr<T>>::iterator;

                private:
                    native_iter_type nIter;

                public:
                    // user needs
                    Iterator(native_iter_type nIter);

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

                    // std::random_access_iterator<I>
                    //     std::totally_ordered<I>
                    std::weak_ordering operator<=> (const Iterator& it) const;

                    //     std::sized_sentinel_for<I, I>
                    difference_type operator-(const Iterator& it) const;

                    //     std::iter_difference<I> operators
                    Iterator&       operator+=(difference_type diff);
                    Iterator&       operator-=(difference_type diff);
                    Iterator        operator+ (difference_type diff) const;
                    Iterator        operator- (difference_type diff) const;
                    friend Iterator operator+ (difference_type diff, const Iterator& it);
                    friend Iterator operator- (difference_type diff, const Iterator& it);
                    reference operator[](difference_type diff) const;

                    // std::contiguous_iterator<I>
                    pointer operator->() const;
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
            static_assert(std::totally_ordered<Iterator>);
            static_assert(std::sized_sentinel_for<Iterator, Iterator>);
            static_assert(std::random_access_iterator<Iterator>);
            static_assert(std::is_lvalue_reference_v<std::iter_reference_t<Iterator>>);
            static_assert(std::same_as<std::iter_value_t<Iterator>,
                          std::remove_cvref_t<std::iter_reference_t<Iterator>>>);
            //        static_assert(std::contiguous_iterator<Iterator>);

            ArrayIterable() = default;

            virtual Iterator begin() = 0;
            virtual Iterator end() = 0;
    };
}

#include "arrayiterable.txx"

#endif // VECTORLIKE_H
