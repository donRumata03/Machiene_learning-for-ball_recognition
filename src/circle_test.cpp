#include "main.hpp"

using namespace std;

pms points;
point cent(0, 0);
pms edges;

double f_to_plot(double r){
    return fast_error_function(edges, circle(point(cent.x, cent.y), r));
}

int main(){
    Test_Generator t1(circle(point(0, 0), 30), point(-110, -110), point(110, 110), circle(point(0, 30), 30));
    point_matrix mt = t1.generate_random_distortion();
    mt.print();
    points = mt.get_points();
    clear_plot();
    /*
    double minval = 999999;
    double minindex = -1;
    for(double i = 0; i < 40; i += 0.01){
        double val = error_function(points, circle(cent.x, cent.y, i));
        if (val < minval){
            minval = val;
            minindex = i;
        }
    }
    cout << "Optimum at r = : " << minindex << "; It is: " << minval;
    */
    edges = detect_edges(points);
    point_matrix(edges).print();
    add_function_to_plot(f_to_plot, -1, 40, 0.01);
    
    show_plot();
    _getwch();
    return 0;
}