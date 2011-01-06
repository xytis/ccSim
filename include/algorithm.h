#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

namespace DoI
{
    //Abstracti funkcija. Nurodo visas mechanikas kurios turi būti taikomos cAbstractBlock
    class aMechanics
    {
        public:
            void operator()(cAbstractBlock *);
            void apply(cAbstractBlock *);
    };
    //Reikia sukurti tokias klases, kad naudojimasis jomis atrodytų
    //kaip arba paprasta funkcija iš vidaus, arba operatorius iš išorės...
    class aDifusion : public aMechanics;
    {
        public:

        private:
    };
};

#endif // ALGORITHM_H_INCLUDED
