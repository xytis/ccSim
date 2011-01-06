#ifndef CTESTENVIROMENT_H_INCLUDED
#define CTESTENVIROMENT_H_INCLUDED

namespace DoI
{
    class cTestEnviroment
    {
        public:

        private:
            /**
            *   Čia sudėsim visus operatorius, kuriuos paeliui taikysim kiekvienam blokui.
            */
            vector<aMechanics *>operators;
            /**
            *   Čia pagrindinis blokų masyvas. Jame kartu ir lauko vertės užslėptos, kad būtų galima
            *   taikyti operatorius.
            */
            vector<cAbstractBlock *>blocks;
            /**
            *   Elektrinio lauko sąrašo pradžią ir pabaigą, kad galima būtų skaičiuoti el. lauką nelendant į blocks.
            */
            cField * field_begin;
            cField * field_end;

    };
};

#endif // CTESTENVIROMENT_H_INCLUDED
