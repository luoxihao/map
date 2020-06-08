#include "Map.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    Map M;
    // cout << "无序积:" << endl;
    // M.Disorder_product_print();
    // cout << "多重集:" << endl;
    // M.Multiset_print();
    // cout << "顶点集:" << endl;
    // M.Vertex_set_print();
    // cout << "边集:" << endl;
    // M.Side_set_print();
    // cout << "是" << M.Number_of_vertices() << "阶图" << endl;
    // cout << "是否为零图" << endl;
    // cout << M.if_Zero_graph() << endl;
    // cout << "是否为平凡图" << endl;
    // cout << M.if_Trivial_graph() << endl;
    // cout << "是否为空图" << endl;
    // cout << M.if_Empty_graph() << endl;
    cout << "重度" << endl;
    M.Multiple_print_num();

    // cout << "转换为无向图" << endl;
    // M.Undirected_graph();

    return 0;
}
