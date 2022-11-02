#include <vector>
#include <algorithm>

namespace mcc {

    template<typename Function>
    auto armar_tabla(Function f, double x0, double h, std::size_t n)
    {
        std::vector<double> vec(n+1);
        for(auto& v : vec) { 
            v = f(x0); 
            x0 += h; 
        }
        return vec;
    }

    template<typename Function>
    auto armar_tabla(Function f, double x0, double y, double h, double k, std::size_t m, std::size_t n)
    {
        std::vector<std::vector<double>> vec(n+1);
        for(auto& v : vec) {
            v = armar_tabla([y, &f](double x0){return f(x0, y);}, x0, h, m);
            y += k;
        }
        return vec;
    }
        
    struct Riemman {
        template<typename Container2D>
        static double doble(Container2D const& container, double h, double k)
        {
            double area { h * k }, volumen { 0 };

            std::vector<std::vector<double>> cont(container.begin(), container.end()-1);

            for(auto& vec_y : cont) {
                 std::vector<double>  vec_yy(vec_y.begin(), vec_y.end()-1);
                for(auto& xy: vec_yy)
 
                    volumen += (xy*area);
            }
            return volumen;
        }
    };

    struct Trapecio {
        template<typename Container>
        static double simple(Container const& container, double h)
        {
            double resultado { container.front() + container.back() };
            std::for_each(container.begin()+1, container.end()-1, [&resultado](auto x){ resultado += x*2;});
            return resultado*(h/2);
        }
        template<typename Container2D>
        static double doble(Container2D const& container, double h, double k)
        {
            std::vector<double> vec(container[0].size());
            auto it { container.begin() };
            for(auto& v : vec) 
                v = simple(*it++, h);
            return simple(vec, k);
        }
    };

    struct Simpson {
        template<typename Container>
        static double simple(Container const& container, double h)
        {
            double resultado { container.front() + container.back() };
            bool par { false };
            std::for_each(container.begin()+1, container.end()-1, [&resultado, &par](auto x){ resultado += x*(par ? 2 : 4) ; par = !par; });
            return resultado*(h/3);
        }
        template<typename Container2D>
        static double doble(Container2D const& container, double h, double k)
        {
            std::vector<double> vec(container[0].size());
            auto it { container.begin() };
            for(auto& v : vec) 
                v = simple(*it++, h);
            return simple(vec, k);
        }
    };

    template<typename Metodo, typename Function> 
    double integrar(Function f, double a, double b, std::size_t n)
    {
        double h {(b-a)/ n};
        return Metodo::simple(armar_tabla(f, a, h, n), h);
    }

    template<typename Metodo, typename Funcion>
    double integrar(Funcion f, double a, double b, std::size_t m, double c, double d, std::size_t n)
    {
        double h { (b-a)/m };
        double k { (d-c)/n };
        return Metodo::doble(armar_tabla(f, a, c, h, k, m, n), h, k);
    }
}