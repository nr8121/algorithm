#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> m;
    m["str"]+=1;

    printf("%d\n", m["str"]);

}