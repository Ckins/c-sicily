#include <iostream>
#include <utility>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        map<string, string> mapName;
        map<string, string> mapIp;
        for (int i = 0; i < n; i++) {
            string name;
            string ip;
            cin >> name >> ip;
            map<string, string>::iterator it = mapIp.begin();
            for (;it != mapIp.end(); it++) {
                if (it->second == ip) {
                    mapName.insert(make_pair(it->first, name));
                    break;
                }
            }
            if (it == mapIp.end()) {
                mapIp.insert(make_pair(name, ip));
            }
        }
        map<string, string>::iterator it = mapName.begin();
        for (;it != mapName.end(); it++) {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
