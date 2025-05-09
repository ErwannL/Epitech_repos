/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD13-erwann.laplante
** File description:
** Array
*/

#ifndef ARRAY_HPP_
    #define ARRAY_HPP_

    #include <iostream>
    #include <exception>
    #include <functional>

    template <typename Type, std::size_t Size>
    class Array {
        public:
            Array() : _array(new Type[Size]){}

            ~Array() {};

            Type &operator[](std::size_t where) const
            {
                if (where >= Size)
                    throw std::out_of_range("Out of range");
                return _array[where];
            }

            std::size_t size() const
            {
                return Size;
            }

            void forEach (const std::function <void(const Type &)> &task) const
            {
                for (std::size_t i = 0; i != Size; i++)
                    task(_array[i]);
            }

            template <typename U>
            Array <U, Size> convert(const std::function <U (const Type &)> &converter) const
            {
                Array<U, Size> new_array;

                for (std::size_t i = 0; i != Size; i++)
                    new_array[i] = converter(_array[i]);

                return new_array;
            }

            Type *_array;
    };

    template <typename Type, std::size_t size>
    std::ostream &operator<<(std::ostream &stream, Array<Type, size> const &array)
    {
        stream << "[";
        for (std::size_t i = 0; i != size; i++) {
            if (i != 0)
                stream << ", ";
            stream <<  array._array[i];
        }
        stream << "]";
        return stream;
    }

#endif /* !ARRAY_HPP_ */
