#include "numtotext.hpp"

std::string textize3(int n, bool thousands) {
    int a = n % 10;  //единицы
    n /= 10;
    int b = n % 10;  //десятки
    n /= 10;
    int c = n;  //сотни
    std::string str = "";
    switch (c) {
    case 1: {
        str += "сто ";
        break;
    }
    case 2: {
        str += "двести ";
        break;
    }
    case 3: {
        str += "триста ";
        break;
    }
    case 4: {
        str += "четыреста ";
        break;
    }
    case 5: {
        str += "пятьсот ";
        break;
    }
    case 6: {
        str += "шестьсот ";
        break;
    }
    case 7: {
        str += "семьсот ";
        break;
    }
    case 8: {
        str += "восемьсот ";
        break;
    }
    case 9: {
        str += "девятьсот ";
        break;
    }
    }
    bool b_is_1 = false;
    switch (b) {
    case 2: {
        str += "двадцать ";
        break;
    }
    case 3: {
        str += "тридцать ";
        break;
    }
    case 4: {
        str += "сорок ";
        break;
    }
    case 5: {
        str += "пятьдесят ";
        break;
    }
    case 6: {
        str += "шестьдесят ";
        break;
    }
    case 7: {
        str += "семьдесят ";
        break;
    }
    case 8: {
        str += "восемьдесят ";
        break;
    }
    case 9: {
        str += "девяносто ";
        break;
    }
    case 1: {
        b_is_1 = true;
        switch (a) {
        case 0: {
            str += "десять ";
            break;
        }
        case 1: {
            str += "одиннадцать ";
            break;
        }
        case 2: {
            str += "двенадцать ";
            break;
        }
        case 3: {
            str += "тринадцать ";
            break;
        }
        case 4: {
            str += "четырнадцать ";
            break;
        }
        case 5: {
            str += "пятнадцать ";
            break;
        }
        case 6: {
            str += "шестнадцать ";
            break;
        }
        case 7: {
            str += "семнадцать ";
            break;
        }
        case 8: {
            str += "восемнадцать ";
            break;
        }
        case 9: {
            str += "девятнадцать ";
            break;
        }
        }
    }
    }
    if (!b_is_1)
        switch (a) {
        case 1: {
            if (thousands)
                str += "одна ";
            else
                str += "один ";
            break;
        }
        case 2: {
            if (thousands)
                str += "две ";
            else
                str += "два ";
            break;
        }
        case 3: {
            str += "три ";
            break;
        }
        case 4: {
            str += "четыре ";
            break;
        }
        case 5: {
            str += "пять ";
            break;
        }
        case 6: {
            str += "шесть ";
            break;
        }
        case 7: {
            str += "семь ";
            break;
        }
        case 8: {
            str += "восемь ";
            break;
        }
        case 9: {
            str += "девять ";
            break;
        }
        }

    return str;
}

std::string textize(std::string n) {
    std::string str = "";

    if (n.at(0) == '-') {
        str += "минус ";
        n.erase(n.begin());
    }
    
    for (auto it = n.begin(); it != n.end(); ++it)
        if (!isdigit(*it))
            n.erase(it--);
    
    if (n == "0")
        str += "ноль ";

    int number_of_group = -1;
    int value[20];
    while (!n.empty()) {
        int size_group = 3;
        if (n.size() < 3) 
            size_group = n.size();
        std::string last_three = n.substr(n.size() - size_group, size_group);
        value[++number_of_group] = std::stoi(last_three);
        n.erase(n.end() - size_group, n.end());
    }

    std::vector<std::string> names_of_pos_group(2);
    names_of_pos_group.push_back("миллион");
    names_of_pos_group.push_back("миллиард");
    names_of_pos_group.push_back("триллион");
    names_of_pos_group.push_back("квадриллион");
    names_of_pos_group.push_back("квинтиллион");
    names_of_pos_group.push_back("секстиллион");
    names_of_pos_group.push_back("септиллион");
    names_of_pos_group.push_back("октиллион");
    names_of_pos_group.push_back("нониллион");
    names_of_pos_group.push_back("дециллион");
    names_of_pos_group.push_back("ундециллион");
    names_of_pos_group.push_back("додециллион");
    names_of_pos_group.push_back("тредециллион");
    names_of_pos_group.push_back("кваттуордециллион");
    names_of_pos_group.push_back("квиндециллион");
    names_of_pos_group.push_back("седециллион");
    names_of_pos_group.push_back("септдециллион");
    names_of_pos_group.push_back("октодециллион");
    names_of_pos_group.push_back("новемдециллион");
    names_of_pos_group.push_back("вигинтиллион");

    for (int pos_group = number_of_group; pos_group >= 0; --pos_group) {
        if (value[pos_group] != 0) {
            str += textize3(value[pos_group], (pos_group == 1));
            
            int last = value[pos_group] % 10, penult = (value[pos_group] / 10) % 10;
            
            if (pos_group > 1) {
                str += (names_of_pos_group[pos_group]);
                
                if (penult != 1)
                    if (last == 1)                
                        str += " ";
                    else if ((last == 2) || (last == 3) || (last == 4))
                        str += "а ";
                    else
                        str += "ов ";
                else
                    str += "ов ";
            }
            else if (pos_group == 1) {
                if (penult != 1)
                    if (last == 1)
                        str += "тысяча ";
                    else if ((last == 2) || (last == 3) || (last == 4))
                        str += "тысячи ";
                    else
                        str += "тысяч ";
                else
                    str += "тысяч ";
            }
        }
    }

    str.erase(str.end() - 1);
    return str;
}
