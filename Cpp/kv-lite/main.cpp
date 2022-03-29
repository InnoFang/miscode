#include <iostream>
#include <string>
#include <skip_list.hpp>

#define FILE_PATH "./store/dumpFile"

int main() {
    inno::SkipList<int, std::string> skipList(6);
    skipList.insert_element(1, "H");
    skipList.insert_element(2, "e");
    skipList.insert_element(4, "l");
    skipList.insert_element(5, "0");
    skipList.insert_element(6, ",");

    std::cout << "skip list size: " << skipList.size() << std::endl;

    skipList.dump_file();

    skipList.search_element(3);
    skipList.search_element(4);

    skipList.display_list();

    skipList.delete_element(1);

    std::cout << "skip list size: " << skipList.size() << std::endl;

    skipList.display_list();

    return 0;
}
