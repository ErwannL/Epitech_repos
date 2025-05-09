/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** List
*/

#ifndef LIST_HPP_
    #define LIST_HPP_

     #include <list>
     #include "IObject.hpp"

    class List {
        public:
            List();
            ~List();

            bool empty() const;
            std::size_t size() const;
            void clear();
            void forEach(void(*function)(IObject*));

            IObject*& front();
            IObject* front() const;

            IObject*& back();
            IObject* back() const;

            void pushBack(IObject* obj);
            void pushFront(IObject* obj);

            void popFront();
            void popBack();

            class InvalidOperationException {
                public:
                    InvalidOperationException();
                    ~InvalidOperationException();

                    void what() const noexcept;
            };

        private:
            std::list<IObject *> _list;
    };

#endif /* !LIST_HPP_ */
