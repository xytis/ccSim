#ifndef CFIELD_H_INCLUDED
#define CFIELD_H_INCLUDED

namespace DoI
{
    class cField
    {
        public:
            /**
            *   Masyvo sukūrimas paliekamas išoriniam objektui.
            */
            cField()
            {
                //Empty
            };

            /**
            *   Su šaknies sunaikinimu miršta visas masyvas.
            */
            ~cField()
            {
                if (m_next!=NULL)
                    delete m_next;
            };

            cField * next()
            {
                return m_next;
            };

            cField * prev()
            {
                return m_prev;
            };

            void set_next(cField * next)
            {
                m_next = next;
            };
            void set_prev(cField * prev)
            {
                m_prev = prev;
            };
            void attach_left(cAbstractBlock * left)
            {
                m_left = left;
            };
            void attach_right(cAbstractBlock *right)
            {
                m_right = right;
            };

            /**
            *   Saviiteruojantis išvedimas
            */
            friend std::ostream & operator << (std::ostream & out, cField & cur)
            {
                out << cur.value() << ' ';
                //Saviiteracinė dalis
                if (cur.next() != NULL)
                    return (out << (*cur->next()));
                return out;
            };

            /**
            *   Saviiteruojantis metodas, kuris suskaičiuoja lauką medžiagoje.
            */
            virtual void calc() = 0;
            /**
            *   Saviiteruojantis metodas, kuris sunormuoja vidinį lauką palei duotą vertę.
            */
            virtual void norm(double) = 0;
            /**
            *   Metodas unifikuoti laukus
            */
            virtual double value() = 0;
            /**
            *   Metodas vidinio lauko perdavimui
            */
            virtual void deltaValue(double) = 0;

        protected:
            cField * m_next;
            cField * m_prev;
            cAbstractBlock * m_left;
            cAbstractBlock * m_right;
    };

    class cElectricField : public cField
    {
        public:
            void calc()
            {
                //Choose which way to integrate, depending on end.
                if (m_next == NULL)
                {
                    //Darbu sumos ištrinamos kai įvedama delta vertė
                    backward(0);
                }
                if (m_prev == NULL)
                {
                    forward(0);
                }
            };
            void norm(double n)
            {
                //Sulyginamos Darbu sumos ir paimamas jų vidurkis
                m_value = (m_forward + m_backward)/2;
                //Išvalomos vertės
                m_forward = 0;
                m_backward = 0;
                //Sunormuojama
                m_value += n;

                if (m_next != NULL)
                {
                    m_next->norm(n);
                }

            };
            double value()
            {
                return m_value;
            };
            void deltaValue(double dv)
            {
                m_dv=dv;
            };
        private:
            double  m_value;
            double  m_dv;
            double  m_forward;
            double  m_backward;
            void  forward(double cum)
            {
                cum += m_dv;
                m_forward = cum;
                if (m_next!=NULL)
                    m_next->forward(cum);
            };
            void  backward(double cum)
            {
                cum += m_dv;
                m_backward = cum;
                if (m_prev!=NULL)
                    m_prev->backward(cum);
            };


    };
};

#endif // CFIELD_H_INCLUDED
