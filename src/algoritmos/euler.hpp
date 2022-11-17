#pragma once

#include <vector>
#include <algorithm>

namespace mcc
{
    using Point = std::pair<double, double>;
    using TablePoint = std::vector<Point>;

    template<typename Metodo, typename Function>
    TablePoint ecuacion_diferencial(Function dydx, Point x0y0, double h, std::size_t length)
    {
        TablePoint table(length);
        table[0] = x0y0;
        auto it { table.begin() };
        while(it!=table.end()-1)
            *(++it) = Metodo::calc(dydx, *it, h);
        return table;
    }

    class Euler {
        template<typename Function>
        static Point calc(const Function& dydx, const Point& point, const double& h)
        {
            return { point.first+h, point.second+h*dydx(point.first, point.second) };
        }

        template<typename Metodo, typename Function>
        friend TablePoint ecuacion_diferencial(Function dydx, Point x0y0, double h, std::size_t length);
        friend class EulerMejorado;
    };

    class EulerMejorado {
        template<typename Function>
        static Point calc(const Function& dydx, const Point& x0y0, const double& h)
        {
            auto pre { Euler::calc(dydx, x0y0, h) };
            return { pre.first, x0y0.second + (h/2)*(dydx(x0y0.first, x0y0.second) + dydx(pre.first, pre.second)) };
        }

        template<typename Metodo, typename Function>
        friend TablePoint ecuacion_diferencial(Function dydx, Point x0y0, double h, std::size_t length);
    };

} // namespace mcc
