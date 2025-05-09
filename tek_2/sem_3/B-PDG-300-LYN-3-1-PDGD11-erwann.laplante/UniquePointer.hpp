/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
    #define UNIQUEPOINTER_HPP_

    #include <iostream>
    #include "IObject.hpp"
    #include <memory>

    class UniquePointer : virtual public IObject {
        public:
            UniquePointer();
            UniquePointer(TestObject *obj);
            ~UniquePointer();

            void touch() override;
            void swap(UniquePointer &obj);

            UniquePointer &operator=(TestObject *obj);
            TestObject *operator->();
            TestObject &operator*();

            void reset(TestObject *obj);
            void reset();

        protected:
            std::unique_ptr<TestObject> _obj;
    };

#endif /* !UNIQUEPOINTER_HPP_ */
