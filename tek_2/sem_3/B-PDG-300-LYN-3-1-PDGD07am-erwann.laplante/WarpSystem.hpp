/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07am-erwann.laplante
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
    #define WARPSYSTEM_HPP_

    namespace WarpSystem
    {
        class QuantumReactor
        {
            bool _stability ;
            public:
                QuantumReactor();
                ~QuantumReactor();
                bool isStable ();
                void setStability (bool stability);
        };
        class Core
        {
            QuantumReactor *_coreReactor;
            public:
                Core(QuantumReactor *coreReactor);
                ~Core();
                QuantumReactor *checkReactor(void);
        };
    };

#endif /* !WARPSYSTEM_HPP_ */
