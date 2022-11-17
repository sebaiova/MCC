#pragma once

#include <vector>
#include <algorithm>

namespace mcc
{
    using Point = std::pair<double, double>;
    using TablePoint = std::vector<Point>;

    template<typename Function>
    TablePoint euler(Function dydx, Point x0y0, double h, std::size_t length)
    {
        TablePoint table(length);
        table[0] = x0y0;
        auto it { table.begin() };
        while(it!=table.end()-1)
            *(++it) = Point(it->first+h, it->second+h*dydx(it->first, it->second));
        return table;
    }
    
} // namespace mcc
