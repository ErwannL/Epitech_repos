/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
    #define SHAREDPOINTER_HPP_

    #include <iostream>
    #include "IObject.hpp"
    #include <memory>

    class SharedPointer : virtual public IObject {
        public:
            SharedPointer();
            SharedPointer(TestObject *obj);
            ~SharedPointer();

            void touch() override;
            void swap(SharedPointer &obj);
            long use_count();

            SharedPointer &operator=(TestObject *obj);
            TestObject *operator->();
            TestObject &operator*();

            void reset(TestObject *obj);
            void reset();

        protected:
            std::shared_ptr<TestObject> _obj;
    };

#endif /* !SHAREDPOINTER_HPP_ */
