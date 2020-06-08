#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int count = 1;
struct {
    int next; //   上一个同起点的边的编号
    int to;   //   指向的位置
    int num;  //   权
    int from;

} Star[2000];
int head[2000];
class Map {
  private:
  public:
    Map();
    ~Map();
    void Disorder_product_print(); //无序积
    void Multiset_print();         //多重集
    void Vertex_set_print();       //顶点集合
    void Side_set_print();         //边集
    int Number_of_vertices();      //顶点数 n阶图
    int if_Zero_graph();           //是否为零图 是返回1 不是返回0；
    int if_Trivial_graph();        //是否为平凡图 是返回1不是返回0
    int if_Empty_graph();          //是否为空图
    void print_hraph();            //打印图
    void Undirected_graph();       //转换为无向图
    void Multiple_print_num();     //重数
    void add(int first, int second);
};
void Map::Multiple_print_num() {
    int book1[2000] = {0};
    int book2[2000] = {0};
    int book3[2000] = {0};
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            if (book1[Star[j].from] == Star[j].to) {
                book2[Star[j].from]++;
            }
            book1[Star[j].from] = Star[j].to;
        }
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            cout << "(" << Star[j].from << " ," << Star[j].to << "):"
                 << book2[Star[j].from] << ";  ";
        }
    cout << endl;
}
void Map::Undirected_graph() {
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            add(Star[j].to, Star[j].from);
        }
}
void Map::print_hraph() {
    for (int i = 1; i <= count; i++) {
        for (int j = head[i]; j != -1; j = Star[j].next) {
            cout << " (" << Star[j].from << " " << Star[j].to << ") ";
        }
    }
    cout << endl;
}
int Map::if_Empty_graph() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].from);
        }
    if (s.size() == 0 && if_Zero_graph())
        return 1;
    else {
        return 0;
    }
}
int Map::if_Trivial_graph() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].to);
        }
    if (s.size() == 1)
        return 1;
    else {
        return 0;
    }
}
int Map::if_Zero_graph() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].to);
        }
    if (s.size() == 0)
        return 1;
    else {
        return 0;
    }
}
int Map::Number_of_vertices() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].from);
        }
    return s.size();
}
void Map::Side_set_print() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].to);
        }
    cout << "{ ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << " }" << endl;
}
void Map::Vertex_set_print() {
    set<int> s;
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            s.insert(Star[j].from);
        }
    cout << "{ ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << " }" << endl;
}
void Map::Multiset_print() {
    map<int, int> m;
    int book[2000] = {0};
    for (int i = 1; i <= count; i++)
        for (int j = head[i]; j != -1; j = Star[j].next) {
            m[Star[j].from]++;
            m[Star[j].to]++;
            book[Star[j].from] = 1;
            book[Star[j].to] = 1;
        }
    for (int i = 1; i <= 2000; i++) {
        if (book[i] == 1) {
            cout << " <" << i << "," << m[i] << ")";
        }
    }
    cout << endl;
}
void Map::Disorder_product_print() {
    for (int i = 1; i <= count; i++) {
        for (int j = head[i]; j != -1; j = Star[j].next) {
            cout << " (" << Star[j].from << " " << Star[j].to << ") ";
        }
    }
    cout << endl;
}
Map::Map() {
    memset(head, -1, sizeof(head));
    ifstream in;
    in.open("math/map/map.txt", ios::in);
    int first, second;
    while (in >> first >> second) {
        add(first, second);
        // add(second, first);
    }
}
void Map::add(int first, int second) {
    Star[count].from = first;
    Star[count].to = second;
    Star[count].next = head[first];
    head[first] = count++;
    return;
}
Map::~Map() {}
